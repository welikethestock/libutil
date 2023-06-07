#include "patch.h"
#include "../common/memheap.h"
#include "../common/memlib.h"
#include "../platform/virtual_memory/page.h"

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Patch_Setup(LIBUTIL_CODE_PATCH *PatchInfo, void *Address, libutil_size Size, libutil_u8 *Patch)
{
    PatchInfo->Address  = Address;
    PatchInfo->Size     = Size;

    if((PatchInfo->Backup = (libutil_u8 *)(LibUtil_Heap_Allocate(Size))) == NULL)
    {
        PatchInfo->Address = NULL;

        return FALSE;
    }

    if((PatchInfo->Patch = (libutil_u8 *)(LibUtil_Heap_Allocate(Size))) == NULL)
    {
        PatchInfo->Address = NULL;
        LibUtil_Heap_Free(PatchInfo->Backup);

        return FALSE;
    }

    LibUtil_Memcpy(PatchInfo->Patch, Patch, Size);
    LibUtil_Memcpy(PatchInfo->Backup, Address, Size);

    return TRUE;
}

LIBUTIL_API
LIBUTIL_CODE_PATCH *LibUtil_Patch_Create(void *Address, libutil_size Size, libutil_u8 *Patch)
{
    LIBUTIL_CODE_PATCH *PatchInfo = (LIBUTIL_CODE_PATCH *)(LibUtil_Heap_Allocate(sizeof(LIBUTIL_CODE_PATCH)));
    if(PatchInfo == NULL)
    {
        return NULL;
    }

    if(Address != NULL)
    {
        if(!LibUtil_Patch_Setup(PatchInfo, Address, Size, Patch))
        {
            LibUtil_Heap_Free(PatchInfo);

            return NULL;
        }
    }

    return PatchInfo;
}

LIBUTIL_API
void LibUtil_Patch_Destroy(LIBUTIL_CODE_PATCH *Patch)
{
    if(Patch->Backup != NULL)
    {
        LibUtil_Heap_Free(Patch->Backup);
    }

    if(Patch->Patch != NULL)
    {
        LibUtil_Heap_Free(Patch->Patch);
    }

    LibUtil_Heap_Free(Patch);
}

LIBUTIL_API
void LibUtil_Patch_Apply(LIBUTIL_CODE_PATCH *Patch)
{
    libutil_u32 OldProtection = LIBUTIL_PAGE_RX; // assume page was RX on linux
    LibUtil_Page_Protect(Patch->Address, Patch->Size, LIBUTIL_PAGE_RWX, &OldProtection);
    LibUtil_Memcpy(Patch->Address, Patch->Patch, Patch->Size);
    LibUtil_Page_Protect(Patch->Address, Patch->Size, OldProtection, &OldProtection);
}

LIBUTIL_API
void LibUtil_Patch_Revert(LIBUTIL_CODE_PATCH *Patch)
{
    libutil_u32 OldProtection = LIBUTIL_PAGE_RX; // assume page was RX on linux
    LibUtil_Page_Protect(Patch->Address, Patch->Size, LIBUTIL_PAGE_RWX, &OldProtection);
    LibUtil_Memcpy(Patch->Address, Patch->Backup, Patch->Size);
    LibUtil_Page_Protect(Patch->Address, Patch->Size, OldProtection, &OldProtection);
}
