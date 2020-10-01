#include "Graph.h"

vertex::vertex() {

	id=0;
	comments=0;
	name="";
	nextV=NULL;
	nextE=NULL;
}

edge::edge() {

	comments=0;
	node=NULL;
	nextE=NULL;
}

void graph::createUsers() {

	head=NULL;
	N=0;
	int ch;

	do {

		cout<<"=========================================\n";
		cout<<"1. Register a User\n";
		cout<<"2. Exit\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"=========================================\n";

		if(ch==1)
			insertV();

		else if(ch==2)
			break;

		else
			cout<<"Select Correct Option\n";
	}
	while(true);
}

void graph::createFriends() {

	int ch,id1,id2;

	do {

		cout<<"=========================================\n";
		cout<<"1. Add a Friend\n";
		cout<<"2. Exit\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"=========================================\n";

		if(ch==1) {

			cout<<"ID1: ";
			cin>>id1;
			cout<<"ID2: ";
			cin>>id2;
			insertE(id1,id2);
		}

		else if(ch==2)
			break;

		else
			cout<<"Select Correct Option\n";
	}
	while(true);
}

void graph::insertV() {

	vertex *node=new vertex(),*ptr;
	int ch;
	char dummy[1];

	node->id=N++;
	cout<<"ID  : "<<node->id<<endl;

	cin.getline(dummy,1);
	cout<<"Name: ";
	getline(cin,node->name);

	cout<<"Date of Birth(DD/MM/YYYY):\n";
	cout<<"DD  : ";
	cin>>node->dob.day;
	cout<<"MM  : ";
	cin>>node->dob.month;
	cout<<"YY  : ";
	cin>>node->dob.year;

	if(head==NULL)
		head=node;

	else {

		ptr=head;

		while(ptr->nextV!=NULL)
			ptr=ptr->nextV;
		ptr->nextV=node;
	}
}

void graph::insertE(int id1,int id2) {

	vertex *V1=head,*V2=head;
	edge *E1=NULL,*E2=NULL;
	bool flag1=false,flag2=false;

	while(V1->id!=id1 && V1->nextV!=NULL)
		V1=V1->nextV;

	if(V1->id==id1) {

		E1=V1->nextE;
		flag1=true;
	}

	while(V2->id!=id2 && V2->nextV!=NULL)
		V2=V2->nextV;

	if(V2->id==id2) {

		E2=V2->nextE;
		flag2=true;
	}

	if(flag1&&flag2) {

		if(E1==NULL) {

			V1->nextE=new edge();
			E1=V1->nextE;
		}
		else {

			while(E1->nextE!=NULL)
				E1=E1->nextE;
			E1->nextE=new edge();
			E1=E1->nextE;
		}
		E1->node=V2;
		cout<<"Number of Comments from "<<E1->node->id<<" to "<<V1->id<<": ";
		cin>>E1->comments;
		V1->comments+=E1->comments;

		if(E2==NULL) {

			V2->nextE=new edge();
			E2=V2->nextE;
		}
		else {

			while(E2->nextE!=NULL)
				E2=E2->nextE;
			E2->nextE=new edge();
			E2=E2->nextE;
		}
		E2->node=V1;
		cout<<"Number of Comments from "<<E2->node->id<<" to "<<V2->id<<": ";
		cin>>E2->comments;
		V2->comments+=E2->comments;
	}
}

void graph::DFS() {

	bool *visited=new bool[N];
	vertex *max=head,*min=head;

	for(int i=0;i<N;i++)
		visited[i]=false;

	SearchDFS(head,visited,&max,&min);

	cout<<"User with maximum comments: "<<"Name: "<<max->name<<" (ID: "<<max->id<<") Comments: "<<max->comments<<endl;
	cout<<"User with minimum comments: "<<"Name: "<<min->name<<" (ID: "<<min->id<<") Comments: "<<min->comments<<endl;
}

void graph::SearchDFS(vertex *V,bool *visited,vertex **max,vertex **min) {

	edge *ptrE=V->nextE;

	visited[V->id]=true;

	if((*max)->comments<V->comments)
		*max=V;

	if((*min)->comments>V->comments)
		*min=V;

	while(ptrE!=NULL) {

		if(!visited[ptrE->node->id])
			SearchDFS(ptrE->node,visited,max,min);
		ptrE=ptrE->nextE;
	}
}

void graph::BFS() {

	bool *visited=new bool[N];
	int month;

	for(int i=0;i<N;i++)
		visited[i]=false;

	cout<<"Enter month: ";
	cin>>month;

	SearchBFS(head,visited,month);
}

void graph::SearchBFS(vertex *V,bool *visited,int month) {

	vertex *ptrV;
	edge *ptrE;
	queue <vertex*> Q;

	cout<<"Users having birthday in this month:\n";
	cout<<"----------------------------\n";

	visited[V->id]=true;
	Q.push(V);

	while(!Q.empty()) {

		ptrV=Q.front();
		Q.pop();

		if(ptrV->dob.month==month)
			cout<<"(ID: "<<ptrV->id<<") Name: "<<ptrV->name<<" DOB: "<<ptrV->dob.day<<"/"<<ptrV->dob.month<<"/"<<ptrV->dob.year<<endl;

		ptrE=ptrV->nextE;

		while(ptrE!=NULL) {

			if(!visited[ptrE->node->id]) {

				Q.push(ptrE->node);
				visited[ptrE->node->id]=true;
			}
			ptrE=ptrE->nextE;
		}
	}
}

void graph::max_friends() {

	vertex *ptrV=head;
	edge *ptrE=NULL;
	int max=0,count;
	vertex* Vmax;

	while(ptrV!=NULL) {

		count=0;
		ptrE=ptrV->nextE;

		while(ptrE!=NULL) {

			count++;
			ptrE=ptrE->nextE;
		}
		if(max<count) {

			max=count;
			Vmax=ptrV;
		}
		ptrV=ptrV->nextV;
	}
	cout<<"User with maximum number of friends: (ID: "<<Vmax->id<<") Name: "<<Vmax->name<<" with "<<max<<" friends\n";
}

void graph::Display() {

	vertex* ptrV=head;
	edge* ptrE=NULL;

	cout<<"----------------------------\n";

	while(ptrV!=NULL) {

		cout<<"["<<ptrV->id<<"\t"<<ptrV->name<<"\t"<<ptrV->dob.day<<"/"<<ptrV->dob.month<<"/"<<ptrV->dob.year<<"]->";
		ptrE=ptrV->nextE;

		while(ptrE!=NULL) {

			cout<<"["<<ptrE->node->id<<" "<<ptrE->comments<<"]->";
			ptrE=ptrE->nextE;
		}
		cout<<"Total: "<<ptrV->comments<<endl;
		ptrV=ptrV->nextV;
	}
	cout<<"----------------------------\n";
}
