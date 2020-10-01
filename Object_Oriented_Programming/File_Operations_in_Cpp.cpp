/*================================================================
Title     : FILE OPERATION  IN C++
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Write a C++ program that creates an output file, writes information to it,
closes the file and open it again as an input file and read the information
from the file.
================================================================*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

const int sizeofLine=20;

class FileOperations {

	char line1[sizeofLine],line2[sizeofLine];

public:

	FileOperations () {}

	void writeToFile(char *line);
	void readFromFile();

	~FileOperations () {}
};

void FileOperations::writeToFile(char *line) {

	ofstream fout;
	fout.open("File.txt",ios::app);

	strcpy(line1,line);
	fout<<line1<<endl;

	fout.close();
}

void FileOperations::readFromFile() {

	ifstream fin;
	fin.open("File.txt");

	while(fin) {

		fin.getline(line2,sizeofLine);
		cout<<line2<<endl;
	}
	fin.close();
}

int main() {

	FileOperations FILE;
	char line[sizeofLine];

	cout<<"Write something to file:";
	cin.getline(line,sizeofLine);
	FILE.writeToFile(line);

	cout<<"Contents of File are:\n\n";
	FILE.readFromFile();

	return 0;
}

/*

Output:

Someshwars-MBP-0ae4:C++ someshwargaikwad$ ./File_Operations_in_Cpp
Write something to file:Someshwar Gaikwad
Contents of File are:

Someshwar Gaikwad

Someshwars-MBP-0ae4:C++ someshwargaikwad$ ./File_Operations_in_Cpp
Write something to file:Hey There!!!!
Contents of File are:

Someshwar Gaikwad
Hey There!!!!

Someshwars-MBP-0ae4:C++ someshwargaikwad$
*/
