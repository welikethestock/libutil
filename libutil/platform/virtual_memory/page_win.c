#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "page.h"
#include "../sys/syscall.h"
#include "../../common/mathbits.h"

#define LIBUTIL_PAGE_ALIGN 0x1000

#define MEM_COMMIT  0x1000
#define MEM_RESERVE 0x2000

LIBUTIL_API
libutil_bool LibUtil_Page_Allocate(void **BaseAddress, libutil_size Size, libutil_u32 Protection, libutil_u32 Flags)
{
    /*return LibUtil_Syscall6(

    )*/
}

LIBUTIL_API
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    /*return LibUtil_Syscall6(
        0,
        LibUtil_AlignDown((libutil_size)(Address), 0x1000),
        LibUtil_AlignDown((libutil_size)(Address), 0x1000),
        Protection,
        OldProtection
    );*/


}

#endif
