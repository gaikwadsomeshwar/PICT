#include "node.h"

node::node() {

	data=0;
	left=NULL;
	right=NULL;
}

node::~node() {

	delete left;
	delete right;
}
