#include "strlib.h"
#include "memlib.h"

LIBUTIL_API
libutil_size LibUtil_StringLength(const char *String)
{
    return LibUtil_StringNLength(String, (libutil_size)(-1));
}

LIBUTIL_API
libutil_size LibUtil_StringNLength(const char *String, libutil_size MaxLength)
{
    libutil_size Length = 0;
    for(; *String != '\0' && MaxLength > 0; ++String, ++Length, --MaxLength) {}

    return Length;
}

LIBUTIL_API
libutil_bool LibUtil_StringCompare(const char *String, const char *Other)
{
    return LibUtil_StringNCompare(String, LibUtil_StringLength(String), Other);
}

LIBUTIL_API
libutil_bool LibUtil_StringNCompare(const char *String, libutil_size StringLength, const char *Other)
{
    return (LibUtil_Memcmp(String, Other, StringLength) == 0);
}

LIBUTIL_API
const char *LibUtil_FindSubString(const char *String, const char *SubString)
{
    return LibUtil_FindNSubStringN(String, LibUtil_StringLength(String), SubString, LibUtil_StringLength(SubString));
}

LIBUTIL_API
const char *LibUtil_FindNSubString(const char *String, libutil_size StringLength, const char *SubString)
{
    return LibUtil_FindNSubStringN(String, StringLength, SubString, LibUtil_StringLength(SubString));
}

LIBUTIL_API
const char *LibUtil_FindNSubStringN(const char *String, libutil_size StringLength, const char *SubString, libutil_size SubStringLength)
{
    for(; *String != '\0' && StringLength > 0; ++String, --StringLength)
    {
        for(libutil_size Index = 0; Index < SubStringLength; ++Index)
        {
            if((StringLength - Index) == 0 || String[Index] != SubString[Index] || String[Index] == '\0')
            {
                break;
            }

            if(Index == (SubStringLength - 1))
            {
                return String;
            }
        }
    }

    return NULL;
}

LIBUTIL_API
libutil_bool LibUtil_StringToNumber(libutil_i32 Base, const char *String, libutil_i32 *Output)
{
    *Output = 0;
    for(; *String != '\0'; ++String)
    {
        *Output *= Base;
        if(*String >= '0' && *String <= '9')
        {
            *Output += (*String - '0');
        }
        else if(Base > 10 && ((*String >= 'a' && *String <= 'z') || (*String >= 'A' && *String <= 'Z')))
        {
            *Output += (*String - ((*String >= 'a') ? 'a' : 'A')) + 10;
        }
        else
        {
            return FALSE;
        }
    }

    return TRUE;
}
