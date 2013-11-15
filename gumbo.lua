local have_ffi, ffi = pcall(require, "ffi")

if not have_ffi then -- load the C module instead
    local oldpath = package.path
    package.path = ""
    local gumbo_c_module = require "gumbo"
    package.path = oldpath
    return gumbo_c_module
end

local gumbo = require "gumbo-cdef"
local build

local function add_children(t, children)
    for i = 0, children.length-1 do
        t[i+1] = build(ffi.cast("GumboNode*", children.data[i]))
    end
end

local function get_attributes(attrs)
    if attrs.length ~= 0 then
        local t = {}
        for i = 0, attrs.length-1 do
            local attr = ffi.cast("GumboAttribute*", attrs.data[i])
            t[ffi.string(attr.name)] = ffi.string(attr.value)
        end
        return t
    end
end

local quirksmap = {
    [tonumber(gumbo.GUMBO_DOCTYPE_NO_QUIRKS)] = "no-quirks",
    [tonumber(gumbo.GUMBO_DOCTYPE_QUIRKS)] = "quirks",
    [tonumber(gumbo.GUMBO_DOCTYPE_LIMITED_QUIRKS)] = "limited-quirks"
}

local function create_document(node, root_index)
    local document = node.v.document
    local ret = {
        type = "document",
        name = ffi.string(document.name),
        public_identifier = ffi.string(document.public_identifier),
        system_identifier = ffi.string(document.system_identifier),
        has_doctype = document.has_doctype,
        quirks_mode = quirksmap[tonumber(document.doc_type_quirks_mode)]
    }
    add_children(ret, document.children)
    ret.root = ret[root_index]
    return ret
end

local function get_tag_name(element)
    if element.tag == gumbo.GUMBO_TAG_UNKNOWN then
        local original_tag = element.original_tag
        gumbo.gumbo_tag_from_original_text(original_tag)
        return ffi.string(original_tag.data, original_tag.length)
    else
        return ffi.string(gumbo.gumbo_normalized_tagname(element.tag))
    end
end

local function create_element(node)
    local element = node.v.element
    local ret = {
        type = "element",
        tag = get_tag_name(element),
        parse_flags = tonumber(node.parse_flags),
        start_pos = {
            line = element.start_pos.line,
            column = element.start_pos.column,
            offset = element.start_pos.offset
        },
        end_pos = {
            line = element.end_pos.line,
            column = element.end_pos.column,
            offset = element.end_pos.offset
        },
        attr = get_attributes(element.attributes)
    }
    add_children(ret, element.children)
    return ret
end

local typemap = {
    [tonumber(gumbo.GUMBO_NODE_DOCUMENT)] = "document",
    [tonumber(gumbo.GUMBO_NODE_ELEMENT)] = "element",
    [tonumber(gumbo.GUMBO_NODE_TEXT)] = "text",
    [tonumber(gumbo.GUMBO_NODE_CDATA)] = "cdata",
    [tonumber(gumbo.GUMBO_NODE_COMMENT)] = "comment",
    [tonumber(gumbo.GUMBO_NODE_WHITESPACE)] = "whitespace"
}

local function create_text(node)
    local text = node.v.text
    return {
        type = typemap[tonumber(node.type)],
        text = ffi.string(text.text),
        start_pos = {
            line = text.start_pos.line,
            column = text.start_pos.column,
            offset = text.start_pos.offset
        }
    }
end

local handlers = {
    [tonumber(gumbo.GUMBO_NODE_DOCUMENT)] = function() error() end,
    [tonumber(gumbo.GUMBO_NODE_ELEMENT)] = create_element,
    [tonumber(gumbo.GUMBO_NODE_TEXT)] = create_text,
    [tonumber(gumbo.GUMBO_NODE_CDATA)] = create_text,
    [tonumber(gumbo.GUMBO_NODE_COMMENT)] = create_text,
    [tonumber(gumbo.GUMBO_NODE_WHITESPACE)] = create_text
}

build = function(node)
    return handlers[tonumber(node.type)](node)
end

local function parse(input, tab_stop)
    local options = ffi.new("GumboOptions")
    ffi.copy(options, gumbo.kGumboDefaultOptions, ffi.sizeof("GumboOptions"))
    options.tab_stop = tab_stop or 8
    local output = gumbo.gumbo_parse_with_options(options, input, #input)
    local root_index = output.root.index_within_parent + 1
    local document = create_document(output.document, root_index)
    gumbo.gumbo_destroy_output(options, output)
    return document
end

return {parse = parse}
