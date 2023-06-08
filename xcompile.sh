#rm -rf ./build

#export PATH=/opt/cmake/bin:$PATH
export PATH=/opt/msvc/bin/x64:$PATH
BIN=/opt/msvc/bin/x64 . /opt/msvc/msvcenv-native.sh

CC=cl CXX=cl cmake -B ./build -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
CC=cl CXX=cl cmake --build ./build

export PATH=/opt/msvc/bin/x86:$PATH
BIN=/opt/msvc/bin/x86 . /opt/msvc/msvcenv-native.sh

CC=cl CXX=cl cmake -B ./build32 -S . -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -DCMAKE_C_COMPILER_LAUNCHER=ccache
CC=cl CXX=cl cmake --build ./build32
