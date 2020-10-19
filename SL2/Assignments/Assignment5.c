#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *reader(void *arg);
void *writer(void *arg);

sem_t *resource;
sem_t *rmutex;
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
  resource=sem_open("/resourceSem", O_CREAT, 0644, 1);
  rmutex=sem_open("/mutexSem", O_CREAT, 0644, 1);
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
  sem_unlink("/resourceSem");
  sem_unlink("/mutexSem");

  exit(EXIT_SUCCESS);
}

void *reader(void *arg) {

  while(1) {

    //<Enter Critical Section>
    sem_wait(rmutex);
    readcount++;
    if(readcount==1) {
      sem_wait(resource);
    }
    //<Exit Critical Section>
    sem_post(rmutex);

    //Reading
    printf("\nThread ID: %d. Reading data as: %d\n",(int)pthread_self()%100,*(int*)arg);

    //<Enter Critical Section>
    sem_wait(rmutex);
    readcount--;
    if(readcount==0) {
      sem_post(resource);
    }
    //<Exit Critical Section>
    sem_post(rmutex);

    sleep(3);
  }
  pthread_exit(NULL);
}

void *writer(void *arg) {

  while(1) {

    //<Enter Critical Section>
    sem_wait(resource);

    //Reading
    printf("\nThread ID: %d. Data is: %d\n",(int)pthread_self()%100,*(int*)arg);
    printf("Enter Data: ");
    scanf("%d",(int*)arg);
    printf("Writing data as: %d",*(int*)arg);

    //<Exit Critical Section>
    sem_post(rmutex);

    sleep(3);
  }
  pthread_exit(NULL);
}
