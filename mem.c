#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libs/common.h"

int main(int argc, char *argv[]) {
	int *p = malloc(sizeof(int));
	assert(p != NULL);
	printf("%d memory address of p: %08x\n", getpid(),(unsigned int) p);

	*p = 0;
	while(1) {
		Spin(1);
		*p = *p + 1;
		printf("%d p: %d\n", getpid(), *p);
	}

	return 0;
}
