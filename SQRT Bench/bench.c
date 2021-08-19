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

float rndFloat() // forces the -Ofast mode to produce code containing sqrt
{
    float ret = 0;
    int f = open("/dev/urandom", O_RDONLY | O_CLOEXEC);
    read(f, &ret, sizeof(float));
    close(f);
    return ret;
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
    setlocale(LC_NUMERIC, "");
    srand(8008135);
    float ret = 0;


    // fpu

    printf("FPU:\n");

    uint64_t st = microtime();
    uint64_t count = 0;
    while(microtime()-st < 3000000)
    {
        ret += 1 / sqrt(rndFloat());
        count++;
    }
    printf("3 Seconds of Executions: %'lu\n", count);
    
    st = microtime();
    for(int i = 0; i < 1000000; i++)
        ret += 1 / sqrt(rndFloat());
    printf("1,000,000 Exections Microseconds: %'lu\n", microtime()-st);

    
    // intrinsics

    printf("\nIntrinsics:\n");

    st = microtime();
    count = 0;
    while(microtime()-st < 3000000)
    {
        ret += rsqrtss(rndFloat());
        count++;
    }
    printf("3 Seconds of Executions: %'lu\n", count);
    
    st = microtime();
    for(int i = 0; i < 1000000; i++)
        ret += rsqrtss(rndFloat());
    printf("1,000,000 Exections Microseconds: %'lu\n", microtime()-st);


    printf("\n%.0f\n", ret); // forces the -Ofast mode to produce code containing sqrt

    return 0;
}
