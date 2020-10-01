/*============================================================================
 	Title   : Binary Search Tree
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Implement binary search tree and perform following operations:
	a. Insert
	b. Delete
	c. Search
	d. Mirror image
	e. Display
	f. Display level wise
============================================================================*/

#include "Tree.h"

int main() {

	Tree T;
	node *root;
	int ch,flag,Flag,data;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Search\n";
		cout<<"4. Mirror Image\n";
		cout<<"5. Display\n";
		cout<<"6. Display Level Wise\n";
		cout<<"7. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==7) {

			switch(ch) {

				case 1: {

					root=T.Create();
					flag=1;
					cout<<endl;
					break;
				}

				case 2: {

					cout<<"Before Deleting\nTree: ";
					T.Display(root);
					cout<<endl<<endl;

					cout<<"Enter value to delete: ";
					cin>>data;

					root=T.Delete(root,data);
					cout<<"After Deleting\nTree: ";
					T.Display(root);
					cout<<endl;
					break;
				}

				case 3: {

					cout<<"Enter value to be Searched: ";
					cin>>data;
					Flag=T.Search(root,data);

					if(Flag)
						cout<<data<<" Found";
					else
						cout<<data<<" not Found";

					cout<<endl;
					break;
				}

				case 4: {

					cout<<"Tree: ";
					T.Display(root);
					cout<<endl<<endl;

					cout<<"Mirror: ";
					root=T.Mirror(root);
					T.Display(root);
					cout<<endl;

					T.Mirror(root);
					break;
				}

				case 5: {

					cout<<"Tree: ";
					T.Display(root);
					cout<<endl;
					break;
				}

				case 6: {

					cout<<"Tree Level Wise: ";
					T.LDisplay(root);
					cout<<endl;
					break;
				}

				case 7: {

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
	while(ch!=7);

	return 0;
}
