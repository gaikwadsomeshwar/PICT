#include <iostream>
#include <cstring>
using namespace std;

class List;
class Stack;

class node {

	int data;
	node *next;

	public:

	friend class List;
};

class List {

	private:

	node *head;

	public:

	List();
	~List();
	void Insert(int data);
	int Delete();
	int Reveal();
	void revList();
	friend class Stack;
};
