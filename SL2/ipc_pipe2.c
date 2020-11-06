#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  int file_pipes[2],data_pro,pid;
  const char data[]="Hello Person";
  char buffer[20];
  pipe(file_pipes);
  pid=fork();

  if(pid==0) {
    data_pro=write(file_pipes[1],data,strlen(data));
    printf("pid: %d. Wrote %d bytes\n",getpid(),data_pro);
  }
  else {
    data_pro=read(file_pipes[0],buffer,20);
    printf("pid: %d. Read %d bytes: %s\n",getpid(),data_pro,buffer);
  }
  return 0;
}
