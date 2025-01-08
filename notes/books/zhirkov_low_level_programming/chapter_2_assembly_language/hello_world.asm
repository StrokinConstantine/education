global _start; this label is the entry point, it should be declared global

global _START; not the same label as _start, cause labels are case sensitive

section .data; section for data, characters are encoded in ASCII, code of symbol for new line is 10

message: db 'hello, world!', 10; db ( bytes ) directive is used to create byte data ( dw = words, dd = double words, dq = quad words )
example1: db 5, 15, 1
example2: times 20 db 42; times n cmd is a directive to repeat cmd n times in program code
example3: dw 999

section .TEXT; not the same section as .text, cause section names are case sensitive

section .text; section for code

_start:
; mov a, b means write value from register or memory or imm value 'b' into register or memory 'a', but mov cannot copy data from mem to mem and src and dst operands must be of the same size
	mov rax, 1; rax holding system call's number. rdi, rsi, rdx, r10, r8 and r9 are used to hold arguments
	mov rdi, 1; argument 1, file descriptor ( where to write )
	mov rsi, message; argument 2, where does the string start? 
	mov rdx, 14; argument 3, how many bytes to write?
	
	syscall; system call in *nix systems, changes rcx and r11
	
	mov byte[ message ], 1; here we have to provide size explicitly
	mov word[ message ], 2
	mov dword[ message ], 3
	mov qword[ message ], 4
	
	push word 1
	push qword 2

	mov rax, 60; exit syscall number
	xor rdi, rdi; effective zeroing
	SYSCALL; assembly language is case insensitive
	
; to compile and execute:
; nasm -felf64 hello.asm -o hello.o
; ld -o hello hello.o
; chmod u+x hello
; ./hello