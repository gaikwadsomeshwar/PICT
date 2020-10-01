#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BufferSize 5

void *producer(void *arg);
void *consumer(void *arg);

sem_t *empty;
sem_t *full;
sem_t *mutex;
int in=0;
int out=0;
int buffer[BufferSize];

int main() {

  int res,i,sizeP,sizeC;

  printf("\nNumber of Producers: ");
  scanf("%d",&sizeP);

  printf("\nNumber of Consumers: ");
  scanf("%d",&sizeC);
  printf("\n");

  pthread_t threadP[sizeP],threadC[sizeC];

  full=sem_open("/fullSem", O_CREAT, 0644, 0);
  empty=sem_open("/emptySem", O_CREAT, 0644, BufferSize);
  mutex=sem_open("/mutexSem", O_CREAT, 0644, 1);

  for(i=0;i<sizeP;i++)
    res=pthread_create(&threadP[i], NULL, producer, NULL);
  for(i=0;i<sizeC;i++)
    res=pthread_create(&threadC[i], NULL, consumer, NULL);
  for(i=0;i<sizeP;i++)
    res=pthread_join(threadP[i], NULL);
  for(i=0;i<sizeC;i++)
    res=pthread_join(threadC[i], NULL);

  sem_unlink("/emptySem");
  sem_unlink("/fullSem");
  sem_unlink("/mutexSem");
  exit(EXIT_SUCCESS);
}

void *producer(void *arg) {

  while(1) {
    int item=rand();
    sem_wait(empty);
    sem_wait(mutex);
    buffer[in]=item%10;
    in=(in+1)%BufferSize;

    printf("[ ");
    for(int i=0;i<BufferSize;i++)
      printf("%d ",buffer[i]);
    printf("]");
    printf("\nProduced: %d\n\n",item%10);

    sem_post(mutex);
    sem_post(full);
    sleep(3);
  }
  pthread_exit(NULL);
}

void *consumer(void *arg) {

  while(1) {
    sem_wait(full);
    sem_wait(mutex);
    int item=buffer[out];
    out=(out+1)%BufferSize;

    printf("[ ");
    for(int i=0;i<BufferSize;i++)
      printf("%d ",buffer[i]);
    printf("]");
    printf("\nConsuming: %d\n\n",item);

    sem_post(mutex);
    sem_post(empty);
    sleep(3);
  }
  pthread_exit(NULL);
}
