section .data
	newline_character: db 10
	codes: db '0123456789abcdef'
	
section .text

global _start
global print_newline
global print_rdi


print_newline:
	mov rax, 1
	mov rdi, 1
	mov rsi, newline_character
	mov rdx, 1
	syscall
	ret

print_rdi:
	mov rax, rdi
	mov rdi, 1
	mov rdx, 1
	mov rcx, 64; how far are we shifting rax

iterate:
	push rax
	sub rcx, 4
	sar rax, cl; shift to 60, 56, ..., 4, 0
	and rax, 0xf; clear all bits but the lowest for
	lea rsi, [codes + rax]
	mov rax, 1
	push rcx
	syscall
	pop rcx
	pop rax
	test rcx, rcx
	jnz iterate
	ret
