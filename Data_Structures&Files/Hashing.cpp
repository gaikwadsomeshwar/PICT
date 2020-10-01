//============================================================================
// Name        : Hashing.cpp
// Author      : Sachin
// Version     :
// Copyright   : Your copyright notice
// Description : Collision Resolution

//============================================================================

#include <iostream>
using namespace std;
#define MAX 10
// Hash function can be defined as macro
//division method or other methods of hashing may be used to get the index/location

struct student{
	string name;
	long tel_number;
};

struct HT{
	student stud;
	int flag;
	int chain;
};

class LP_withreplacement{

	HT Records[MAX];
public:
	//functions for insertion, display and search


};
class LP_withoutreplacement{

	HT Records[MAX];
public:
	//functions for insertion, display and search

};

int main() {

	LP_withreplacement LPWR;
	LP_withoutreplacement LPWTR;

	//case 1 : LP with replacement.....nested case for insert, display and search operations
	//case 2 : LP without replacement.....nested case for insert, display and search operations
	return 0;
}

//output should contain index, record and chain

/* sample o/p

index	record				chain

0		xyz, 0123456789		-1
1		--		--			--
2		--		--			--
3		--		--			--
*/
