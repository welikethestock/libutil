#rm -rf ./build

#export PATH=/opt/cmake/bin:$PATH
export PATH=/opt/msvc/bin/x64:$PATH

BIN=/opt/msvc/bin/x64 . /opt/msvc/msvcenv-native.sh
CC=cl CXX=cl cmake -B ./build -S . -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_SYSTEM_NAME=Windows
CC=cl CXX=cl cmake --build ./build
