section .data
codes:
	db	'0123456789ABCDEF'

section .text
global _start
_start:; global label
	mov rax, 0x11223344556677df; number to be printed
	
	mov rdi, 1; descriptor of stdout
	mov rdx, 1; number of bytes to write
	mov rcx, 64; number is 64 bit long, loop will iterate 16 ( = 64 / 4 ) times

.loop:; local label with full name _start.loop ( because _start is the last used dotless global label ) 
	push rax; saves value of rax onto the stack
	sub rcx, 4; <-> iterator decrement

	; rax -- eax -- ax -- ah + al
	; rcx -- ecx -- cx -- ch + cl

	sar rax, cl; this instruction shifts the required hexadecimal digit into the least significant 4 bits of rax
	and rax, 0xf; masks the lowest 4 bits of rax to extract a single hexadecimal digit
	
	
	; square brackets denote indirect addressing, the address is written inside them
	; lea = load effective address = calculate an address of a memory cell and store it
	lea rsi, [codes + rax]; calculates the address of the character in codes corresponing to extracted digit
	
	mov rax, 1; system call number for write
	push rcx; save rcx because syscall can modify it
	syscall
	pop rcx

	pop rax
	test rcx, rcx; checks if rcx is zero by performing a bitwise AND
	jnz .loop; if rcx is not zero, jumps back to .loop, same instruction as jnz _start.loop

	mov rax, 60
	xor rdi, rdi
	syscall