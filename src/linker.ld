OUTPUT_FORMAT(binary)
OUTPUT_ARCH(i386:x86-64)

ENTRY(_start)

SECTIONS
{
	. = 0x001E0000;

	.text : {
    . = 0x001E0000
		*(.text .text.*)
	}
}
