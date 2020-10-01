#include "Tree.h"

node::node() {

	data=-99;
	left=NULL;
	right=NULL;
}

node* Tree::Create() {

	node *root=NULL;
	int data,ch;

	do {

		cout<<"\n==============================\n";
		cout<<"0. Exit\n";
		cout<<"1. Enter Data\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"==============================\n\n";

		if(ch==1) {

			cout<<"Enter Data: ";
			cin>>data;
			root=Insert(root,data);
		}

		else if(ch>1)
			cout<<"Select Correct Option\n";
	}
	while(ch);
	return root;
}

node* Tree::Insert(node *T,int data) {

	if(T==NULL) {
		T=new node();
		T->data=data;
	}

	else if(data>T->data)
		T->right=Insert(T->right,data);

	else if(data<T->data)
		T->left=Insert(T->left,data);

	return T;
}

node* Tree::Mirror(node *T) {

	node *temp;

	if(T!=NULL) {

		temp=T->right;
		T->right=T->left;
		T->left=temp;

		Mirror(T->left);
		Mirror(T->right);
	}
	return T;
}

node* Tree::Delete(node *T,int data) {

	node *temp;

	if(T==NULL)
		return T;

	if(T->data>data)
		T->left=Delete(T->left,data);

	else if(T->data<data)
		T->right=Delete(T->right,data);

	else {

		if(T->left==NULL && T->right!=NULL) {

			temp=T->right;
			delete T;
			return temp;
		}
		else if(T->right==NULL && T->left!=NULL ) {

			temp=T->left;
			delete T;
			return temp;
		}

		else if(T->left==NULL && T->right==NULL) {

			delete T;
			return NULL;
		}

		temp=T->right;

		while(temp->left!=NULL)
			temp=temp->left;

		T->data=temp->data;
		T->right=Delete(T->right,temp->data);
	}
	return T;
}

int Tree::Search(node *T,int data) {

	if(T!=NULL) {

		if(data>T->data)
			return Search(T->right,data);

		else if(data<T->data)
			return Search(T->left,data);

		if(T->data==data)
			return 1;
	}
	return 0;
}

void Tree::Display(node* T) {

	if(T!=NULL) {

		Display(T->left);
		cout<<T->data<<" ";
		Display(T->right);
	}
}

void Tree::LDisplay(node *T) {

	queue <node*> Q;
	node *temp;

	cout<<T->data<<" ";

	do {

		if(T->left!=NULL)
			Q.push(T->left);

		if(T->right!=NULL)
			Q.push(T->right);

		temp=Q.front();
		Q.pop();

		cout<<temp->data<<" ";
		T=temp;
	}
	while(!Q.empty());
}
