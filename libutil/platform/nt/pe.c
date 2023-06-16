#include "pe.h"

LIBUTIL_API
libutil_bool LibUtil_Nt_IsValidImage(void *Image, libutil_bool Is64Bit)
{
    LIBUTIL_NT_DOS_HEADER *DOSHeader = (LIBUTIL_NT_DOS_HEADER *)(Image);
    if(DOSHeader->e_magic != LIBUTIL_NT_DOS_HEADER_MAGIC)
    {
        return FALSE;
    }

    LIBUTIL_NT_IMAGE_NT_HEADERS32 *NTHeaders = (LIBUTIL_NT_IMAGE_NT_HEADERS32 *)(LIBUTIL_NT_RVA_TO_ABS32(DOSHeader, DOSHeader->e_lfanew));
    if(NTHeaders->Signature != LIBUTIL_NT_NT_HEADERS_SIGNATURE)
    {
        return FALSE;
    }

    if(NTHeaders->OptionalHeader.Magic != ((Is64Bit) ? LIBUTIL_NT_IMAGE_FILE_MAGIC64 : LIBUTIL_NT_IMAGE_FILE_MAGIC32))
    {
        return FALSE;
    }

    return TRUE;
}
