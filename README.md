# libutil

A cross-platform, (mostly) architecture-independent [few exceptions, such as syscalls and on-chip random generators], CRT/Exception-less utility library with no dependencies (except for `intrin.h`, `x86intrin.h` and `sys/syscalls.h` as of right now) mainly for reverse engineering, binary/memory hacking, but my goal is it being able to be used instead of the entire C runtime/system libraries instead eventually

Currently very early WIP and only developed on Linux as of now, works with both GCC and Clang

Windows and MSVC support will be added as the project continues on

Features will also be added on an as-needed basis

Feel free to request features aswell

# Configuration

## PreProcessor Definitions

### Heap
You can only use one of the following.

| Definition  | Behavior |
| - | - |
| `LIBUTIL_HEAP_CALLBACKS` | You must supply the malloc/free functions you want libutil to use to `LibUtil_Heap_SetMalloc/LibUtil::Heap::SetMalloc` and `LibUtil_Heap_SetFree/LibUtil::Heap::SetFree` respectively |
| `LIBUTIL_HEAP_STATIC` | libutil defines a static byte buffer and allocates memory using it, never calling any external functions or allocating pages in the process. Use `LIBUTIL_HEAP_STATIC_ALIGN` and `LIBUTIL_HEAP_STATIC_SIZE_IN_BYTES` to control alignment and total available size respectively. |
