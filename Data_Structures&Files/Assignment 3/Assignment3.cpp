/*============================================================================
 	Title   : Binary Tree
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Create Binary tree and perform following operations:
	a. Insert
	b. Display
	c. Depth of a tree
	d. Display leaf-nodes
	e. Create a copy of a tree
============================================================================*/

#include "Tree.h"

class TreeOps {

	Tree T;
	node* root;

public:
	void Create();
	void Display();
	void DisplayLeaves();
	void Depth();
	void Copy(TreeOps obj);
};

void TreeOps::Create() { root=T.Create(); }

void TreeOps::Display() { T.Display(root); }

void TreeOps::DisplayLeaves() { T.DisplayLeaves(root); }

void TreeOps::Depth() { cout<<T.Depth(root)-1; }

void TreeOps::Copy(TreeOps obj) { this->root=T.Copy(obj.root); }

int main() {

	TreeOps T,Tcpy;

	int ch,flag;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Create Tree\n";
		cout<<"2. Display Tree\n";
		cout<<"3. Display the Leaves\n";
		cout<<"4. Depth of Tree\n";
		cout<<"5. Copy the Tree\n";
		cout<<"6. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==6) {

			switch(ch) {

				case 1: {

					cout<<"Creating a Tree\n";
					T.Create();
					cout<<"Tree Created\n\n";
					flag=1;
					break;
				}

				case 2: {

					cout<<"Tree: ";
					T.Display();
					cout<<endl<<endl;
					break;
				}

				case 3: {

					cout<<"Leaves: ";
					T.DisplayLeaves();
					cout<<endl<<endl;;
					break;
				}

				case 4: {

					cout<<"Depth: ";
					T.Depth();
					cout<<endl<<endl;
					break;
				}

				case 5: {

					cout<<"Copying Tree\n";
					Tcpy.Copy(T);
					cout<<"Tree Copied\n\n";
					cout<<"Tree: ";
					Tcpy.Display();
					cout<<endl<<endl;
					break;
				}

				case 6: {

					cout<<"End\n";
					break;
				}

				default: cout<<"Select Correct Option\n\n";
			}
		}
		else {

			cout<<"Tree Empty\n\n";
		}
	}
	while(ch!=6);

	return 0;
}
