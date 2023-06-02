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
void                LibUtil_Patch_Apply(LIBUTIL_CODE_PATCH *Patch);

LIBUTIL_API LIBUTIL_IMPORT
void                LibUtil_Patch_Revert(LIBUTIL_CODE_PATCH *Patch);

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
        };
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
