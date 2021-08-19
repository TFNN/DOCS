// with -Ofast enabled, both methods will optimise to rsqrtss
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <locale.h>
#include <xmmintrin.h>

#pragma GCC diagnostic ignored "-Wunused-result"

static inline float rsqrtss(float f)
{
    return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(f)));
}

static inline uint32_t rdtsc(void)
{
    uint32_t a = 0;
    asm volatile( "rdtsc" :"=a"(a) ::"edx" );
    return a;
}

uint64_t microtime()
{
    struct timeval tv;
    struct timezone tz;
    memset(&tz, 0, sizeof(struct timezone));
    gettimeofday(&tv, &tz);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

float rndFloat() // forces the -Ofast mode to produce code containing sqrt
{
    float ret = 0;
    int f = open("/dev/urandom", O_RDONLY | O_CLOEXEC);
    read(f, &ret, sizeof(float));
    close(f);
    return ret;
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
        ret += 1 / sqrt(rndFloat());
        count++;
        iv += 0.1f;
    }
    printf("FPU Executions:  %'lu\n", count);
    
    // intrinsics
    st = microtime();
    count = 0;
    iv = 0;
    while(microtime()-st < 3000000)
    {
        ret += rsqrtss(rndFloat());
        count++;
        iv += 0.1f;
    }
    printf("SIMD Executions: %'lu\n", count);

    printf("%.0f\n", ret);  // forces the -Ofast mode to produce code containing sqrt
}

void ST2()
{
    float ret = 0;
    uint32_t et = 0;
    float iv = rndFloat();

    // fpu
    uint32_t st = rdtsc();
    //for(int i = 0; i < 100000; i++)
        ret += 1 / sqrt(rndFloat());
    et = rdtsc()-st;
    printf("FPU Cycles:  %'u\n", et);
    
    // intrinsics
    st = rdtsc();
    //for(int i = 0; i < 100000; i++)
        ret += rsqrtss(rndFloat());
    et = rdtsc()-st;
    printf("SIMD Cycles: %'u\n", et);

    printf("%.0f\n", ret);  // forces the -Ofast mode to produce code containing sqrt
}

int main()
{
    setlocale(LC_NUMERIC, "");
    ST1();
    ST2();
    return 0;
}
