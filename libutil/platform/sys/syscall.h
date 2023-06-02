#ifndef __LIBUTIL_PLATFORM_SYSCALL__
#define __LIBUTIL_PLATFORM_SYSCALL__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall0(libutil_i32 ID);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall1(libutil_i32 ID, libutil_size Arg1);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall2(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall4(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall5(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_Syscall6(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
