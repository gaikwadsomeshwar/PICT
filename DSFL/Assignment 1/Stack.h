#include "List.h"

class Stack {

	private:

	List top;

	public:

	Stack();
	~Stack();
	void push(int data);
	int pop();
	int showTop();
	bool isEmpty();
	void revStack();
	void display();
};
