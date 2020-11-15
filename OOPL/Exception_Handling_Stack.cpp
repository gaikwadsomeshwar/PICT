/*
================================================================
Title     : Exception Handling Stack
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Use exception handling for implementing a Stack Data Structure
================================================================
*/

#include<iostream>
using namespace std;

class Stack {

  int a[5],top;

public:

  Stack() {

    top=-1;
  }

  void push(int data);
  int pop();
  bool isEmpty();
  bool isFull();
  void display();
};

void Stack::push(int data) {

  if(isEmpty())
    top=0;

  else if(isFull())
    throw(top);

  a[top]=data;
  top++;
}

int Stack::pop() {

  if(isEmpty())
    throw(top);

  int data=a[top];
  top--;

  return data;
}

void Stack::display() {

  int i;
  if(isEmpty())
    throw(top);

  cout<<"Stack Elements: ";
  for(i=0;i<top;i++)
    cout<<a[i]<<" ";
   cout<<"\n\n";
}

bool Stack::isFull() {

  if(top>4)
    return true;

  return false;
}

bool Stack::isEmpty() {

  if(top==-1)
    return true;

  return false;
}

int main() {

  Stack S;
  int i;

  try {

    for(i=0;i<5;i++)
      S.push(i);
    S.push(5);
  }

  catch(int top) {

    if(top==-1)
      cout<<"Stack Empty Exception\n";

    else if(top>4)
      cout<<"Stack Full Exception\n";
  }

  S.display();

  try {

    for(i=0;i<5;i++) {

      S.display();
      S.pop();
    }

    S.pop();
    S.display();
  }

  catch(int top) {

    if(top==-1)
      cout<<"Stack Empty Exception\n";

    else if(top>4)
      cout<<"Stack Full Exception\n";
  }
}

/*

Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_Stack
Stack Full Exception
Stack Elements: 0 1 2 3 4

Stack Elements: 0 1 2 3 4

Stack Elements: 0 1 2 3

Stack Elements: 0 1 2

Stack Elements: 0 1

Stack Elements: 0

Stack Empty Exception
Someshwars-MacBook-Pro:C++ someshwargaikwad$

*/
