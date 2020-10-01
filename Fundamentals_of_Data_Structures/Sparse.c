/*
============================================================================
Name   : Someshwar Gaikwad
Class  : SE-10 (H-10)
Roll No: 23257

Title: Sparse Matrix

Problem Statement:

Implement Sparse matrix and perform following operations on it:
1. Addition
2. Simple Transpose
3. Fast Transpose
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Sparse {
	int row;
	int col;
	int value;
} Sparse;

void getValues(int a[50][50],int *row,int *col) {

	int i,j;

	printf("Enter the size of matrix\n");

	printf("No. of Rows: ");
	scanf("%d",row);

	printf("No. of Columns: ");
	scanf("%d",col);

	printf("Enter elements:\n");

	for(i=0;i<*row;i++) {

		for(j=0;j<*col;j++) {

			scanf("%d",&a[i][j]);
		}
	}
}

Sparse* RegtoSpar(Sparse *S,int a[50][50],int row,int col) {

	int i,j,count=1;

	for(i=0;i<row;i++) {

		for(j=0;j<col;j++) {

			if(a[i][j]!=0)
			{
				count++;
			}
		}
	}

	S=(Sparse*)malloc(sizeof(Sparse)*count);
	count=1;

	for(i=0;i<row;i++) {

		for(j=0;j<col;j++) {

			if(a[i][j]!=0)
			{
				S[count].row=i;
				S[count].col=j;
				S[count].value=a[i][j];
				count++;
			}
		}
	}

	S[0].row=row;
	S[0].col=col;
	S[0].value=count-1;

	return S;
}

void SpartoReg(Sparse *S,int a[50][50],int row,int col) {

	int i,j,k=1;

	for(i=0;i<row;i++) {

		for(j=0;j<col;j++) {

			if(S[k].row==i && S[k].col==j) {

				a[i][j]=S[k].value;
				k++;
			}

			else
				a[i][j]=0;
		}
	}
}

void DisplaySpar(Sparse *S) {

	int i;

	printf("------------------------------\n");
	printf("Row \t Col. \t Value\n");
	printf("------------------------------\n");

	for(i=0;i<=S[0].value;i++)
		printf("%5d %5d %5d\n",S[i].row,S[i].col,S[i].value);
	printf("\n\n");
}

void DisplayReg(int a[50][50],int row,int col) {

	int i,j;

	for(i=0;i<row;i++) {
		for(j=0;j<col;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

Sparse* Addition(Sparse *A,Sparse *B,Sparse *C) {

	C=(Sparse*)malloc(sizeof(Sparse)*((A[0].value)+1));

	int currentA=1,currentB=1,currentC=1;

	while(currentA<=A[0].value && currentB<=B[0].value) {

		if(A[currentA].row==B[currentB].row && A[currentA].col==B[currentB].col) {

			C[currentC].value=A[currentA].value+B[currentB].value;
			C[currentC].row=A[currentA].row;
			C[currentC].col=A[currentA].col;
			currentA++;
			currentB++;
			currentC++;
		}

		else if(A[currentA].row==B[currentB].row && A[currentA].col<B[currentB].col) {

			C[currentC]=A[currentA];
			currentA++;
			currentC++;
		}

		else if(A[currentA].row==B[currentB].row && A[currentA].col>B[currentB].col) {

			C[currentC]=B[currentB];
			currentB++;
			currentC++;
		}

		else  if(A[currentA].row<B[currentB].row) {

			C[currentC]=A[currentA];
			currentA++;
			currentC++;
		}

		else if(A[currentA].row>B[currentB].row) {

			C[currentC]=B[currentB];
			currentB++;
			currentC++;
		}
	}

	while(currentA<=A[0].value) {

		C[currentC]=A[currentA];
		currentA++;
		currentC++;
	}

	while(currentB<=B[0].value) {

		C[currentC]=B[currentB];
		currentB++;
		currentC++;
	}

	C[0].row=A[0].row;
	C[0].col=A[0].col;
	C[0].value=currentC-1;

	return C;
}

Sparse* Transpose(Sparse *S,Sparse *T) {

	T=(Sparse*)malloc(sizeof(Sparse)*((S[0].value)+1));

	int i,j,currentT;

	T[0].row=S[0].col;
	T[0].col=S[0].row;
	T[0].value=S[0].value;

	if(S[0].value>0) {

		currentT=1;

		for(i=0;i<S[0].col;i++) {

			for(j=1;j<=S[0].value;j++) {

				if(S[j].col==i) {

					T[currentT].row=S[j].col;
					T[currentT].col=S[j].row;
					T[currentT].value=S[j].value;
					currentT++;
				}
			}
		}
	}
	return T;
}

Sparse* FastTranspose(Sparse *S,Sparse *T) {

	T=(Sparse*)malloc(sizeof(Sparse)*((S[0].value)+1));

	int row_terms[S[0].col],starting_pos[S[0].col];
	int i,j;

	T[0].row=S[0].col;
	T[0].col=S[0].row;
	T[0].value=S[0].value;

	if(S[0].value>0) {

		for(i=0;i<=S[0].value;i++)
			row_terms[i]=0;

		for(i=1;i<=S[0].value;i++)
			row_terms[S[i].col]++;

		starting_pos[0]=1;

		for(i=1;i<S[0].col;i++)
			starting_pos[i]=starting_pos[i-1]+row_terms[i-1];

		for(i=1;i<=S[0].value;i++) {

			j=starting_pos[S[i].col]++;

			T[j].row=S[i].col;
			T[j].col=S[i].row;
			T[j].value=S[i].value;
		}
	}
	return T;
}

int main(void) {

	int a[50][50],b[50][50],c[50][50],m1,n1,m2,n2,ch,Ch,flag=0,Flag=0;

	Sparse *A,*B,*ADD,*TA,*TB,*FTA,*FTB;

	do {

		printf("Select the Options:\n");
		printf("1. Accept Values\n");
		printf("2. Convert Regular Matrix to Sparse Matrix\n");
		printf("3. Addition\n");
		printf("4. Simple Transpose\n");
		printf("5. Fast Transpose\n");
		printf("6. Convert Sparse Matrix to Regular Matrix\n");
		printf("7. Exit\n\n");
		printf("Your Choice: ");
		scanf("%d",&ch);
		printf("\n\n");

		if(ch==1||ch==6||flag==1) {

			switch(ch) {

				case 1: {

					printf("Accepting Matrix A\n\n");
					getValues(a,&m1,&n1);
					printf("\n\n");

					printf("Accepting Matrix B\n\n");
					getValues(b,&m2,&n2);
					printf("\n\n");

					flag=1;
					Flag=0;
					break;
				}

				case 2: {

					A=RegtoSpar(A,a,m1,n1);
					B=RegtoSpar(B,b,m2,n2);

					printf("Sparse Matrix A:\n\n");
					DisplaySpar(A);

					printf("Sparse Matrix B:\n\n");
					DisplaySpar(B);

					Flag=1;

					break;
				}

				case 3: {

					if(Flag==0) {
						A=RegtoSpar(A,a,m1,n1);
						B=RegtoSpar(B,b,m2,n2);
					}

					printf("Sparse Matrix A:\n\n");
					DisplaySpar(A);

					printf("Sparse Matrix B:\n\n");
					DisplaySpar(B);

					if(m1==m2 && n1==n2) {
						ADD=Addition(A,B,ADD);
						printf("Addition is:\n\n");
						DisplaySpar(ADD);
					}
					else
						printf("Addition not possible\n\n");

					break;
				}

				case 4: {

					do {

						printf("1. Transpose of A\n");
						printf("2. Transpose of B\n");
						printf("3. Back\n");
						printf("You Choice: ");
						scanf("%d",&Ch);
						printf("\n\n");

						if(Ch==1) {

							if(Flag==0)
								A=RegtoSpar(A,a,m1,n1);

							TA=Transpose(A,TA);

							printf("Sparse Matrix A:\n\n");
							DisplaySpar(A);

							printf("Transpose of A:\n\n");
							DisplaySpar(TA);
						}

						else if(Ch==2) {

							if(Flag==0)
								B=RegtoSpar(B,b,m2,n2);

							TB=Transpose(B,TB);

							printf("Sparse Matrix B:\n\n");
							DisplaySpar(B);

							printf("Transpose of B:\n\n");
							DisplaySpar(TB);
						}

						else
							printf("Invalid Choice\n\n");
					}
					while(Ch!=3);

					break;
				}

				case 5: {

					do {

						printf("1. Fast Transpose of A\n");
						printf("2. Fast Transpose of B\n");
						printf("3. Back\n\n");
						printf("You Choice: ");
						scanf("%d",&Ch);
						printf("\n\n");

						if(Ch==1) {

							if(Flag==0)
								A=RegtoSpar(A,a,m1,n1);

							FTA=FastTranspose(A,FTA);

							printf("Sparse Matrix A:\n\n");
							DisplaySpar(A);

							printf("Fast Transpose of A:\n\n");
							DisplaySpar(FTA);
						}

						else if(Ch==2) {

							if(Flag==0)
								B=RegtoSpar(B,b,m2,n2);

							FTB=FastTranspose(B,FTB);

							printf("Sparse Matrix B:\n\n");
							DisplaySpar(B);

							printf("Fast Transpose of B:\n\n");
							DisplaySpar(FTB);
						}

						else if(Ch!=3)
							printf("Invalid Choice\n\n");
					}
					while(Ch!=3);

					break;
				}

				case 6: {

					SpartoReg(A,a,m1,n1);
					printf("Matrix A:\n");
					DisplayReg(a,m1,n1);

					SpartoReg(B,b,m2,n2);
					printf("Matrix B:\n");
					DisplayReg(b,m2,n2);

					SpartoReg(ADD,c,m1,n1);
					printf("Addition:\n");
					DisplayReg(c,m1,n1);

					SpartoReg(TA,c,n1,m1);
					printf("Transpose of A:\n");
					DisplayReg(c,n1,m1);

					SpartoReg(FTA,c,n1,m1);
					printf("Fast Transpose of A:\n");
					DisplayReg(c,n1,m1);

					SpartoReg(TB,c,n2,m2);
					printf("Transpose of B:\n");
					DisplayReg(c,n2,m2);

					SpartoReg(FTB,c,n2,m2);
					printf("Fast Transpose of B:\n");
					DisplayReg(c,n2,m2);

					break;
				}

				case 7:

					printf("END\n\n");
					break;

				default:printf("Enter Again/n");

			}
		}
		else
			printf("Please Accept some values first\n\n");
	}
	while(ch!=7);

	return EXIT_SUCCESS;
}
/*

Output:

Someshwars-MBP-0ae4:C someshwargaikwad$ ./Sparse
Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 1


Accepting Matrix A

Enter the size of matrix
No. of Rows: 3
No. of Columns: 3
Enter elements:
1
0
0
0
0
5
8
0
0


Accepting Matrix B

Enter the size of matrix
No. of Rows: 3
No. of Columns: 3
Enter elements:
0
0
0
0
1
2
0
0

0


Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 2


Sparse Matrix A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    1     2     5
    2     0     8


Sparse Matrix B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    1     2     2


Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 3


Sparse Matrix A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    1     2     5
    2     0     8


Sparse Matrix B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    1     2     2


Addition is:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     4
    0     0     1
    1     1     1
    1     2     7
    2     0     8


Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 4


1. Transpose of A
2. Transpose of B
3. Back
You Choice: 1


Sparse Matrix A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    1     2     5
    2     0     8


Transpose of A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    0     2     8
    2     1     5


1. Transpose of A
2. Transpose of B
3. Back
You Choice: 2


Sparse Matrix B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    1     2     2


Transpose of B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    2     1     2


1. Transpose of A
2. Transpose of B
3. Back
You Choice: 3


Invalid Choice

Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 5


1. Fast Transpose of A
2. Fast Transpose of B
3. Back

You Choice: 1


Sparse Matrix A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    1     2     5
    2     0     8


Fast Transpose of A:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     3
    0     0     1
    0     2     8
    2     1     5


1. Fast Transpose of A
2. Fast Transpose of B
3. Back

You Choice: 2


Sparse Matrix B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    1     2     2


Fast Transpose of B:

------------------------------
Row 	 Col. 	 Value
------------------------------
    3     3     2
    1     1     1
    2     1     2


1. Fast Transpose of A
2. Fast Transpose of B
3. Back

You Choice: 3


Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 6


Matrix A:
1 0 0
0 0 5
8 0 0


Matrix B:
0 0 0
0 1 2
0 0 0


Addition:
1 0 0
0 1 7
0 0 0


Transpose of A:
1 0 8
0 0 0
0 5 0


Fast Transpose of A:
1 0 8
0 0 0
0 5 0


Transpose of B:
0 0 0
0 1 0
0 2 0


Fast Transpose of B:
0 0 0
0 1 0
0 2 0


Select the Options:
1. Accept Values
2. Convert Regular Matrix to Sparse Matrix
3. Addition
4. Simple Transpose
5. Fast Transpose
6. Convert Sparse Matrix to Regular Matrix
7. Exit

Your Choice: 7


END

Someshwars-MBP-0ae4:C someshwargaikwad$
*/
