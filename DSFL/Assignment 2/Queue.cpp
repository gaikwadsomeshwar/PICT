#include "Queue.h"

node::node() {

	next=NULL;
	data=NULL;
	priority=0;
}

void node::Display() {

    cout<<"================================\n";
	cout<<"Name    : "<<data->name<<endl;
    cout<<"City    : "<<data->city<<endl;
    cout<<"Age     : "<<data->age<<endl;
	cout<<"Priority: "<<priority<<endl;
    cout<<"================================\n";
}

Queue::Queue() { front=NULL; rear=NULL; }

Queue::~Queue() { delete front; delete rear; }

void Queue::EnQueue(node* data) {

	data->next=NULL;
	node *ptr,*temp;

	if(front==NULL)
		front=data;

	else if(data->priority>front->priority) {

		data->next=front;
		front=data;
	}

	else {

		ptr=front;
		temp=ptr;

		while(ptr->next!=NULL && data->priority<=ptr->priority) {

			temp=ptr;
			ptr=ptr->next;
		}

		if(data->priority>ptr->priority) {

			temp->next=data;
			data->next=ptr;
		}

		else {

			data->next=ptr->next;
			ptr->next=data;
		}
	}

	ptr=front;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	rear=ptr;
}

node* Queue::DeQueue() {

	node *data;

	if(front!=NULL && rear!=NULL) {


		data=front;
		front=front->next;
		data->next=NULL;

		return data;
	}

	else
		return NULL;
}

void Queue::Display() {

	node *ptr=front;

	if(ptr==NULL)
		cout<<"Record Empty\n";

	while(ptr!=NULL) {

		ptr->Display();
		ptr=ptr->next;
	}
}
