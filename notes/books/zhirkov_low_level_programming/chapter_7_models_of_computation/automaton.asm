section .text

_A:
	call getsymbol
	cmp al, '1'
	je _B
	cmp al, '0'
	je _A
	cmp al, 0
	je _EVEN
	jmp _ERROR
	
_B:
	call getsymbol
	cmp al, '1'
	je _A
	cmp al, '0'
	je _B
	cmp al, 0
	je _ODD
	jmp _ERROR
	
_EVEN:


_ODD:


_ERROR:
