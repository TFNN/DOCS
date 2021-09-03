# SQRT Benchmark
using different compiler flags

.asm = x86-64 gcc 11.2

No optimisation benchmarks:
```
./reg
FPU:
16 Seconds of Executions: 473,881,610
16,000,000 Exections Microseconds: 233,742

Intrinsics:
16 Seconds of Executions: 528,473,352
16,000,000 Exections Microseconds: 122,039

./reg2
FPU Executions:  475,313,790
SIMD Executions: 557,850,357

FPU Cycles:  3,508
SIMD Cycles: 42
```

-Ofast benchmarks:
```
./ofast
FPU:
16 Seconds of Executions: 728,973,339
16,000,000 Exections Microseconds: 49,976

Intrinsics:
16 Seconds of Executions: 1,098,945,234
16,000,000 Exections Microseconds: 38,670

./ofast2
FPU Executions:  730,852,847
SIMD Executions: 1,115,006,760

FPU Cycles:  22
SIMD Cycles: 20
```
