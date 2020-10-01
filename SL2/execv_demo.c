#include<stdio.h>
#include<unistd.h>

int main() {

	printf("I am in execv-demo.c\n");
	printf("PID of execv-demo is %d\n", getpid());
	char *args[] = {"./hello", NULL};
	execv(args[0], args);
	printf("Coming back to execv-demo.c");	//This will not be executed
	return 0;
}
