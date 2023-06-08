#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "syscall.h"

#ifdef LIBUTIL_X86
#include "../../arch/x86/mode.h"

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall0(libutil_i32 ID)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall1(libutil_i32 ID, libutil_syscallarg Arg1)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall2(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall3(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall4(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        push    Arg4
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R9)

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall5(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        push    Arg4
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R9)

        push    Arg5

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h + 08h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall6(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        push    Arg4
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R9)

        push    Arg6
        push    Arg5

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h + 010h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall7(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        push    Arg4
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R9)

        push    Arg7
        push    Arg6
        push    Arg5

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h + 018h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall8(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7, libutil_syscallarg Arg8)
{
#ifdef LIBUTIL_MSVC
    __asm
    {
        push    ebp
        mov     ebp, esp
    }

    LIBUTIL_X86_ENTER_CS(0x33);

    __asm
    {
        and     esp, -010h

        push    Arg1
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        push    Arg2
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDX)

        push    Arg3
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R8)

        push    Arg4
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R9)

        push    Arg8
        push    Arg7
        push    Arg6
        push    Arg5

        mov     eax, ID
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX)
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10)

        sub     esp, 028h
        __asm _emit 0x0F __asm _emit 0x05 // syscall
        add     esp, 028h + 020h
    }

    LIBUTIL_X86_EXIT_CS(0x23);

    __asm
    {
        mov     edx, eax
        mov     ax, ds
        mov     ss, ax
        mov     eax, edx
    }

    __asm
    {
        mov     esp, ebp
        pop     ebp

        ret
    }
#endif
}
#endif

#endif
