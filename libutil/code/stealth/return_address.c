#include "../../common/features.h"
//TODO: maybe move away from the not so really cool defines in use rn and maybe do it similiar to how syscalls are handled?

static
void *s_SpoofedReturnAddress;

#if 0
#ifdef LIBUTIL_X86
    #ifdef LIBUTIL_MSVC
        #define PROLOGUE \
            __asm { push    ebp } \
            __asm { mov     ebp, esp }

        #define PUSH_SPOOFED_RETURN_ADDRESS \
            __asm { mov     eax, s_SpoofedReturnAddress }
            __asm { push    eax }

        #define EPILOGUE \
            __asm { mov     esp, ebp } \
            __asm { pop     ebp }
    #else
#endif

#include "return_address.h"

LIBUTIL_API
void LibUtil_Stealth_SetReturnAddress(void *ReturnAddress)
{
    s_SpoofedReturnAddress = ReturnAddress;
}

LIBUTIL_API LIBUTIL_NAKED
void *LibUtil_Stealth_Call(void)
{
    PROLOGUE;



    EPILOGUE;
}
#endif
#endif
