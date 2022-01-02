#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("pid: %d\n", (int) getpid());
	int x = 0;
	int rc = fork();
	x = 100;
	if(rc < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
	}else if(rc == 0) {
		printf("Fork succeed. In child, pid: %d.\n", getpid());
		printf("Value of x: %d.\n", x);
		x = 200;
		printf("Value of x: %d after change.\n", x);
	}else {
		int wc = wait(NULL);
		printf("Fork succeed. In parent, parent pid: %d, child pid: %d.\n ",
				(int) getpid(), rc);
		printf("Value of x: %d\n", x);
		x = -1;
	}

	return 0;
}
