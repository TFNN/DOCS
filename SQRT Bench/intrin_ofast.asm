sub     rsp, 8
call    rand
pxor    xmm0, xmm0
pxor    xmm1, xmm1
add     rsp, 8
cvtsi2ss        xmm0, eax
movss   xmm1, xmm0
movaps  xmm0, xmm1
rsqrtss xmm0, xmm1
cvttss2si       eax, xmm0
ret
