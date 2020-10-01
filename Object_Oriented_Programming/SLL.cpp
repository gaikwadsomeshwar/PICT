#include<iostream>
using namespace std;

class node {
	
	public :
	
	int data;
	node *next;
};

class SLL {

	node *head;
	
	public:
	
	SLL();
	void Create();
	void Insert(int pos);
	void Delete(int pos);
	void Display();
};

SLL::SLL() { head=NULL; }

void SLL::Create() {

	head=NULL;
	int size,flag;
	node *temp=new node;
	
	cout<<"Enter data: ";
	cin>>temp->data;
	temp->next=NULL;
	
	head=temp;
	
	do {
	
		cout<<"\n------------------------------\n";
		cout<<"0. Stop Adding Node\n";
		cout<<"1. Add a new Node\n\n";
		cout<<"Your Choice: ";
		cin>>flag;
		cout<<"------------------------------\n\n";
		
		if(flag==1) {
			
			temp->next=new node;
			temp=temp->next;
			
			cout<<"Enter data: ";
			cin>>temp->data;
			temp->next=NULL;
		}
	}
	while(flag!=0);
}

void SLL::Display() {

	node *temp=head;
	
	while(temp!=NULL) {
		
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl<<endl;
}

void SLL::Insert(int pos) {
	
	node *ptr=head;
	node *temp=new node;
	int currentPos=2;
	
	cout<<"Enter data: ";
	cin>>temp->data;
	
	if(pos<=1) {
	
		temp->next=head;
		head=temp;
	}
	
	if(pos>1) {
	
		while(ptr->next!=NULL && currentPos<pos) {
			
			ptr=ptr->next;
			currentPos++;
		}
		
		temp->next=ptr->next;
		ptr->next=temp;
	}
}

void SLL::Delete(int pos) {
	
	node *ptr=head;
	node *temp;
	int currentPos=1;
	
	if(pos<=1) {
	
		ptr=ptr->next;
		delete head;
		head=ptr;
	}
	
	if(pos>1) {
	
		do {
			
			temp=ptr;
			ptr=ptr->next;
			currentPos++;
		}
		while(ptr->next!=NULL && currentPos<pos);
		
		temp->next=ptr->next;
		delete ptr;
	}
}
	
int main() {

	SLL list;
	
	int ch,flag,pos;
	
	do {
		
		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Create New List\n";
		cout<<"2. Display List\n";
		cout<<"3. Insert an element\n";
		cout<<"4. Delete an element\n";
		cout<<"5. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";
		
		if(ch==1 || flag==1) {
		
			switch(ch) {
			
				case 1: {
					
					cout<<"Creating new list\n";
					list.Create();
					cout<<"\nYour List: ";
					list.Display();
					flag=1;
					break;
				}
				
				case 2: {
					
					cout<<"\nYour List: ";
					list.Display();
					break;
				}
				
				case 3: {
				
					cout<<"Enter position: ";
					cin>>pos;
					
					list.Insert(pos);
					cout<<"\nYour List: ";
					list.Display();
					break;
				}
				
				case 4: {
				
					cout<<"Enter position: ";
					cin>>pos;
					
					list.Delete(pos);
					cout<<"\nYour List: ";
					list.Display();
					break;
				}
				
				case 5: {
					
					cout<<"End\n";
					break;
				}
				
				default: cout<<"Select Correct Option\n\n";
			}
		}
		else {
		
			cout<<"Create a List First\n\n";
		}
	}
	while(ch!=5);	
	return 0;
}
