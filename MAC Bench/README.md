# Multiply–accumulate operation benchmark
using different compiler flags

.asm = x86-64 gcc 11.2

Benchmarks Intel Core i7-1165G7 4700 MHz:
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

./ofast_fma4
FMA4 is not supported on Intel CPUs
```

Benchmarks AMD Ryzen 7 2700X 3700 MHz:
```
./fpu
3 Seconds of Executions: 455,851
1,000,000 Exections Microseconds: 6,540,218
Cycles: 24,050

./ofast
3 Seconds of Executions: 6,667,809
1,000,000 Exections Microseconds: 423,362
Cycles: 1,665

./ofast_fma
3 Seconds of Executions: 7,929,733
1,000,000 Exections Microseconds: 342,391
Cycles: 1,369

./ofast_fma4
3 Seconds of Executions: 8,015,119
1,000,000 Exections Microseconds: 338,027
Cycles: 1,369
```
