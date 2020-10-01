//============================================================================
// Name        : SeqFile.cpp
// Author      : Sachin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {


	struct student{
		int rollno;
		string name;
		int division;
		struct address{
			 // nested structure for address
		};
	};

	class studentInfo{
		student record;
	public:

		addRecord(); // get the data from user and write into the file using file operations
		//need to open the file in write mode, once operation completed close the file.

		displayallRecords();// open the file in read mode and display all records in tabular form
		//close the file

		serachRecord(int rollno);//open the file, get the roll no from user and search the record, if found display
		// record else display appropriated message
		// close the file

		deleteRecord(int rollno);// get the roll no from user, search the record if found delete the record
		// display appropriate message
		// close the file
	};

//	Note:We have implemented the sequential file in PL, logic is same you just need to use appropriate C++ functions


	return 0;
}
