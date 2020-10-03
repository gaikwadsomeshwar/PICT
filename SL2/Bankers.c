#include<stdio.h>

int main() {

  int n,m;
  int i,j,k,FLAG;

  //accepting step

  n=5;
  m=3;

  int alloc[5][3]={{0,1,0},
         {2,0,0},
         {3,0,2},
         {2,1,1},
         {0,0,2}};

  int max[5][3]={{7,5,3},
       {3,2,2},
       {9,0,2},
       {2,2,2},
       {4,3,3}};

  int avail[3]={3,3,2};

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
  FLAG=1;

  while(i<n) {

    if(finish[i]==0) {

      int flag=1;
      for(j=0;j<m;j++) {
        if(need[i][j]>=work[j]) {
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
      }
    }
    i++;

    if(FLAG) {
      if(i==n) {
        i=0;
        FLAG=0;
      }
    }
  }

  if(k==n) {
    printf("\n[");
    for(i=0;i<n;i++) {
      printf("%d ",sseq[i]);
    }
    printf("]");
  }
  else {
    printf("\nNo Safe Sequence\n");
    printf("\n[");
    for(i=0;i<n;i++) {
      printf("%d ",sseq[i]);
    }
    printf("]");
  }
  printf("\n\n");

  return 0;
}
