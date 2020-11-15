#include<iostream>
#include<cstring>
using namespace std;

#define MAX 10

struct student;
struct HT;
class LP_withreplacement;
class LP_withoutreplacement;

struct student {
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
	void init();
	void insert(student key);
	void display();
	int search(long tel_number);

};
class LP_withoutreplacement{

	HT Records[MAX];

public:
	void init();
	void insert(student key);
	void display();
	int search(long tel_number);
};
