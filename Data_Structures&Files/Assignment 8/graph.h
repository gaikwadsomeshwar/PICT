#include<iostream>
#include<list>
using namespace std;

class graph;

class graph {

	int N;
	int **g;

public:

	void Create();
	void djikstra();
	int minDist(bool *visited,int *dist);
	void Display();
};
