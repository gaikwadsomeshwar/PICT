/*
================================================================
Title     : Exception Handling Televison Problem
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Create a class named Televison that has data members: model_no,
screen_size (inches) and price.

If more than 4 digit number is entered for model_no OR if screen_size
is less than 12 or greater than 17 OR if price is negative or grater than
$5000 then throw an exception.

Write a main function that instantiates the object and allows user to
enter data members. If an exception is caught, replace all data members
with value zero.

================================================================
*/

#include<iostream>
using namespace std;

class Televison {

  int model_no;
  float screen_size;
  double price;

public:

  Televison() {

    model_no=0;
    screen_size=0.0;
    price=0.0;
  }

  friend istream& operator>>(istream&,Televison&);
  friend ostream& operator<<(ostream&,Televison&);    //Operator Oveloading
};

istream& operator>>(istream& input,Televison &TV) {

  cout<<"Model Number:  ";
  input>>TV.model_no;

  int q=TV.model_no/10000;
  if(q>0)
    throw(TV.model_no);

  cout<<"Screen Size: ";
  input>>TV.screen_size;

  if(TV.screen_size<12 || TV.screen_size>17)    //Throwing exception as per question
    throw(TV.screen_size);

  cout<<"Price: $";
  input>>TV.price;

  if(TV.price<0 || TV.price>5000)
    throw(TV.price);

  return input;
}

ostream& operator<<(ostream& out,Televison &TV) {

  out<<"\nModel Number: "<<TV.model_no;
  out<<"\nScreen Size: "<<TV.screen_size;
  out<<"\nPrice: $"<<TV.price;
  out<<"\n\n";

  return out;
}

int main() {

  Televison TV;

  try { cin>>TV; }        //Possiblity of exception while accepting

  catch(int model_no) { TV=Televison(); }

  catch(float screen_size) { TV=Televison(); }     //Exception Handler

  catch(double price) { TV=Televison(); }

  cout<<TV;
}

/*

Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ g++ Exception_Handling_TV.cpp -o Exception_Handling_TV
Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  234
Screen Size: 13
Price: $3452

Model Number: 234
Screen Size: 13
Price: $3452

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  12345

Model Number: 0
Screen Size: 0
Price: $0

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  1234
Screen Size: 11

Model Number: 0
Screen Size: 0
Price: $0

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  123
Screen Size: 17.1

Model Number: 0
Screen Size: 0
Price: $0

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  2
Screen Size: 13
Price: $-10

Model Number: 0
Screen Size: 0
Price: $0

Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Exception_Handling_TV
Model Number:  13
Screen Size: 15
Price: $6543

Model Number: 0
Screen Size: 0
Price: $0

Someshwars-MacBook-Pro:C++ someshwargaikwad$

*/
