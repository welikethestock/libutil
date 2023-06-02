#include "libutil/common/memheap.h"
#include "libutil/containers/doubly_linked_list.h"
#include "libutil/containers/vector.h"
#include "libutil/code/patch.h"
#include "libutil/platform/virtual_memory/page.h"
#include "libutil/platform/sys/syscall.h"
#include "libutil/common/memlib.h"
#include "libutil/common/random.h"

#include <errno.h>
#include <stdio.h>

char Test[512] = {};

int main(int argc, const char **argv)
{
    LibUtil::Heap::SetMalloc(malloc);
    LibUtil::Heap::SetRealloc(realloc);
    LibUtil::Heap::SetFree(free);

    // memcpy
    LibUtil::Memcpy(Test, "123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)", sizeof("123456789abcdef123456789abdef123456789abcdef123456789abdef123456789abcdef123456789abdef:)"));

    printf("memcpy> %s\n", Test);

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

    return 0;
}
