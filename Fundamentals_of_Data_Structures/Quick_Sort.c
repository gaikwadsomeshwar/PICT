/*
============================================================================
Name        : Someshwar Gaikwad
Class       : SE-10 (H-10)
Roll No.    : 23257

Title       : Quick Sort

Problem Statement:

Accept Mobile user information (e.g. MobileNo, Name, BillAmount etc.)

a) Display the data in descending order of Name (Quick Sort, Recursive)
b) Display the data in ascending order of MobileNo (Quick Sort, Non-Recursive)
c) Display pivot position and its corresponding list in each pass.
d) Display the number of passes and comparisons for different test cases
(Worst, Average, Best case).
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {


  long int MobileNo;
  char name[30];
  float BillAmount;
};

void Add(struct User U[],int n,int *i) {

  for(;*i<n && *i<50;(*i)++)
  {
    printf("Enter Mobile Number of User: ");
    scanf("%ld",&U[*i].MobileNo);

    int j;

    for(j=0;j<*i;)
    {
      if(U[j].MobileNo==U[*i].MobileNo)
      {
        printf("\nMobile Number already exists\n");
        printf("Enter again\n\n");

        printf("Enter Mobile Number of User: ");
        scanf("%ld",&U[*i].MobileNo);

        j=0;
      }

      else
      j++;
    }

    printf("Enter Name of User: ");
    scanf("%s",U[*i].name);

    printf("Enter User's Bill Amount: ");
    scanf("%f",&U[*i].BillAmount);

    printf("\n\n");

    if(*i>49)
    {
      printf("Record Full\n\n");
    }
  }
}

void Display(struct User U[],int n) {

  printf("\n\n-------------------------------------------------\n");
  printf("Mobile No. \t\t Name \t Bill Amt.\n");
  printf("-------------------------------------------------\n");

  int i;
  for(i=0;i<n;i++)
  {
    printf("%10ld\t%10s\t%5f\n",U[i].MobileNo,U[i].name,U[i].BillAmount);
  }
}

int partitionName(struct User U[],int left,int right,int n,int *pass) {

  struct User temp,pivot;
  int i,j,k;

  i=left;
  j=right+1;
  pivot=U[left];

  printf(" Pivot %s at %d \n\n",pivot.name,left);

  do {

    do {
      i++;
    }
    while(strcmp(U[i].name,pivot.name)>0);

    do {
      j--;
    }
    while(strcmp(U[j].name,pivot.name)<0);

    if(i<j)
    {
      temp=U[j];
      U[j]=U[i];
      U[i]=temp;
    }
  }
  while(i<j);

  U[left]=U[j];
  U[j]=pivot;

  printf("Pass %d: ",*pass);
  for(k=0;k<n;k++) {
    printf("%s ",U[k].name);
  }

  (*pass)++;

  return j;
}

void QuickSortR(struct User U[],int left,int right,int *pass,int n) {

	int j;
	if(*pass==0) {

		printf("Pass %d: ",*pass);

		for(j=0;j<n;j++) {
		    printf("%s ",U[j].name);
		  }

		printf(" (Initial) ");

		(*pass)++;
	}

  if(left<right) {

    j=partitionName(U,left,right,n,pass);
    QuickSortR(U,left,j-1,pass,n);
    QuickSortR(U,j+1,right,pass,n);
  }
}

int partitionMobileNo(struct User U[],int left,int right) {

  struct User temp,pivot;
  int i,j;

  pivot=U[right];
  i=left-1;

  for(j=left;j<right;j++) {

    if(U[j].MobileNo<pivot.MobileNo) {

      i++;
      temp=U[i];
      U[i]=U[j];
      U[j]=temp;
    }
  }

  temp=U[i+1];
  U[i+1]=U[right];
  U[right]=temp;

  return i+1;
}

void QuickSortNR(struct User U[],int left,int right) {

  int stack[right-left+1];
  int top=-1;

  stack[++top]=left;
  stack[++top]=right;

  while(top>=0) {

    right=stack[top--];
    left=stack[top--];

    int p=partitionMobileNo(U,left,right);

    if(p-1>left) {

      stack[++top]=left;
      stack[++top]=p-1;
    }

    if(p+1<right) {

      stack[++top]=p+1;
      stack[++top]=right;
    }
  }
}

int main() {

  struct User U[50];

  static int size,Pass;

  int ch,flag=0;

  do
  {
    printf("1. Add Record(s)\n");
    printf("2. Display Record in Descending Order of Name\n");
    printf("3. Display Record in Ascending Order of Mobile Number\n");
    printf("4. Exit\n\n");
    printf("Your Choice: ");
    scanf("%d",&ch);

    printf("\n\n");

    int n;

    if(ch==1||ch==4||flag==1)
    {
      switch(ch)
      {
        case 1:

        if(size>49)
        {
          printf("Record Full\n\n");
          break;
        }

        printf("Enter the number of records you want to add: ");
        scanf("%d",&n);

        printf("\n");

        n=n+size;

        Add(U,n,&size);

        flag=1;
        break;

        case 2:

        QuickSortR(U,0,size-1,&Pass,size);

        if(Pass==size)
        	printf("\n\nWorst Case\n");

        else
        	printf("\n\nBest Case\n");

        Pass=0;

        Display(U,size);
        printf("\n\n");
        break;

        case 3:

        QuickSortNR(U,0,size-1);
        Display(U,size);
        printf("\n\n");
        break;


        case 4:

        printf("End\n\n");
        break;

        default:

        printf("Invalid Choice\n");
        printf("Enter a choice between 1 and 6\n\n");
      }
    }

    else
    {
      printf("Record Empty\n");
      printf("Hint: Add a Record\n\n");
    }

  } while(ch!=4);

  return EXIT_SUCCESS;
}

/*

Output:

Someshwars-MacBook-Pro:C someshwargaikwad$ gcc Quick_Sort.c -o Quick_Sort
Someshwars-MacBook-Pro:C someshwargaikwad$ ./Quick_Sort
1. Add Record(s)
2. Display Record in Descending Order of Name
3. Display Record in Ascending Order of Mobile Number
4. Exit

Your Choice: 1


Enter the number of records you want to add: 4

Enter Mobile Number of User: 2642562349
Enter Name of User: Someshwar
Enter User's Bill Amount: 456


Enter Mobile Number of User: 746528975
Enter Name of User: Shreyas
Enter User's Bill Amount: 543


Enter Mobile Number of User: 76128731019
Enter Name of User: Yash
Enter User's Bill Amount: 876


Enter Mobile Number of User: 8468375334
Enter Name of User: Muskaan
Enter User's Bill Amount: 543


1. Add Record(s)
2. Display Record in Descending Order of Name
3. Display Record in Ascending Order of Mobile Number
4. Exit

Your Choice: 2


Pass 0: Someshwar Shreyas Yash Muskaan  (Initial)  Pivot Someshwar at 0

Pass 1: Yash Someshwar Shreyas Muskaan  Pivot Shreyas at 2

Pass 2: Yash Someshwar Shreyas Muskaan

Best Case


-------------------------------------------------
Mobile No. 		 Name 	 Bill Amt.
-------------------------------------------------
76128731019	      Yash	876.000000
2642562349	 Someshwar	456.000000
 746528975	   Shreyas	543.000000
8468375334	   Muskaan	543.000000


1. Add Record(s)
2. Display Record in Descending Order of Name
3. Display Record in Ascending Order of Mobile Number
4. Exit

Your Choice: 3




-------------------------------------------------
Mobile No. 		 Name 	 Bill Amt.
-------------------------------------------------
 746528975	   Shreyas	543.000000
2642562349	 Someshwar	456.000000
8468375334	   Muskaan	543.000000
76128731019	      Yash	876.000000


1. Add Record(s)
2. Display Record in Descending Order of Name
3. Display Record in Ascending Order of Mobile Number
4. Exit

Your Choice: 4


End

Someshwars-MacBook-Pro:C someshwargaikwad$

*/
