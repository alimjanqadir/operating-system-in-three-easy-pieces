#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../../libs/common.h"

int main(int argc, char *argv[]) {
	int parent_pid = getpid();
	printf("Process id: %d\n", parent_pid);
	int child_pid = fork();
	switch(child_pid) {
		case -1:
			printf("Process creation failed.\n");
			break;
		case 0:
			printf("Child process created: %d\n", (int) getpid());
			printf("Child is waiting: \n");
			int wr  = waitpid(parent_pid, NULL, 0);
			printf("wait result: %d\n", wr);
			printf("Child process finished.\n");
			break;
		default:
			Spin(5);
			// printf("Parent is waiting: \n");
			// int result  = wait(NULL);
			// printf("wait result: %d\n", result);
			 printf("Parent process finished.\n");

	}

	return 0;
}
