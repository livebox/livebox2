Build the bluez package in two steps. First, build the bluez-libs:
    export TOOLCHAIN_DIR=/path/to/mips-linux-uclibc
    export PATH=${TOOLCHAIN_DIR}/bin:${PATH}
    cd bluez-libs-2.13
    ./configure --host=mips-linux-uclibc            \
                --target=mips-linux-uclibc          \
                --disable-shared                    \
                --enable-static                     \
                CC=mips-linux-uclibc-gcc            \
                AR=mips-linux-uclibc-ar             \
                RANLIB=mips-linux-uclibc-ranlib     \
                STRIP=mips-linux-uclibc-strip       \
                NM=mips-linux-uclibc-nm
    make

Then, build the bluez-utils:
    cd ../bluez-utils-2.13
    ./configure --prefix=$(pwd)                     \
                --host=mips-linux-uclibc            \
                --target=mips-linux-uclibc          \
                CC=mips-linux-uclibc-gcc            \
                AR=mips-linux-uclibc-ar             \
                RANLIB=mips-linux-uclibc-ranlib     \
                STRIP=mips-linux-uclibc-strip       \
                NM=mips-linux-uclibc-nm
    make
