#include<stdio.h>
#include<stdlib.h>

int n,m;

int safety(int alloc[n][m],int max[n][m],int avail[m]) {

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

    printf("\n============================\n\nAfter:\n");
    printf("\nSafe Sequence:[ ");
    for(i=0;i<n;i++) {
      printf("P%d ",sseq[i]);
    }
    printf("]\n");

    printf("\nAllocation Matrix:\n\n");
    for(i=0;i<n;i++) {
      printf("P%d: ",i);
      for(j=0;j<m;j++) {
        printf("%d ",alloc[i][j]);
      }
      printf("\n");
    }

    printf("\nMaximum Matrix:\n\n");
    for(i=0;i<n;i++) {
      printf("P%d: ",i);
      for(j=0;j<m;j++) {
        printf("%d ",max[i][j]);
      }
      printf("\n");
    }

    printf("\nAvailable Matrix:\n\n");
    for(j=0;j<m;j++) {
      printf("%d ",avail[j]);
    }

    printf("\n\nNeed Matrix:\n\n");
    for(i=0;i<n;i++) {
      printf("P%d: ",i);
      for(j=0;j<m;j++) {
        printf("%d ",need[i][j]);
      }
      printf("\n");
    }
    return 1;
  }
  printf("\nNo Safe Sequence. ");
  return 0;
}

int resourceAlloc(int alloc[n][m],int max[n][m],int avail[m], int pid, int req[m]) {

  int i,j,flag=1;
  int need[n][m];

  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }

  printf("\n============================\n\nBefore:\n");
  printf("\nAllocation Matrix:\n\n");
  for(i=0;i<n;i++) {
    printf("P%d: ",i);
    for(j=0;j<m;j++) {
      printf("%d ",alloc[i][j]);
    }
    printf("\n");
  }

  printf("\nMaximum Matrix:\n\n");
  for(i=0;i<n;i++) {
    printf("P%d: ",i);
    for(j=0;j<m;j++) {
      printf("%d ",max[i][j]);
    }
    printf("\n");
  }

  printf("\nAvailable Matrix:\n\n");
  for(j=0;j<m;j++) {
    printf("%d ",avail[j]);
  }

  printf("\n\nNeed Matrix:\n\n");
  for(i=0;i<n;i++) {
    printf("P%d: ",i);
    for(j=0;j<m;j++) {
      printf("%d ",need[i][j]);
    }
    printf("\n");
  }

  //requesting resources
  /*
  int req[5][3]={ {0,0,0},
                  {1,0,2},
                  {0,0,0},
                  {0,0,0},
                  {0,0,0} };
  */
  //resource request algorithm

  for(j=0;j<m;j++) {
    if(req[j]>need[pid][j]) {
      return 0;
    }
  }
  for(j=0;j<m;j++) {
    if(req[j]>avail[j]) {
      flag=0;
      return 2;
    }
  }
  if(flag==1) {
    for(j=0;j<m;j++) {
      avail[j]-=req[j];
      alloc[pid][j]+=req[j];
      need[pid][j]-=req[j];
    }
    if(!safety(alloc,max,avail)) {
      for(j=0;j<m;j++) {
        avail[j]+=req[j];
        alloc[pid][j]-=req[j];
        need[pid][j]+=req[j];
      }
    }
    else {
      return 1;
    }
  }
}

int main() {

  //accepting step

  /*
  n=5;
  m=3;

  int pid=1;
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

  int avail[3]={3,3,2}; */

  int i,j,ch,pid;

  printf("\nNumber of Processes: ");
  scanf("%d",&n);
  printf("Number of Resources: ");
  scanf("%d",&m);

  int alloc[n][m],max[n][m],avail[m],req[m];

  printf("\nAllocation Matrix:\n\n");
  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      scanf("%d",&alloc[i][j]);
    }
  }

  printf("\nMaximum Matrix:\n\n");
  for(i=0;i<n;i++) {
    for(j=0;j<m;j++) {
      scanf("%d",&max[i][j]);
    }
  }

  printf("\nAvailable Matrix:\n\n");
  for(j=0;j<m;j++) {
    scanf("%d",&avail[j]);
  }

  while(1) {

    printf("\nSelect Correct Option\n");
    printf("\n1.Request\n2.Exit\n\nYour Choice: ");
    scanf("%d",&ch);

    if(ch==1) {
      printf("\nProcess ID: ");
      scanf("%d",&pid);
      if(pid>=n || pid<0) {
        printf("\nInvalid Process ID\n\n");
      }
      else {
        printf("\nRequest: ");
        for(j=0;j<m;j++) {
          scanf("%d",&req[j]);
        }
        int res=resourceAlloc(alloc,max,avail,pid,req);
        if(res==0) {
          printf("\nCannot Allocate\n");
        }
        else if(res==2) {
          printf("\nWaiting\n");
        }
        printf("\n============================\n");
      }
    }
    else if(ch==2) {
      printf("\n");
      break;
    }
    else {
      printf("\nIncorrect Option Selected\n\n");
    }
  }
  return 0;
}
