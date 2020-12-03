#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>

int main() {

  int source, target;
  char source_file[25], target_file[25], fileContent[100];

  printf("Enter Source Filename: ");
  scanf("%s",source_file);

  printf("Enter Target Filename: ");
  scanf("%s",target_file);

  source = open(source_file, O_RDONLY);
  target = open(target_file, O_WRONLY);

  int x = read(source, (char*)fileContent, 50);
  write(target, (char *)fileContent, x);

  close(source);
  close(target);
}
