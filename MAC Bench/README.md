# Multiply–accumulate operation benchmark
using different compiler flags

.asm = x86-64 gcc 11.2

Benchmarks:
```
./fpu
3 Seconds of Executions: 608,762
1,000,000 Exections Microseconds: 4,905,539
Cycles: 14,995

./ofast
3 Seconds of Executions: 5,610,024
1,000,000 Exections Microseconds: 477,529
Cycles: 1,442

./ofast_fma
3 Seconds of Executions: 10,496,165
1,000,000 Exections Microseconds: 224,081
Cycles: 765
```
