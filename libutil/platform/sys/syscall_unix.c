#include "../../common/features.h"

#ifdef LIBUTIL_LINUX
#include "syscall.h"

#if defined(LIBUTIL_X86_64)
LIBUTIL_API
libutil_syscallresult LibUtil_Syscall0(libutil_i32 ID)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall1(libutil_i32 ID, libutil_size Arg1)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall2(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1), "S" (Arg2)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1), "S" (Arg2), "d" (Arg3)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall4(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    register libutil_size r10 __asm("r10") = Arg4;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1), "S" (Arg2), "d" (Arg3), "r" (r10)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall5(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    register libutil_size r10 __asm("r10") = Arg4;
    register libutil_size r8 __asm("r8") = Arg5;

    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1), "S" (Arg2), "d" (Arg3), "r" (r10), "r" (r8)
        : "rcx", "r11", "memory"
    );

    return rax;
}

LIBUTIL_API
libutil_syscallresult LibUtil_Syscall6(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6)
{
    __asm __volatile__("and rsp, -010");

    register libutil_size rax __asm("rax") = ID;
    register libutil_size r10 __asm("r10") = Arg4;
    register libutil_size r8 __asm("r8") = Arg5;
    register libutil_size r9 __asm("r9") = Arg6;
    __asm __volatile__(
        "syscall"
        : "=a" (rax)
        : "a" (ID), "D" (Arg1), "S" (Arg2), "d" (Arg3), "r" (r10), "r" (r8), "r" (r9)
        : "rcx", "r11", "memory"
    );

    return rax;
}
#endif

#endif
