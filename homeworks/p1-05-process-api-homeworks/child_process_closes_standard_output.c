#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../libs/common.h"

int main(int argc, char *argv[]) {
	int parent_pid = getpid();
	printf("Parent process id: %d\n", parent_pid);
	int child_pid = fork();
	switch(child_pid) {
		case -1:
			printf("Child process creation failed.\n");
			break;
		case 0:
			printf("Child process created: %d\n", (int) getpid());
			close(STDOUT_FILENO);
			printf("This is a test!");
			break;
		default:
			 printf("Parent process finished.\n");

	}

	return 0;
}
