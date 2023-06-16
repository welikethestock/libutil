cmake_minimum_required(VERSION 3.0.0)
#set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,RelWithDebInfo>:Embedded>")

# libutil-internal
project(util-internal)

#message(${PROJECT_SOURCE_DIR})
include_directories("./")

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/internal/stack_chk_fail.c
    ${PROJECT_SOURCE_DIR}/libutil/internal/stack_chk_fail_local.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

# libutil-common
project(util-common)

if(${CMAKE_C_COMPILER_FRONTEND_VARIANT} STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /O2 /arch:AVX2 /Oi /GL /Gw /GR- /Qspectre- ") # avx2, intrinsics, whole program optimization, disable RTTI, disable spectre mitigations
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /O2 /guard:cf- /guard:ehcont- /Gy") # disable control flow guard, disable EH continuation metadata, enable function-level linking
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zc:threadSafeInit- /Zc:throwingNew- /Zc:tlsGuards- ")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2 /arch:AVX2 /Oi /GL /Gw /GR- /Qspectre- ") # avx2, intrinsics, whole program optimization, disable RTTI, disable spectre mitigations
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2 /guard:cf- /guard:ehcont- /Gy") # disable control flow guard, disable EH continuation metadata, enable function-level linking
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:threadSafeInit- /Zc:throwingNew- /Zc:tlsGuards- ")

    add_definitions(/DLIBUTIL_HEAP_CALLBACKS)
    add_definitions(/DLIBUTIL_FEATURE_SSE2)

    set(LINK_OPTIONS "/MAP /NODEFAULTLIB")
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

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-internal)
#target_link_libraries(${PROJECT_NAME}_shared util-internal)

#libutil-math
project(util-math)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/math/float.c
    ${PROJECT_SOURCE_DIR}/libutil/math/vector.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

#libutil-crypto
project(util-crypto)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/crypto/luhash.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

# libutil-arch
project(util-arch)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/arch/x86/mode.c
    ${PROJECT_SOURCE_DIR}/libutil/arch/x86/random.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
#target_link_libraries(${PROJECT_NAME}_shared util-common)

target_link_libraries(util-common ${PROJECT_NAME})
#target_link_libraries(util-common_shared ${PROJECT_NAME})

# libutil-containers
project(util-containers)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/containers/doubly_linked_list.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/stack.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/string.c
    ${PROJECT_SOURCE_DIR}/libutil/containers/vector.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-arch)
target_link_libraries(${PROJECT_NAME} util-common)

#target_link_libraries(${PROJECT_NAME}_shared util-arch)
#target_link_libraries(${PROJECT_NAME}_shared util-common)

# libutil-analysis
project(util-analysis)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/analysis/debug.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-containers)

#target_link_libraries(${PROJECT_NAME}_shared util-common)
#target_link_libraries(${PROJECT_NAME}_shared util-containers)

# libutil-platform
enable_language(C CXX ASM ASM_MASM)
project(util-platform C CXX ASM ASM_MASM)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/platform/nt/ldr.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/nt/pe.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/nt/peb.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/nt/teb.c

    ${PROJECT_SOURCE_DIR}/libutil/platform/sys/syscall_unix.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/sys/syscall_win.c

    ${PROJECT_SOURCE_DIR}/libutil/platform/virtual_memory/page_unix.c
    ${PROJECT_SOURCE_DIR}/libutil/platform/virtual_memory/page_win.c
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND ${CMAKE_C_COMPILER_FRONTEND_VARIANT} STREQUAL "MSVC")
    set(PROJECT_SOURCES
        ${PROJECT_SOURCES}
        ${PROJECT_SOURCE_DIR}/libutil/platform/sys/syscall_win_msvcx64.asm
    )
endif()

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
#target_link_libraries(${PROJECT_NAME}_shared util-common)

# libutil-code
project(util-code)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/libutil/code/disasm/x86.c

    ${PROJECT_SOURCE_DIR}/libutil/code/hook/jmp.c
    ${PROJECT_SOURCE_DIR}/libutil/code/hook/pe_eat.c
    ${PROJECT_SOURCE_DIR}/libutil/code/hook/pe_iat.c
    ${PROJECT_SOURCE_DIR}/libutil/code/hook/vft.c

    ${PROJECT_SOURCE_DIR}/libutil/code/signature/find.c

    ${PROJECT_SOURCE_DIR}/libutil/code/patch.c
)

#add_library(${PROJECT_NAME}_shared SHARED ${PROJECT_SOURCES})
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})
#target_link_options(${PROJECT_NAME}_shared PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-platform)

#target_link_libraries(${PROJECT_NAME}_shared util-common)
#target_link_libraries(${PROJECT_NAME}_shared util-platform)

# tests
project(tests-crt)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/tests/main.cpp
)

target_link_options(${PROJECT_NAME} PRIVATE ${LINK_OPTIONS})

target_link_libraries(${PROJECT_NAME} util-common)
target_link_libraries(${PROJECT_NAME} util-math)
target_link_libraries(${PROJECT_NAME} util-crypto)
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
