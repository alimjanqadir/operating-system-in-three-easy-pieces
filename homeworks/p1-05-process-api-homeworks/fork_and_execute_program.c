#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int result = fork();

	switch(result) {
		case 0:
			printf("Child process: %d\n", (int) getpid());
			char *argv[3];
			argv[0] = "ls";
			argv[1] = ".";
			argv[2] = NULL;
			execv("/bin/ls", argv);
			break;
		case -1:
			printf("Error\n");
			exit(1);
			break;
		default:
			printf("Parent %d, child %d\n", (int) getpid(), result);

	}

	getchar();
	return 0;
}
