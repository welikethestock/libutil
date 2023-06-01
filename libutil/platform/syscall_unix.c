#ifdef __linux__
#include "syscall.h"

LIBUTIL_API
libutil_i32 LibUtil_Syscall3(libutil_i32 ID, libutil_size Arg1, libutil_size Arg2, libutil_size Arg3)
{
#if defined(__x86_64__) || defined(_M_X64)
    __asm("and rsp, -010");

    register libutil_i32 rax __asm("rax") = ID;
    __asm __volatile__(
        "syscall"
        : "=r" (rax)
        : "D" (Arg1), "S" (Arg2), "d" (Arg3)
        : "rcx", "r11", "memory"
    );

    return rax;
#endif
}
#endif
