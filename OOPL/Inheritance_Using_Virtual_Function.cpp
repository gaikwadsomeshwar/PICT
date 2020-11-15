/*
================================================================
Title     : Inheritance Using Virtual Function
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Create a base class shape with two double type values and member
functions to input the data and compute_area() for calculating
area of figure.

Derive two classes’ triangle and rectangle. Make compute_area()
as a virtual function and redefine this function in the derived class
to suit their requirements. Write a program that accepts dimensions
of triangle/rectangle and display calculated area..
================================================================*/

#include<iostream>
using namespace std;

class Shape {

protected:
  double width,height;

public:

  virtual void compute_area()=0;            //Virtual Function
  void set_dimensions();
};

class Rectangle: public Shape {

public:
  void compute_area() { cout<<"Area of Rectangle: "<<(width*height)<<endl<<endl; }   //Overriding Virtual Function
};

class Triangle: public Shape {

public:
  void compute_area() { cout<<"Area of Triangle: "<<(0.5*width*height)<<endl<<endl; }    //Overriding Virtual Function
};

void Shape::set_dimensions() {

  cout<<"Width: ";
  cin>>width;

  cout<<"Height: ";
  cin>>height;

  cout<<"\n\n";
}

int main() {

  Shape *s=new Rectangle();

  cout<<"Enter dimensions of Rectangle\n";
  s->set_dimensions();
  s->compute_area();

  s=new Triangle();

  cout<<"Enter dimensions of Triangle\n";
  s->set_dimensions();
  s->compute_area();

  return 0;
}

/*
Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Inheritance_Using_Virtual_Function
Enter dimensions of Rectangle
Width: 34
Height: 12.5


Area of Rectangle: 425

Enter dimensions of Triangle
Width: 23.5
Height: 23


Area of Triangle: 270.25

Someshwars-MacBook-Pro:C++ someshwargaikwad$
*/
