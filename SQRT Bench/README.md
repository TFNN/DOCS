# SQRT Benchmark
using different compiler flags

.asm = x86-64 gcc 11.2

No optimisation benchmarks:
```
./reg
FPU:
3 Seconds of Executions: 1,733,999
1,000,000 Exections Microseconds: 1,671,917

Intrinsics:
3 Seconds of Executions: 1,773,704
1,000,000 Exections Microseconds: 1,703,873

./reg2
FPU Executions:  1,763,217
SIMD Executions: 1,757,952

FPU Cycles:  5,388
SIMD Cycles: 4,510
```

-Ofast benchmarks: _(both are optimised to rsqrtss so all this shows is the bench error flux)_
```
./ofast
FPU:
3 Seconds of Executions: 1,735,649
1,000,000 Exections Microseconds: 1,734,337

Intrinsics:
3 Seconds of Executions: 1,761,141
1,000,000 Exections Microseconds: 1,701,034

./ofast2
FPU Executions:  1,768,106
SIMD Executions: 1,763,336

FPU Cycles:  4,701
SIMD Cycles: 4,927
```








