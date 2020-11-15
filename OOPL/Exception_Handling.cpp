/*
================================================================
Title     : Exception Handling
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Write a program in C++ which includes the code for following operations :
i.   A function to read two double type numbers from keyboard
ii.  A function to calculate the division of these two numbers
iii. A try block to detect and throw an exception if the condition “divide-by-
     zero”occurs
iv.  Appropriate catch block to handle the exceptions thrown
================================================================
*/

#include<iostream>
using namespace std;

class DivisionHandling {

  double x,y;

  public:

  DivisionHandling() {

    x=0.0;
    y=0.0;
  }

  void accept();
  void compute();
};

void DivisionHandling::accept() {

  cout<<"Enter 2 numbers\n";
  cout<<"Divdend: ";
  cin>>x;
  cout<<"Divisor: ";
  cin>>y;
  cout<<"\n";
}

void DivisionHandling::compute() {

  if(y==0)
    throw(y);

  else
    cout<<"Division is: "<<(x/y)<<"\n\n";
}

int main() {

  DivisionHandling D;
  D.accept();

  try {
    D.compute();
  }

  catch(double y) {

    cout<<"Division not possible. It's an Exception\n\n";
  }
}

/*

Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling
Enter 2 numbers
Divdend: 5
Divisor: 4

Division is: 1.25

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling
Enter 2 numbers
Divdend: 5
Divisor: 0

Division not possible. It's an Exception

Someshwars-MacBook-Pro:C++ someshwargaikwad$

*/
