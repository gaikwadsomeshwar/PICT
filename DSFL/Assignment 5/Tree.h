#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

class node;
class Tree;

class node {

	int data;
	node *left;
	node *right;

public:
	node();
	friend class Tree;
};

class Tree {

public:

	node* Create();
	node* Insert(node *T,int data);
	node* Mirror(node *T);
	node* InorderSucc(node* T);
	node* Delete(node *T,int data);
	int Search(node *T,int data);
	void Display(node* T);
	void LDisplay(node *T);
};
