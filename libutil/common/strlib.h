#ifndef __LIBUTIL_COMMON_STRLIB__
#define __LIBUTIL_COMMON_STRLIB__

#include "decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_size    LibUtil_StringLength(const char *String);

LIBUTIL_API LIBUTIL_IMPORT
libutil_size    LibUtil_StringNLength(const char *String, libutil_size MaxLength);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_StringCompare(const char *String, const char *Other);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_StringNCompare(const char *String, libutil_size StringLength, const char *Other);

LIBUTIL_API LIBUTIL_IMPORT
const char      *LibUtil_FindSubString(const char *String, const char *SubString);

LIBUTIL_API LIBUTIL_IMPORT
const char      *LibUtil_FindNSubString(const char *String, libutil_size StringLength, const char *SubString);

LIBUTIL_API LIBUTIL_IMPORT
const char      *LibUtil_FindNSubStringN(const char *String, libutil_size StringLength, const char *SubString, libutil_size SubStringLength);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_StringToNumber(libutil_i32 Base, const char *String, libutil_i32 *Output);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
