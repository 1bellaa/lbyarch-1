section .text
bits 64
default rel
global asmdotproduct 

asmdotproduct:
	
	xorps xmm2, xmm2
	
    L1:
        movss xmm0, [rdx]
        movss xmm1, [r8]
        mulss xmm0, xmm1        
		addss xmm2, xmm0
        add rdx, 4
        add r8, 4
        loop L1
    movss [r9], xmm2
	
    ret