#ifndef __LIBUTIL_PLATFORM_SYSCALL__
#define __LIBUTIL_PLATFORM_SYSCALL__

#include "../../common/decl.h"
#include "../nt/peb.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef libutil_ssize libutil_syscallresult;

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall0(libutil_i32 ID);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall1(libutil_i32 ID, libutil_size Arg1);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall2(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall4(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall5(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall6(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6);

#ifdef LIBUTIL_WINDOWS
LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall7(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6, libutil_size Arg7);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall8(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6, libutil_size Arg7, libutil_size Arg8);
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef libutil_syscallresult lu_syscallr;

    #define lu_syscall0 LibUtil_Syscall0
    #define lu_syscall1 LibUtil_Syscall1
    #define lu_syscall2 LibUtil_Syscall2
    #define lu_syscall3 LibUtil_Syscall3
    #define lu_syscall4 LibUtil_Syscall4
    #define lu_syscall5 LibUtil_Syscall5
    #define lu_syscall6 LibUtil_Syscall6
    #ifdef LIBUTIL_WINDOWS
        #define lu_syscall7 LibUtil_Syscall7
        #define lu_syscall8 LibUtil_Syscall8
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
