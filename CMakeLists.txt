cmake_minimum_required(VERSION 3.0)

include_directories("./")

# libutil-common
project(util-common)
add_library(${PROJECT_NAME} STATIC
    libutil/common/memory/heap.c
    libutil/common/memory/mlib.c
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

# libutil-containers
project(util-containers)
add_library(${PROJECT_NAME} STATIC
    libutil/containers/doubly_linked_list.c
    libutil/containers/stack.c
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)

# libutil-platform
project(util-platform)
add_library(${PROJECT_NAME} STATIC
    libutil/platform/virtual_memory/page_unix.c
    libutil/platform/virtual_memory/page_win.c

    libutil/platform/syscall_unix.c
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -masm=intel
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)

# libutil-code
project(util-code)
add_library(${PROJECT_NAME} STATIC
    libutil/code/hook/jmp.c
    libutil/code/hook/pe_eat.c
    libutil/code/hook/pe_iat.c

    libutil/code/signature/find.c

    libutil/code/patch.c
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-platform)

# tests
project(tests-crt)
add_executable(${PROJECT_NAME}
    tests/main.cpp
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)
target_link_libraries(${PROJECT_NAME} util-code)

# tests-crtless
#[[project(tests-crtless)
add_executable(${PROJECT_NAME}
    tests/main.cpp
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
    -emain
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)
target_link_libraries(${PROJECT_NAME} util-code)]]
