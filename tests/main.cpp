#include "libutil/common/memheap.h"
#include "libutil/containers/doubly_linked_list.h"
#include "libutil/containers/vector.h"
#include "libutil/code/patch.h"
#include "libutil/platform/virtual_memory/page.h"
#include "libutil/platform/sys/syscall.h"
#include "libutil/common/memlib.h"
#include "libutil/common/random.h"
#include "libutil/common/strlib.h"
#include "libutil/containers/string.h"
#include "libutil/platform/nt/teb.h"
#include "libutil/platform/nt/peb.h"
#include "libutil/platform/nt/ldr.h"
#include "libutil/platform/nt/pe.h"
#include "libutil/code/signature/find.h"
#include "libutil/code/stealth/return_address.h"
#include "libutil/math/vector.h"
#include "libutil/math/float.h"
#include "libutil/crypto/luhash.h"

#include <stdio.h>
#include <stddef.h>

#include <windows.h>

void CallProxy();
void __fastcall Stuff(void *, void *, float);

int main(int argc, const char **argv)
{
    LibUtil::Heap::SetMalloc((LIBUTIL_HEAP_MALLOC)(malloc));
    LibUtil::Heap::SetRealloc((LIBUTIL_HEAP_REALLOC)(realloc));
    LibUtil::Heap::SetFree((LIBUTIL_HEAP_FREE)(free));

    // memcpy
    char MemcpyTestBuffer[512] = { 0 };
    static const char MemcpyTestString[] = "123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)asfasf";
    volatile const char *MemcpyTestPtr = MemcpyTestString;
    LibUtil::Memcpy(&MemcpyTestBuffer, ((const char *)(MemcpyTestPtr)) + 1, sizeof(MemcpyTestString) - 5);

    printf("memcpy> %s %p %p\n", MemcpyTestBuffer, MemcpyTestBuffer, MemcpyTestString + 3);

    //syscall
    //lu_syscall3(1, 1, (libutil_size)("syscall>\n"), sizeof("syscall>\n"));

    // vector
    LibUtil::Containers::Vector<int> *Vector = new LibUtil::Containers::Vector<int>();
    int VectorTestInts[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(libutil_size Index = 0; Index < (sizeof(VectorTestInts) / sizeof(VectorTestInts[0])); ++Index)
    {
        Vector->PushBack(VectorTestInts[Index]);
    }

    (*Vector)[2] = -1;

    printf("vector> ");
    for(libutil_size Index = 0; Index < Vector->Count; ++Index)
    {
        printf("%d ", Vector->Get(Index));
    }
    printf("(%zu %zu)\n", Vector->Count, Vector->Reserved);

    delete Vector;

    // random
    printf("crnghw> %d %llu %d %f %f\n",
        LibUtil::Random::Generate(NULL, LIBUTIL_RANDOM_GENERATOR_CHIP),
        LibUtil::Random::Generate<libutil_u64>(NULL, LIBUTIL_RANDOM_GENERATOR_CHIP),
        LibUtil::Random::Generate<libutil_i16>(NULL, LIBUTIL_RANDOM_GENERATOR_CHIP),
        LibUtil::Random::Generate<float>(NULL, LIBUTIL_RANDOM_GENERATOR_CHIP),
        LibUtil::Random::Generate<double>(NULL, LIBUTIL_RANDOM_GENERATOR_CHIP)
    );

    // string to number
    libutil_i32 Number;
    LibUtil_StringToNumber(16, "Ff", &Number);
    printf("str2num> %d\n", Number);

    // strstr
    const char *Found = lu_strstr("test string", "st");
    printf("substr> %s %s\n", Found, lu_strstr(Found + 1, "st"));

    //memcmp
    static const char MemcmpTest1[] = "123456789abdefghijklmnopqrstuvwxyz";
    static const char MemcmpTest2[] = "123456789abdefghijklmnopqrstuvwxyz";
    printf("memcmp> %d\n", lu_memcmp(MemcmpTest1, MemcmpTest2, sizeof(MemcmpTest1)));

    //memset
    static char MemsetTest[64 + 16 + 8 + 7] = { 0 };
    lu_memset(MemsetTest, 0xAF, sizeof(MemsetTest));
    {
        libutil_bool Success = TRUE;
        for(libutil_size Index = 0; Index < sizeof(MemsetTest); ++Index)
        {
            if(MemsetTest[Index] != '\xAF')
            {
                printf("memset> %zu %zu %d %d\n", Index, sizeof(MemsetTest) - Index, MemsetTest[Index], 0xAF);

                Success = FALSE;

                break;
            }
        }

        printf("memset> %s\n", (Success) ? "success" : "fail");
    }

    //printf("-> %d\n", lu_syscall0(0x123)); //win10 32
    printf("-> %d\n", lu_syscall0(0xF8)); //win11
    printf("%d\n", LibUtil_Page_IsExecutable((libutil_syscallarg)(&main)));

#ifdef LIBUTIL_X86
    LIBUTIL_STEALTH_PUSH_RETURN_ADDRESS(1);
    LIBUTIL_STEALTH_PUSH_ARGUMENT_FLOAT(2.0f);
    LIBUTIL_STEALTH_PUSH_SPOOFED_RETURN_ADDRESS(CallProxy);
    LIBUTIL_STEALTH_PUSH_THISPTR(0xFFAABB);
    LIBUTIL_STEALTH_JUMP_TO_FUNCTION(1, Stuff);
#endif

    LIBUTIL_VECTOR3DF V1, V2, V3;
    V1.X = 3.0f; V1.Y = 10.0f; V1.Z = 15.0f;
    V2.X = -2.0f; V2.Y = 3.0f; V2.Z = -0.5f;

    LibUtil_Vector3DFAdd(&V3, &V1, &V2);

    printf("%f %f %f %f %f %f %f %f %f\n", V3.X, V3.Y, V3.Z, V1.X, V1.Y, V1.Z, V2.X, V2.Y, V2.Z);
    printf("%f %f %f %f %d %f\n", LibUtil_FloorF(1.3f), LibUtil_CeilF(1.3f), LibUtil_SinF(10.0f), LibUtil_CosF(10.0f), LibUtil_FtoI(1.67f), LibUtil_ItoF(10));
    printf("%f %f %f\n", LibUtil_SqrtF(45.0f * 45.0f), LibUtil_InvSqrtF(45.0f * 45.0f), LibUtil_PowF(2.0f, 3.0f));

    return 0;
}

#ifdef LIBUTIL_X86
LIBUTIL_NAKED
void CallProxy()
{
    __asm
    {
        ret
    }
}

void __fastcall Stuff(void *ECX, void *, float X)
{
    printf("%p %p %p %p %p %f\n", _ReturnAddress(), ECX, &CallProxy, &Stuff, &main, X);
}
#endif
