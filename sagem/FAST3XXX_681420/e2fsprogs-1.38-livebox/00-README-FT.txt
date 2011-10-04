
First, set PATH to include the path to your mips-linux-uclibc compiler:
export PATH="/path/to/mips-linux-uclibc/bin:${PATH}"

Then, configure and build e2fsprogs:
./configure --build=$(./config/config.guess) --host=mips-linux-uclibc   \\
            --prefix=/usr                                               \\
            CC=mips-linux-uclibc-gcc                                    \\
            AR=mips-linux-uclibc-ar                                     \\
            RANLIB=mips-linux-uclibc-ranlib                             \\
            STRIP=mips-linux-uclibc-strip                               \\
            NM=mips-linux-uclibc-nm
make
