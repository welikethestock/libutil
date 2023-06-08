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

#include <stdio.h>
#include <stddef.h>

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

    //string test
    LIBUTIL_STRING  *StringTest = lu_stringcreatenarrowconst("test ");
    libutil_bool StringAppendResult = lu_stringappendnarrow(StringTest, "test");
    printf("string> %d %s %zu\n", StringAppendResult, (const char *)(StringTest->Vector.Data), StringTest->Vector.Count);

    // mmap/mprotect/munmap test
    /*void *BaseAddress = NULL;
    if(lu_pageallocate(&BaseAddress, 0x4000, LIBUTIL_PAGE_R, LIBUTIL_MAP_PRIVATE | LIBUTIL_MAP_ANONYMOUS))
    {
        printf("mmap> success %p\n", BaseAddress);
    }
    else
    {
        printf("mmap> fail\n");
    }*/

    //NtRaiseHardError test
#if 0
    LIBUTIL_ALIGN(16) LIBUTIL_NT_UNICODE_STRING64 Caption, Text;
    LIBUTIL_ALIGN(16) void *Arguments[] =
    {
        &Caption,
        &Text,
        (void *)(0x10) /*MB_OK | MB_ICONERROR*/
    };

    Caption.Buffer = (libutil_size)L"cool";
    Caption.Length = sizeof(L"cool");
    Caption.MaximumLength = sizeof(L"cool");

    Text.Buffer = (libutil_size)L"cool";
    Text.Length = sizeof(L"cool");
    Text.MaximumLength = sizeof(L"cool");

    LIBUTIL_ALIGN(16) libutil_u32 Response;
    printf("%p %p\n", Arguments, &Response);
    libutil_i64 Result = LibUtil_Syscall6(0x147, 0x40000018, 3, 0x3, (libutil_size)(Arguments), 0/*OptionOk*/, (libutil_size)(&Response));
    printf("%X %d\n", Result, Response);
#endif

#ifdef LIBUTIL_WINDOWS // works
    lu_nt_teb           *TEB = lu_nt_getteb();
    lu_nt_peb           *PEB = (lu_nt_peb *)(TEB->ProcessEnvironmentBlock);
    lu_nt_ldrdata       *Ldr = (lu_nt_ldrdata *)(PEB->Ldr);
    lu_nt_ldrdataentry  *Entry = (lu_nt_ldrdataentry *)(Ldr->InLoadOrderModuleList.Flink);
    while(Entry)
    {
        if(Entry->BaseDllName.Buffer == NULL)
        {
            break;
        }

        printf("%S\n", Entry->BaseDllName.Buffer);

        Entry = (lu_nt_ldrdataentry *)(Entry->InLoadOrderMemoryLinks.Flink);
    }

    printf("%p %p %p %llX %llX %d\n",
        TEB,
        PEB,
        Ldr,
        lu_nt_getteb64(),
        ((lu_nt_teb64 *)(lu_nt_getteb64()))->ProcessEnvironmentBlock,
        ((lu_nt_peb64 *)(((lu_nt_teb64 *)(lu_nt_getteb64()))->ProcessEnvironmentBlock))->OSMajorVersion
    );
#endif

#if defined(LIBUTIL_WINDOWS) && defined(LIBUTIL_X86)
    lu_nt_teb64 TEB64;
    if(lu_nt_readteb64(&TEB64))
    {
        printf("%llX\n", TEB64.ProcessEnvironmentBlock);
    }

    printf("%d\n", lu_syscall0(0xE1));
#endif

    return 0;
}
