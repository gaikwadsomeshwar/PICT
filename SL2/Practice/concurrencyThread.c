#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *myturn(void *arg) {

  for(int i=1;i<4;i++) {
    printf("My Turn\n\n");
    sleep(2);
  }
  pthread_exit(NULL);
}

void *yourturn(void *arg) {

  for(int i=1;i<5;i++) {
    printf("Your Turn\n\n");
    sleep(2);
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv) {

  pthread_t thread1,thread2;

  pthread_create(&thread1,NULL,myturn,NULL);
  pthread_create(&thread2,NULL,yourturn,NULL);
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);

  printf("\n======Back In Main======\n\n");

  return 0;
}
