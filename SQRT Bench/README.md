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

No optimisation a few times in a row:
```
./reg2
FPU Executions:  1,759,833
SIMD Executions: 1,752,094

FPU Cycles:  6,558
SIMD Cycles: 4,536

./reg2
FPU Executions:  1,739,897
SIMD Executions: 1,759,603

FPU Cycles:  4,962
SIMD Cycles: 4,301

./reg2
FPU Executions:  1,736,354
SIMD Executions: 1,735,781

FPU Cycles:  8,679
SIMD Cycles: 4,394

./reg2
FPU Executions:  1,741,070
SIMD Executions: 1,734,509

FPU Cycles:  6,201
SIMD Cycles: 4,376

./reg2
FPU Executions:  1,762,834
SIMD Executions: 1,746,352

FPU Cycles:  6,525
SIMD Cycles: 4,767

./reg2
FPU Executions:  1,755,283
SIMD Executions: 1,700,055

FPU Cycles:  7,480
SIMD Cycles: 4,516

./reg2
FPU Executions:  1,718,544
SIMD Executions: 1,678,173

FPU Cycles:  8,026
SIMD Cycles: 4,664
```








