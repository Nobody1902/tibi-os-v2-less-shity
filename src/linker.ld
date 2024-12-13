OUTPUT_FORMAT(binary)
OUTPUT_ARCH(i386:x86-64)

MEMORY
{
    MEM1           : ORIGIN = 0x00000000,          LENGTH = 100K
    MEM2           : ORIGIN = 0x001E0000,          LENGTH = 2048K
}


SECTIONS
{
    .libBareMetal    : { libBareMetal.o(.text .text.*) } >MEM1
    .main    : { main.o(.text .text.*) } >MEM2
}
