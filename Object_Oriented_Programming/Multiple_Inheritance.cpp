/*
================================================================
Title     : Multiple Inheritance
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Create employee bio-data using following classes:

1. Personal record
2. Professional record
3. Academic record

Assume appropriate data members and member function to accept required
data & print bio-data. Create bio-data using multiple inheritance using C++.
================================================================*/

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class PersonalRecord {   //Contains Physical Records

  protected:

    char name[50];
    char add[50];
    char blood_grp[3];

  public:

    void set_values();     //Input function for data members
};

class ProfessionalRecord {     //Contains Professional Records

  protected:

    char skill[25];
    int work_exp;

  public:

    void set_values();      //Input function for data members

};

class AcademicRecord {        //Contains Academic Records

  protected:

    char degree[25];
    float percentage;

  public:

    void set_values();          //Input function for data members

};

class Resume:public PersonalRecord,public ProfessionalRecord,public AcademicRecord {

  public:

    void display();      //Displays the resume
};

void PersonalRecord :: set_values() {

  cout<<"Name: ";
  cin>>name;

  cout<<"Address: ";
  cin>>add;

  cout<<"Blood Group: ";
  cin>>blood_grp;

  for(int i=0;i<strlen(blood_grp);i++) {
    if(isalpha(blood_grp[i])!=0)
      blood_grp[i]=toupper(blood_grp[i]);
  }

  do {

    if(strcmp(blood_grp,"A+")==0)
      break;

    else if(strcmp(blood_grp,"B+")==0)
      break;

    else if(strcmp(blood_grp,"AB+")==0)
      break;

    else if(strcmp(blood_grp,"O+")==0)
      break;

    else if(strcmp(blood_grp,"A-")==0)
      break;

    else if(strcmp(blood_grp,"B-")==0)
      break;

    else if(strcmp(blood_grp,"AB-")==0)
      break;

    else if(strcmp(blood_grp,"O-")==0)
      break;

    else {

      cout<<"\nInvalid Blood Group\n";
      cout<<"Enter Again:\n\n";
      cout<<"Blood Group: ";
      cin>>blood_grp;

      for(int i=0;i<strlen(blood_grp);i++) {
        if(isalpha(blood_grp[i])!=0)
          blood_grp[i]=toupper(blood_grp[i]);
      }
    }
  }
  while(1);
}

void ProfessionalRecord :: set_values() {

  cout<<"Work Experience: ";
  cin>>work_exp;

  cout<<"Skill: ";
  cin>>skill;
}

void AcademicRecord :: set_values() {

  cout<<"Degree: ";
  cin>>degree;

  cout<<"Percentage: ";
  cin>>percentage;

}

void Resume :: display() {

    cout<<setw(14)<<name<<setw(7)<<blood_grp;
    cout<<setw(8)<<work_exp<<setw(16)<<skill;
    cout<<setw(12)<<degree<<setw(12)<<percentage<<"\t"<<add<<"\n";
}

int main() {

    int ch,i,n,flag=0;
    static int pos;

    Resume R[50];

    do {

        cout<<"1. Insert Records\n";
        cout<<"2. Display Records\n";   //Menu for user
        cout<<"3. Exit\n\n";
        cout<<"Your Choice: ";
        cin>>ch;

        cout<<"\n\n";

        if(ch!=2 || flag==1) {

          switch(ch) {

            case 1: {

                cout<<"Enter the number of Records you want to add: ";
                cin>>n;

                cout<<"\n\n";

                n=n+pos;

                for(i=pos;i<n && i<50;i++)
                {
                  R[i].PersonalRecord::set_values();
                  R[i].ProfessionalRecord::set_values();    //Function calls for accepting values
                  R[i].AcademicRecord::set_values();
                  cout<<"\n\n";
                }
                pos=i;

                if(i==50)
                {
                    cout<<"Record Full";
                }

                flag=1;
                break;
            }

            case 2: {

              cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
              cout<<setw(8)<<"Name"<<setw(15)<<"Bl. Grp."<<setw(10)<<"Work Exp."<<setw(10)<<"Skill"<<setw(15)<<"Degree"<<setw(15)<<"Percentage"<<setw(15)<<"Address\n";
              cout<<"----------------------------------------------------------------------------------------------------------------------------\n";

                for(i=0;i<pos;i++)
                {
                    R[i].display();       //function call for printing the resume
                }

                cout<<"\n\n";
                break;
            }

            case 3: {

                cout<<"End\n\n";
                break;
            }

            default:

                cout<<"Enter a value between 1 and 7\n\n";
        }
      }

      else {
          cout<<"Record Empty\nEnter some Records\n\n";
      }
    }
    while(ch!=3);

    return 0;
}

/*

Output:

Someshwars-MacBook-Pro:C++ someshwargaikwad$ g++ Multiple_Inheritance.cpp -o Multiple_Inheritance
Someshwars-MacBook-Pro:C++ someshwargaikwad$ ./Multiple_Inheritance
1. Insert Records
2. Display Records
3. Exit

Your Choice: 2


Record Empty
Enter some Records

1. Insert Records
2. Display Records
3. Exit

Your Choice: 1


Enter the number of Records you want to add: 3


Name: Someshwar
Address: Mundhwa
Blood Group: n+

Invalid Blood Group
Enter Again:

Blood Group: o+
Work Experience: 5
Skill: Programming
Degree: BE
Percentage: 74


Name: Muskaan
Address: Akola
Blood Group: o-
Work Experience: 6
Skill: Managing
Degree: BBA
Percentage: 87


Name: Shreyas
Address: Pune
Blood Group: b+
Work Experience: 5
Skill: Leader
Degree: MBA
Percentage: 78


1. Insert Records
2. Display Records
3. Exit

Your Choice: 2


----------------------------------------------------------------------------------------------------------------------------
    Name       Bl. Grp. Work Exp.     Skill         Degree     Percentage       Address
----------------------------------------------------------------------------------------------------------------------------
     Someshwar     O+       5     Programming          BE          74	Mundhwa
       Muskaan     O-       6        Managing         BBA          87	Akola
       Shreyas     B+       5          Leader         MBA          78	Pune


1. Insert Records
2. Display Records
3. Exit

Your Choice: 3


End

Someshwars-MacBook-Pro:C++ someshwargaikwad$

*/
