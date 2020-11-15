/*================================================================
Title     : FILE HANDLING IN C++(SEQUENTIAL FILE )
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Write a program in C++ to implement sequential file for students' database
and perform following operations on it
1. Create
2. Display
3. Add
4. Delete
5. Modify
================================================================*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class FileHandling {

	char name[30];
	int rollno,age;
	float marks;

public:

	FileHandling() {

		rollno=0;
		age=0;
		marks=0.0;
	}

	void Create();
	void Display();
	void Insert();
	void Modify();
	void Delete();

	~FileHandling () {}
};

void FileHandling::Create() {

	int size,i;
	ofstream fout;

	fout.open("Student_Records.txt",ios::trunc);

	cout<<"Enter the number of Records: ";
	cin>>size;
	cout<<endl;

	for(i=0;i<size;i++) {
		Insert();
	}
	fout.close();
}

void FileHandling::Display() {

	ifstream fin;
	fin.open("Student_Records.txt");

	cout<<"Roll No.\tName\tAge\tMarks\n";

	while(fin>>rollno>>name>>age>>marks) {
		cout<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
	}
	fin.close();
}

void FileHandling::Insert() {

	char dummy[1];
	ofstream fout;
	ifstream temp;
	int Rollno;

	fout.open("Student_Records.txt",ios::ate|ios::app);
	temp.open("Student_Records.txt");

	cout<<"Roll No: ";
	cin>>rollno;

	while(temp>>Rollno>>name>>age>>marks) {

		if(rollno==Rollno) {

			cout<<"\nRoll Number already exists\nEnter Again\n\n";
			cout<<"Roll No:";
			cin>>rollno;
			temp.close();
			temp.open("Student_Records.txt");
		}
	}
	temp.close();

	cout<<"Name: ";
	cin.getline(dummy,1);
	cin.getline(name,30);

	cout<<"Age: ";
	cin>>age;

	while(age<5 || age>21) {

		cout<<"\nInvalid Age\nEnter Again\n\n";
		cout<<"Age: ";
		cin>>age;
	}

	cout<<"Marks: ";
	cin>>marks;

	while(marks<0) {

		cout<<"\nInvalid Marks\nEnter Again\n\n";
		cout<<"Marks: ";
		cin>>marks;
	}

	cout<<endl;

	fout<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
	fout.close();
}

void FileHandling::Modify() {

	int Rollno,ch,flag=0;
	char dummy[1];

	cout<<"Enter Roll Number: ";
	cin>>Rollno;

	cout<<"\n1. Modify Name\n";
	cout<<"2. Modify Age\n";
	cout<<"3. Modify Marks\n";
	cout<<"4. Back\n\n";
	cout<<"Your Choice: ";
	cin>>ch;

	ifstream fin;
	ofstream fout;

	fin.open("Student_Records.txt");
	fout.open("Temp.txt");

	while(fin>>rollno>>name>>age>>marks) {

		if(Rollno==rollno) {

			cout<<"\nModifying Record:\n\n";
			cout<<"Roll No: "<<rollno<<endl;
			cout<<"Name   : "<<name<<endl;
			cout<<"Age    : "<<age<<endl;
			cout<<"Marks  : "<<marks<<endl<<endl;
			flag=1;

			switch(ch) {

				case 1: {

					cout<<"Name: ";
					cin.getline(dummy,1);
					cin.getline(name,30);

					fout<<"\n"<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
					break;
				}

				case 2: {
					cout<<"Age: ";
					cin>>age;

					fout<<"\n"<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
					break;
				}

				case 3: {

					cout<<"Marks: ";
					cin>>marks;

					fout<<"\n"<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
					break;
				}

				case 4: break;
			}
		}
		else {
			fout<<"\n"<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
		}
	}
	fin.close();
	fout.close();
	remove("Student_Records.txt");
	rename("Temp.txt","Student_Records.txt");

	if(flag==0) {
		cout<<"Record not Found";
	}
}

void FileHandling::Delete() {

	int Rollno,flag=0;

	cout<<"Enter Roll Number: ";
	cin>>Rollno;

	ifstream fin;
	ofstream fout;

	fin.open("Student_Records.txt");
	fout.open("Temp.txt");

	while(fin>>rollno>>name>>age>>marks) {

		if(Rollno==rollno) {
			cout<<"\nDeleting Record:\n\n";
			cout<<"Roll No: "<<rollno<<endl;
			cout<<"Name   : "<<name<<endl;
			cout<<"Age    : "<<age<<endl;
			cout<<"Marks  : "<<marks<<endl<<endl;
			flag=1;
		}
		else {
			fout<<"\n"<<rollno<<"\t"<<name<<"\t"<<age<<"\t"<<marks<<"\n";
		}
	}
	fin.close();
	fout.close();
	remove("Student_Records.txt");
	rename("Temp.txt","Student_Records.txt");

	if(flag==0) {
		cout<<"Record not Found";
	}
}

int main() {

	FileHandling FILE;

	int ch,flag=0;

	do {
		cout<<("1. Create a Record\n");
		cout<<("2. Display Record\n");
		cout<<("3. Add a Record\n");
		cout<<("4. Modify a Record\n");
		cout<<("5. Delete a Record\n");
		cout<<("6. Exit\n");
		cout<<("\nYour Choice: ");

		cin>>ch;

		cout<<"\n\n";

		if(ch==1||flag==1||ch==6) {

			switch(ch) {

				case 1: {

					FILE.Create();
					flag=1;
					cout<<endl;
					break;
				}

				case 2: {

					FILE.Display();
					cout<<endl<<endl;
					break;
				}

				case 3: {

					FILE.Insert();
					cout<<endl<<endl;
					break;
				}

				case 4: {

					cout<<"Before Modifying:\n\n";
					FILE.Display();
					cout<<endl<<endl;
					FILE.Modify();
					cout<<"\n\nAfter Modifying:\n\n";
					FILE.Display();
					cout<<endl<<endl;
					break;
				}

				case 5: {

					cout<<"Before Deleting:\n\n";
					FILE.Display();
					cout<<endl<<endl;
					FILE.Delete();
					cout<<"\n\nAfter Deleting:\n\n";
					FILE.Display();
					cout<<endl<<endl;
					break;
				}

				case 6: {

					cout<<"End\n";
					break;
				}

				default: cout<<"Enter a value between 1 and 6\n\n";
			}
		}
		else {
			cout<<("Record Empty\n\nAdd some values first\n\n");
		}
	}
	while(ch!=6);
	return 0;
}

/*

Output:

Someshwars-MBP-0ae4:C++ someshwargaikwad$ g++ File_Handling_in_Cpp.cpp -o File_Handling_in_Cpp
Someshwars-MBP-0ae4:C++ someshwargaikwad$ ./File_Handling_in_Cpp
1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 2


Record Empty

Add some values first

1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 1


Enter the number of Records: 4

Roll No: 23257
Name: Someshwar
Age: 23

Invalid Age
Enter Again

Age: 20
Marks: 34

Roll No: 23257

Roll Number already exists
Enter Again

Roll No:23255
Name: Shreyas
Age: 12
Marks: 55

Roll No: 23256
Name: Sushant
Age: 13
Marks: 56

Roll No: 23260
Name: Tanmay
Age: 15
Marks: 45


1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 2


Roll No.	Name	Age	Marks
23257	Someshwar	20	34
23255	Shreyas	12	55
23256	Sushant	13	56
23260	Tanmay	15	45


1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 4


Before Modifying:

Roll No.	Name	Age	Marks
23257	Someshwar	20	34
23255	Shreyas	12	55
23256	Sushant	13	56
23260	Tanmay	15	45


Enter Roll Number: 23257

1. Modify Name
2. Modify Age
3. Modify Marks
4. Back

Your Choice: 2

Modifying Record:

Roll No: 23257
Name   : Someshwar
Age    : 20
Marks  : 34

Age: 18


After Modifying:

Roll No.	Name	Age	Marks
23257	Someshwar	18	34
23255	Shreyas	12	55
23256	Sushant	13	56
23260	Tanmay	15	45


1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 3


Roll No: 23264
Name: Muskaan
Age: 12
Marks: 66



1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 2


Roll No.	Name	Age	Marks
23257	Someshwar	18	34
23255	Shreyas	12	55
23256	Sushant	13	56
23260	Tanmay	15	45
23264	Muskaan	12	66


1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 5


Before Deleting:

Roll No.	Name	Age	Marks
23257	Someshwar	18	34
23255	Shreyas	12	55
23256	Sushant	13	56
23260	Tanmay	15	45
23264	Muskaan	12	66


Enter Roll Number: 23260

Deleting Record:

Roll No: 23260
Name   : Tanmay
Age    : 15
Marks  : 45



After Deleting:

Roll No.	Name	Age	Marks
23257	Someshwar	18	34
23255	Shreyas	12	55
23256	Sushant	13	56
23264	Muskaan	12	66


1. Create a Record
2. Display Record
3. Add a Record
4. Modify a Record
5. Delete a Record
6. Exit

Your Choice: 6


End
Someshwars-MBP-0ae4:C++ someshwargaikwad$ 

*/
