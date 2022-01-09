#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	printf("pid: %d\n", (int) getpid());
	int fd = open("temp.rtf",O_CREAT | O_RDWR | O_TRUNC | S_IRWXU, 0755);
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "Fork failed.\n");
		exit(1);
	}else if(rc == 0) {
		printf("Fork succeed. In child, pid: %d.\n", getpid());
		write(fd, "child", 4);
		close(fd);
		printf("File closed. pid: %d\n", (int)getpid());
	}else {
		printf("Fork succeed. In parent, parent pid: %d, child pid: %d.\n ",
				(int) getpid(), rc);
		write(fd, "parent", 4);
		close(fd);
		printf("File closed. pid: %d\n", (int)getpid());
	}

	return 0;
}
