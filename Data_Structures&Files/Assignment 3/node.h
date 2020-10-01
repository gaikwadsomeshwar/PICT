#include<iostream>
using namespace std;

class Tree;

class node {

private:
	int data;
	node *left;
	node *right;

public:
	node();
	~node();
	friend class Tree;
};
