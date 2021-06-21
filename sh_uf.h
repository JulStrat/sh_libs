/*
 * ISC License
 * 
 * Copyright (c) 2021, Ioulianos Kakoulidis
 * 
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR 
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE. 
 */

/*
 * indent options: -orig -nut -nbc -di1 
 */

/**
 * @file    sh_uf.h
 * @brief   Union find.
 * @author  Ioulianos Kakoulidis
 */

#ifndef SH_UF_H
#define SH_UF_H

typedef size_t *UNION_FIND;

#ifdef __cplusplus
extern "C" {
#endif

    UNION_FIND uf_create(size_t size);

    int uf_union(UNION_FIND uf, size_t x, size_t y);

    int uf_connected(UNION_FIND uf, size_t x, size_t y);

    size_t uf_find(UNION_FIND uf, size_t x);

    void uf_free(UNION_FIND uf);

#ifdef __cplusplus
}
#endif
#ifdef SH_UF_IMPLEMENTATION_H
#include <stdlib.h>
#include <string.h>
UNION_FIND
uf_create(size_t size)
{
    UNION_FIND uf;
    size_t i;

    uf = malloc(sizeof(size_t) * size);
    for (i = 0; i < size; i++)
        uf[i] = i;

    return uf;
}

int
uf_union(UNION_FIND uf, size_t x, size_t y)
{
    size_t t;

    while (uf[x] != uf[y]) {
        if (uf[x] < uf[y]) {
            t = x;
            x = y;
            y = t;
        }
        if (uf[y] == y) {
            uf[y] = uf[x];
            return 1;
        }
        t = uf[y];
        uf[y] = uf[x];
        y = t;
    }

    return 0;
}

int
uf_connected(UNION_FIND uf, size_t x, size_t y)
{
    size_t t;

    while (uf[x] != uf[y]) {
        if (uf[x] < uf[y]) {
            t = x;
            x = y;
            y = t;
        }
        if (uf[y] == y) {
            return 0;
        }
        t = uf[y];
        uf[y] = uf[t];
        y = t;
    }

    return 1;
}

size_t
uf_find(UNION_FIND uf, size_t x)
{
    size_t p;

    while (uf[x] != x) {
        p = uf[x];
        uf[x] = uf[p];
        x = p;
    }

    return x;
}

void
uf_free(UNION_FIND uf)
{
    free(uf);
}

#endif
#endif
