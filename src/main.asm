use64

include 'api/libBareMetal.asm'

org 0x001E0000

START:
	mov r8, 2
LOOP1:
	mov rsi, msg
	mov rcx, msglen
	call qword[b_output]
	dec r8
	jnz LOOP1
	jmp $

msg db "Hello for FASM",0x0A
msglen = 15
