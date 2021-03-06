cmake_minimum_required (VERSION 2.6)
project (LuaGumbo C)

set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_C_STANDARD 99)

if(UNIX)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

# Lua
if(WIN32)
  find_package (Lua REQUIRED)
else()
  # Only the include dir matters on UNIX
  find_package (Lua)
  if(NOT LUA_INCLUDE_DIR)
    message( FATAL_ERROR "Variable `LUA_INCLUDE_DIR' expected to be defined.")
  endif()
endif()

# Gumbo
set(LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib)
set(WINDOWS_LIB_INCLUDE_DIR ${LIB_INCLUDE_DIR}/visualc/include)
set(LIBGUMBO_OBJ attribute char_ref error parser string_buffer string_piece svg_attrs svg_tags tag tag_lookup tokenizer utf8 util vector)

add_library( attribute lib/attribute.c lib/attribute.h lib/gumbo.h lib/util.h )
add_library( char_ref lib/char_ref.c lib/char_ref.h lib/error.h lib/gumbo.h
 lib/insertion_mode.h lib/string_buffer.h lib/token_type.h
 lib/string_piece.h lib/utf8.h lib/util.h )
add_library( error lib/error.c lib/error.h lib/gumbo.h lib/insertion_mode.h
 lib/string_buffer.h lib/token_type.h lib/parser.h lib/util.h
 lib/vector.h )
add_library( parser lib/parser.c lib/attribute.h lib/gumbo.h lib/error.h
 lib/insertion_mode.h lib/string_buffer.h lib/token_type.h lib/parser.h
 lib/tokenizer.h lib/tokenizer_states.h lib/utf8.h lib/util.h
 lib/vector.h lib/replacement.h )
add_library( string_buffer lib/string_buffer.c lib/string_buffer.h lib/gumbo.h
 lib/string_piece.h lib/util.h )
add_library( string_piece lib/string_piece.c lib/string_piece.h lib/gumbo.h lib/util.h )
add_library( svg_attrs lib/svg_attrs.c lib/replacement.h )
add_library( svg_tags lib/svg_tags.c lib/replacement.h )
add_library( tag lib/tag.c lib/gumbo.h lib/util.h lib/tag_lookup.h )
add_library( tag_lookup lib/tag_lookup.c lib/tag_lookup.h lib/gumbo.h )
add_library( tokenizer lib/tokenizer.c lib/tokenizer.h lib/gumbo.h lib/token_type.h
 lib/tokenizer_states.h lib/attribute.h lib/char_ref.h lib/error.h
 lib/insertion_mode.h lib/string_buffer.h lib/parser.h lib/string_piece.h
 lib/utf8.h lib/util.h lib/vector.h )
add_library( utf8 lib/utf8.c lib/utf8.h lib/gumbo.h lib/error.h
 lib/insertion_mode.h lib/string_buffer.h lib/token_type.h lib/parser.h
 lib/util.h lib/vector.h )
add_library( util lib/util.c lib/util.h lib/gumbo.h lib/parser.h )
add_library( vector lib/vector.c lib/vector.h lib/gumbo.h lib/util.h )

foreach(LIB_NAME ${LIBGUMBO_OBJ})
  target_include_directories( ${LIB_NAME} PUBLIC ${LIB_INCLUDE_DIR} )
  if (WIN32)
    target_include_directories( ${LIB_NAME} PRIVATE ${WINDOWS_LIB_INCLUDE_DIR} )
  endif()
endforeach(LIB_NAME)

# Lua-Gumbo
add_library( parse MODULE gumbo/parse.c )
target_link_libraries ( parse ${LIBGUMBO_OBJ} )
target_include_directories( parse PRIVATE ${LUA_INCLUDE_DIR} )
if(WIN32)
  target_compile_definitions( parse PRIVATE _CRT_SECURE_NO_WARNINGS )
endif()

# Only link against the Lua library on Windows
if(WIN32)
  target_link_libraries( parse ${LUA_LIBRARIES} )
endif()

# Needed to avoid getting undefined references to liblua
if(APPLE)
  set(CMAKE_SHARED_MODULE_CREATE_C_FLAGS "${CMAKE_SHARED_MODULE_CREATE_C_FLAGS} -undefined dynamic_lookup")
endif()

# Install targets for Luarocks and non-Luarocks
if(LUAROCKS_INSTALL_LIBDIR)
  SET(INSTALL_LIB_DIR ${LUAROCKS_INSTALL_LIBDIR})
elseif(UNIX)
  set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
elseif(WIN32)
  set(INSTALL_LIB_DIR "${PROJECT_SOURCE_DIR}")
endif()

if(INSTALL_LIB_DIR)
  install(TARGETS parse ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" LIBRARY DESTINATION "${INSTALL_LIB_DIR}")
endif()
