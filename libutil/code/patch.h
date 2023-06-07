#ifndef __LIBUTIL_CODE_PATCH__
#define __LIBUTIL_CODE_PATCH__

#include "../common/decl.h"
#include "../common/memheap.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef struct _LIBUTIL_CODE_PATCH
{
    void            *Address;
    libutil_size    Size;
    libutil_u8      *Backup;
    libutil_u8      *Patch;
} LIBUTIL_CODE_PATCH;

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool        LibUtil_Patch_Setup(LIBUTIL_CODE_PATCH *PatchInfo, void *Address, libutil_size Size, libutil_u8 *Patch);

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_CODE_PATCH  *LibUtil_Patch_Create(void *Address, libutil_size Size, libutil_u8 *Patch);

LIBUTIL_API LIBUTIL_IMPORT
void                LibUtil_Patch_Destroy(LIBUTIL_CODE_PATCH *Patch);

LIBUTIL_API LIBUTIL_IMPORT
void                LibUtil_Patch_Apply(LIBUTIL_CODE_PATCH *Patch);

LIBUTIL_API LIBUTIL_IMPORT
void                LibUtil_Patch_Revert(LIBUTIL_CODE_PATCH *Patch);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_CODE_PATCH lu_codepatch;

    #define lu_patchsetup LibUtil_Patch_Setup
    #define lu_patchcreate LibUtil_Patch_Create
    #define lu_patchapply LibUtil_Patch_Apply
    #define lu_patchrevert LibUtil_Patch_Revert
#endif

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        struct Patch : public LIBUTIL_CODE_PATCH
        {
            LIBUTIL_FORCE_INLINE
            Patch(void *Address, LibUtil::Size Size, LibUtil::U8 *Patch)
            {
                LibUtil_Patch_Setup(
                    this,
                    Address,
                    Size,
                    Patch
                );
            }

            LIBUTIL_FORCE_INLINE
            void *operator new(LibUtil::Size Size)
            {
                return LibUtil_Patch_Create(
                    NULL,
                    0,
                    NULL
                );
            }

            LIBUTIL_FORCE_INLINE
            void operator delete(void *Address)
            {
                LibUtil_Patch_Destroy((LIBUTIL_CODE_PATCH *)(Address));
            }
        };
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
