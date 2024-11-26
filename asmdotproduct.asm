section .text
bits 64
default rel
global asmdotproduct

asmdotproduct:
    ; A@rdi, B@rsi, sdot@rdx, n@rcx
    ; registers 

.loop:
    ; arithmetic 

.exit
    ; Store result
    ret