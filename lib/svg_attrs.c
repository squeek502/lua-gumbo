/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -m100 lib/svg_attrs.gperf  */
/* Computed positions: -k'1,10,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif


#include "replacement.h"
#include <string.h>

#define TOTAL_KEYWORDS 58
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 19
#define MIN_HASH_VALUE 5
#define MAX_HASH_VALUE 77
/* maximum key range = 73, duplicates = 0 */

#ifndef GPERF_DOWNCASE
#define GPERF_DOWNCASE 1
static unsigned char gperf_downcase[256] =
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
     30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
     45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
     60,  61,  62,  63,  64,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255
  };
#endif

#ifndef GPERF_CASE_MEMCMP
#define GPERF_CASE_MEMCMP 1
static int
gperf_case_memcmp (register const char *s1, register const char *s2, register size_t n)
{
  for (; n > 0;)
    {
      unsigned char c1 = gperf_downcase[(unsigned char)*s1++];
      unsigned char c2 = gperf_downcase[(unsigned char)*s2++];
      if (c1 == c2)
        {
          n--;
          continue;
        }
      return (int)c1 - (int)c2;
    }
  return 0;
}
#endif

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static const unsigned char asso_values[] =
    {
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78,  5, 78, 39, 14,  1,
      31, 31, 13, 13, 78, 78, 22, 25, 10,  2,
       7, 78, 22,  0,  1,  3,  1, 78,  0, 36,
      14, 17, 20, 78, 78, 78, 78,  5, 78, 39,
      14,  1, 31, 31, 13, 13, 78, 78, 22, 25,
      10,  2,  7, 78, 22,  0,  1,  3,  1, 78,
       0, 36, 14, 17, 20, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
      78, 78, 78, 78, 78, 78, 78, 78
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
      case 8:
      case 7:
      case 6:
      case 5:
      case 4:
      case 3:
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]+2];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

const StringReplacement *
gumbo_get_svg_attr_replacement (register const char *str, register size_t len)
{
  static const unsigned char lengthtable[] =
    {
       0,  0,  0,  0,  0,  4,  0,  7,  7,  0,  8,  9, 10, 11,
      11, 11, 11, 10, 16, 18, 16, 12, 16, 11, 13, 11, 12, 11,
      16,  0, 17,  9,  9,  8,  9, 10, 13, 10, 12, 14,  8,  4,
      12, 19,  7,  9, 12, 12, 11, 14, 10, 19,  8, 16, 13, 16,
      16, 15, 10, 12,  0,  0, 13, 13, 13,  0,  0,  9, 16,  0,
       0,  0,  0,  0,  0,  0,  0, 17
    };
  static const StringReplacement wordlist[] =
    {
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
      {"refx", "refX"},
      {(char*)0},
      {"viewbox", "viewBox"},
      {"targetx", "targetX"},
      {(char*)0},
      {"calcmode", "calcMode"},
      {"maskunits", "maskUnits"},
      {"viewtarget", "viewTarget"},
      {"tablevalues", "tableValues"},
      {"markerunits", "markerUnits"},
      {"stitchtiles", "stitchTiles"},
      {"startoffset", "startOffset"},
      {"numoctaves", "numOctaves"},
      {"requiredfeatures", "requiredFeatures"},
      {"requiredextensions", "requiredExtensions"},
      {"specularexponent", "specularExponent"},
      {"surfacescale", "surfaceScale"},
      {"specularconstant", "specularConstant"},
      {"repeatcount", "repeatCount"},
      {"clippathunits", "clipPathUnits"},
      {"filterunits", "filterUnits"},
      {"lengthadjust", "lengthAdjust"},
      {"markerwidth", "markerWidth"},
      {"maskcontentunits", "maskContentUnits"},
      {(char*)0},
      {"limitingconeangle", "limitingConeAngle"},
      {"pointsatx", "pointsAtX"},
      {"repeatdur", "repeatDur"},
      {"keytimes", "keyTimes"},
      {"keypoints", "keyPoints"},
      {"keysplines", "keySplines"},
      {"gradientunits", "gradientUnits"},
      {"textlength", "textLength"},
      {"stddeviation", "stdDeviation"},
      {"primitiveunits", "primitiveUnits"},
      {"edgemode", "edgeMode"},
      {"refy", "refY"},
      {"spreadmethod", "spreadMethod"},
      {"preserveaspectratio", "preserveAspectRatio"},
      {"targety", "targetY"},
      {"pointsatz", "pointsAtZ"},
      {"markerheight", "markerHeight"},
      {"patternunits", "patternUnits"},
      {"baseprofile", "baseProfile"},
      {"systemlanguage", "systemLanguage"},
      {"zoomandpan", "zoomAndPan"},
      {"patterncontentunits", "patternContentUnits"},
      {"glyphref", "glyphRef"},
      {"xchannelselector", "xChannelSelector"},
      {"attributetype", "attributeType"},
      {"kernelunitlength", "kernelUnitLength"},
      {"ychannelselector", "yChannelSelector"},
      {"diffuseconstant", "diffuseConstant"},
      {"pathlength", "pathLength"},
      {"kernelmatrix", "kernelMatrix"},
      {(char*)0}, {(char*)0},
      {"preservealpha", "preserveAlpha"},
      {"attributename", "attributeName"},
      {"basefrequency", "baseFrequency"},
      {(char*)0}, {(char*)0},
      {"pointsaty", "pointsAtY"},
      {"patterntransform", "patternTransform"},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {"gradienttransform", "gradientTransform"}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == lengthtable[key])
          {
            register const char *s = wordlist[key].from;

            if (s && (((unsigned char)*str ^ (unsigned char)*s) & ~32) == 0 && !gperf_case_memcmp (str, s, len))
              return &wordlist[key];
          }
    }
  return 0;
}
