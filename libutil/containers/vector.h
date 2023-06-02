#ifndef __LIBUTIL_CONTAINERS_VECTOR__
#define __LIBUTIL_CONTAINERS_VECTOR__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef struct _LIBUTIL_VECTOR
{
    libutil_size    ElementSize;
    libutil_size    Count;
    libutil_size    Reserved;
    void            *Data;
} LIBUTIL_VECTOR;

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_VECTOR  *LibUtil_Vector_Create(libutil_size ElementSize);

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_Vector_Destroy(LIBUTIL_VECTOR *Vector);

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_Vector_Reserve(LIBUTIL_VECTOR *Vector, libutil_size Count);

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_Vector_SetElement(LIBUTIL_VECTOR *Vector, libutil_size Index, const void *Data);

LIBUTIL_API LIBUTIL_IMPORT
void            *LibUtil_Vector_GetElement(LIBUTIL_VECTOR *Vector, libutil_size Index);

LIBUTIL_API LIBUTIL_IMPORT
void            LibUtil_Vector_PushBack(LIBUTIL_VECTOR *Vector, const void *Data);

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Containers
        {
            template< typename _T >
            struct Vector;
        }
    }

    template< typename _T >
    struct LibUtil::Containers::Vector
    {
        LIBUTIL_FORCE_INLINE
        void Reserve(LibUtil::Size Count)
        {
            LibUtil_Vector_Reserve(
                (LIBUTIL_VECTOR *)(this),
                Count
            );
        }

        LIBUTIL_FORCE_INLINE
        _T &Get(LibUtil::Size Index)
        {
            return *(_T *)(
                LibUtil_Vector_GetElement(
                    (LIBUTIL_VECTOR *)(this),
                    Index
                )
            );
        }

        LIBUTIL_FORCE_INLINE
        const _T Get(LibUtil::Size Index) const
        {
            return *(_T *)(
                LibUtil_Vector_GetElement(
                    (LIBUTIL_VECTOR *)(this),
                    Index
                )
            );
        }

        LIBUTIL_FORCE_INLINE
        void Set(LibUtil::Size Index, const _T Value)
        {
            LibUtil_Vector_SetElement(
                (LIBUTIL_VECTOR *)(this),
                Index,
                &Value
            );
        }

        LIBUTIL_FORCE_INLINE
        void Set(LibUtil::Size Index, _T &Value)
        {
            LibUtil_Vector_SetElement(
                (LIBUTIL_VECTOR *)(this),
                Index,
                &Value
            );
        }

        LIBUTIL_FORCE_INLINE
        void PushBack(_T &Value)
        {
            LibUtil_Vector_PushBack(
                (LIBUTIL_VECTOR *)(this),
                &Value
            );
        }

        const LibUtil::Size GetCount() const
        {
            return Data.Count;
        }

        LIBUTIL_FORCE_INLINE
        static void *operator new(LibUtil::Size Size)
        {
            return LibUtil_Vector_Create(sizeof(_T));
        }

        LIBUTIL_VECTOR Data;
    };
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif