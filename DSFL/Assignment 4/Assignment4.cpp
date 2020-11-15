/*============================================================================
 	Title   : Expression Tree
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Construct and expression tree from postfix/prefix expression and perform
	recursive and non- recursive In-order, pre-order and post-order traversals
============================================================================*/

#include "Tree.h"

int main() {

	Tree T;
	node *root;
	char str[25];

	int ch,flag,Ch;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Accept Postfix Expression\n";
		cout<<"2. Accept Prefix Expression\n";
		cout<<"3. Display Inorder Expression\n";
		cout<<"4. Display Preorder Expression\n";
		cout<<"5. Display Postorder Expression\n";
		cout<<"6. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || ch==2 || flag==1 || ch==6) {

			switch(ch) {

				case 1: {

					cout<<"Expresion: ";
					cin>>str;
					cout<<"Creating a Tree\n";
					root=T.CreatefromPostfix(str);
					cout<<"Tree Created\n\n";
					flag=1;
					break;
				}

				case 2: {

					cout<<"Expresion: ";
					cin>>str;
					cout<<"Creating a Tree\n";
					root=T.CreatefromPrefix(str);
					cout<<"Tree Created\n\n";
					flag=1;
					break;
				}

				case 3: {

					cout<<"1. Recursive\n";
					cout<<"2. Non Recursive\n";
					cout<<"3. Back\n";
					cout<<"Your Choice: ";
					cin>>Ch;
					cout<<"----------------------------\n\n";

					while(Ch>3 || Ch<1) {

						cout<<"Invalid Choice\n";
						cout<<"Enter Again\n";
						cout<<"----------------------------\n\n";
						cout<<"1. Recursive\n";
						cout<<"2. Non Recursive\n";
						cout<<"Your Choice: ";
						cin>>Ch;
						cout<<"----------------------------\n\n";
					}

					if(Ch==1) {

						cout<<"Inorder Tree by Recursion: ";
						T.InorderR(root);
					}

					else if(Ch==2) {

						cout<<"Inorder Tree by Non Recursion: ";
						T.InorderNR(root);
					}
					cout<<endl<<endl;
					break;
				}

				case 4: {

					cout<<"1. Recursive\n";
					cout<<"2. Non Recursive\n";
					cout<<"3. Back\n";
					cout<<"Your Choice: ";
					cin>>Ch;
					cout<<"----------------------------\n\n";

					while(Ch>3 || Ch<1) {

						cout<<"Invalid Choice\n";
						cout<<"Enter Again\n";
						cout<<"----------------------------\n\n";
						cout<<"1. Recursive\n";
						cout<<"2. Non Recursive\n";
						cout<<"Your Choice: ";
						cin>>Ch;
						cout<<"----------------------------\n\n";
					}

					if(Ch==1) {

						cout<<"Preorder Tree by Recursion: ";
						T.PreorderR(root);
					}

					else if(Ch==2) {

						cout<<"Preorder Tree by Non Recursion: ";
						T.PreorderNR(root);
					}
					cout<<endl<<endl;
					break;
				}

				case 5: {

					cout<<"1. Recursive\n";
					cout<<"2. Non Recursive\n";
					cout<<"3. Back\n";
					cout<<"Your Choice: ";
					cin>>Ch;
					cout<<"----------------------------\n\n";

					while(Ch>3 || Ch<1) {

						cout<<"Invalid Choice\n";
						cout<<"Enter Again\n";
						cout<<"----------------------------\n\n";
						cout<<"1. Recursive\n";
						cout<<"2. Non Recursive\n";
						cout<<"Your Choice: ";
						cin>>Ch;
						cout<<"----------------------------\n\n";
					}

					if(Ch==1) {

						cout<<"Postorder Tree by Recursion: ";
						T.PostorderR(root);
					}

					else if(Ch==2) {

						cout<<"Postorder Tree by Non Recursion: ";
						T.PostorderNR(root);
					}
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
