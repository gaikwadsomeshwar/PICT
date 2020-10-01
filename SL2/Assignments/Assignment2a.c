#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

void merge(int arr[], int l, int m, int r) {

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {

  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {

  pid_t pid; //stores the pid

  int *arr,size,ch;

  printf("\nEnter size: ");
  scanf("%d",&size);
  arr=(int*)malloc(sizeof(int)*size);

  printf("\nEnter the numbers: "); //accepting elements
  for(int i=0;i<size;i++) {
    scanf("%d",&arr[i]);
  }

  printf("\n=====Select Option=====\n"); //options
  printf("\n0. Synchronize Parent and Child\n1. Demonstrate Orphan\n2. Demonstrate Zombie\n\nYour Choice: ");
  scanf("%d",&ch);

  pid = fork(); //creating a new process

  if(pid==0) { //child

    printf("\n======In Child======\n\n");
    printf("I am child %d, my parent is %d\n\n",getpid(),getppid());

    printf("Array: ");  //printing original array
    for(int i=0;i<size;i++) {
      printf("%d ",arr[i]);
    }
    printf("\n\n");

    mergeSort(arr,0,size-1); //sorting

    printf("Merge Sorted: ");
    for(int i=0;i<size;i++) {
      printf("%d ",arr[i]);
    }
    printf("\n\n");

    if(ch==0) {
      exit(0);
    }

    else if(ch==1) {  //orphan

      sleep(10);
      printf("\n\nChild %d Becomes Orphan, Adopted by Parent %d\n\n",getpid(),getppid());
      system("ps -al");
      printf("\n");
    }

    else if(ch==2) {
      printf("Child %d Becomes Zombie\n\n",getpid());
    }
  }

  else if(pid>=1) {  //parent

    printf("\n======In Parent======\n\n");

    printf("ID: %d\n\n",getpid());

    printf("Array: ");  //printing original array
    for(int i=0;i<size;i++) {
      printf("%d ",arr[i]);
    }
    printf("\n\n");

    mergeSort(arr,0,size-1); //sorting

    printf("Merge Sorted: ");
    for(int i=0;i<size;i++) {
      printf("%d ",arr[i]);
    }
    printf("\n\n");

    if(ch==0) { //sychronize/smooth communication between parent and child

      int stat_val;
      pid_t child_pid;

      child_pid = wait(&stat_val); //waiting for child

      printf("Child has finished: PID = %d\n\n", child_pid);
      printf("======Back in Parent======\n\n");
      printf("ID: %d\n\n",getpid());
    }

    if(ch==2) { //zombie

      sleep(10);
      system("ps -al");
      printf("\n");
    }
  }
  exit(0);
}
