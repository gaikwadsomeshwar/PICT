#include "node.h"

class Tree {

public:

	node* Create();
	void Display(node* T);
	int Depth(node *T);
	void DisplayLeaves(node *T);
	node* Copy(node* T);
};
