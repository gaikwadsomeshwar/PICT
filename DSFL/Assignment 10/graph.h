#include<iostream>
#include<list>
using namespace std;

class graph;

class graph {

	int N;
	int **g;
	int **mst;

public:

	void Create();
	void MST();
	int minKey(bool *visited,int *key);
	void Display();
};
