#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("pid: %d\n", (int) getpid());
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
	}else if(rc == 0) {
		printf("Fork succeed! I'm a child. Process id: %d\n", (int) getpid());
		close(STDOUT_FILENO);
		open("./p4.out", O_CREAT|O_WRONLY|O_TRUNC|S_IRWXU);
		char *args[3];
		args[0] = strdup("wc");
		args[1] = strdup("p3.c");
		args[2] = NULL;
		execvp(args[0], args);

	}else {
		int wc = wait(NULL);
		printf("I'm parent of %d. Wait id: %d; Process id:  %d\n", wc, rc, (int) getpid());
	}

	return 0;	
}
