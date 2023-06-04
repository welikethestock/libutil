#include "string.h"
#include "../common/strlib.h"
#include "../common/memheap.h"
#include "../common/memlib.h"

LIBUTIL_API
LIBUTIL_STRING *LibUtil_String_Create()
{
    LIBUTIL_STRING *String = (LIBUTIL_STRING *)(LibUtil_Heap_Allocate(sizeof(LIBUTIL_STRING)));
    if(String != NULL)
    {
        String->Type = LIBUTIL_STRING_UNINITIALIZED;
    }

    return String;
}

LIBUTIL_API
void LibUtil_String_Destroy(LIBUTIL_STRING *String)
{
    LibUtil_String_DestroyData(String);
    LibUtil_Heap_Free(String);
}

LIBUTIL_API
void LibUtil_String_DestroyData(LIBUTIL_STRING *String)
{
    if(String->Type == LIBUTIL_STRING_VECTOR_NARROWSTRING || String->Type == LIBUTIL_STRING_VECTOR_WIDESTRING)
    {
        LibUtil_Vector_DestroyData(&String->Vector);
    }
}

LIBUTIL_API
LIBUTIL_STRING *LibUtil_String_CreateConstNarrow(const char *String)
{
    return LibUtil_String_CreateConstNarrowN(String, LibUtil_StringLength(String));
}

LIBUTIL_API
LIBUTIL_STRING *LibUtil_String_CreateConstNarrowN(const char *String, libutil_size Length)
{
    LIBUTIL_STRING *StringData = LibUtil_String_Create();
    if(StringData == NULL)
    {
        return NULL;
    }

    StringData->Type                = LIBUTIL_STRING_CONST_NARROWSTRING;
    StringData->Const.Length        = Length;
    StringData->Const.NarrowString  = String;

    return StringData;
}

LIBUTIL_API
libutil_bool LibUtil_String_ConvertConstToVector(LIBUTIL_STRING *String)
{
    if(String->Type == LIBUTIL_STRING_VECTOR_NARROWSTRING || String->Type == LIBUTIL_STRING_VECTOR_WIDESTRING)
    {
        return TRUE;
    }

    libutil_size    CharacterWidth  = (String->Type == LIBUTIL_STRING_CONST_NARROWSTRING) ? sizeof(char) : sizeof(libutil_wchar);
    libutil_size    Length          = String->Const.Length;
    const void      *Data           = String->Const.Data;

    LibUtil_Vector_Setup(
        &String->Vector,
        CharacterWidth
    );

    if(!LibUtil_Vector_Reserve(
        &String->Vector,
        Length + 1
    ))
    {
        return FALSE;
    }

    LibUtil_Memcpy(
        &((char *)(String->Vector.Data))[0],
        Data,
        (Length) * CharacterWidth
    );

    String->Type = (CharacterWidth == sizeof(char)) ? LIBUTIL_STRING_VECTOR_NARROWSTRING : LIBUTIL_STRING_VECTOR_WIDESTRING;
    String->Vector.Count = Length;

    return TRUE;
}

LIBUTIL_API
libutil_bool LibUtil_String_AppendNarrow(LIBUTIL_STRING *String, const char *ToAppend)
{
    return LibUtil_String_AppendNarrowN(String, ToAppend, LibUtil_StringLength(ToAppend));
}

LIBUTIL_API
libutil_bool LibUtil_String_AppendNarrowN(LIBUTIL_STRING *String, const char *ToAppend, libutil_size Length)
{
    if(String->Type != LIBUTIL_STRING_UNINITIALIZED)
    {
        if(!LibUtil_String_ConvertConstToVector(String))
        {
            return FALSE;
        }
    }
    else
    {
        LibUtil_Vector_Setup(
            &String->Vector,
            sizeof(char)
        );

        String->Type = LIBUTIL_STRING_VECTOR_NARROWSTRING;
    }

    if(!LibUtil_Vector_Reserve(
        &String->Vector,
        String->Vector.Count + Length + 1
    ))
    {
        return FALSE;
    }

    LibUtil_Memcpy(
        &((char *)(String->Vector.Data))[(String->Vector.Count > 0) ? String->Vector.Count : 0],
        ToAppend,
        Length + 1
    );

    String->Vector.Count += Length;

     return TRUE;
}
