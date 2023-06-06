cmake_minimum_required(VERSION 3.0.0)
#set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")

include_directories("./")

# libutil-common
project(util-common)

if(${CMAKE_C_COMPILER_FRONTEND_VARIANT} STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:AVX2 /Oi /Zc:tlsGuards-") # avx2, intrinsics, disable tls guard
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2 /Oi /Zc:tlsGuards-") # avx2, intrinsics, disable tls guard

    add_definitions(/DLIBUTIL_HEAP_CALLBACKS)

    set(LINK_OPTIONS "")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -masm=intel")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -masm=intel")


    add_definitions(-DLIBUTIL_HEAP_CALLBACKS)
    set(LINK_OPTIONS
        -nodefaultlibs
        -nostdlib
        -nostartfiles
    )
endif()

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/common/mathbits.c

    ${PROJECT_SOURCE_DIR}/libutil/common/memheap.c
    ${PROJECT_SOURCE_DIR}/libutil/common/memlib.c

    ${PROJECT_SOURCE_DIR}/libutil/common/random.c

    ${PROJECT_SOURCE_DIR}/libutil/common/strlib.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

# libutil-arch
project(util-arch)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/arch/random/x86.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME}_shared util-common)

target_link_libraries(util-common ${PROJECT_NAME})
target_link_libraries(util-common_shared ${PROJECT_NAME})

# libutil-containers
project(util-containers)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/containers/doubly_linked_list.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/stack.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/string.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/vector.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-arch)
target_link_libraries(${PROJECT_NAME} util-common)

target_link_libraries(${PROJECT_NAME}_shared util-arch)
target_link_libraries(${PROJECT_NAME}_shared util-common)

# libutil-analysis
project(util-analysis)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/analysis/debug.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)

target_link_libraries(${PROJECT_NAME}_shared util-common)
target_link_libraries(${PROJECT_NAME}_shared util-containers)

# libutil-platform
project(util-platform)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/platform/sys/syscall_unix.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/sys/syscall_win.c

    ${PROJECT_SOURCE_DIR}/libutil/platform/virtual_memory/page_unix.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/virtual_memory/page_win.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME}_shared util-common)

# libutil-code
project(util-code)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/code/disasm/x86.c

    ${PROJECT_SOURCE_DIR}/libutil/code/hook/jmp.c
    ${PROJECT_SOURCE_DIR}/libutil/code/hook/pe_eat.c
    ${PROJECT_SOURCE_DIR}/libutil/code/hook/pe_iat.c

    ${PROJECT_SOURCE_DIR}/libutil/code/signature/find.c

    ${PROJECT_SOURCE_DIR}/libutil/code/patch.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-platform)

target_link_libraries(${PROJECT_NAME}_shared util-common)
target_link_libraries(${PROJECT_NAME}_shared util-platform)

# libutil-internal
project(util-internal)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/internal/stack_chk_fail.c
)

add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

# tests
project(tests-crt)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/tests/main.cpp
)

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)
target_link_libraries(${PROJECT_NAME} util-code)
target_link_libraries(${PROJECT_NAME} util-arch)
target_link_libraries(${PROJECT_NAME} util-internal)

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
