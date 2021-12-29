#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("pid: %d\n", (int) getpid());
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
	}else if(rc == 0) {

		printf("Fork succeed! I'm a child. Process id: %d\n", (int) getpid());
	}else {
		int wc = wait(NULL);
		printf("I'm parent of %d. Wait id: %d; Process id:  %d\n", wc, rc, (int) getpid());
	}

	return 0;	
}
