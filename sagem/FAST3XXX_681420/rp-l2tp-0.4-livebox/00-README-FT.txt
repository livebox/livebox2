
To build rp-l2tp:
export PATH="/path/to/mips-linux-uclibc/bin:${PATH}"

autoconf
automake -a
./configure --build=i386-pc-linux-gnu       \
            --host=mips-linux-uclibc        \
            --target=mips-linux-uclibc      \
            CC=mips-linux-uclibc-gcc        \
            AR=mips-linux-uclibc-ar         \
            RANLIB=mips-linux-uclibc-ranlib \
            STRIP=mips-linux-uclibc-strip   \
            NM=mips-linux-uclibc-nm
make clean
make TOOLCHAIN_DIR="/path/to/mips-linux-uclibc/"
