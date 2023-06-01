# libutil

A cross-platform, architecture-independent and CRT-less utility library for reverse engineering, binary/memory hacking
Currently very early WIP and only developed on Linux as of now, works with both GCC and Clang
Windows and MSVC support will be added as the project continues on
Features will also be added on an as-needed basis

# Configuration

## PreProcessor Definitions

### Heap
You can only use one of the following.

| Definition  | Behavior |
| - | - |
| `LIBUTIL_HEAP_CALLBACKS` | You must supply the malloc/free functions you want libutil to use to `LibUtil_Heap_SetMalloc/LibUtil::Heap::SetMalloc` and `LibUtil_Heap_SetFree/LibUtil::Heap::SetFree` respectively |
| `LIBUTIL_HEAP_STATIC` | libutil defines a static byte buffer and allocates memory using it, never calling any external functions or allocating pages in the process. Use `LIBUTIL_HEAP_STATIC_ALIGN` and `LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES` to control alignment and total available size respectively. |
