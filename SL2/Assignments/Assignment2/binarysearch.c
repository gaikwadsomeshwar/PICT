#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int binarysearch(int arr[],int data,int left,int right) {

  while(left<right) {

    int mid=(left+right)/2;
    if(arr[mid]==data) {
      return mid;
    }

    if(arr[mid]>data) {
      return binarysearch(arr,data,left,mid);
    }

    else {
        return binarysearch(arr,data,mid+1,right);
      }
    }
    return -1;
}

int main(int argc, char *argv[]) {

  printf("\n======In Binary Search======\n\n");
  printf("ID: %d\n",getpid());

  int arr[argc-3],size=argc-3,data,ch;

	for(int i=1;i<size+1;i++) {
    sscanf(argv[i],"%d",&arr[i-1]);
  }

  do {
    printf("\nEnter the value to be searched: ");
  	scanf("%d",&data);

  	int pos=binarysearch(arr,data,0,size);

    if(pos!=-1) {
      printf("\nValue Found at position: %d\n\n",pos);
    }
    else {
      printf("\nNot found\n\n");
    }
    printf("===================\n\n");
    printf("Continue (0/1): ");
    scanf("%d",&ch);
  }
  while(ch!=0);

  return 0;
}
