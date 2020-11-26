#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  int file_pipes1[2]; //Parent Pipe
  int file_pipes2[2]; //Child Pipe
  int pid,count=0;
  char filename[]="record.txt",msg1[]="This is message1.\n",msg2[]="This is message2.\n";
  FILE *fptr;
  pipe(file_pipes1); //One Way Communication from Parent to Child
  pipe(file_pipes2); //One Way Communication from Child to Parent

  file_pipes1[0]=open(filename,O_RDONLY);
  file_pipes1[1]=open(filename,O_WRONLY);
  file_pipes2[0]=open(filename,O_RDONLY);
  file_pipes2[1]=open(filename,O_WRONLY);

  pid=fork();

  if(pid==0) { //Child Process

    close(file_pipes1[1]); // Close the unwanted write side of parent
    close(file_pipes2[0]); // Close the unwanted read side of child

    read(file_pipes1[0],msg1,sizeof(msg1));
    printf("\nIn Child  (id %d): Reading from Pipe 1\n\n%s\n",getpid(),msg1);

    write(file_pipes2[1],msg2,sizeof(msg2));
    printf("\nIn Child  (id %d): Writing to Pipe 2\n\n%s\n",getpid(),msg2);
  }
  else { //Parent Process

    close(file_pipes1[0]); // Close the unwanted read side of parent
    close(file_pipes2[1]); // Close the unwanted write side child

    //writing to parent pipe
    write(file_pipes1[1],msg1,sizeof(msg1));
    printf("\nIn Parent (id %d): Writing to Pipe 1\n\n%s\n",getpid(),msg1);
    close(file_pipes1[1]); // Close the unwanted write side of parent
    sleep(2);

    //Reading from child pipe
    read(file_pipes2[0],msg2,sizeof(msg2));
    printf("\nIn Parent (id %d): Reading from Pipe 2\n\n%s\n",getpid(),msg2);
  }
  return 0;
}
