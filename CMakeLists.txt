cmake_minimum_required(VERSION 3.0)
include_directories("./")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")

add_definitions(
    -DLIBUTIL_HEAP_CALLBACKS
)

# libutil-common
project(util-common)

set(PROJECT_SOURCES
    libutil/common/mathbits.c

    libutil/common/memheap.c
    libutil/common/memlib.c

    libutil/common/random.c

    libutil/common/strlib.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

# libutil-containers
project(util-containers)

set(PROJECT_SOURCES
    libutil/containers/doubly_linked_list.c
    libutil/containers/stack.c
    libutil/containers/string.c
    libutil/containers/vector.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-arch)
target_link_libraries(${PROJECT_NAME}_shared util-arch)

# libutil-analysis
project(util-analysis)

set(PROJECT_SOURCES
    libutil/analysis/debug.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)

target_link_libraries(${PROJECT_NAME}_shared util-common)
target_link_libraries(${PROJECT_NAME}_shared util-containers)

# libutil-platform
project(util-platform)

set(PROJECT_SOURCES
    libutil/platform/sys/syscall_unix.c
    libutil/platform/sys/syscall_win.c

    libutil/platform/virtual_memory/page_unix.c
    libutil/platform/virtual_memory/page_win.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -masm=intel
)

target_compile_options(${PROJECT_NAME}_shared PRIVATE
    -masm=intel
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME}_shared util-common)

# libutil-arch
project(util-arch)

set(PROJECT_SOURCES
    libutil/arch/random/x86.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -masm=intel
)

target_compile_options(${PROJECT_NAME}_shared PRIVATE
    -masm=intel
)

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

# libutil-code
project(util-code)

set(PROJECT_SOURCES
    libutil/code/disasm/x86.c

    libutil/code/hook/jmp.c
    libutil/code/hook/pe_eat.c
    libutil/code/hook/pe_iat.c

    libutil/code/signature/find.c

    libutil/code/patch.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_options(${PROJECT_NAME}_shared PRIVATE
    -nodefaultlibs
    -nostdlib
    -nostartfiles
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-platform)

target_link_libraries(${PROJECT_NAME}_shared util-common)
target_link_libraries(${PROJECT_NAME}_shared util-platform)

# tests
project(tests-crt)

add_executable(${PROJECT_NAME}
    tests/main.cpp
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)
target_link_libraries(${PROJECT_NAME} util-code)
target_link_libraries(${PROJECT_NAME} util-arch)

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
