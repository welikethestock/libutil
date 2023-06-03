#include "libutil/common/memheap.h"
#include "libutil/containers/doubly_linked_list.h"
#include "libutil/containers/vector.h"
#include "libutil/code/patch.h"
#include "libutil/platform/virtual_memory/page.h"
#include "libutil/platform/sys/syscall.h"
#include "libutil/common/memlib.h"
#include "libutil/common/random.h"
#include "libutil/common/strlib.h"

#include <errno.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    LibUtil::Heap::SetMalloc(malloc);
    LibUtil::Heap::SetRealloc(realloc);
    LibUtil::Heap::SetFree(free);

    // memcpy
    char MemcpyTestBuffer[512] = { 0 };
    static const char MemcpyTestString[] = "123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)asfasf";
    volatile const char *MemcpyTestPtr = MemcpyTestString;
    LibUtil::Memcpy(&MemcpyTestBuffer, ((const char *)(MemcpyTestPtr)) + 1, sizeof(MemcpyTestString) - 5);

    printf("memcpy> %s %p %p\n", MemcpyTestBuffer, MemcpyTestBuffer, MemcpyTestString + 3);

    //syscall
    LibUtil_Syscall3(1, 1, (libutil_size)("syscall>\n"), sizeof("syscall>\n"));

    // vector
    LibUtil::Containers::Vector<int> Vector = LibUtil::Containers::Vector<int>();
    int VectorTestInts[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(libutil_size Index = 0; Index < (sizeof(VectorTestInts) / sizeof(VectorTestInts[0])); ++Index)
    {
        Vector.PushBack(VectorTestInts[Index]);
    }

    Vector[2] = -1;

    printf("vector> ");
    for(libutil_size Index = 0; Index < Vector.Count; ++Index)
    {
        printf("%d ", Vector[Index]);
    }
    printf("(%zu %zu)\n", Vector.Count, Vector.Reserved);

    // random
    printf("crnghw> %d %llu %d %f %f\n",
        LibUtil::Random::Generate(NULL, LIBUTIL_RANDOM_GENERATOR_HW),
        LibUtil::Random::Generate<libutil_u64>(NULL, LIBUTIL_RANDOM_GENERATOR_HW),
        LibUtil::Random::Generate<libutil_i16>(NULL, LIBUTIL_RANDOM_GENERATOR_HW),
        LibUtil::Random::Generate<float>(NULL, LIBUTIL_RANDOM_GENERATOR_HW),
        LibUtil::Random::Generate<double>(NULL, LIBUTIL_RANDOM_GENERATOR_HW)
    );

    // string to number
    libutil_i32 Number;
    LibUtil_StringToNumber(16, "Ff", &Number);
    printf("str2num> %d\n", Number);

    // strstr
    const char *Found = LibUtil_FindSubString("test string", "st");
    printf("substr> %s %s\n", Found, LibUtil_FindSubString(Found + 1, "st"));

    //memcmp
    static const char MemcmpTest1[] = "123456789abdefghijklmnopqrstuvwxyz";
    static const char MemcmpTest2[] = "123456789abdefghijklmnopqrstuvwxyz";
    printf("memcmp> %d\n", LibUtil_Memcmp(MemcmpTest1, MemcmpTest2, sizeof(MemcmpTest1)));

    //memset
    static char MemsetTest[64 + 16 + 8 + 7] = { 0 };
    LibUtil_Memset(MemsetTest, 0xAF, sizeof(MemsetTest));
    {
        libutil_bool Success = TRUE;
        for(libutil_size Index = 0; Index < sizeof(MemsetTest); ++Index)
        {
            if(MemsetTest[Index] != '\xAF')
            {
                printf("memset> %d %d %d %d\n", Index, sizeof(MemsetTest) - Index, MemsetTest[Index], 0xAF);

                Success = FALSE;

                break;
            }
        }

        printf("memset> %s\n", (Success) ? "success" : "fail");
    }

    return 0;
}
