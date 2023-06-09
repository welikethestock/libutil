CC=gcc CXX=g++ cmake -B ./build-gcc -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
CC=gcc CXX=g++ cmake --build ./build-gcc

#CC=gcc CXX=g++ cmake -B ./build-gcc32 -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32
#CC=gcc CXX=g++ cmake --build ./build-gcc32

#CC=clang CXX=clang++ cmake -B ./build-clang -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
#CC=clang CXX=clang++ cmake --build ./build-clang

#CC=clang CXX=clang++ cmake -B ./build-clang32 -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32
#CC=clang CXX=clang++ cmake --build ./build-clang32

#export PATH=/opt/msvc/bin/x64:$PATH
#BIN=/opt/msvc/bin/x64 . /opt/msvc/msvcenv-native.sh

#CC=cl CXX=cl cmake -B ./build-win -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
#CC=cl CXX=cl cmake --build ./build-win

export PATH=/opt/msvc/bin/x86:$PATH
BIN=/opt/msvc/bin/x86 . /opt/msvc/msvcenv-native.sh

CC=cl CXX=cl cmake -B ./build-win32 -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
CC=cl CXX=cl cmake --build ./build-win32
