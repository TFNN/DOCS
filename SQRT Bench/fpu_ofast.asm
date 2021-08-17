sub     rsp, 8
call    rand
pxor    xmm1, xmm1
movsd   xmm0, QWORD PTR .LC0[rip]
add     rsp, 8
cvtsi2sd        xmm1, eax
sqrtsd  xmm1, xmm1
divsd   xmm0, xmm1
cvttsd2si       eax, xmm0
ret
