#ifndef __LIBUTIL_ARCH_X86_MODE__
#define __LIBUTIL_ARCH_X86_MODE__

// processor mode switching stuff

#include "../../common/decl.h"

#ifdef LIBUTIL_X86
    #define LIBUTIL_X86_RAX (0)
    #define LIBUTIL_X86_RCX (1)
    #define LIBUTIL_X86_RDX (2)
    #define LIBUTIL_X86_RBX (3)
    #define LIBUTIL_X86_RSP (4)
    #define LIBUTIL_X86_RBP (5)
    #define LIBUTIL_X86_RSI (6)
    #define LIBUTIL_X86_RDI (7)
    #define LIBUTIL_X86_R8  (8)
    #define LIBUTIL_X86_R9  (9)
    #define LIBUTIL_X86_R10 (10)
    #define LIBUTIL_X86_R11 (11)
    #define LIBUTIL_X86_R12 (12)
    #define LIBUTIL_X86_R13 (13)
    #define LIBUTIL_X86_R14 (14)
    #define LIBUTIL_X86_R15 (15)

    #ifdef LIBUTIL_MSVC
        #define LIBUTIL_X86_ENTER_CS(Segment) \
        { \
            __asm push Segment \
            __asm call $+5 \
            __asm add dword ptr [esp], 0x5 \
            __asm retf \
        }

        #define LIBUTIL_X86_EXIT_CS(Segment) \
        __asm \
        { \
            __asm call $+5 \
            __asm mov dword ptr [esp + 0x4], Segment \
            __asm add dword ptr [esp], 0xD \
            __asm retf \
        }

        #define LIBUTIL_X86_PUSHREG64(Register) __asm _emit (0x48 | (Register >> 3)) __asm _emit (0x50 | (Register & 7))
    #endif
#endif

#endif
