// with -Ofast enabled, both methods will optimise to rsqrtss
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
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


// adapted from ogre3d asm_math.h
// https://www.flipcode.com/archives/07-15-2002.shtml
// https://www.cs.cmu.edu/afs/andrew/scs/cs/oldfiles/15-494-sp09/dst/A/sw/ogre-1.6.4/OgreMain/include/asm_math.h
// https://gist.github.com/mrbid/51ed2963c88981452a5f87a3b072f8fb#file-random_float_bench-c-L71
float rndFloat(const __int64_t seed) // forces the -Ofast mode to produce code containing sqrt
{
    static __int64_t q = 8008135;
    if(seed != 0)
        q = seed;

    __m64 mm0 = _mm_cvtsi64_m64(q);
    __m64 mm1 = _m_pshufw(mm0, 0x1E);
    mm0 = _mm_add_pi32(mm0, mm1);
    q = _m_to_int64(mm0);

    _m_empty();
    return q;
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
    rndFloat(time(0));
    setlocale(LC_NUMERIC, "");
    ST1();
    ST2();
    return 0;
}
