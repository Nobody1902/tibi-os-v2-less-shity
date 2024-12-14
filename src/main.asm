use64

include 'api/libBareMetal.asm'

org 001E0000h

start:
	mov rsi, msg
	mov rcx, msglen
	call qword[b_output]
	jmp $

msg db "Hello for FASM"
msglen = 14
