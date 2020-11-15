#include "List.h"

List::List() { head=NULL; }

List::~List() { delete head; }

int List::Reveal() {

	if (head!=NULL)
		return head->data;

	else
		return 0;
}

void List::Insert(int data) {

	node *temp=new node;

	temp->data=data;
	temp->next=NULL;

	if(head==NULL)
		head=temp;

	else {

		temp->next=head;
		head=temp;
	}
}

int List::Delete() {

	node *ptr=head;
	int data=head->data;

	ptr=ptr->next;
	delete head;
	head=ptr;

	return data;
}

void List::revList() {

	node *temp,*rev=NULL,*ptr=head;

	while(ptr!=NULL) {

		temp=ptr->next;
		ptr->next=rev;
		rev=ptr;
		ptr=temp;
	}
	head=rev;
}
