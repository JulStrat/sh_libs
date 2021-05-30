# sh_libs

Single Header ANSI C mini libraries

### sh_karatsuba.h

Polynomial multiplication using Karatsuba algorithm.

```
#include "sh_karatsuba.h"
#include <assert.h>

KARATSUBA(int)
KARATSUBA(double)

#define BENCH_SZ 1024*16
#define TCALLOC(type, x) (type *)(calloc(x, sizeof (type)))

int main(void) {
    int i, j;
    int *ai, *bi, *ci, *expi;
    double *ad, *bd, *cd, *expd;
    
    /* int type */
    ai = TCALLOC(int, BENCH_SZ);
    bi = TCALLOC(int, BENCH_SZ);
    ci = TCALLOC(int, 2*BENCH_SZ-1);
    expi = TCALLOC(int, 2*BENCH_SZ-1);
    for (i = 0; i < BENCH_SZ; i++) {
        ai[i] = rand(); bi[i] = rand();
    }
    for (i = 0; i < BENCH_SZ; i++) {
        for (j = 0; j < BENCH_SZ; j++) {
            expi[i+j] += ai[i] * bi[j];
        }
    }

    karatsuba_int(ai, bi, BENCH_SZ, ci);
    for (i = 0; i < 2*BENCH_SZ-1; i++) {
        assert(expi[i] = ci[i]);
    }

    /* double type */    
    ad = TCALLOC(double, BENCH_SZ);
    bd = TCALLOC(double, BENCH_SZ);
    cd = TCALLOC(double, 2*BENCH_SZ-1);
    expd = TCALLOC(double, 2*BENCH_SZ-1);
    for (i = 0; i < BENCH_SZ; i++) {
        ad[i] = rand()*1.0; bd[i] = rand()*1.0;
    }
    for (i = 0; i < BENCH_SZ; i++) {
        for (j = 0; j < BENCH_SZ; j++) {
            expd[i+j] += ad[i] * bd[j];
        }
    }

    karatsuba_double(ad, bd, BENCH_SZ, cd);
    for (i = 0; i < 2*BENCH_SZ-1; i++) {
        assert(expd[i] = cd[i]);
    }

    return 0;
}
```

### sh_bisect.h

Ordered array bisection algorithms.

```
void *bisect_left(const void *key, const void *arr,
                  size_t el_num, size_t el_size,
                  int (*compare) (const void *, const void *));
```

```
void *bisect_right(const void *key, const void *arr,
                   size_t el_num, size_t el_size,
                   int (*compare) (const void *, const void *));
```