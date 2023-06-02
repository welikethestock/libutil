#include "heap.h"

#ifdef LIBUTIL_HEAP_STATIC
    #ifndef LIBUTIL_HEAP_STATIC_ALIGN
        #define LIBUTIL_HEAP_STATIC_ALIGN (sizeof(libutil_size))
    #endif

    #ifndef LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES // Must be divideable by LIBUTIL_HEAP_STATIC_ALIGN
        #define LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES   4096
    #endif

    typedef struct _LIBUTIL_HEAP_BLOCK
    {
        libutil_bool    Used;
        libutil_u32     DeltaToEndBlock;
    } LIBUTIL_HEAP_BLOCK;

    static
    LIBUTIL_HEAP_BLOCK s_HeapBlocks[LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES / LIBUTIL_HEAP_STATIC_ALIGN];

    static
    libutil_u8 s_HeapData[LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES];
#elif defined(LIBUTIL_HEAP_CALLBACKS)
    static
    LIBUTIL_HEAP_MALLOC     s_MallocCallback;

    static
    LIBUTIL_HEAP_REALLOC    s_ReallocCallback;

    static
    LIBUTIL_HEAP_FREE       s_FreeCallback;
#endif

LIBUTIL_API
void *LibUtil_Heap_Allocate(libutil_size Size)
{
    if(Size == 0)
    {
        return NULL;
    }

    void *Address = NULL;

#ifdef LIBUTIL_HEAP_STATIC
    Size = (Size + (LIBUTIL_HEAP_STATIC_ALIGN - 1)) & ~(LIBUTIL_HEAP_STATIC_ALIGN - 1);
    libutil_u32 BlocksNeeded = Size / LIBUTIL_HEAP_STATIC_ALIGN;

    for(libutil_u32 Index = 0; Index < (sizeof(s_HeapBlocks) / sizeof(s_HeapBlocks[0]));)
    {
        LIBUTIL_HEAP_BLOCK *Block = &s_HeapBlocks[Index];
        if(Block->Used)
        {
            Index += Block->DeltaToEndBlock;

            continue;
        }

        libutil_bool HasSpace = TRUE;
        for(libutil_u32 OtherBlockIndex = 0; OtherBlockIndex < (BlocksNeeded - 1); ++OtherBlockIndex)
        {
            LIBUTIL_HEAP_BLOCK *OtherBlock = &s_HeapBlocks[Index + OtherBlockIndex];
            if(OtherBlock->Used)
            {
                HasSpace = FALSE;
                Index += 1 + OtherBlockIndex + OtherBlock->DeltaToEndBlock;

                break;
            }

            if(OtherBlockIndex == (BlocksNeeded - 1))
            {
                break;
            }
        }

        if(!HasSpace)
        {
            continue;
        }

        Block->Used = TRUE;
        Block->DeltaToEndBlock = BlocksNeeded;

        Address = &s_HeapData[Index * LIBUTIL_HEAP_STATIC_ALIGN];

        break;
    }
#elif defined(LIBUTIL_HEAP_CALLBACKS)
    Address = s_MallocCallback(Size);
#else
    #error "No heap method selected"
#endif

    return Address;
}

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Heap_Reallocate(void *Address, libutil_size Size)
{
#ifdef LIBUTIL_HEAP_STATIC
    #error "Implement me"
#elif defined(LIBUTIL_HEAP_CALLBACKS)
    return s_ReallocCallback(Address, Size);
#else
    #error "No heap method selected"
#endif
}

void LibUtil_Heap_Free(void *Address)
{
#ifdef LIBUTIL_HEAP_STATIC
    libutil_u32 BlockIndex      = (libutil_u32)((libutil_u8 *)(Address) - &s_HeapData[0]) / sizeof(LIBUTIL_HEAP_STATIC_ALIGN);
    LIBUTIL_HEAP_BLOCK *Block   = &s_HeapBlocks[BlockIndex];

    Block->Used = FALSE;
    Block->DeltaToEndBlock = 0;
#elif defined(LIBUTIL_HEAP_CALLBACKS)
    s_FreeCallback(Address);
#else
    #error "No heap method selected"
#endif
}

#ifdef LIBUTIL_HEAP_CALLBACKS
LIBUTIL_API
void LibUtil_Heap_SetMalloc(LIBUTIL_HEAP_MALLOC Callback)
{
    s_MallocCallback = Callback;
}

LIBUTIL_API
void LibUtil_Heap_SetRealloc(LIBUTIL_HEAP_REALLOC Callback)
{
    s_ReallocCallback = Callback;
}

LIBUTIL_API
void LibUtil_Heap_SetFree(LIBUTIL_HEAP_FREE Callback)
{
    s_FreeCallback = Callback;
}
#endif
