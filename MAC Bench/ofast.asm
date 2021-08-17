-Ofast
processModel(float const*):
 sub    rsp,0x8
 xor    eax,eax
 pxor   xmm0,xmm0
 nop    WORD PTR [rax+rax*1+0x0]
 movups xmm1,XMMWORD PTR [rdi+rax*1]
 mulps  xmm1,XMMWORD PTR [rax+0x402020]
 add    rax,0x10
 addps  xmm0,xmm1
 cmp    rax,0x24c0
 jne    401170 <processModel(float const*)+0x10>
 movaps xmm1,xmm0
 movhlps xmm1,xmm0
 addps  xmm1,xmm0
 movaps xmm0,xmm1
 shufps xmm0,xmm1,0x55
 addps  xmm0,xmm1
 subss  xmm0,DWORD PTR [rip+0x333f]        # 4044e4 <aim_kernel+0x24c4>
 call   401030 <tanhf@plt>
 cvtss2sd xmm0,xmm0
 mulsd  xmm0,QWORD PTR [rip+0x3332]        # 4044e8 <aim_kernel+0x24c8>
 subsd  xmm0,QWORD PTR [rip+0x3332]        # 4044f0 <aim_kernel+0x24d0>
 cvtsd2ss xmm0,xmm0
 cvtss2sd xmm0,xmm0
 addsd  xmm0,QWORD PTR [rip+0x332a]        # 4044f8 <aim_kernel+0x24d8>
 mulsd  xmm0,QWORD PTR [rip+0x332a]        # 404500 <aim_kernel+0x24e0>
 add    rsp,0x8
 cvtsd2ss xmm0,xmm0
 ret    
 nop
