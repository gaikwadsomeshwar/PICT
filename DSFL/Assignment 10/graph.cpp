#include "graph.h"

void graph::Create() {

	int i,j,k=0,ch;

	cout<<"Enter number of Vertices: ";
	cin>>N;

	g=new int*[N];
	mst=new int*[N];

	for(i=0;i<N;i++) {

		g[i]=new int[N];
		mst[i]=new int[N];
	}

	for(i=0;i<N;i++) {

		for(j=0;j<N;j++) {

			g[i][j]=0;
			mst[i][j]=0;
		}
	}

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

int graph::minKey(bool *visited, int *key) {

	int min=INT_MAX,index=-1;

	for(int i=0;i<N;i++) {

		if(!visited[i] && key[i]<min) {

			min=key[i];
			index=i;
		}
	}

	return index;
}

void graph::MST() {

	int i,j,k,cost=0;
	bool visited[N];
	int key[N],parent[N],list[N];

	for(i=0;i<N;i++) {

		key[i]=INT_MAX;
		visited[i]=false;
	}

	key[0]=0;
	parent[0]=-1;

	for(i=0;i<N-1;i++) {

		k=minKey(&visited[0],&key[0]);
		visited[k]=true;

		for(j=0;j<N;j++) {

			if(g[k][j] && !visited[j] && g[k][j]<key[j]) {

				parent[j]=k;
				key[j]=g[k][j];
			}
		}
	}

	cout<<"-------------------------\n";
	cout<<"Minimmum Spanning Tree:\n";
	cout<<"-------------------------\n";

	for(i=1;i<N;i++) {

		cout<<parent[i]<<","<<i<<": "<<g[i][parent[i]]<<endl;
		cost+=g[i][parent[i]];
	}

	cout<<"Total Cost: "<<cost<<endl;
	cout<<"-------------------------\n";
}

void graph::Display() {

	int i,j;

	cout<<"-------------------------\n";
	cout<<"Tree:\n";
	for(i=0;i<N;i++)
		for(j=0;j<i;j++)
			if(g[i][j]!=0)
				cout<<i<<","<<j<<": "<<g[i][j]<<endl;

	cout<<"-------------------------\n";
}
