/*
 ============================================================================
 Name     : Someshwar .K. Gaikwad
 Class    : SE-10 (H-10)
 Roll No  : 23257
 
 Title    : Set Operations

 Problem Statement:
 
 Represent sets using one dimensional arrays and implement functions to perform:
 
 a) Union
 b) Intersection
 c) Difference
 d) Symmetrical Difference
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getValues(int a[10],int b[10],int *m,int *n)
{
	int i,j;

	printf("Enter the size of set A: ");
	scanf("%d",m);

	printf("Enter the elements of set A: ");
	for(i=0;i<*m;i++)
	{
		scanf("%d",&a[i]);
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
				printf("Do not enter duplicate values\n");
				i--;
			}
		}
	}

	printf("Enter the size of set B: ");
	scanf("%d",n);

	printf("Enter the elements of set B: ");
	for(i=0;i<*n;i++)
	{
		scanf("%d",&b[i]);
		for(j=0;j<i;j++)
		{
			if(b[i]==b[j])
			{
				printf("Do not enter duplicate values\n");
				i--;
			}
		}
	}
}

void display(int a[10],int b[10],int m,int n)
{
	int i;

	printf("\nSet A: ");
	for(i=0;i<m;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");

	printf("Set B: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}

	printf("\n");
}

int Union(int a[10],int b[10],int c[20],int m,int n)
{
	int i,j,l=m;

	for(i=0;i<m;i++)
	{
		c[i]=a[i];				//copy first set into resultant
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[j]==b[i])
			break;
		}
		if(j==m)
		{
			c[l++]=b[i];
		}
	}
	return l;
}

int Intersection(int a[10],int b[10],int c[20],int m,int n)
{
	int i,j,l=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				c[l]=b[j];
				l=l+1;
				break;
			}
		}
	}
	return l;
}

int Difference(int a[10],int b[10],int c[20],int m,int n)
{

	int d[20];
	int x=Intersection(a,b,d,m,n);
	int i,j,k=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<x;j++)
		{
			if(d[j]==a[i])
			{
				break;
			}
		}
		if(j==x)
		{
			c[k++]=a[i];
		}
	}
	return k;
}

int SymmetricalDiff(int a[10],int b[10],int c[20],int m,int n)
{
	int x,y,z,d[20],e[20];

	x=Difference(a,b,d,m,n);
	y=Difference(b,a,e,n,m);
	z=Union(d,e,c,x,y);

	return z;
}

int main(void)
{
	int m,n,l,a[10],b[10],c[20],i,flag=0;

	int ch;
	do
	{
		printf("Select the Options:\n");
		printf("1. INPUT THE VALUES\n");
		printf("2. UNION\n");
		printf("3. INTERSECTION\n");
		printf("4. DIFFERENCE\n");
		printf("5. SYMETRICAL DIFFERENCE\n");
		printf("6. EXIT\n\n");
		scanf("%d",&ch);

		if(ch==1||flag==1){

			switch(ch)

			{

			case 1:getValues(a,b,&m,&n);
				   display(a,b,m,n);
				   printf("\n\n\n");
				   flag=1;
				   break;

			case 2:l=Union(a,b,c,m,n);
				   display(a,b,m,n);
				   printf("Result of Union: ");
				   for(i=0;i<l;i++)
				   {
				   		printf("%d ",c[i]);
				   }
				   printf("\n\n\n");
				   break;

			case 3:l=Intersection(a,b,c,m,n);
			       display(a,b,m,n);
				   printf("Result of Intersection: ");
				   for(i=0;i<l;i++)
				   {
					   printf("%d ",c[i]);
				   }
				   printf("\n\n\n");
				   break;

			case 4:l=Difference(a,b,c,m,n);
				   display(a,b,m,n);
				   printf("Result of Difference: ");
				   for(i=0;i<l;i++)
				   {
					   printf("%d ",c[i]);
				   }
				   printf("\n\n\n");
				   break;

			case 5:l=SymmetricalDiff(a,b,c,m,n);
			       display(a,b,m,n);
			       printf("Result of Symmetrical Difference: ");
			       for(i=0;i<l;i++)
		           {
			    	   printf("%d ",c[i]);
			       }
			       printf("\n\n\n");
			       break;

			case 6:printf("END");
				   break;
			default:printf("Enter Again/n");

			}
		}
		else
		{
			printf("Please Input the Values First\n\n");
			continue;
		}
	}
	while(ch!=6);

	return EXIT_SUCCESS;
}
