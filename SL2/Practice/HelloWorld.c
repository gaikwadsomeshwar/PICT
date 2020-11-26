#include<stdio.h>
#include<unistd.h>

int main() {

  printf("Hello World\n");
  printf("PID  of HelloWorld.c is: %d\n",getpid());
  printf("PPID of HelloWorld.c is: %d\n",getppid());
}
