/*
============================================================================
Name        : Someshwar Gaikwad
Class       : SE-10 (H-10)
Roll No.    : 23257

Title       : Sorting & Searching Operations

Problem Statement:

Accept student information (e.g. RollNo, Name, Percentage etc.).

a) Display the data in ascending order of name (Bubble Sort)
b) Display the data in descending order of name (Selection sort)
c) Display data for RollNo specified by user (Binary search)
d) Display the number of passes and comparisons for different test cases
(Worst, Average, Best case).
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {

  int rollno;
  char name[30];
  float percentage;
};

void Add(struct Student s[],int n,int *i) {

  for(;*i<n && *i<50;(*i)++)
  {
    printf("Enter Roll Number of Student: ");
    scanf("%d",&s[*i].rollno);

    int j;

    for(j=0;j<*i;)
    {
      if(s[j].rollno==s[*i].rollno)
      {
        printf("\nRoll Number already exists\n");
        printf("Enter again\n\n");

        printf("Enter Roll Number of Student: ");
        scanf("%d",&s[*i].rollno);

        j=0;
      }

      else
      j++;
    }

    printf("Enter Name of Student: ");
    scanf("%s",s[*i].name);

    printf("Enter Student's Percentage: ");
    scanf("%f",&s[*i].percentage);

    while(s[*i].percentage>100 || s[*i].percentage<0)
    {
      printf("\nPercentage cannot be greater than 100 (or less than 0)\n");
      printf("Enter again:\n\n");

      printf("Enter Student's Percentage: ");
      scanf("%f",&s[*i].percentage);
    }

    printf("\n\n");

    if(*i>49)
    {
      printf("Record Full\n\n");
    }
  }
}

void Display(struct Student s[],int size) {

  int i;

  printf("Sr.No.\t Roll No.\t Student Name \t Percentage\n");

  for(i=0;i<size;i++)
  {
    printf("%6d\t%10d\t%15s\t%5f\n",(i+1),s[i].rollno,s[i].name,s[i].percentage);
  }
}

void BubbleSort(struct Student s[],int ch,int size) {

  int i,j,k,flag=1,pass,comp,compT=0;
  struct Student temp;

  switch(ch)
  {
    case 1: {

      for(i=0;i<size-1 && flag;i++) {

        flag=0;

        for(j=0;j<(size-1-i);j++) {

          if(s[j].rollno>s[j+1].rollno) {

            temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;

            flag=1;
          }
        }
      }
      break;
    }

    case 2: {

      pass=0;
      comp=0;

      printf("Sorting By Student Name using Bubble Sort\n\n");

      for(k=0;k<size;k++) {

        printf("%s ",s[k].name);
      }
      printf("Pass %d  (Initial)\n\n",pass);


      for(i=0;i<size-1 && flag;i++) {

        flag=0;

        for(j=0;j<(size-1-i);j++) {

          comp++;

          if(strcmp(s[j].name,s[j+1].name)>0) {

            temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;

            flag=1;
          }
        }

        pass++;

        for(k=0;k<size;k++) {

          printf("%s ",s[k].name);
        }

        printf("Pass %d  No. of Comparisons: %d\n\n",pass,comp);

        compT=compT+comp;
        comp=0;
      }

      printf("\nTotal Passes: %d\n",pass);
      printf("Total Comparisons: %d\n",compT);

      if(pass==1)
        printf("\nBest Case\n\n");

      else if(pass==size-1)
        printf("\nWorst Case\n\n");

      else
        printf("\nAverage Case\n\n");

      Display(s,size);
      break;
    }
  }
}

void SelectionSort(struct Student s[],int size) {

  int i,j,k,pass=0,comp=0,pos,compT=0;
  struct Student temp;


  printf("Sorting By Name using Selection Sort\n\n");

  for(k=0;k<size;k++)
  {
    printf("%s ",s[k].name);
  }

  printf("Pass %d  (Initial)\n\n",pass);

  printf("Sorting By Student Name using Selection Sort\n\n");

  for(i=0;i<size;i++)
  {
    pos=i;

    for(j=i+1;j<size;j++)
    {
      comp++;

      if(strcmp(s[pos].name,s[j].name)<0)
      {
        pos=j;
      }
    }

    temp=s[pos];
    s[pos]=s[i];
    s[i]=temp;

    if(comp!=0)
    {
      pass++;

      for(k=0;k<size;k++)
      {
        printf("%s ",s[k].name);
      }

      printf("Pass %d  No. of Comparisons: %d\n\n",pass,comp);
    }

    compT=compT+comp;
    comp=0;
  }

  printf("Total Passes: %d\n",pass);
  printf("Total Comparisons: %d\n\n",compT);
  Display(s,size);
}

int BinarySearchR(struct Student s[],int left,int right,int Rollno) {

  int mid=(left+right)/2;

  if(left>right)
    return -1;

  if(s[mid].rollno==Rollno)
    return mid;

  else if(s[mid].rollno<Rollno)
    return BinarySearchR(s,mid+1,right,Rollno);

  return BinarySearchR(s,left,mid-1,Rollno);
}

void BinarySearchNR(struct Student s[],int size) {

  struct Student t;
  int left,right,mid,flag=0;

  printf("Enter Student's Roll Number: ");
  scanf("%d",&t.rollno);

  printf("Sr.No.\t Roll No.\t Student Name \t Percentage\n");

  BubbleSort(s,1,size);

  left=0;
  right=size-1;

  while(left<=right) {

    mid=(left+right)/2;

    if(s[mid].rollno>t.rollno)
      right=mid-1;

    else if(s[mid].rollno<t.rollno)
      left=mid+1;

    else if(s[mid].rollno==t.rollno) {

      flag=1;
      printf("%6d\t%10d\t%10s\t%5f\n",flag,s[mid].rollno,s[mid].name,s[mid].percentage);
      break;
    }
  }

  if(flag==0)
    printf("Record not Found");
}

int main() {

  struct Student s[50];

  static int size;

  int ch,flag=0;

  do
  {
    printf("1. Add Record(s)\n");
    printf("2. Sort Record in Ascending Order\n");
    printf("3. Sort Record in Descending Order\n");
    printf("4. Search Record\n");
    printf("5. Display all Records\n");
    printf("6. Exit\n\n");
    printf("Your Choice: ");
    scanf("%d",&ch);

    printf("\n\n");

    int Ch,n;

    if(ch==1||ch==6||flag==1)
    {
      switch(ch)
      {
        case 1: {

        if(size>49)
        {
          printf("Record Full\n\n");
          break;
        }

        printf("Enter the number of records you want to add: ");
        scanf("%d",&n);

        printf("\n");

        n=n+size;

        Add(s,n,&size);

        flag=1;
        break;
      }

        case 2:

        BubbleSort(s,2,size);
        printf("\n\n");
        break;

        case 3:

        SelectionSort(s,size);
        printf("\n\n");
        break;

        case 4:

        do
        {
          printf("Search By:\n");
          printf("1. Non-Recursion\n");
          printf("2. Recursion\n");
          printf("3. Back\n\n");
          printf("Your Choice: ");
          scanf("%d",&Ch);

          printf("\n\n");

          while(Ch>3 && Ch<0) {

            printf("Invalid Choice\n");
            printf("Enter Again\n\n");

            printf("Your Choice: ");
            scanf("%d",&Ch);
            printf("\n\n");
          }

          if(Ch==1)
            BinarySearchNR(s,size);

          else if(Ch==2) {

            int rno;
            printf("Enter Student Roll Number: ");
            scanf("%d",&rno);

            int mid=BinarySearchR(s,0,size-1,rno);

            if(mid==-1)
              printf("Record not Found");

            else {

              printf("Sr.No.\t Roll No.\t Student Name \t Percentage\n");
              printf("%6d\t%10d\t%10s\t%5f\n",flag,s[mid].rollno,s[mid].name,s[mid].percentage);
            }

          }
          printf("\n\n");
        }
        while(Ch!=3);
        break;

        case 5:

        Display(s,size);
        printf("\n\n");

        break;

        case 6:

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

  } while(ch!=6);

  return EXIT_SUCCESS;
}

/*

Ouput:

Someshwars-MacBook-Pro:C someshwargaikwad$ ./Searching_and_Sorting_Operations
1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 1


Enter the number of records you want to add: 5

Enter Roll Number of Student: 57
Enter Name of Student: Someshwar
Enter Student's Percentage: 65


Enter Roll Number of Student: 56
Enter Name of Student: Shreyas
Enter Student's Percentage: 54


Enter Roll Number of Student: 43
Enter Name of Student: Pawar
Enter Student's Percentage: 45


Enter Roll Number of Student: 56

Roll Number already exists
Enter again

Enter Roll Number of Student: 55
Enter Name of Student: Muskaan
Enter Student's Percentage: 35


Enter Roll Number of Student: 66
Enter Name of Student: Yash
Enter Student's Percentage: 87


1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 5


Sr.No.	 Roll No.	 Student Name 	 Percentage
     1	        57	      Someshwar	65.000000
     2	        56	        Shreyas	54.000000
     3	        43	          Pawar	45.000000
     4	        55	        Muskaan	35.000000
     5	        66	           Yash	87.000000


1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 2


Sorting By Student Name using Bubble Sort

Someshwar Shreyas Pawar Muskaan Yash Pass 0  (Initial)

Shreyas Pawar Muskaan Someshwar Yash Pass 1  No. of Comparisons: 4

Pawar Muskaan Shreyas Someshwar Yash Pass 2  No. of Comparisons: 3

Muskaan Pawar Shreyas Someshwar Yash Pass 3  No. of Comparisons: 2

Muskaan Pawar Shreyas Someshwar Yash Pass 4  No. of Comparisons: 1


Total Passes: 4
Total Comparisons: 10

Worst Case

Sr.No.	 Roll No.	 Student Name 	 Percentage
     1	        55	        Muskaan	35.000000
     2	        43	          Pawar	45.000000
     3	        56	        Shreyas	54.000000
     4	        57	      Someshwar	65.000000
     5	        66	           Yash	87.000000


1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 3


Sorting By Name using Selection Sort

Muskaan Pawar Shreyas Someshwar Yash Pass 0  (Initial)

Sorting By Student Name using Selection Sort

Yash Pawar Shreyas Someshwar Muskaan Pass 1  No. of Comparisons: 4

Yash Someshwar Shreyas Pawar Muskaan Pass 2  No. of Comparisons: 3

Yash Someshwar Shreyas Pawar Muskaan Pass 3  No. of Comparisons: 2

Yash Someshwar Shreyas Pawar Muskaan Pass 4  No. of Comparisons: 1

Total Passes: 4
Total Comparisons: 10

Sr.No.	 Roll No.	 Student Name 	 Percentage
     1	        66	           Yash	87.000000
     2	        57	      Someshwar	65.000000
     3	        56	        Shreyas	54.000000
     4	        43	          Pawar	45.000000
     5	        55	        Muskaan	35.000000


1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 4


Search By:
1. Non-Recursion
2. Recursion
3. Back

Your Choice: 1


Enter Student's Roll Number: 90
Sr.No.	 Roll No.	 Student Name 	 Percentage
Record not Found

Search By:
1. Non-Recursion
2. Recursion
3. Back

Your Choice: 1


Enter Student's Roll Number: 56
Sr.No.	 Roll No.	 Student Name 	 Percentage
     1	        56	   Shreyas	54.000000


Search By:
1. Non-Recursion
2. Recursion
3. Back


Your Choice: 3


1. Add Record(s)
2. Sort Record in Ascending Order
3. Sort Record in Descending Order
4. Search Record
5. Display all Records
6. Exit

Your Choice: 6


End

Someshwars-MacBook-Pro:C someshwargaikwad$

*/
