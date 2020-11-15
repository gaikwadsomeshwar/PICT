/*============================================================================
 	Title   : Kruskal's Algorithm
 	Name    : Someshwar Gaikwad
 	Roll No : 23257
 	Batch   : H-10

	Problem Statement   :

	Represent any real world graph using adjacency list /adjacency matrix find
	minimum spanning tree using Kruskal‘s algorithm.
============================================================================*/

#include "graph.h"

int main() {

	graph G;
	int ch,flag,data;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Create Graph\n";
		cout<<"2. Minimum Spanning Tree\n";
		cout<<"3. Display Graph\n";
		cout<<"4. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==4) {

			switch(ch) {

				case 1: {

					G.Create();
					flag=1;
					cout<<endl;
					break;
				}

				case 2: {

					G.MST();
					cout<<endl;
					break;
				}

				case 3: {

					G.Display();
					cout<<endl;
					break;
				}

				case 4: {

					cout<<"End\n";
					break;
				}

				default: cout<<"Select Correct Option\n\n";
			}
		}
		else {

			cout<<"Graph not Created\n\n";
		}
	}
	while(ch!=4);

	return 0;
}
