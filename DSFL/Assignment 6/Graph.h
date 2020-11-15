#include<iostream>
#include<queue>
using namespace std;

class vertex;
class edge;
class graph;
struct DOB;

struct DOB {

	int day;
	int month;
	int year;
};

typedef struct DOB DOB;

class vertex {

	int id;
	int comments;
	string name;
	DOB dob;
	vertex *nextV;
	edge *nextE;

public:

	vertex();
	friend class edge;
	friend class graph;
};

class edge {

	vertex *node;
	int comments;
	edge *nextE;

public:

	edge();
	friend class graph;
};

class graph {

	vertex *head;
	int N;

public:

	void createUsers();
	void createFriends();
	void insertV();
	void insertE(int id1,int id2);
	void DFS();
	void SearchDFS(vertex *V,bool *visited,vertex **max,vertex **min);
	void BFS();
	void SearchBFS(vertex *V,bool *visited,int month);
	void max_friends();
	void Display();
};
