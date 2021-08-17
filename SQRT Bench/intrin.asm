push    rbp
mov     rbp, rsp
sub     rsp, 48
call    rand
pxor    xmm0, xmm0
cvtsi2ss        xmm0, eax
movss   DWORD PTR [rbp-36], xmm0
mov     eax, DWORD PTR [rbp-36]
movd    xmm0, eax
movaps  XMMWORD PTR [rbp-32], xmm0
movaps  xmm0, XMMWORD PTR [rbp-32]
rsqrtss xmm0, DWORD PTR [rbp-32]
nop
movaps  XMMWORD PTR [rbp-16], xmm0
movss   xmm0, DWORD PTR [rbp-16]
cvttss2si       eax, xmm0
leave
ret
