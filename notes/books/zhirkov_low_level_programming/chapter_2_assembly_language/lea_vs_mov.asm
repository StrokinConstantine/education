; lea allows you to calculate an address of a memory cell and store it somewhere

	mov rsi, codes; address of label 'codes' are copied to rsi
	mov rsi, [codes]; first consecutive 8 bytes starting at address 'codes' are copied to rsi  
	lea rsi, [codes]; <-> mov rsi, codes
	mov rsi, [codes + rax]
	lea rsi, [codes + rax]; <-> mov rsi, codes; add rsi, rax
	
; jmp addr <-> mov rip, addr, but you can't change rip by mov command
; conditional jumps rely on contents of rflags register
; jz jumps only if zero flag is set	
; to set flags you can use test or cmp instructions
; cmp a, b computes  a - b and set flags based on a - b, test do the same with logical AND

	cmp rax, 42
	jl yes
	mov rbx, 0
	jmp ex
yes:
	mov rbx, 1
ex:

	test reg, reg <-> fast check if register = 0
	
	ja/jb unsigned numbers
	
	jg/jl signed
	
	jae/jle 
	
	
	mov rax, -1 mov rdx, 2
cmp rax, rdx jg location ja location ; different logic!
cmp rax, rdx je location ; if rax equals rdx jne location ; if rax is not equal to rdx

Instruction call <address> is used to perform calls. It does exactly the following:
push rip jmp <address>
The address now stored in the stack (former rip contents) is called return address. Any function can accept an unlimited number of arguments. The first six arguments are passed in rdi,
rsi, rdx, rcx, r8, and r9, respectively. The rest is passed on to the stack in reverse order

ret <-> pop rip