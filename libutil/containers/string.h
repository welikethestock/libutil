#ifndef __LIBUTIL_CONTAINERS_STRING__
#define __LIBUTIL_CONTAINERS_STRING__

#include "../common/decl.h"
#include "vector.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef enum _LIBUTIL_STRING_TYPE
{
    LIBUTIL_STRING_UNINITIALIZED = 0,

    LIBUTIL_STRING_CONST_NARROWSTRING,
    LIBUTIL_STRING_VECTOR_NARROWSTRING,

    LIBUTIL_STRING_CONST_WIDESTRING,
    LIBUTIL_STRING_VECTOR_WIDESTRING,

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    LU_STRING_UNINITIALIZED = LIBUTIL_STRING_UNINITIALIZED,

    LU_STRING_CONST_NARROWSTRING = LIBUTIL_STRING_CONST_NARROWSTRING,
    LU_STRING_VECTOR_NARROWSTRING = LIBUTIL_STRING_VECTOR_NARROWSTRING,

    LU_STRING_CONST_WIDESTRING = LIBUTIL_STRING_CONST_WIDESTRING,
    LU_STRING_VECTOR_WIDESTRING = LIBUTIL_STRING_VECTOR_WIDESTRING
#endif
} LIBUTIL_STRING_TYPE;

typedef struct _LIBUTIL_STRING
{
    LIBUTIL_STRING_TYPE             Type;
    union
    {
        LIBUTIL_VECTOR  Vector;
        struct
        {
            libutil_size                Length;
            union
            {
                const void                  *Data;
                const char                  *NarrowString;
                const libutil_wchar         *WideString;
            };
        } Const;
    };
} LIBUTIL_STRING;

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_STRING  *LibUtil_String_Create();

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_String_Destroy(LIBUTIL_STRING *String);

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_String_DestroyData(LIBUTIL_STRING *String);

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_STRING  *LibUtil_String_CreateConstNarrow(const char *String);

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_STRING  *LibUtil_String_CreateConstNarrowN(const char *String, libutil_size Length);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_String_ConvertConstToVector(LIBUTIL_STRING *String);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_String_AppendNarrow(LIBUTIL_STRING *String, const char *ToAppend);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool    LibUtil_String_AppendNarrowN(LIBUTIL_STRING *String, const char *ToAppend, libutil_size Length);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_STRING_TYPE         lu_stringtype;
    typedef LIBUTIL_STRING              lu_string;

    #define lu_stringcreate             LibUtil_String_Create
    #define lu_stringdestroy            LibUtil_String_Destroy
    #define lu_stringdestroydata        LibUtil_String_DestroyData

    #define lu_stringcreatenarrowconst  LibUtil_String_CreateConstNarrow
    #define lu_stringcreatenarrowconstn LibUtil_String_CreateConstNarrowN

    #define lu_stringconst2vector       LibUtil_String_ConvertConstToVector

    #define lu_stringappendnarrow       LibUtil_String_AppendNarrow
    #define lu_stringappendnarrown      LibUtil_String_AppendNarrowN
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
