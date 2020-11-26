#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  int file_pipes1[2]; //Parent Pipe
  int file_pipes2[2]; //Child Pipe
  int pid,count=0;
  char fileContent[999],filename[]="record.txt",msg[]="This is a new message.";
  FILE *fptr;
  pipe(file_pipes1); //One Way Communication from Parent to Child
  pipe(file_pipes2); //One Way Communication from Child to Parent

  pid=fork();

  if(pid==0) { //Child Process

    close(file_pipes1[1]); // Close the unwanted write side of parent
    close(file_pipes2[0]); // Close the unwanted read side of child
    printf("\n============================================\n");

    fptr=fopen("Record.txt","a");
    fprintf(fptr,"%s\n",msg);
    fclose(fptr);

    int x=write(file_pipes2[1],msg,sizeof(msg));
    printf("\nIn Child  (id %d): Writing to Pipe 2\n\n%s\n(Number of characters written to record.txt: %d)\n",getpid(),msg,x);
    close(file_pipes2[1]);
    printf("\n============================================\n");

    read(file_pipes1[0],fileContent,sizeof(fileContent));
    sleep(3);
    printf("\n============================================\n");
    printf("\nIn Child  (id %d): Reading from Pipe 1\n\n%s\n",getpid(),fileContent);
    close(file_pipes2[0]);

  }
  else { //Parent Process

    close(file_pipes1[0]); // Close the unwanted read side of parent
    close(file_pipes2[1]); // Close the unwanted write side child

    //Reading from child pipe
    read(file_pipes2[0],fileContent,sizeof(fileContent));
    printf("\nIn Parent (id %d): Reading from Pipe 2\n\n%s\n",getpid(),fileContent);
    printf("\n============================================\n");

    fptr=fopen("Record.txt","r");
    while(!feof(fptr)) {
			fileContent[count++] = fgetc(fptr);
		}
    fclose(fptr);
    close(file_pipes2[0]); //Close the unwanted read side of child

    //writing to parent pipe
    write(file_pipes1[1],fileContent,sizeof(fileContent));
    printf("\nIn Parent (id %d): Writing to Pipe 1\n\n%s\n",getpid(),fileContent);
    close(file_pipes1[1]); // Close the unwanted write side of parent
    sleep(3);
    printf("\n============================================\n");
  }
  return 0;
}
