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
  pthread_t *threadP,*threadC;

  printf("\nNumber of Producers: ");
  scanf("%d",&sizeP);

  printf("Number of Consumers: ");
  scanf("%d",&sizeC);
  printf("\n");

  threadP=(pthread_t*)malloc(sizeof(pthread_t)*sizeP);
  threadC=(pthread_t*)malloc(sizeof(pthread_t)*sizeC);
  int pno[sizeP],cno[sizeC];

  full=sem_open("/fullSem", O_CREAT, 0644, 0);
  empty=sem_open("/emptySem", O_CREAT, 0644, BufferSize);
  mutex=sem_open("/mutexSem", O_CREAT, 0644, 0);

  for(i=0;i<sizeP;i++) {
    pno[i]=i+1;
    res=pthread_create(&threadP[i], NULL, producer, &pno[i]);
  }
  for(i=0;i<sizeC;i++) {
    cno[i]=i+1;
    res=pthread_create(&threadC[i], NULL, consumer, &cno[i]);
  }
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

    buffer[in]=item%100;
    int pos=in;
    in=(in+1)%BufferSize;

    printf("Thread ID: %d. Producer: %d",(int)pthread_self()%100,*(int*)arg);
    printf("\nProduced item %d at %d position\nBuffer:[ ",item%100,pos);

    for(int i=0;i<BufferSize;i++) {
      printf("%d ",buffer[i]);
    }
    printf("]\n\n");

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
    int pos=out;
    out=(out+1)%BufferSize;

    printf("Thread ID: %d. Consumer: %d",(int)pthread_self()%100,*(int*)arg);
    printf("\nConsuming item %d from %d position\nBuffer:[ ",item,pos);

    for(int i=0;i<BufferSize;i++) {
      printf("%d ",buffer[i]);
    }
    printf("]->[ ");

    buffer[pos]=0;
    for(int i=0;i<BufferSize;i++) {
      printf("%d ",buffer[i]);
    printf("]\n\n");
    }

    sem_post(mutex);
    sem_post(empty);
    sleep(3);
  }
  pthread_exit(NULL);
}
