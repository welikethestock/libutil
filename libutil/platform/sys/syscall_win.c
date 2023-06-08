#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "syscall.h"

#ifdef LIBUTIL_X86
#include "../../arch/x86/mode.h"

#ifdef LIBUTIL_MSVC
    #define PROLOGUE \
        __asm { push    ebp } \
        __asm { mov     ebp, esp} \
        { LIBUTIL_X86_ENTER_CS(0x33) } \
        __asm { and     esp, -010h }

    #define PUSH_ARG_REG(Register, Argument) \
        __asm { push    Argument } \
        LIBUTIL_X86_POPREG64(Register)

    #define PUSH_ARG_STACK(Argument) \
        __asm { push Argument }

    #define SET_SYSCALL_ID(ID) \
        LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_RCX) \
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_R10) \
        __asm { mov eax, ID }

    #define SYSCALL(ID, PopAmount) \
        SET_SYSCALL_ID(ID) \
        __asm sub esp, 028h \
        __asm _emit 0x0F __asm _emit 0x05 \
        __asm add esp, 028h + PopAmount

    #define EPILOGUE \
        { LIBUTIL_X86_EXIT_CS(0x23) } \
        __asm { mov     edx, eax } \
        __asm { mov     ax, ds } \
        __asm { mov     ss, ax} \
        __asm { mov     eax, edx } \
        __asm { mov     esp, ebp } \
        __asm { pop     ebp }

    #define RETURN \
        __asm { ret }

#endif

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall0(libutil_i32 ID)
{
    PROLOGUE;

    SYSCALL(ID, 0x0);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall1(libutil_i32 ID, libutil_syscallarg Arg1)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);

    SYSCALL(ID, 0x0);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall2(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);

    SYSCALL(ID, 0x0);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall3(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);

    SYSCALL(ID, 0x0);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall4(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);
    PUSH_ARG_REG(LIBUTIL_X86_R9, Arg4);

    SYSCALL(ID, 0x0);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall5(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);
    PUSH_ARG_REG(LIBUTIL_X86_R9, Arg4);

    PUSH_ARG_STACK(Arg5)

    SYSCALL(ID, 0x8);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall6(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);
    PUSH_ARG_REG(LIBUTIL_X86_R9, Arg4);

    PUSH_ARG_STACK(Arg6);
    PUSH_ARG_STACK(Arg5);

    SYSCALL(ID, 0x10);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall7(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);
    PUSH_ARG_REG(LIBUTIL_X86_R9, Arg4);

    PUSH_ARG_STACK(Arg7);
    PUSH_ARG_STACK(Arg6);
    PUSH_ARG_STACK(Arg5);

    SYSCALL(ID, 0x18);

    EPILOGUE;

    RETURN;
}

LIBUTIL_API LIBUTIL_NAKED
libutil_syscallresult LibUtil_Syscall8(libutil_i32 ID, libutil_syscallarg Arg1, libutil_syscallarg Arg2, libutil_syscallarg Arg3, libutil_syscallarg Arg4, libutil_syscallarg Arg5, libutil_syscallarg Arg6, libutil_syscallarg Arg7, libutil_syscallarg Arg8)
{
    PROLOGUE;

    PUSH_ARG_REG(LIBUTIL_X86_RCX, Arg1);
    PUSH_ARG_REG(LIBUTIL_X86_RDX, Arg2);
    PUSH_ARG_REG(LIBUTIL_X86_R8, Arg3);
    PUSH_ARG_REG(LIBUTIL_X86_R9, Arg4);

    PUSH_ARG_STACK(Arg8);
    PUSH_ARG_STACK(Arg7);
    PUSH_ARG_STACK(Arg6);
    PUSH_ARG_STACK(Arg5);

    SYSCALL(ID, 0x20);

    EPILOGUE;

    RETURN;
}
#endif

#endif

/*
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
*/
