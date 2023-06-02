#ifdef __linux__
#include "syscall.h"

LIBUTIL_API
libutil_i32 LibUtil_Syscall0(libutil_i32 ID)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_i32 rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        :
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall1(libutil_i32 ID, libutil_size Arg1)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi)
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall2(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_size  rsi __asm("rsi") = Arg2;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi), "r" (rsi)
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_size  rsi __asm("rsi") = Arg2;
    register volatile libutil_size  rdx __asm("rdx") = Arg3;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi), "r" (rsi), "r" (rdx)
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall4(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_size  rsi __asm("rsi") = Arg2;
    register volatile libutil_size  rdx __asm("rdx") = Arg3;
    register volatile libutil_size  rcx __asm("rcx") = Arg4;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi), "r" (rsi), "r" (rdx), "r" (rcx)
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall5(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_size  rsi __asm("rsi") = Arg2;
    register volatile libutil_size  rdx __asm("rdx") = Arg3;
    register volatile libutil_size  rcx __asm("rcx") = Arg4;
    register volatile libutil_size  r8  __asm("r8")  = Arg5;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi), "r" (rsi), "r" (rdx), "r" (rcx), "r" (r8)
        : "r11", "memory"
    );

    return rax;
#endif
}

LIBUTIL_API
libutil_i32 LibUtil_Syscall6(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3, libutil_size Arg4, libutil_size Arg5, libutil_size Arg6)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm __volatile__("and rsp, -010");

    register volatile libutil_size  rdi __asm("rdi") = Arg1;
    register volatile libutil_size  rsi __asm("rsi") = Arg2;
    register volatile libutil_size  rdx __asm("rdx") = Arg3;
    register volatile libutil_size  rcx __asm("rcx") = Arg4;
    register volatile libutil_size  r8  __asm("r8")  = Arg5;
    register volatile libutil_size  r9  __asm("r9")  = Arg6;
    register volatile libutil_i32   rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "r" (rdi), "r" (rsi), "r" (rdx), "r" (rcx), "r" (r8), "r" (r9)
        : "r11", "memory"
    );

    return rax;
#endif
}
#endif
