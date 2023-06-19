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
libutil_size LibUtil_WStringLength(const libutil_wchar *String)
{
    return LibUtil_WStringNLength(String, (libutil_size)(-1));
}

LIBUTIL_API
libutil_size LibUtil_WStringNLength(const libutil_wchar *String, libutil_size MaxLength)
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

#include <stdarg.h>

LIBUTIL_API
libutil_size LibUtil_StringFormat(char *Buffer, const char *Format, ...)
{
    va_list List;
    va_start(List, Format);
    libutil_size Length = LibUtil_VStringFormat(Buffer, Format, List);
    va_end(List);

    return Length;
}

LIBUTIL_API
libutil_size LibUtil_VStringFormat(char *Buffer, const char *Format, va_list List)
{
    return LibUtil_VNStringFormat(Buffer, -1, Format, List);
}

typedef enum _LIBUTIL_STRING_FORMAT_FLAGS
{
    LIBUTIL_STRING_FORMAT_UPPERCASE = 0x1,
    LIBUTIL_STRING_FORMAT_PAD_ZERO  = 0x2
} LIBUTIL_STRING_FORMAT_FLAGS;


LIBUTIL_API
libutil_size LibUtil_VNStringFormat(char *Buffer, libutil_size BufferSize, const char *Format, va_list List)
{
    libutil_size Length = 0;

    while(*Format && BufferSize > 1)
    {
        if(*Format != '%')
        {
            if(Buffer != NULL)
            {
                *Buffer = *Format;
            }

            --BufferSize;
            ++Length;
            ++Format;
            ++Buffer;

            continue;
        }

        ++Format;

        libutil_u32 Flags = 0;
        switch(*Format)
        {
            case '%':
            {
                if(Buffer != NULL)
                {
                    *Buffer = '%';
                }

                --BufferSize;
                ++Length;
                ++Format;
                ++Buffer;

                break;
            }

            case 'd':
            case 'i':
            case 'u':
            case 'x':
            case 'X':
            case 'z':
            case 'p':
            {
                libutil_i32 Base = 10;
                if(*Format == 'x' || *Format == 'X' || *Format == 'p')
                {
                    Base = 16;
                }

                if(*Format == 'X' || *Format == 'p')
                {
                    Flags |= LIBUTIL_STRING_FORMAT_UPPERCASE;
                }

                if(*Format == 'p')
                {
                    Flags |= LIBUTIL_STRING_FORMAT_PAD_ZERO;
                }

                ++Format;

                break;
            }

            case 'f':
            {
                ++Format;

                break;
            }

            case 's':
            {
                const char *String = va_arg(List, const char *);
                if(String == NULL)
                {
                    String = "(nil)";
                }

                libutil_size StringLength = LibUtil_StringLength(String);
                for(libutil_size StrIndex = 0; StrIndex < StringLength; ++StrIndex)
                {
                    if(!(BufferSize > 1))
                    {
                        break;
                    }

                    if(Buffer != NULL)
                    {
                        *Buffer = *String;
                    }

                    ++Buffer;
                    ++String;

                    --BufferSize;
                    ++Length;
                }

                ++Format;

                break;
            }

            case 'S':
            {
                const libutil_wchar *String = va_arg(List, const libutil_wchar *);
                if(String == NULL)
                {
                    String = L"(nil)";
                }

                libutil_size StringLength = LibUtil_WStringLength(String);
                for(libutil_size StrIndex = 0; StrIndex < StringLength; ++StrIndex)
                {
                    if(!(BufferSize > 1))
                    {
                        break;
                    }

                    if(Buffer != NULL)
                    {
                        *Buffer = (char)(*String);
                    }

                    ++Buffer;
                    ++String;

                    --BufferSize;
                    ++Length;
                }


                ++Format;

                break;
            }

            default:
            {
                ++Format;

                break;
            }
        }
    }

    *Buffer = '\0';

    return Length;
}
