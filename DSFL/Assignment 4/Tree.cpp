#include "Tree.h"

nodes::nodes() {

	data=NULL;
	next=NULL;
}

nodes::~nodes() {

	delete data;
	delete next;
}

node::node() {

	data='\0';
	left=NULL;
	right=NULL;
}

node::~node() {

	delete left;
	delete right;
}

void Stack::push(node *data) {

	nodes *temp=new nodes();
	temp->data=data;
	temp->next=top;
	top=temp;
}

node* Stack::pop() {

	node* data=NULL;

	if(!isEmpty()) {

		data=top->data;
		top=top->next;
	}
	return data;
}

bool Stack::isEmpty() {

	if(top==NULL)
		return true;
	else
		return false;
}

bool Tree::isOperator(char ch) {

	switch(ch) {

	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '%':
		return true;
	}
	return false;
}

node* Tree::CreatefromPostfix(char str[25]) {

	int len=strlen(str),i=0;
	node *op=NULL,*root=NULL;
	Stack S;

	while(i<=(len-1)) {

		char ch=str[i];

		if(isOperator(ch)) {

			op=new node();
			op->data=ch;
			op->right=S.pop();
			op->left=S.pop();
			S.push(op);
			root=op;
		}
		else {

			op=new node();
			op->data=ch;
			S.push(op);
		}
		i++;
	}
	return root;
}

node* Tree::CreatefromPrefix(char str[25]) {

	int i=strlen(str)-1;
	node *op=NULL,*root=NULL;
	Stack S;

	while(i>=0) {

		char ch=str[i];

		if(isOperator(ch)) {

			op=new node();
			op->data=ch;
			op->left=S.pop();
			op->right=S.pop();
			S.push(op);
			root=op;
		}
		else {

			op=new node();
			op->data=ch;
			S.push(op);
		}
		i--;
	}
	return root;
}

void Tree::InorderR(node *T) {

	if(T!=NULL) {
		InorderR(T->left);
		cout<<T->data;
		InorderR(T->right);
	}
}

void Tree::PreorderR(node *T) {

	if(T!=NULL) {
		cout<<T->data;
		PreorderR(T->left);
		PreorderR(T->right);
	}
}

void Tree::PostorderR(node *T) {

	if(T!=NULL) {
		PostorderR(T->left);
		PostorderR(T->right);
		cout<<T->data;
	}
}

void Tree::InorderNR(node *T) {

	Stack S;

	while(true) {

		while(T!=NULL) {

			S.push(T);
			T=T->left;
		}

		if(S.isEmpty())
			return;

		T=S.pop();
		cout<<T->data;
		T=T->right;
	}
}

void Tree::PreorderNR(node *T) {

	Stack S;

	while(true) {

		while(T!=NULL) {

			cout<<T->data;
			S.push(T);
			T=T->left;
		}

		if(S.isEmpty())
			return;

		T=S.pop();
		T=T->right;
	}
}

void Tree::PostorderNR(node *T) {

	if(T==NULL)
		return;

	Stack S1,S2;
	node *temp;

	S1.push(T);

	while(!S1.isEmpty()) {

		temp=S1.pop();
		S2.push(temp);

		if(temp->left!=NULL)
			S1.push(temp->left);

		if(temp->right!=NULL)
			S1.push(temp->right);
	}

	while(!S2.isEmpty()) {

		temp=S2.pop();
		cout<<temp->data;
	}
}
