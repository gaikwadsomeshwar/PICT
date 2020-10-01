#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

  pid_t pid;

  pid = fork();

  if(pid==0) {

      printf("\n======In Child======\n");
      printf("I am child %d, my parent is %d\n\n",getpid(),getppid());

  }

  else if(pid>=1) {

    printf("\n======In Parent======\n");
    printf("\nI am Parent %d\n",getpid());
    printf("I am leaving now. Bye\n\n");
    //printf("I am sleeping now\n");
    //sleep(10);
    //printf("I am child %d, my parent is %d\n\n",getpid(),getppid());
    //system("ps -axl| grep a.out");
  }
  exit(0);
}
