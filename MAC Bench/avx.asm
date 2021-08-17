-mavx -mfma
processModel(float const*):
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x20
 mov    QWORD PTR [rbp-0x18],rdi
 vxorps xmm0,xmm0,xmm0
 vmovss DWORD PTR [rbp-0x4],xmm0
 mov    DWORD PTR [rbp-0x8],0x0
 jmp    4011ba <processModel(float const*)+0x94>
 cmp    DWORD PTR [rbp-0x8],0x930
 jne    40117e <processModel(float const*)+0x58>
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 vmovss xmm0,DWORD PTR [rax*4+0x402020]
 vmovss xmm1,DWORD PTR [rbp-0x4]
 vaddss xmm0,xmm1,xmm0
 vmovss DWORD PTR [rbp-0x4],xmm0
 mov    eax,DWORD PTR [rbp-0x4]
 vmovd  xmm0,eax
 call   401217 <std::tanh(float)>
 vmovd  eax,xmm0
 mov    DWORD PTR [rbp-0x4],eax
 jmp    4011b6 <processModel(float const*)+0x90>
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 lea    rdx,[rax*4+0x0]
 mov    rax,QWORD PTR [rbp-0x18]
 add    rax,rdx
 vmovss xmm1,DWORD PTR [rax]
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 vmovss xmm0,DWORD PTR [rax*4+0x402020]
 vmulss xmm0,xmm1,xmm0
 vmovss xmm1,DWORD PTR [rbp-0x4]
 vaddss xmm0,xmm1,xmm0
 vmovss DWORD PTR [rbp-0x4],xmm0
 add    DWORD PTR [rbp-0x8],0x1
 cmp    DWORD PTR [rbp-0x8],0x930
 jle    401144 <processModel(float const*)+0x1e>
 vcvtss2sd xmm1,xmm1,DWORD PTR [rbp-0x4]
 vmovsd xmm0,QWORD PTR [rip+0x3318]        # 4044e8 <aim_kernel+0x24c8>
 vmulsd xmm0,xmm1,xmm0
 vmovsd xmm1,QWORD PTR [rip+0x3314]        # 4044f0 <aim_kernel+0x24d0>
 vsubsd xmm0,xmm0,xmm1
 vcvtsd2ss xmm0,xmm0,xmm0
 vmovss DWORD PTR [rbp-0xc],xmm0
 vcvtss2sd xmm1,xmm1,DWORD PTR [rbp-0xc]
 vmovsd xmm0,QWORD PTR [rip+0x3302]        # 4044f8 <aim_kernel+0x24d8>
 vaddsd xmm1,xmm1,xmm0
 vmovsd xmm0,QWORD PTR [rip+0x32fe]        # 404500 <aim_kernel+0x24e0>
 vmulsd xmm0,xmm1,xmm0
 vcvtsd2ss xmm0,xmm0,xmm0
 leave  
 ret      
std::tanh(float):
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x10
 vmovss DWORD PTR [rbp-0x4],xmm0
 mov    eax,DWORD PTR [rbp-0x4]
 vmovd  xmm0,eax
 call   401030 <tanhf@plt>
 leave  
 ret    
 cs nop WORD PTR [rax+rax*1+0x0]
 nop    DWORD PTR [rax+0x0]
