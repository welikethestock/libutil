#include "vft.h"
#include "../../platform/virtual_memory/page.h"
#include "../../common/memheap.h"
#include "../../common/memlib.h"

LIBUTIL_API
libutil_bool LibUtil_VFTHook_Setup(LIBUTIL_VFTHOOK *Hook, void *Instance, libutil_size VFTLength)
{
    void **VFT = *(void ***)(Instance);
    if(VFTLength == NULL)
    {
        for(; LibUtil_Page_IsExecutable((libutil_syscallarg)(VFT[VFTLength])); ++VFTLength);
    }

    Hook->ModifiedVFT = (void **)(LibUtil_Heap_Allocate(sizeof(void *) * VFTLength));
    if(Hook->ModifiedVFT == NULL)
    {
        return FALSE;
    }

    Hook->Instance      = Instance;
    Hook->OriginalVFT   = VFT;
    Hook->VFTLength     = VFTLength;
    Hook->HasRTTI       = FALSE;
    if(Hook->ModifiedVFT == NULL)
    {
        return FALSE;
    }

    LibUtil_Memcpy(Hook->ModifiedVFT, Hook->OriginalVFT, sizeof(void *) * Hook->VFTLength);

    return TRUE;
}

LIBUTIL_API
LIBUTIL_VFTHOOK *LibUtil_VFTHook_Create(void* Instance, libutil_size VFTLength)
{
    LIBUTIL_VFTHOOK *VFTHook = (LIBUTIL_VFTHOOK *)(LibUtil_Heap_Allocate(sizeof(LIBUTIL_VFTHOOK)));
    if(VFTHook == NULL)
    {
        return NULL;
    }

    if(Instance != NULL)
    {
        if(!LibUtil_VFTHook_Setup(VFTHook, Instance, VFTLength))
        {
            LibUtil_Heap_Free(VFTHook);

            return NULL;
        }
    }
    else
    {
        VFTHook->Instance = NULL;
        VFTHook->OriginalVFT = VFTHook ->ModifiedVFT = NULL;
        VFTHook->VFTLength = NULL;
        VFTHook->HasRTTI = FALSE;
    }

    return VFTHook;
}
