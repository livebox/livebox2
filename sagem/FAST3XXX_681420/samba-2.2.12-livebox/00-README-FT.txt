
First, set PATH to include the path to your mips-linux-uclibc compiler:
export PATH="/path/to/mips-linux-uclibc/bin:${PATH}"

Then, build samba proper:
make

The resulting binaries are stored in the bin/ sub-directory
