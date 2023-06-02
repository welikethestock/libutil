#include "vector.h"
#include "../common/memheap.h"
#include "../common/memlib.h"

LIBUTIL_API
LIBUTIL_VECTOR *LibUtil_Vector_Create(libutil_size ElementSize)
{
    LIBUTIL_VECTOR *Vector = LibUtil_Heap_Allocate(sizeof(LIBUTIL_VECTOR));
    if(Vector != NULL)
    {
        if(ElementSize != -1)
        {
            LibUtil_Vector_Setup(Vector, ElementSize);
        }
    }

    return Vector;
}

LIBUTIL_API
void LibUtil_Vector_Setup(LIBUTIL_VECTOR *Vector, libutil_size ElementSize)
{
    Vector->ElementSize = ElementSize;
    Vector->Count       = 0;
    Vector->Reserved    = 0;
    Vector->Data        = NULL;
}

LIBUTIL_API
void LibUtil_Vector_Destroy(LIBUTIL_VECTOR *Vector)
{
    if(Vector->Data != NULL)
    {
        LibUtil_Heap_Free(Vector->Data);
    }

    LibUtil_Heap_Free(Vector);
}

LIBUTIL_API
void LibUtil_Vector_Reserve(LIBUTIL_VECTOR *Vector, libutil_size Count)
{
    Vector->Data        = (Vector->Data == NULL) ? LibUtil_Heap_Allocate(Vector->ElementSize * Count) : LibUtil_Heap_Reallocate(Vector->Data, Vector->ElementSize * Count);
    Vector->Reserved    = Count;
}

LIBUTIL_API
void LibUtil_Vector_SetElement(LIBUTIL_VECTOR *Vector, libutil_size Index, const void *Data)
{
    LibUtil_Memcpy(
        (void *)((libutil_u8 *)(Vector->Data) + Vector->ElementSize * Index),
        Data,
        Vector->ElementSize
    );
}

LIBUTIL_API
void *LibUtil_Vector_GetElement(LIBUTIL_VECTOR *Vector, libutil_size Index)
{
    return ((libutil_u8 *)(Vector->Data) + Vector->ElementSize * Index);
}

void LibUtil_Vector_PushBack(LIBUTIL_VECTOR *Vector, const void *Data)
{
    if(Vector->Data == NULL)
    {
        LibUtil_Vector_Reserve(Vector, 2);
    }

    if(Vector->Count >= Vector->Reserved) // out of reserved memory, reallocate
    {
        LibUtil_Vector_Reserve(Vector, Vector->Count * 2);
    }

    LibUtil_Vector_SetElement(Vector, Vector->Count, Data);

    ++Vector->Count;
}
