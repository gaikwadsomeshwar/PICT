#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *reader(void *arg);
void *writer(void *arg);

sem_t *resource;
pthread_mutex_t rmutex;
int readcount;

int main() {

  int res,i,sizeR,sizeW,data;
  pthread_t *threadR,*threadW;

  printf("\nData: ");
  scanf("%d",&data);

  //Accepting Number of Readers and Writers
  printf("Number of Readers: ");
  scanf("%d",&sizeR);

  printf("Number of Writers: ");
  scanf("%d",&sizeW);
  printf("\n");

  threadR=(pthread_t*)malloc(sizeof(pthread_t)*sizeR);
  threadW=(pthread_t*)malloc(sizeof(pthread_t)*sizeW);

  //Creating semaphores
  resource=sem_open("/resource", O_CREAT, 0644, 1);
  pthread_mutex_init(&rmutex, NULL);
  readcount=0;

  //Function Calls
  for(i=0;i<sizeR;i++) {
    res=pthread_create(&threadR[i], NULL, reader, &data);
  }
  for(i=0;i<sizeW;i++) {
    res=pthread_create(&threadW[i], NULL, writer, &data);
  }
  for(i=0;i<sizeR;i++)
    res=pthread_join(threadR[i], NULL);
  for(i=0;i<sizeW;i++)
    res=pthread_join(threadW[i], NULL);

  //destroying the semaphores
  sem_close(resource);
  pthread_mutex_destroy(&rmutex);

  exit(EXIT_SUCCESS);
}

void *reader(void *arg) {

  //<Enter Critical Section>
  pthread_mutex_lock(&rmutex);
  readcount++;
  if(readcount==1) {
    sem_wait(resource);
  }
  //<Exit Critical Section>
  pthread_mutex_unlock(&rmutex);

  //Reading
  printf("\nThread ID: %d. Reading data as: %d\n",(int)pthread_self()%100,*(int*)arg);

  //<Enter Critical Section>
  pthread_mutex_lock(&rmutex);
  readcount--;
  if(readcount==0) {
    sem_post(resource);
  }
  //<Exit Critical Section>
  pthread_mutex_unlock(&rmutex);
  pthread_exit(NULL);
}

void *writer(void *arg) {

  //<Enter Critical Section>
  sem_wait(resource);

  //Reading
  printf("\nThread ID : %d. Data is: %d\n",(int)pthread_self()%100,*(int*)arg);
  *(int*)arg+=2;
  printf("Writing data as: %d\n",*(int*)arg);

  //<Exit Critical Section>
  sem_post(resource);
  pthread_exit(NULL);
}
