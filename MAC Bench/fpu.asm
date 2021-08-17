processModel(float const*):
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x20
 mov    QWORD PTR [rbp-0x18],rdi
 pxor   xmm0,xmm0
 movss  DWORD PTR [rbp-0x4],xmm0
 mov    DWORD PTR [rbp-0x8],0x0
 jmp    4011ba <processModel(float const*)+0x94>
 cmp    DWORD PTR [rbp-0x8],0x930
 jne    40117e <processModel(float const*)+0x58>
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 movss  xmm0,DWORD PTR [rax*4+0x402020]
 movss  xmm1,DWORD PTR [rbp-0x4]
 addss  xmm0,xmm1
 movss  DWORD PTR [rbp-0x4],xmm0
 mov    eax,DWORD PTR [rbp-0x4]
 movd   xmm0,eax
 call   40121f <std::tanh(float)>
 movd   eax,xmm0
 mov    DWORD PTR [rbp-0x4],eax
 jmp    4011b6 <processModel(float const*)+0x90>
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 lea    rdx,[rax*4+0x0]
 mov    rax,QWORD PTR [rbp-0x18]
 add    rax,rdx
 movss  xmm1,DWORD PTR [rax]
 mov    eax,DWORD PTR [rbp-0x8]
 cdqe   
 movss  xmm0,DWORD PTR [rax*4+0x402020]
 mulss  xmm0,xmm1
 movss  xmm1,DWORD PTR [rbp-0x4]
 addss  xmm0,xmm1
 movss  DWORD PTR [rbp-0x4],xmm0
 add    DWORD PTR [rbp-0x8],0x1
 cmp    DWORD PTR [rbp-0x8],0x930
 jle    401144 <processModel(float const*)+0x1e>
 pxor   xmm1,xmm1
 cvtss2sd xmm1,DWORD PTR [rbp-0x4]
 movsd  xmm0,QWORD PTR [rip+0x3314]        # 4044e8 <aim_kernel+0x24c8>
 mulsd  xmm0,xmm1
 movsd  xmm1,QWORD PTR [rip+0x3310]        # 4044f0 <aim_kernel+0x24d0>
 subsd  xmm0,xmm1
 cvtsd2ss xmm0,xmm0
 movss  DWORD PTR [rbp-0xc],xmm0
 pxor   xmm1,xmm1
 cvtss2sd xmm1,DWORD PTR [rbp-0xc]
 movsd  xmm0,QWORD PTR [rip+0x32fa]        # 4044f8 <aim_kernel+0x24d8>
 addsd  xmm1,xmm0
 movsd  xmm0,QWORD PTR [rip+0x32f6]        # 404500 <aim_kernel+0x24e0>
 mulsd  xmm0,xmm1
 cvtsd2ss xmm0,xmm0
 leave  
 ret      
std::tanh(float):
 push   rbp
 mov    rbp,rsp
 sub    rsp,0x10
 movss  DWORD PTR [rbp-0x4],xmm0
 mov    eax,DWORD PTR [rbp-0x4]
 movd   xmm0,eax
 call   401030 <tanhf@plt>
 leave  
 ret    
 nop    WORD PTR [rax+rax*1+0x0]
