#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

  pid_t pid;
  printf("fork program starting\n");
  pid = fork();

  switch(pid) {

  case -1: perror("fork failed\n");
           exit(1);

  case 0: printf("This is the child\n");
          printf("\nPID: %d PPID: %d\n\n", getpid(),getppid());
          printf("sleeping\n\n");
          sleep(10);
          printf("\nPID: %d PPID: %d\n\n", getpid(),getppid());
          system("ps -elf");
          break;

  default: printf("This is the parent\n");
           printf("PID: %d\n", getpid());
           break;
  }
  exit(1);
}
