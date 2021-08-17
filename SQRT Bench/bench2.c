#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <xmmintrin.h>

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

int main()
{
    srand(8008135);
    float ret = 0;

    // fpu
    uint64_t st = microtime();
    uint64_t count = 0;
    float iv = 0;
    while(microtime()-st < 9000000)
    {
        ret = 1 / sqrt(iv);
        count++;
        iv += 0.1f;
    }
    printf("FPU Executions: %lu\n", count);
    
    // intrinsics
    st = microtime();
    count = 0;
    iv = 0;
    while(microtime()-st < 9000000)
    {
        ret = isqrt(iv);
        count++;
        iv += 0.1f;
    }
    printf("SIMD Executions: %lu\n", count);

    return 0;
}
