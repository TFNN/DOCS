gcc bench.c -lm -o fpu
gcc bench.c -Ofast -lm -o ofast
gcc bench.c -Ofast -mavx -mfma -lm -o ofast_fma
gcc bench.c -Ofast -mavx -mfma4 -lm -o ofast_fma4
