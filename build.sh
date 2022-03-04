#!/bin/bash

clone_docparser(){
    if test ! -d ./docparser
    then
        git clone https://github.com/linuxdeepin/docparser.git
    fi
}

clone_docparser
mkdir -p build
cd build
qmake ../docparser "CONFIG+=staticlib"
make CC=xfuzz-cc CXX=xfuzz-c++ LINK=xfuzz-c++ V=1 -j
make install INSTALL_ROOT=$PWD/install

for ext in docx pdf pptx; do
    xfuzz-c++ ../target.cpp -o docparse_$ext -I./install/usr/include/docparser  ./install/usr/lib/libdocparser.a -lpoppler-cpp -DFILE_EXT=\"$ext\"
done
