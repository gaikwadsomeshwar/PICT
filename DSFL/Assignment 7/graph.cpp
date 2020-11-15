#include "graph.h"

void graph::Create() {

	int i,j,k=0,ch,size=0;

	cout<<"Enter number of Vertices: ";
	cin>>N;

	g=new int*[N];
	mst=new int*[N];

	size=(N*(N-1)/2);

	L.list=new int[size];
	L.col=new int[size];
	L.row=new int[size];

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

	for(i=0;i<size;i++) {

		L.list[i]=0;
		L.col[i]=-1;
		L.row[i]=-1;
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

void graph::Sort(int size) {

	int i,j,temp;

	for(i=0;i<size;i++) {

		for(j=0;j<size-i-1;j++) {

			if(L.list[j]>L.list[j+1]) {

				temp=L.list[j];
				L.list[j]=L.list[j+1];
				L.list[j+1]=temp;

				temp=L.row[j];
				L.row[j]=L.row[j+1];
				L.row[j+1]=temp;

				temp=L.col[j];
				L.col[j]=L.col[j+1];
				L.col[j+1]=temp;
			}
		}
	}
}

int graph::Find(subset subsets[],int i) {

	if(subsets[i].parent!=i)
		subsets[i].parent=Find(subsets,subsets[i].parent);

	return subsets[i].parent;
}

void graph::Union(subset subsets[],int x,int y) {

	int xroot=Find(subsets,x);
	int yroot=Find(subsets,y);

	if(subsets[xroot].rank<subsets[yroot].rank)
		subsets[xroot].parent=yroot;
	else if(subsets[xroot].rank>subsets[yroot].rank)
		subsets[yroot].parent=xroot;

	else {

		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}
}

void graph::MST() {

	int i,j,k=0,cost=0,size=0;
	subset *subsets=new subset[N];

	size=(N*(N-1))/2;

	for(i=0;i<N;i++) {

		subsets[i].parent=i;
		subsets[i].rank=0;
	}

	for(i=0;i<N;i++) {

		for(j=0;j<i;j++) {

			L.list[k]=g[i][j];
			L.row[k]=i;
			L.col[k]=j;
			k++;
		}
	}

	Sort(size);

	cout<<"-------------------------\n";
	cout<<"Minimum Spanning Tree:\n";

	for(i=0;i<size;i++) {

			if(L.list[i]!=0) {

				int x=Find(subsets,L.row[i]);
				int y=Find(subsets,L.col[i]);

				if(x!=y) {

					mst[L.row[i]][L.col[i]]=L.list[i];
					mst[L.col[i]][L.row[i]]=L.list[i];
					cout<<L.row[i]<<","<<L.col[i]<<": "<<L.list[i]<<endl;
					cost+=L.list[i];
					Union(subsets,x,y);
				}
			}
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
