#include <stdio.h>
#include <assert.h>

#define SH_UF_IMPLEMENTATION_H
#include "sh_uf.h"

int
main(int argc, char *argv[]) {
	FILE *ufdata;
	UNION_FIND uf;
	unsigned long sz, cn, res;
	unsigned long x, y;
	unsigned long i, r = 0;
	
	ufdata = fopen(argv[1], "r");
	fscanf(ufdata, "%lu %lu %lu", &sz, &cn, &res);
	printf("size: %lu, connections: %lu, expected: %lu\n", sz, cn, res);
	uf = uf_create(sz);
	
	while (cn--) {
		fscanf(ufdata, "%lu %lu", &x, &y);
		uf_union(uf, x, y);
	}
	fclose(ufdata);	
	for (i = 0; i < sz; i++) {
		if (uf[i] == i) r++;
	}
	printf("expected: %lu, result: %lu\n", res, r);
	assert(r == res);
	uf_free(uf);
}
