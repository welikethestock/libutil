#ifndef __LIBUTIL_CODE_STEALTH_RETURN_ADDRESS__
#define __LIBUTIL_CODE_STEALTH_RETURN_ADDRESS__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_X86 // real return address -> stack args (back to front) -> spoofed ret address [-> this ptr] -> jmp
    #define LIBUTIL_STEALTH_RETURN_LABEL(CallCount) \
        __libutil_stealth_return_label_##CallCount

    #ifdef LIBUTIL_MSVC
        #define LIBUTIL_STEALTH_PUSH_RETURN_ADDRESS(CallCount) \
            __asm { lea     eax, LIBUTIL_STEALTH_RETURN_LABEL(CallCount) } \
            __asm { push    eax }

        #define LIBUTIL_STEALTH_PUSH_ARGUMENT(Argument) \
            __asm { push    Argument }

        #define LIBUTIL_STEALTH_PUSH_ARGUMENT_EVAL(Type, Value) \
        { \
            Type __libutil_eval_V = Value; \
            __asm { push    __libutil_eval_V } \
        }

        #define LIBUTIL_STEALTH_PUSH_ARGUMENT_FLOAT(Value) \
            { \
                union \
                { \
                    float       F; \
                    libutil_i32 I; \
                } __libutil_union_V; \
                __libutil_union_V.F = Value; \
                __asm { push __libutil_union_V.I } \
            }

        #define LIBUTIL_STEALTH_PUSH_ARGUMENT_DOUBLE(Value) \
            { \
                union \
                { \
                    double      D; \
                    libutil_i64 I; \
                } __libutil_union_V; \
                __libutil_union_V.D = Value; \
                __asm { push __libutil_union_V.I } \
            }

        #define LIBUTIL_STEALTH_PUSH_SPOOFED_RETURN_ADDRESS(Address) \
            __asm { mov     eax, Address } \
            __asm { push    eax }

        #define LIBUTIL_STEALTH_PUSH_THISPTR(Thisptr) \
            __asm { mov     ecx, Thisptr }

        #define LIBUTIL_STEALTH_JUMP_TO_FUNCTION(CallCount, Address) \
            __asm { xor     eax, eax } \
            __asm { jmp     Address } \
            __asm { LIBUTIL_STEALTH_RETURN_LABEL(CallCount): }
    #endif
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
