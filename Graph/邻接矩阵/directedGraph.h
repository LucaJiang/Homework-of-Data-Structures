//directed graph.h
#pragma once
const int MAXV = 26; //max num_vertices
const int INF = 65535;

template<class T, class E> //T type of vertex; E type of edge
struct ShortEdge
{//4prim
	T adjvex;
	E lowcost;
};

template<class T, class E> //T type of vertex; E type of edge
class directedGraph
{
public:
	directedGraph(int, T[], E[]);
	~directedGraph(){}
	void Info();
	bool Traverse(int begin, double alpha); //begin:the begining vertex; alpha = p(DFS) a=0:BFS a=1:DFS
	bool DFS_T(int begin);
	//=========
	void Prim();
	int MinEdge(ShortEdge<T, E> edge[]);
	void Kruskal();
	int FindRoot(int parent[], int v);
//	bool isCity() { return numV == 11; }
	//========
	void BreakCycle();
//	void TSP(E*arc_mst, T root); //MST+Preorder
//------------------------
	void Dijkstra(int v);
	void Floyd();
private:
	double randd();
	double rand_v1();
	int numV; //current num_vertices
	int numE; //current num_edge
	T nameV[MAXV]; //name of vertices
	E arc[MAXV][MAXV]; // adjacency list
};
