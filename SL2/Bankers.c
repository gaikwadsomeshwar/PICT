#include<stdio.h>
#include<stdlib.h>

int n,m;

int safety(int alloc[5][3],int max[5][3],int avail[3]) {

  int i,j,k;
  int work[m],finish[n],sseq[n];
  int need[n][m];

  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }

  //initialisation step

  for(i=0;i<n;i++) {
    finish[i]=0;
    sseq[i]=-1;
  }

  for(i=0;i<m;i++) {
    work[i]=avail[i];
  }

  //Safety Algorithm

  k=0;
  i=0;

  while(1) {

    int FLAG=0;
    for(i=0;i<n;i++) {

      if(finish[i]==0) {
        int flag=1;
        for(j=0;j<m;j++) {
          if(need[i][j]>work[j]) {
            flag=0;
            break;
          }
        }
        if(flag==1) {
          for(j=0;j<m;j++) {
            work[j]+=alloc[i][j];
          }
          finish[i]=1;
          sseq[k++]=i;
          FLAG=1;
        }
      }
    }
    if(FLAG==0) {
      break;
    }
  }

  if(k==n) {
    printf("\nSafe Sequence:[ ");
    for(i=0;i<n;i++) {
      printf("%d ",sseq[i]);
    }
    printf("]\n\n");
    return 1;
  }
  printf("\nNo Safe Sequence. ");
  return 0;
}

int resourceAlloc(int alloc[5][3],int max[5][3],int avail[3]) {

  int i,j,k;
  int need[n][m],finish[n];

  for(i=0;i<n;i++) {
    finish[i]=0;
  }

  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }

  //requesting resources

  int req[5][3]={ {0,2,0},
                  {0,0,0},
                  {2,0,0},
                  {0,0,0},
                  {0,0,1} };

  //resource request algorithm

  i=0;
  k=0;
  while(k<n) {

    if(finish[i]==0) {
      int flag=1;
      for(j=0;j<m;j++) {
        if(req[i][j]>need[i][j]) {
          return 0;
        }
      }
      for(j=0;j<m;j++) {
        if(req[i][j]>avail[j]) {
          flag=0;
          break;
        }
      }
      if(flag==1) {
        for(j=0;j<m;j++) {
          avail[j]-=req[i][j];
          alloc[i][j]+=req[i][j];
          need[i][j]-=req[i][j];
        }
        finish[i]=1;
        if(!safety(alloc,max,avail)) {
          return 0;
        }
      }
      i++;
    }
    k++;
    if(i==n) i=0;
  }
  return 1;
}

int main() {

  //accepting step

  n=5;
  m=3;

  int alloc[5][3]={ {0,1,0},
                    {2,0,0},
                    {3,0,2},
                    {2,1,1},
                    {0,0,2} };

  int max[5][3]={ {7,5,3},
                  {3,2,2},
                  {9,0,2},
                  {2,2,2},
                  {4,3,3} };

  int avail[3]={3,3,2};

  int res=resourceAlloc(alloc,max,avail);
  if(!res) {
    printf("Hence, Unsafe State\n\n");
  }
  return 0;
}
