#include "Stack.h"

Stack::Stack() { top.head=NULL; }

Stack::~Stack() { delete top.head; }

void Stack::push(int data) { top.Insert(data); }

void Stack::revStack() { top.revList(); }

int Stack::showTop() {	return top.Reveal(); }

int Stack::pop() { return top.Delete(); }

bool Stack::isEmpty() {

	if(top.head==NULL)
		return true;
	else
		return false;
}
