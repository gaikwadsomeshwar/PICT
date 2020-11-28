#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int rfile, wfile;

  if(argc!=3) {
    printf("Two files expected\n");
    exit(1);
  }

  rfile = open(argv[1], O_CREAT | O_RDNLY, 0);
  wfile = open(argv[2], O_CREAT | O_WRNLY, 0);


}
