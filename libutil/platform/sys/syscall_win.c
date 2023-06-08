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

#endif

#endif
