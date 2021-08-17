push    rbp
mov     rbp, rsp
call    rand
mov     edi, eax
call    __gnu_cxx::__enable_if<std::__is_integer<int>::__value, double>::__type std::sqrt<int>(int)
movsd   xmm1, QWORD PTR .LC0[rip]
divsd   xmm1, xmm0
cvttsd2si       eax, xmm1
pop     rbp
ret
