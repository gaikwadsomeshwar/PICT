#include "graph.h"

void graph::Create() {

	int i,j,k=0,ch;

	cout<<"Enter number of Vertices: ";
	cin>>N;

	g=new int*[N];

	for(i=0;i<N;i++) { g[i]=new int[N]; }

	for(i=0;i<N;i++) { for(j=0;j<N;j++) { g[i][j]=0; } }

	do {

		cout<<"-------------------------\n";
		cout<<"1. Enter Edge\n";
		cout<<"2. Exit\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"-------------------------\n";

		if(ch==1) {

			cout<<"1st Node: ";
			cin>>i;
			cout<<"2nd Node: ";
			cin>>j;

			if(g[i][j]==0 && i!=j) {

				cout<<"Cost    : ";
				cin>>g[i][j];
				g[j][i]=g[i][j];
			}
		}
	}
	while(ch!=2);
}

int graph::minDist(bool *visited, int *dist) {

	int min=INT_MAX,index=-1;

	for(int i=0;i<N;i++) {

		if(!visited[i] && dist[i]<=min) {

			min=dist[i];
			index=i;
		}
	}

	return index;
}

void graph::djikstra() {

	int i,j,k,source=-1;
	bool visited[N];
	int dist[N];

	for(i=0;i<N;i++) {

		dist[i]=INT_MAX;
		visited[i]=false;
	}

	cout<<"Enter the source node: ";
	cin>>source;
	cout<<"-------------------------\n";

	dist[source]=0;

	for(i=0;i<N-1;i++) {

		k=minDist(&visited[0],&dist[0]);
		visited[k]=true;

		for(j=0;j<N;j++) {

			if(g[k][j] && !visited[j] && dist[k]!=INT_MAX && dist[k]+g[k][j]<dist[j]) {
				dist[j]=dist[k]+g[k][j];
			}
		}
	}

	cout<<"-------------------------\n";
	cout<<"Distance of source node ("<<source<<") is:\n\n";

	for(i=0;i<N;i++)
		cout<<i<<"\t"<<dist[i]<<endl;
	cout<<"-------------------------\n";
}

void graph::Display() {

	int i,j;

	cout<<"-------------------------\n";
	cout<<"Graph:\n";
	for(i=0;i<N;i++)
		for(j=0;j<i;j++)
			if(g[i][j]!=0)
				cout<<i<<","<<j<<": "<<g[i][j]<<endl;

	cout<<"-------------------------\n";
}
