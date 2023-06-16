#ifndef __LIBUTIL_CODE_HOOK_VFT__
#define __LIBUTIL_CODE_HOOK_VFT__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef struct _LIBUTIL_VFTHOOK
{
    void            *Instance;
    void            **OriginalVFT;
    void            **ModifiedVFT;
    libutil_size    VFTLength;
    libutil_bool    HasRTTI;
} LIBUTIL_VFTHOOK;

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool        LibUtil_VFTHook_Setup(LIBUTIL_VFTHOOK *Hook, void *Instance, libutil_size VFTLength);

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_VFTHOOK     *LibUtil_VFTHook_Create(void *Instance, libutil_size VFTLength);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_VFTHOOK     lu_vfthook;

    #define lu_vfthook_setup    LibUtil_VFTHook_Setup
    #define lu_vfthook_create   LibUtil_VFTHook_Create
#endif

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        struct VFTHook;
    }

    struct LibUtil::VFTHook : public LIBUTIL_VFTHOOK
    {

    };
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
