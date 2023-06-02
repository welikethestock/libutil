#ifndef __LIBUTIL_PLATFORM_SYSCALL__
#define __LIBUTIL_PLATFORM_SYSCALL__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
