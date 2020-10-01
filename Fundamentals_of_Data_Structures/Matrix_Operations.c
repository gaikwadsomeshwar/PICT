/*
 ============================================================================
 Name        : Someshwar Gaikwad
 Class       : SE-10 (H-10)
 Roll No.    : 23257
 
 Title       : Matrix Operations
 
 Problem Statement:
 
 Represent matrix using two dimensional arrays and perform following operations
 with and without pointers:
 
 1. Addition  
 2. Multiplication
 3. Transpose  
 4. Saddle point
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void getValues(int a[20][20],int b[20][20],int *m1,int *m2,int *n1,int *n2)
{
	int i,j;

	printf("Enter the size of Matrix A\n");
	printf("Enter the number of rows of Matrix A: ");
	scanf("%d",m1);

	printf("Enter the number of columns of Matrix A: ");
	scanf("%d",n1);

	printf("Enter the elements of Matrix A: \n");
	for(i=0;i<*m1;i++)
	{
		for(j=0;j<*n1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("Enter the size of Matrix B\n");
	printf("Enter the number of rows of Matrix B: ");
	scanf("%d",m2);

	printf("Enter the number of columns of Matrix B: ");
	scanf("%d",n2);

	printf("Enter the elements of Matrix B: \n");
	for(i=0;i<*m2;i++)
	{
		for(j=0;j<*n2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
}

void display(int a[20][20],int m1,int n1)
{
	int i,j;

	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

}

int Add(int a[20][20],int b[20][20],int c[20][20],int m1,int m2,int n1,int n2)
{
	int l;
	if((m1==m2)&&(n1==n2))
    {
		int i,j;
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		l=1;
    }
	else
	{
		l=0;
	}
	return l;
}

int Mul(int a[20][20],int b[20][20],int c[20][20],int m1,int m2,int n1,int n2)
{
	int l;
	if(n1==m2)
	{
		int value=0;
		int i,j,k;
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n2;j++)
			{
				for(k=0;k<n1;k++)
				{
					value=value+(a[i][k]*b[k][j]);
				}
				c[i][j]=value;
				value=0;
			}
		}
		l=1;
	}
	else
	{
		l=0;
	}
	return l;
}

void Trans(int a[20][20],int c[20][20],int m1,int n1)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			c[i][j]=a[j][i];
		}
	}
}

void Saddle(int a[20][20],int m1,int n1)
{
	printf("Saddle Points are:\n");

	int i,j,k;

	for(i=0;i<m1;i++)
	{
		int min1=a[i][0];
		int max2=a[i][0];
		int pos1=0;
		int pos2=0;

		for(j=1;j<n1;j++)
		{
			if(a[i][j]<min1)
			{
				min1=a[i][j];
				pos1=j;
			}
			if(a[i][j]>max2)
			{
				max2=a[i][j];
				pos2=j;
			}
		}

		int max1=a[0][pos1];
		int min2=a[0][pos2];
		int pos12=0,pos21=0;

		for(k=1;k<m1;k++)
		{
			if(a[k][pos1]>max1)
			{
				max1=a[k][pos1];
				pos12=k;
			}

			if(a[k][pos2]<min2)
			{
				min2=a[k][pos2];
				pos21=k;
			}
		}

		if(min1==max1)
		{
			printf("%d at [%d][%d]\n",min1,pos12,pos1);
		}

		if(min2==max2)
		{
			printf("%d at [%d][%d]\n",min2,pos21,pos2);
		}

	}

	printf("\n\n");
}

void getValuesP(int *a,int *b,int *m1,int *m2,int *n1,int *n2)
{
	int i,j;

	printf("Enter the size of Matrix A\n");
	printf("Enter the number of rows of Matrix A: ");
	scanf("%d",m1);

	printf("Enter the number of columns of Matrix A: ");
	scanf("%d",n1);

	int col1=*n1;

	printf("Enter the elements of Matrix A: \n");
	for(i=0;i<*m1;i++)
	{
		for(j=0;j<*n1;j++)
		{
			scanf("%d",(a+(i*col1)+j));
		}
	}

	printf("Enter the size of Matrix B\n");
	printf("Enter the number of rows of Matrix B: ");
	scanf("%d",m2);

	printf("Enter the number of columns of Matrix B: ");
	scanf("%d",n2);

	int col2=*n2;

	printf("Enter the elements of Matrix B: \n");
	for(i=0;i<*m2;i++)
	{
		for(j=0;j<*n2;j++)
		{
			scanf("%d",(b+(i*col2)+j));
		}
	}
}

void displayP(int *a,int m1,int n1)
{
	int i,j;

	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("%d ",*(a+(i*n1)+j));
		}
		printf("\n");
	}

	printf("\n");

}

int AddP(int *a,int *b,int *c,int m1,int m2,int n1,int n2)
{
	int l;
	if((m1==m2)&&(n1==n2))
    {
		int i,j;
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				*(c+(i*n1)+j)=*(a+(i*n1)+j)+*(b+(i*n1)+j);
			}
		}
		l=1;
    }
	else
	{
		l=0;
	}
	return l;
}

int MulP(int *a,int *b,int *c,int m1,int m2,int n1,int n2)
{
	int l;
	if(n1==m2)
	{
		int value=0;
		int i,j,k;
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n2;j++)
			{
				for(k=0;k<n1;k++)
				{
					value=value+((*(a+(i*n1)+k))*(*(b+(k*n2)+j)));
				}
				*(c+(i*n2)+j)=value;
				value=0;
			}
		}
		l=1;
	}
	else
	{
		l=0;
	}
	return l;
}

void TransP(int *a,int *c,int m1,int n1)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<m1;j++)
		{
			*(c+(i*m1)+j)=*(a+(j*n1)+i);
		}
	}
}

void SaddleP(int *a,int m1,int n1)
{
	printf("Saddle Points are:\n");

	int i,j,k;

	for(i=0;i<m1;i++)
	{
		int min1=*(a+(i*n1));
		int max2=*(a+(i*n1));

		int pos1=0;
		int pos2=0;

		for(j=1;j<n1;j++)
		{
			int value=*(a+(i*n1)+j);
			if(value<min1)
			{
				min1=value;
				pos1=j;
			}
			if(value>max2)
			{
				max2=value;
				pos2=j;
			}
		}

		int max1=*(a+pos1);
		int min2=*(a+pos2);
		int pos12=0,pos21=0;

		for(k=1;k<m1;k++)
		{
			if(*(a+(k*n1)+pos1)>max1)
			{
				max1=*(a+(k*n1)+pos1);
				pos12=k;
			}

			if(*(a+(k*n1)+pos2)<min2)
			{
				min2=*(a+(k*n1)+pos2);
				pos21=k;
			}
		}

		if(min1==max1)
		{
			printf("%d at [%d][%d]\n",min1,pos12,pos1);
		}

		if(min2==max2)
		{
			printf("%d at [%d][%d]\n",min2,pos21,pos2);
		}

	}

	printf("\n\n");
}

int main(void)
{
	int m1,m2,n1,n2,l,a[20][20],b[20][20],c[20][20],flag=0,Flag;

	int CH;

	do
	{
		printf("1.Execute program without pointers\n");
		printf("2.Execute program with pointers\n");
		printf("3. Exit");
		scanf("%d",&CH);

		if(CH==1)
		{
			int ch;
			do
			{
				printf("Select the Options:\n");
				printf("1. INPUT THE VALUES\n");
				printf("2. ADDITION\n");
				printf("3. MULTIPLICATION\n");
				printf("4. TRANSPOSE\n");
				printf("5. SADDLE POINT\n");
				printf("6. BACK\n\n");
				scanf("%d",&ch);

				if(ch==1||ch==6||flag==1){

					switch(ch)

					{

						case 1:getValues(a,b,&m1,&m2,&n1,&n2);

							   printf("\nMatrix A: \n");
							   display(a,m1,n1);

							   printf("\nMatrix B: \n");
							   display(b,m2,n2);

							   printf("\n\n\n");
							   flag=1;
							   break;

						case 2:l=Add(a,b,c,m1,m2,n1,n2);
							   if(l==1)
							   {
								   printf("\nMatrix A: \n");
								   display(a,m1,n1);
								   printf("\nMatrix B: \n");
								   display(b,m2,n2);
								   printf("\nAddition:\n");
								   display(c,m1,n1);
								   printf("\n\n\n");
							   }
							   else
							   {
								   printf("Addition not Possible\n\n\n");
							   }
							   break;

						case 3:l=Mul(a,b,c,m1,m2,n1,n2);

							   if(l==1)
							   {
								   printf("\nMatrix A: \n");
								   display(a,m1,n1);
								   printf("\nMatrix B: \n");
								   display(b,m2,n2);
								   printf("\nMultiplication:\n");
								   display(c,m1,n2);
								   printf("\n\n\n");
							   }
							   else
							   {
								   printf("Multiplication not Possible\n\n\n");
							   }

							   break;

						case 4:Flag=1;
							  do
							  {

								  printf("1. Transpose of A\n");
								  printf("2. Transpose of B\n");
								  printf("3. Back\n");
								  scanf("%d",&l);

								  if(l==1)
								  {
									  Trans(a,c,m1,n1);
									  printf("Matrix A:\n");
									  display(a,m1,n1);
									  printf("Transpose of A:\n");
									  display(c,n1,m1);
									  printf("\n\n");
								  }
								  else if(l==2)
								  {
									  Trans(b,c,m2,n2);
									  printf("Matrix B:\n");
									  display(b,m2,n2);
									  printf("Transpose of B:\n");
									  display(c,n2,m2);
									  printf("\n\n");
								  }
								  else if(l==3)
								  {
									  printf("\n\n");
									  break;
								  }
								  else
								  {
									  printf("Please enter 1 or 2\n\n");
								  }
							  }
							  while(Flag!=0);

							  break;

						case 5:Flag=1;
							   do
							   {

								   printf("1. Saddle Points of A\n");
								   printf("2. Saddle Points of B\n");
								   printf("3. Back\n");

								   scanf("%d",&l);

								   if(l==1)
								   {
									   printf("Matrix A:\n");
									   display(a,m1,n1);
									   Saddle(a,m1,n1);
								   }
								   else if(l==2)
								   {
									   printf("Matrix B:\n");
									   display(b,m2,n2);
									   Saddle(b,m2,n2);
								   }

								   else if(l==3)
								   {
									   printf("\n\n");
									   break;
								   }
								   else
								   {
									   printf("Please enter 1 or 2\n\n");
								   }
							   }
							   while(Flag!=0);

							   break;

						case 6:break;

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
		}
		else if(CH==2)
		{
			int ch;

			do
			{
				printf("Select the Options:\n");
				printf("1. INPUT THE VALUES\n");
				printf("2. ADDITION\n");
				printf("3. MULTIPLICATION\n");
				printf("4. TRANSPOSE\n");
				printf("5. SADDLE POINT\n");
				printf("6. BACK\n\n");
				scanf("%d",&ch);


				if(ch==1||ch==6||flag==1){

					switch(ch)
					{

						case 1:getValuesP(&a[0][0],&b[0][0],&m1,&m2,&n1,&n2);

							   printf("\nMatrix A: \n");
			                   displayP(&a[0][0],m1,n1);

			                   printf("\nMatrix B: \n");
			                   displayP(&b[0][0],m2,n2);

			                   printf("\n\n\n");
							   flag=1;
							   break;

						case 2:l=AddP(&a[0][0],&b[0][0],&c[0][0],m1,m2,n1,n2);
							   if(l==1)
							   {
								   printf("\nMatrix A: \n");
								   displayP(&a[0][0],m1,n1);

								   printf("\nMatrix B: \n");
								   displayP(&b[0][0],m2,n2);

								   printf("\nAddition:\n");
								   displayP(&c[0][0],m1,n1);

								   printf("\n\n\n");
							   }
							   else
							   {
								   printf("Addition not Possible\n\n\n");
							   }
							   break;

						case 3:l=MulP(&a[0][0],&b[0][0],&c[0][0],m1,m2,n1,n2);
						   if(l==1)
						   {
							   printf("\nMatrix A: \n");
							   displayP(&a[0][0],m1,n1);

							   printf("\nMatrix B: \n");
							   displayP(&b[0][0],m2,n2);

							   printf("\nMultiplication:\n");
							   displayP(&c[0][0],m1,n2);

							   printf("\n\n\n");
						   }
						   else
						   {
							   printf("Multiplication not Possible\n\n\n");
						   }
						   break;

						case 4:Flag=1;
							   do
							   {

									printf("1. Transpose of A\n");
									printf("2. Transpose of B\n");
									printf("3. Back\n");
									scanf("%d",&l);

									if(l==1)
					        	    {
					        		   TransP(&a[0][0],&c[0][0],m1,n1);
					        		   printf("Matrix A:\n");

					        		   displayP(&a[0][0],m1,n1);
					        		   printf("Transpose of A:\n");

					        		   displayP(&c[0][0],n1,m1);
					        		   printf("\n\n");
					        	    }
					        		else if(l==2)
					        		{
					        		   TransP(&b[0][0],c,m2,n2);
					        		   printf("Matrix B:\n");

					        		   displayP(&b[0][0],m2,n2);
					        		   printf("Transpose of B:\n");

					        		   displayP(&c[0][0],n2,m2);
					        		   printf("\n\n");

					        		   }
					        	   else if(l==3)
					        	   {
					        		   printf("\n\n");
					        		   break;
					        	   }
					        	   else
					        	   {
					        		   printf("Please enter 1 or 2\n\n");
					        		}
					           }
					           while(Flag!=0);

							   break;

						case 5:Flag=1;
							   do
							   {

									printf("1. Saddle Points of A\n");
									printf("2. Saddle Points of B\n");
									printf("3. Back\n");

									scanf("%d",&l);
					            if(l==1)
					        	   {
					        	   		printf("Matrix A:\n");
					        	   		displayP(&a[0][0],m1,n1);
					        	   		SaddleP(&a[0][0],m1,n1);
					        	   }
					        		else if(l==2)
					        		{
					        			printf("Matrix B:\n");
					        			displayP(&b[0][0],m2,n2);
					        			SaddleP(&b[0][0],m2,n2);
					        		}

					        	   else if(l==3)
					        	   {
					        		   printf("\n\n");
					        		   break;
					        	   }
					        	   else
					        	   {
					        		   printf("Please enter 1 or 2\n\n");
					        		}
					           }
					           while(Flag!=0);

						       break;

						case 6:break;
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
		}
		else if(CH==3)
		{
			printf("END");
			break;
		}
		else
		{
			printf("Enter a value between 1 and 3");
			continue;
		}
	}
	while(CH>0);

		return EXIT_SUCCESS;
}
