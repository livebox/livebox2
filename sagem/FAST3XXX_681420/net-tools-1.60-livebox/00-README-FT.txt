To build the arp tool:
    export PATH="/path/to/mipc-linux-uclibc/bin:${PATH}"
    make AR=mips-linux-uclibc-ar            \
         AS=mips-linux-uclibc-as            \
         LD=mips-linux-uclibc-ld            \
         NM=mips-linux-uclibc-nm            \
         CC=mips-linux-uclibc-gcc           \
         GCC=mips-linux-uclibc-gcc          \
         CXX=mips-linux-uclibc-g++          \
         RANLIB=mips-linux-uclibc-ranlib    \
         OBJCOPY=mips-linux-uclibc-objcopy  \
         STRIP=mips-linux-uclibc-strip      \
         arp
