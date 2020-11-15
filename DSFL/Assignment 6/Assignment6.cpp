/*============================================================================
 	Title   : DFS and BFS for Graph
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Consider a friends‘ network on face book social web site. Model it as a graph
	to represent each node as a user and a link to represent the fried relationship
	between them. Store data such as date of birth, number of comments for each user.
	1. Find who is having maximum friends
	2. Find who has post maximum and minimum comments
	3. Find users having birthday in this month
	Hint: (Use adjacency list representation and perform DFS and BFS traversals)
============================================================================*/

#include "Graph.h"

int main() {

	graph G;
	int ch,flag,data;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Register Users\n";
		cout<<"2. Register Friends\n";
		cout<<"3. Search User with Maximum Friends\n";
		cout<<"4. Search User with Maximum and Minimum Comments\n";
		cout<<"5. Search Users having Birthday in this Month\n";
		cout<<"6. Display\n";
		cout<<"7. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==7) {

			switch(ch) {

				case 1: {

					G.createUsers();
					flag=1;
					cout<<endl;
					break;
				}

				case 2: {

					G.createFriends();
					cout<<endl;
					break;
				}

				case 3: {

					G.max_friends();
					cout<<endl;
					break;
				}

				case 4: {

					G.DFS();
					cout<<endl;
					break;
				}

				case 5: {

					G.BFS();
					cout<<endl;
					break;
				}

				case 6: {

					G.Display();
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
