section .text
bits 64
default rel
global dotproduct ; rename this to asmdotproduct

dotproduct:

    L1:
        movss xmm0, [rdx]
        movss xmm1, [r8]
        mulss xmm0, xmm1
        movss [r9], xmm0
        add rdx, 4
        add r8, 4
        add r9, 4
        loop L1
    
    ret