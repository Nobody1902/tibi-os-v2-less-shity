OUTPUT_FORMAT(binary)
OUTPUT_ARCH(i386:x86-64)

ENTRY(_start)

MEMORY
{
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
	. = 0x001E0000;

	.text : {
		*(.text .text.*)
	}

	. = ALIGN(16);

	.rodata : {
		*(.rodata .rodata.*)
	}

	. = ALIGN(16);

	.data : {
		*(.data .data.*)
	}

	. = ALIGN(16);

	__bss_start = .;
	.bss : {
		*(.bss .bss.*)
	}
	__bss_stop = .;

  .heap (NOLOAD) : {
    __heap_start__ = .;
    . = . + LENGTH(RAM);
    __heap_end__ = .;
  } > RAM


	/DISCARD/ : {
		*(.eh_frame*)
		*(.note .note.*)
		*(.intrep)
	}
}
