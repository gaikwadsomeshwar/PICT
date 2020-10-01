/*
================================================================
Title     : Generic Programming: Templates
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Write a program in C++ using function/class template to read two matrices of
different data types such as integers and floating point values and perform
simple arithmetic operations on these matrices separately and display it.
================================================================*/

#include<iostream>
using namespace std;

template <class X>
class Matrix {

    X a[5][5],b[5][5],c[5][5];
    int m1,m2,n1,n2;

  public:

    Matrix() {

      int i,j;

      for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
          a[i][j]=0;
          b[i][j]=0;
          c[i][j]=0;
        }
      }
    }

    void Accept();
    void Display();
    void Addition();
    void Subtraction();
    void Multiplication();
};

template <class X> void Matrix<X>::Accept() {

  int i,j;

  cout<<"Enter size of Matrix 1\n";
  cout<<"Number of Rows: ";
  cin>>m1;
  cout<<"Number of Columns: ";
  cin>>n1;
  cout<<"\nEnter elements: ";

  for(i=0;i<m1;i++) {
    for(j=0;j<n1;j++) {
      cin>>a[i][j];
    }
  }
  cout<<"\n\nEnter size of Matrix 2\n";
  cout<<"Number of Rows: ";
  cin>>m2;
  cout<<"Number of Columns: ";
  cin>>n2;
  cout<<"\nEnter elements: ";

  for(i=0;i<m2;i++) {
    for(j=0;j<n2;j++) {
      cin>>b[i][j];
    }
  }
}

template <class X> void Matrix<X>::Display() {

  int i,j;

  cout<<"Matrix 1:\n";
  for(i=0;i<m1;i++) {
    for(j=0;j<n1;j++) {
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n\n";

  cout<<"Matrix 2:\n";
  for(i=0;i<m2;i++) {
    for(j=0;j<n2;j++) {
      cout<<b[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n\n";
}

template <class X> void Matrix<X>::Addition() {

  int i,j;

  if(m1==m2 && n1==n2) {

		for(i=0;i<m1;i++) {
			for(j=0;j<n1;j++) {
				c[i][j]=a[i][j]+b[i][j];
			}
		}

    Display();
    cout<<"Addition:\n";

    for(i=0;i<m1;i++) {
      for(j=0;j<n1;j++) {
        cout<<c[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n\n";
  }
  else {
    cout<<"\nAddition not Possible\n\n";
  }
}

template <class X> void Matrix<X>::Subtraction() {

  int i,j;

  if(m1==m2 && n1==n2) {

		for(i=0;i<m1;i++) {
			for(j=0;j<n1;j++) {
				c[i][j]=a[i][j]-b[i][j];
			}
		}

    Display();
    cout<<"Subtraction:\n";

    for(i=0;i<m1;i++) {
      for(j=0;j<n1;j++) {
        cout<<c[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n\n";
  }
  else {
    cout<<"\nSubtraction not Possible\n\n";
  }
}

template <class X> void Matrix<X>::Multiplication() {

  int i,j,k;

  if(n1==m2) {

		for(i=0;i<m1;i++) {
			for(j=0;j<n2;j++) {
				for(k=0;k<n1;k++) {
					c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
				}
			}
    }
    Display();
    cout<<"Multiplication:\n";

    for(i=0;i<m1;i++) {
      for(j=0;j<n2;j++) {
        cout<<c[i][j]<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n\n";
  }
  else {
    cout<<"\nMultiplcation not Possible\n\n";
  }
}

int main() {

    Matrix <int> M1;
    Matrix <float> M2;

    int ch,flag=0;

    do
    {
        cout<<"1. Accept 2 integer Matrices\n";
        cout<<"2. Accept 2 floating Matrices\n";
        cout<<"3. Addition\n";                     //Menu for user
        cout<<"4. Subtraction\n";
        cout<<"5. Multiplication\n";
        cout<<"6. Exit\n\n";
        cout<<"Your choice: ";
        cin>>ch;

        cout<<endl<<endl;

        if(ch==1 || ch==2 ||ch==6||flag==1)
        {

            switch(ch)
            {
                case 1: {

                  M1.Accept();
                  flag=1;
                  cout<<"\n\n";
                  break;
                }

                case 2: {

                  M2.Accept();
                  flag=1;
                  cout<<"\n\n";
                  break;
                }

                case 3: {

                  M1.Addition();
                  M2.Addition();
                  break;
                }

                case 4: {

                  M1.Subtraction();
                  M2.Subtraction();
                  break;
                }

                case 5: {

                  M1.Multiplication();
                  M2.Multiplication();
                  break;
                }

                case 6: {

                  cout<<"End\n\n";
                  break;
                }

                default:cout<<"Enter a value between 1 and 5\n\n";
            }
        }
        else
        {
            cout<<"Please give some Input 1st\n\n";
        }

    }
    while(ch!=6);

    return 0;
}

/*

Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Generic_Programming_Templates
1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 1


Enter size of Matrix 1
Number of Rows: 2
Number of Columns: 2

Enter elements: 1 2 3 4


Enter size of Matrix 2
Number of Rows: 2
Number of Columns: 2

Enter elements: 4 3 2 1


1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 2


Enter size of Matrix 1
Number of Rows: 2
Number of Columns: 2

Enter elements: 1.1 2.2 3.3 4.4


Enter size of Matrix 2
Number of Rows: 2
Number of Columns: 2

Enter elements: 4.4 3.3 2.2 1.1


1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 3


Matrix 1:
1 2
3 4


Matrix 2:
4 3
2 1


Addition:
5 5
5 5


Matrix 1:
1.1 2.2
3.3 4.4


Matrix 2:
4.4 3.3
2.2 1.1


Addition:
5.5 5.5
5.5 5.5


1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 4


Matrix 1:
1 2
3 4


Matrix 2:
4 3
2 1


Subtraction:
-3 -1
1 3


Matrix 1:
1.1 2.2
3.3 4.4


Matrix 2:
4.4 3.3
2.2 1.1


Subtraction:
-3.3 -1.1
1.1 3.3


1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 5


Matrix 1:
1 2
3 4


Matrix 2:
4 3
2 1


Multiplication:
5 4
21 16


Matrix 1:
1.1 2.2
3.3 4.4


Matrix 2:
4.4 3.3
2.2 1.1


Multiplication:
6.38 4.95
25.3 19.03


1. Accept 2 integer Matrices
2. Accept 2 floating Matrices
3. Addition
4. Subtraction
5. Multiplication
6. Exit

Your choice: 6


End

Someshwars-MacBook-Pro:C++ someshwargaikwad$ 
*/
