#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <locale.h>
#include <xmmintrin.h>

#pragma GCC diagnostic ignored "-Wunused-result"

static inline float rsqrtss(float f)
{
    return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(f)));
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
    rndFloat(time(0));
    setlocale(LC_NUMERIC, "");
    float ret = 0;


    // fpu

    printf("FPU:\n");

    uint64_t st = microtime();
    uint64_t count = 0;
    while(microtime()-st < 3000000)
    {
        ret += 1 / sqrt(rndFloat(0));
        count++;
    }
    printf("3 Seconds of Executions: %'lu\n", count);
    
    st = microtime();
    for(int i = 0; i < 1000000; i++)
        ret += 1 / sqrt(rndFloat(0));
    printf("1,000,000 Exections Microseconds: %'lu\n", microtime()-st);

    
    // intrinsics

    printf("\nIntrinsics:\n");

    st = microtime();
    count = 0;
    while(microtime()-st < 3000000)
    {
        ret += rsqrtss(rndFloat(0));
        count++;
    }
    printf("3 Seconds of Executions: %'lu\n", count);
    
    st = microtime();
    for(int i = 0; i < 1000000; i++)
        ret += rsqrtss(rndFloat(0));
    printf("1,000,000 Exections Microseconds: %'lu\n", microtime()-st);


    printf("\n%.0f\n", ret); // forces the -Ofast mode to produce code containing sqrt

    return 0;
}
