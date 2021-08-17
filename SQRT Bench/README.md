# SQRT Benchmark
using different compiler flags

.asm = x86-64 gcc 11.2

No optimisation benchmarks:
```
FPU:
3 Seconds of Executions: 102527563
1,000,000 Exections Microseconds: 6220

Intrinsics:
3 Seconds of Executions: 108612628
1,000,000 Exections Microseconds: 8697
```

Ofast benchmarks:
```
FPU:
3 Seconds of Executions: 189666144
1,000,000 Exections Microseconds: 5084

Intrinsics:
3 Seconds of Executions: 187708726
1,000,000 Exections Microseconds: 4669
```
