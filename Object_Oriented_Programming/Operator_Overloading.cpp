/*
================================================================
Title     : Operator Overloading
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

WAP to design a class ‘Complex ‘with data members for real and imaginary part.
Provide default and parameterized constructors. Write a program to perform
arithmetic operations of two complex numbers using operator overloading.
 
 i. Addition and subtraction using friend functions.
 ii. Multiplication and division using member functions.
================================================================*/

#include<iostream>
using namespace std;

class Complex
{
    private:

    float Real,Img;
    

    public:

    friend Complex operator+(Complex& ,Complex&);
    friend Complex operator-(Complex& ,Complex&);
    Complex operator*(Complex&);                          //Operator Overloading using Functions
    Complex operator/(Complex&);
    friend ostream& operator<<(ostream& ,Complex&);
    friend istream& operator>>(istream& ,Complex&);

    Complex()      //Default Constructor
    {
        Real=0;
        Img=0;
    }
};

Complex operator+(Complex& z1, Complex& z2)
{
    Complex temp;
    
    temp.Real=z1.Real+z2.Real;           //calculating Addition
    temp.Img=z1.Img+z2.Img;
    
    return temp;    // returning result of addition
}


Complex operator-(Complex& z1, Complex& z2)
{
    Complex temp;
    
    temp.Real=z1.Real-z2.Real;         //calculating Subtraction
    temp.Img=z1.Img-z2.Img;
    
    return temp;       //returning result of Subtraction
}

Complex Complex::operator/(Complex& z)
{
    Complex temp;
    if(z.Img!=0 && z.Real!=0)
    {
        float x=((Real*z.Real)+(Img*z.Img))/((z.Real*z.Real)+(z.Img*z.Img));
        float y=(Real*(-(z.Img))+(Img*z.Real))/((z.Real*z.Real)+(z.Img*z.Img));   //Division of complex numbers
        temp.Real=x;
        temp.Img=y;
    }
    
    else
    {
        cout<<"\n\nDivision not Possible\n";
        cout<<"Displaying Default Value: ";       //validation if divided by 0
    }
    
    return temp;    //returning result of Division
}

Complex Complex::operator*(Complex& z)
{
    Complex temp;
    
    temp.Real=(Real*z.Real)-(Img*z.Img);     //Multiplying two complex numbers
    temp.Img=(Real*z.Img)+(Img*z.Real);
    
    return temp;    //returning result of Multiplication
}

ostream& operator<<(ostream& o,Complex& z)  //overloading << operator (output)
{
    if(z.Img>=0)
    {
        o<<z.Real<<"+"<<z.Img<<"i"<<endl;
    }
    else
    {
        o<<z.Real<<z.Img<<"i"<<endl;
    }
    
    return o;
}

istream& operator>>(istream& i,Complex& z)   //overloding >> operator (input)
{
    cout<<"Real Part: ";
    i>>z.Real;
    cout<<endl;
    
    cout<<"Imaginary Part: ";
    i>>z.Img;
    cout<<endl;
    
    return i;
}

int main()
{
    Complex z1,z2,z;
    
    int ch,flag=0;

    do
    {
        cout<<"1. Accept 2 Complex Numbers\n"; 
        cout<<"2. Addition\n";                     //Menu for user
        cout<<"3. Subtraction\n";
        cout<<"4. Multiplication\n";
        cout<<"5. Division\n";
        cout<<"6. Exit\n\n";
        cout<<"Your choice: ";
        cin>>ch;
        
        cout<<endl<<endl;
        
        if(ch==1||ch==6||flag==1)
        {
        
            switch(ch)
            {
                case 1:cout<<"Enter Complex Number 1:\n";
                       cin>>z1;
                   
                       cout<<endl;
                   
                       cout<<"Enter Complex Number 2:\n";
                       cin>>z2;
                   
                       cout<<endl<<endl;
                   
                       flag=1;
     
                       break;
            
                case 2:cout<<"Complex 1: ";
                       cout<<z1;
                       cout<<"\n";
    
                       cout<<"Complex 2: ";
                       cout<<z2;
                       cout<<"\n";
    
                       cout<<"Addition: ";
                       z=z1+z2;               //function call for addition
                   
                       cout<<z;
                       cout<<"\n\n";
                   
                       break;

                case 3:cout<<"Complex 1: ";
                       cout<<z1;
                       cout<<"\n";
    
                       cout<<"Complex 2: ";
                       cout<<z2;
                       cout<<"\n";
    
                       cout<<"Subtraction: ";
                       z=z1-z2;                 //function call for subtraction
                   
                       cout<<z;
                       cout<<"\n\n";
                   
                       break;  
                   
                case 4:cout<<"Complex 1: ";
                       cout<<z1;
                       cout<<"\n";
    
                       cout<<"Complex 2: ";
                       cout<<z2;
                       cout<<"\n";
    
                       cout<<"Multiplication: ";
                       z=z1*z2;                     //function call for Multiplcation
                   
                       cout<<z;
                       cout<<"\n\n";
                   
                       break; 
                   
                case 5:cout<<"Complex 1: ";
                       cout<<z1;
                       cout<<"\n";
    
                       cout<<"Complex 2: ";
                       cout<<z2;
                       cout<<"\n";
    
                       cout<<"Division: ";
                       z=z1/z2;                //function call for Division
                   
                       cout<<z;
                       cout<<"\n\n";
                   
                       break;                                                                         
   
                case 6:cout<<"End\n\n";
                    
                   break;
            
                default:cout<<"Enter a value between 1 and 5\n\n";
            }
        }
        else           
        {
            cout<<"Please give some Input 1st\n\n";
        }
        
        if(ch==6)
        {
            break;
        }
        
    }
    while(ch!=6);   
   
    return 0;
}

/*
 ===============================================================================================
 OutPut:
 ===============================================================================================
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 2
 
 
 Please give some Input 1st
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 1
 
 
 Enter Complex Number 1:
 Real Part: 12
 
 Imaginary Part: 23
 
 
 Enter Complex Number 2:
 Real Part: 54
 
 Imaginary Part: 12
 
 
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 2
 
 
 Complex 1: 12+23i
 
 Complex 2: 54+12i
 
 Addition: 66+35i
 
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 3
 
 
 Complex 1: 12+23i
 
 Complex 2: 54+12i
 
 Subtraction: -42+11i
 
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 4
 
 
 Complex 1: 12+23i
 
 Complex 2: 54+12i
 
 Multiplication: 372+1386i
 
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 5
 
 
 Complex 1: 12+23i
 
 Complex 2: 54+12i
 
 Division: 0.301961+0.358824i
 
 
 1. Accept 2 Complex Numbers
 2. Addition
 3. Subtraction
 4. Multiplication
 5. Division
 6. Exit
 
 Your choice: 6
 
 
 End
 
 Someshwars-MBP-0ae4:C++ someshwargaikwad$

 ===============================================================================================
 */
