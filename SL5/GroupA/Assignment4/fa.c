#include <stdio.h>
#include <string.h>

int main() {

  FILE *fptr;
  char line[50];
  int state, i;

  fptr = fopen("Code.cpp", "r");
  while(fgets(line, 50, fptr) != NULL) {

    state = 0;
    if(((int)line[0] >= 65 && (int)line[0] <= 90) || ((int)line[0] >= 97 && (int)line[0] <= 122)) {
      state = 1;
    }
    else {
      state = -1;
    }

    if(state == 1) {
      for(i = 1; i < strlen(line); i++) {
        if(!(((int)line[i] >= 65 && (int)line[i] <= 90) || ((int)line[i] >= 97 && (int)line[i] <= 122) || ((int)line[i] >= 48 && (int)line[i] <= 57)|| (char)line[i] == ' ' || (char)line[i] == ',') ) {
          if((char)line[i] == ';') {
            state = 2;
            break;
          }
          state = -1;
          break;
        }
      }
    }
    if(state == -1) {
      break;
    }
  }

  if(state == -1) {
    printf("Rejected\n");
  }
  else {
    printf("Accepted\n");
  }

  fclose(fptr);

  return 0;
}
