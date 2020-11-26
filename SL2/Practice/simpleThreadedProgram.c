#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *arg);
char message[] = "Hello World!";
int run_now = 1;

int main() {

  int res;
  pthread_t a_thread;
  void *thread_result;

  printf("\n==========In main()==========\n\n");
  res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
  if (res != 0) {
    perror("Thread creation failed");
    exit(EXIT_FAILURE);
  }

  printf("Waiting for thread to finish...\n\n");

  int print_count1 = 0;
  while(print_count1++ < 20) {

    if (run_now == 1) {
      printf("\n1 ");
      run_now = 2;
    }
    else {
      sleep(1);
    }
  }

  res = pthread_join(a_thread, &thread_result);
  if (res != 0) {
    perror("Thread join failed");
    exit(EXIT_FAILURE);
  }
  printf("==========Back in main()==========\n\n");
  printf("Thread joined, it returned: \"%s\"\n\n", (char *)thread_result);

  printf("Message now is: \"%s\"\n\n", message);
  exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {

  printf("\n==========In thread_function()==========\n\n");
  printf("thread_function is running. Argument was \"%s\"\n\n", (char *)arg);
  //sleep(3);

  int print_count2 = 0;
  while(print_count2++ < 20) {

    if (run_now == 2) {
      printf("2 ");
      run_now = 1;
    }
    else {
      sleep(1);
    }
  }
  printf("\n\n");
  strcpy(message, "Bye!");
  pthread_exit("Thank you for the CPU time.");
}
