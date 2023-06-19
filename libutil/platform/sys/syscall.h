#ifndef __LIBUTIL_PLATFORM_SYSCALL__
#define __LIBUTIL_PLATFORM_SYSCALL__

#include "../../common/decl.h"
#include "../nt/peb.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef _WIN32
    typedef libutil_i32     libutil_syscallresult;

    #if defined(LIBUTIL_WINE) && defined(LIBUTIL_X86)
        typedef libutil_size    libutil_syscallarg;
    #elif defined(LIBUTIL_X86_PURE32)
        typedef libutil_u32     libutil_syscallarg;
    #else
        typedef libutil_u64     libutil_syscallarg;
    #endif
#else
    #ifdef LIBUTIL_X86_PURE32
        typedef libutil_u32     libutil_syscallresult;
        typedef libutil_u32     libutil_syscallarg;
    #else
        typedef libutil_u64     libutil_syscallresult;
        typedef libutil_u64     libutil_syscallarg;
    #endif
#endif

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall0(libutil_i32 ID);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall1(libutil_i32 ID, libutil_syscallarg Arg1);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall2(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall3(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall4(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall5(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall6(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6);

#ifdef LIBUTIL_WINDOWS
LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall7(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7);

LIBUTIL_API LIBUTIL_IMPORT
libutil_syscallresult LibUtil_Syscall8(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7, libutil_syscallarg Arg8);
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef libutil_syscallresult   lu_syscallr;
    typedef libutil_syscallarg      lu_syscallarg;

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

#ifndef LIBUTIL_WINE
#define LIBUTIL_INVALID_SYSCALL         (-1)
#define LIBUTIL_SYSCALLID(Name)         g_LibUtil_##Name##_SyscallID
#define LIBUTIL_DECLARE_SYSCALL(Name)   extern "C" libutil_i32 LIBUTIL_SYSCALLID(Name)
#define LIBUTIL_DEFINE_SYSCALL(Name)    libutil_i32 LIBUTIL_SYSCALLID(Name) = LIBUTIL_INVALID_SYSCALL
#define LIBUTIL_CHECK_SYSCALLID(Name)   ((LIBUTIL_SYSCALLID(Name)) >= 0)
#else
#define LIBUTIL_INVALID_SYSCALL         (NULL)
#define LIBUTIL_SYSCALLID(Name)         g_LibUtil_##Name##_SyscallPtr
#define LIBUTIL_DECLARE_SYSCALL(Name)   LIBUTIL_EXTERN_C_BLOCK_START extern void * LIBUTIL_SYSCALLID(Name) LIBUTIL_EXTERN_C_BLOCK_END
#define LIBUTIL_DEFINE_SYSCALL(Name)    void *LIBUTIL_SYSCALLID(Name) = LIBUTIL_INVALID_SYSCALL
#define LIBUTIL_CHECK_SYSCALLID(Name)   ((LIBUTIL_SYSCALLID(Name)) != LIBUTIL_INVALID_SYSCALL)
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
