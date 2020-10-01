#include<iostream>
#include<cstring>
using namespace std;

class nodes;
class node;
class Stack;
class Tree;

class nodes {

	node *data;
	nodes *next;

public:
	nodes();
	~nodes();
	friend class Stack;
};

class node {

private:
	char data;
	node *left;
	node *right;

public:
	node();
	~node();
	friend class Tree;
};

class Stack {

	private:

	nodes *top=NULL;

	public:

	void push(node* data);
	node* pop();
	bool isEmpty();
	friend class node;
};

class Tree {

public:

	node* CreatefromPostfix(char str[25]);
	node* CreatefromPrefix(char str[25]);
	void InorderR(node* T);
	void PreorderR(node* T);
	void PostorderR(node* T);
	void InorderNR(node* T);
	void PreorderNR(node* T);
	void PostorderNR(node* T);
	bool isOperator(char ch);
};
