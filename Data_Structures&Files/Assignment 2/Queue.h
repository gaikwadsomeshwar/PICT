#include <iostream>
#include <cstring>
using namespace std;

class Queue;
class Patient;

class node {

	int priority;
	node *next;
	Patient *data;

	public:

	node();
	void Display();
	friend class Queue;
	friend class Patient;
};

class Queue {

	private:

	node *front;
	node *rear;

	public:

	Queue();
	~Queue();
	void EnQueue(node* data);
	node* DeQueue();
	void Display();
};

class Patient {

	char *name,*city;
	int age;
	Queue Q;
	node *data;

	public:

	Patient();
	void Admit();
	void Display();
	void Attend();
	friend class node;
	friend class Queue;
};
