#include "Tree.h"

node* Tree::Create() {

	node* T;
	int ch;

	cout<<"================================\n";
	cout<<"1. Enter Data\n2. Exit\n\nYour Choice: ";
	cin>>ch;
	cout<<endl;
	cout<<"================================\n";

	if(ch==2)
		return NULL;

	cout<<"Enter Data: ";
	T=new node();
	cin>>T->data;

	cout<<"Enter Left of "<<T->data<<endl;
	T->left=Create();

	cout<<"Enter Right of "<<T->data<<endl;
	T->right=Create();

	return T;
}

void Tree::Display(node *T) {

	if(T!=NULL) {
		Display(T->left);
		cout<<T->data<<" ";
		Display(T->right);
	}
}

void Tree::DisplayLeaves(node* T) {


	if(T!=NULL) {

		if(T->left==NULL && T->right==NULL)
			cout<<T->data<<" ";

		DisplayLeaves(T->left);
		DisplayLeaves(T->right);
	}
}

int Tree::Depth(node *T) {

	int lheight=0,rheight=0;

	if(T==NULL)
		return 0;

	lheight=Depth(T->left);
	rheight=Depth(T->right);

	if(lheight>rheight)
		return (lheight+1);
	return (rheight+1);
}

node* Tree::Copy(node* T) {

	node *Tcpy=NULL;

	if(T!=NULL) {

		Tcpy=new node();
		Tcpy->data=T->data;
		Tcpy->left=Copy(T->left);
		Tcpy->right=Copy(T->right);
	}
	return Tcpy;
}
