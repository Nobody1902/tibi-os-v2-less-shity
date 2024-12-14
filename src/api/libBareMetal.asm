use64
; =============================================================================
; BareMetal -- a 64-bit OS written in Assembly for x86-64 systems
; Copyright (C) 2008-2024 Return Infinity -- see LICENSE.TXT
;
; Version 1.0
; =============================================================================

; Kernel functions
b_input			= 0x0000000000100010	; Scans keyboard for input. OUT: AL = 0 if no key pressed, otherwise ASCII code
b_output		= 0x0000000000100018	; Displays a number of characters. IN: RSI = message location, RCX = number of characters

b_net_tx		= 0x0000000000100020	; Transmit a packet via a network interface. IN: RSI = Memory location where packet is stored, RCX = Length of packet
b_net_rx		= 0x0000000000100028	; Polls the network interface for received packet. IN: RDI = Memory location where packet will be stored. OUT: RCX = Length of packet

b_storage_read		= 0x0000000000100030	; Read data from a drive. IN: RAX = Starting sector, RCX = Number of sectors to read, RDX = Drive, RDI = Memory location to store data
b_storage_write		= 0x0000000000100038	; Write data to a drive. IN: RAX = Starting sector, RCX = Number of sectors to write, RDX = Drive, RSI = Memory location of data to store

b_system		= 0x0000000000100040	; Configure system. IN: RCX = Function, RAX = Variable 1, RDX = Variable 2. OUT: RAX = Result


; Index for b_system calls
TIMECOUNTER		= 0x00
FREE_MEMORY		= 0x02
NETWORKCALLBACK_GET	= 0x03
NETWORKCALLBACK_SET	= 0x04
CLOCKCALLBACK_GET	= 0x05
CLOCKCALLBACK_SET	= 0x06
SMP_ID			= 0x10
SMP_NUMCORES		= 0x11
SMP_SET			= 0x12
SMP_GET			= 0x13
SMP_LOCK		= 0x14
SMP_UNLOCK		= 0x15
SMP_BUSY		= 0x16
SCREEN_LFB_GET		= 0x20
SCREEN_X_GET		= 0x21
SCREEN_Y_GET		= 0x22
SCREEN_PPSL_GET		= 0x23
SCREEN_BPP_GET		= 0x24
MAC_GET			= 0x30
BUS_READ		= 0x50
BUS_WRITE		= 0x51
STDOUT_SET		= 0x52
STDOUT_GET		= 0x53
DUMP_MEM		= 0x70
DUMP_RAX		= 0x71
DELAY			= 0x72
RESET			= 0x7D
REBOOT			= 0x7E
SHUTDOWN		= 0x7F


; =============================================================================
; EOF
