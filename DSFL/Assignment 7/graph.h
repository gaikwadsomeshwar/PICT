#include<iostream>
#include<list>
using namespace std;

struct sortlist;
class graph;
class subset ;

struct sortlist {

	int *row;
	int *col;
	int *list;
};

class subset {

public:
	int parent;
	int rank;
};

class graph {

	int N;
	int **g;
	int **mst;
	struct sortlist L;

public:

	void Create();
	void MST();
	int Find(subset subsets[],int i);
	void Union(subset subsets[],int x,int y);
	void Sort(int size);
	void Display();
};
