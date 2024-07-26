section .data
n1 dq 1
n2 dq 2
cursum dq 0

section .text
global _start

_start:
	mov rax,[n1]
	add rax,[n2]
	mov [cursum],rax
	mov rax,1
	int 0x80
