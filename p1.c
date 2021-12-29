#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("pid: %d\n", (int) getpid());
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
	}else if(rc == 0) {
		printf("Fork succeed! I'm a child. Process id: %d\n", (int) getpid());
	}else {
		printf("I'm parent of %d. Process id:  %d\n", rc, (int) getpid());
	}

	return 0;	
}
