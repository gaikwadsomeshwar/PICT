#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  int file_pipes1[2],file_pipes2[2],pid;
  const char data1[]="Hello Person1",data2[]="Hello Person2";
  char buffer[20];
  pipe(file_pipes1);
  pipe(file_pipes2);
  pid=fork();

  if(pid==0) { //Child Process
    close(file_pipes1[1]); // Close the unwanted pipe1 write side
    close(file_pipes2[0]); // Close the unwanted pipe2 read side
    read(file_pipes1[0],buffer,sizeof(buffer));
    printf("In Child : Reading from pipe 1 : Message is %s\n\n",buffer);
    printf("In Child : Writing to pipe   2 : Message is %s\n",data2);
    write(file_pipes2[1],data2,sizeof(data2));
  }
  else { //Parent Process
    close(file_pipes1[0]); // Close the unwanted pipe1 read side
    close(file_pipes2[1]); // Close the unwanted pipe2 write side
    printf("\nIn Parent: Writing to pipe   1 : Message is %s\n",data1);
    write(file_pipes1[1],data1,sizeof(data1));
    read(file_pipes2[0],buffer,sizeof(buffer));
    printf("In Parent: Reading from pipe 2 : Message is %s\n\n",buffer);
  }
  return 0;
}
