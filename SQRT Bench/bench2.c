#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <xmmintrin.h>

static inline uint32_t rdtsc(void)
{
    uint32_t a = 0;
    asm volatile( "rdtsc" :"=a"(a) ::"edx" );
    return a;
}

static inline float isqrt(float f)
{
    return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(f)));
}

uint64_t microtime()
{
	struct timeval tv;
	struct timezone tz;
	memset(&tz, 0, sizeof(struct timezone));
	gettimeofday(&tv, &tz);
	return 1000000 * tv.tv_sec + tv.tv_usec;
}

void ST1()
{
    float ret = 0;

    // fpu
    uint64_t st = microtime();
    uint64_t count = 0;
    float iv = 0;
    while(microtime()-st < 3000000)
    {
        ret = 1 / sqrt(iv);
        count++;
        iv += 0.1f;
    }
    printf("FPU Executions:  %lu per microsecond\n", count / 3000000);
    
    // intrinsics
    st = microtime();
    count = 0;
    iv = 0;
    while(microtime()-st < 3000000)
    {
        ret = isqrt(iv);
        count++;
        iv += 0.1f;
    }
    printf("SIMD Executions: %lu per microsecond\n", count / 3000000);
}

void ST2()
{
    float ret = 0;
    float iv = 63;

    // fpu
    uint32_t st = rdtsc();
    ret = 1 / sqrt(iv);
    printf("FPU Cycles:  %u\n", rdtsc()-st);
    
    // intrinsics
    iv = 63;
    st = rdtsc();
    ret = isqrt(iv);
    printf("SIMD Cycles: %u\n", rdtsc()-st);
}

int main()
{
    ST1();
    ST2();

    return 0;
}
