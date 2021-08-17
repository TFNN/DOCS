-Ofast -mavx -mfma4
processModel(float const*):
 lea    r10,[rsp+0x8]
 and    rsp,0xffffffffffffffe0
 vxorps xmm1,xmm1,xmm1
 xor    eax,eax
 push   QWORD PTR [r10-0x8]
 push   rbp
 mov    rbp,rsp
 push   r10
 sub    rsp,0x8
 nop    DWORD PTR [rax]
 vmovaps ymm3,YMMWORD PTR [rax+0x402020]
 vfmaddps ymm1,ymm3,YMMWORD PTR [rdi+rax*1],ymm1
 add    rax,0x20
 cmp    rax,0x24c0
 jne    401180 <processModel(float const*)+0x20>
 vextractf128 xmm0,ymm1,0x1
 vaddps xmm0,xmm0,xmm1
 vmovhlps xmm1,xmm0,xmm0
 vaddps xmm1,xmm1,xmm0
 vshufps xmm0,xmm1,xmm1,0x55
 vaddps xmm0,xmm0,xmm1
 vsubss xmm0,xmm0,DWORD PTR [rip+0x3326]        # 4044e4 <aim_kernel+0x24c4>
 vzeroupper 
 call   401030 <tanhf@plt>
 vmovsd xmm2,QWORD PTR [rip+0x331a]        # 4044e8 <aim_kernel+0x24c8>
 mov    r10,QWORD PTR [rbp-0x8]
 vcvtss2sd xmm0,xmm0,xmm0
 vfmaddsd xmm0,xmm0,xmm2,QWORD PTR [rip+0x3310]        # 4044f0 <aim_kernel+0x24d0>
 vcvtsd2ss xmm0,xmm0,xmm0
 vcvtss2sd xmm0,xmm0,xmm0
 vaddsd xmm0,xmm0,QWORD PTR [rip+0x3308]        # 4044f8 <aim_kernel+0x24d8>
 vmulsd xmm0,xmm0,QWORD PTR [rip+0x3308]        # 404500 <aim_kernel+0x24e0>
 leave  
 lea    rsp,[r10-0x8]
 vcvtsd2ss xmm0,xmm0,xmm0
 ret    
 cs nop WORD PTR [rax+rax*1+0x0]
 nop    DWORD PTR [rax+0x0]
