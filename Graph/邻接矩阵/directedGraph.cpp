//directed graph.cpp
#include "directedGraph.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <random>
//const int MAXV; in directed graph.h
using namespace std;

template<class T, class E>
directedGraph<T, E>::directedGraph(int numv, T namev[], E weight[])//:numV(numv)
{
	numV = numv;
	numE = 0;
	for (int i = 0; i < numv ; i++)
	{
		nameV[i] = namev[i];
		for (int j = 0; j < numv; j++)
		{
			int order = i * numv + j;
			arc[i][j] = weight[order] == 0 ? INF : weight[order];
//			cout << arc[i][j]<<" ";
		}
		arc[i][i] = 0; //diag <-0
	}
	for (int i = 0; i < numV; i++)
		for (int j = i; j < numV; j++)
			if (arc[i][j] && arc[i][j] != INF)
				numE++;
	cout << "Initialization success.\n";
}

template<class T, class E>
void directedGraph<T, E>::Info()
{
	cout << "Vertex\t" << "inDegree" << setw(numV + 10) << "outDegree\n";
	for (int i = 0; i < numV ; i++)
	{
		cout << nameV[i]<<"   ";//for vertex i
		int inD = 0; T inV[MAXV];
		int outD = 0; T outV[MAXV];
		for (int j = 0; j < numV; j++)
		{
			if (arc[j][i]&& arc[j][i] != INF)//in:j->i
				inV[inD++] = nameV[j];
			if (arc[i][j]&& arc[i][j] != INF)//out:i->j
				outV[outD++] = nameV[j];
		}
		cout << setw(6)<<inD<<"   ";
		int k;
		for (k = 0; k < inD; k++)
			cout << inV[k];
		while (k <= numV)
		{
			cout << " ";
			k++;
		}
		cout << setw(4)<<outD<<"   ";
		for (int k = 0; k < outD; k++)
			cout << outV[k];
		cout << endl;
	}
	cout << endl;
}

template<class T, class E>
bool directedGraph<T, E>::Traverse(int beginV, double alpha)
{//beginv [0, numV], alpha [0, 1] 0:BFS, 1:DFS
	if (alpha > 1 || alpha < 0 || beginV >= numV)	return false;
	//init
	bool isVisit[MAXV];
	for (int i = 0; i < numV; i++)
		isVisit[i] = false;
	int front = -1;
	int rear = -1;
	int deQ[MAXV];
	int countVisit = 0;
	//visit first vertex
	deQ[++rear] = beginV;
	isVisit[beginV] = true;
	countVisit++;
	cout << nameV[beginV];
	while (front!=rear)
	{
		if (randd()<alpha)
		{//DFS
//			cout << "+";
			int vnow = deQ[rear];
			int vnext;
			bool isFindNext = false;
			for (int i = 0; i < numV ; i++)
			{
				if (arc[vnow][i] != INF && !isVisit[i])
				{//vnow->i exist &
					vnext = i;
					isFindNext = true;
					break;
				}
			}
			if (isFindNext)
			{//find next
				deQ[++rear] = vnext;
				isVisit[vnext] = true;
				countVisit++;
				cout << nameV[vnext];
			}
			else
				rear--;
		}

		else//BFS
		{
//			cout << "-";
			int vnow = deQ[++front];
			for (int i = 0; i < numV ; i++)
			{
				if(arc[vnow][i] != INF && !isVisit[i])
				{
					deQ[++rear] = i;
					isVisit[i] = true;
					countVisit++;
					cout << nameV[i];
				}
			}
		}
	}
	cout << endl;
	if (countVisit < numV)	return false;
	return true;
}

template<class T, class E>
bool directedGraph<T, E>::DFS_T(int beginV)
{//beginv [0, numV]
	if ( beginV >= numV)	return false;
	//init
	bool isVisit[MAXV];
	for (int i = 0; i < numV; i++)
		isVisit[i] = false;
	int front = -1;
	int rear = -1;
	int deQ[MAXV];
	int countVisit = 0;
	int parent[MAXV]; //parent of i
	//visit first vertex
	deQ[++rear] = beginV;
	isVisit[beginV] = true;
	countVisit++;
	parent[0] = -1;
//	cout << nameV[beginV];
	while (front != rear)
	{//DFS
		int vnow = deQ[rear];
		int vnext;
		bool isFindNext = false;
		for (int i = 0; i < numV; i++)
		{
			if (arc[vnow][i] != INF && !isVisit[i])
			{//vnow->i exist &
				vnext = i;
				isFindNext = true;
				break;
			}
		}
		if (isFindNext)
		{//find next
			deQ[++rear] = vnext;
			isVisit[vnext] = true;
			countVisit++;
			parent[vnext] = vnow;
//			cout << nameV[vnext];
		}
		else
			rear--;
	}
	cout << "Vertex\tParent\n";
	for (int i = 0; i < numV ; i++)
	{
		if (parent[i] == -1)
			cout << nameV[i] << endl;
		else
			cout << nameV[i] << "\t" << nameV[parent[i]] << endl;
	}
	if (countVisit < numV)	return false;
	return true;
}

template<class T, class E>
void directedGraph<T, E>::Prim()
{
	//init
	ShortEdge<T, E> shortEdge[MAXV];
	for (int i = 1; i < numV ; i++)
	{
		shortEdge[i].lowcost = arc[0][i];
		shortEdge[i].adjvex = nameV[0];
	}
	shortEdge[0].lowcost = 0;
	E TotalCost = 0;

	cout << "from to cost\n";
	for (int i = 1; i < numV ; i++)
	{
		int k = MinEdge(shortEdge);
		TotalCost += shortEdge[k].lowcost;
		cout << "(" << shortEdge[k].adjvex <<", "<< nameV[k] << ") " << shortEdge[k].lowcost<< endl;
		shortEdge[k].lowcost = 0;
		for (int j = 0; j < numV ; j++)
		{
			if (arc[k][j] < shortEdge[j].lowcost) 
			{
				shortEdge[j].lowcost = arc[k][j];
				shortEdge[j].adjvex = nameV[k];
			}
		}
	}
	cout << "Total Cost:" << TotalCost << endl << endl;
}

template<class T, class E>
int directedGraph<T, E>::MinEdge(ShortEdge<T, E> egde[])
{//4Prim
	int min = 0;
	for (int i = 0; i < numV; i++)
	{

		if (min&&egde[i].lowcost&&egde[i].lowcost < egde[min].lowcost)
			min = i;
		else if (!min&&egde[i].lowcost)
			min = i;
	}
	return min;
}

struct EdgeType
{
	int from, to;
	int weight;
};

template<class T, class E>
void directedGraph<T, E>::Kruskal()
{
	//init
	int edgeNum = 0;
	EdgeType edge[MAXV*MAXV];
	int parent[MAXV];
	for (int i = 0; i < numV; i++)
	{
		parent[i] = -1;
		for (int j = i + 1; j < numV; j++)
		{
			if (arc[i][j] != INF)
			{
				edge[edgeNum].from = i;
				edge[edgeNum].to = j;
				edge[edgeNum].weight = arc[i][j];
				edgeNum++;
			}
		}
	}
	int num = 0;
	E TotalCost = 0;
	//sort: increase
	for (int i = 0; i < edgeNum; i++)
		for (int j = 0; j < edgeNum - 1 - i; j++)
		{
			if (edge[j].weight > edge[j + 1].weight)
			{
				int k = edge[j].from; edge[j].from = edge[j + 1].from; edge[j + 1].from = k;
				k = edge[j].to; edge[j].to = edge[j + 1].to; edge[j + 1].to = k;
				k = edge[j].weight; edge[j].weight = edge[j + 1].weight; edge[j + 1].weight = k;
			}
		}
	//end init
	cout << "from to cost\n";
	for (int i = 0; i < edgeNum; i++)
	{
		int V_from = FindRoot(parent, edge[i].from);
		int V_to = FindRoot(parent, edge[i].to);
		if (V_from!=V_to)
		{
			cout << "(" << nameV[edge[i].from] << ", " << nameV[edge[i].to] << ")" <<edge[i].weight<< endl;
			parent[V_to] = V_from;
			num++;
			TotalCost += edge[i].weight;
			if (num == numV - 1)
			{
				cout << "Total Cost:" << TotalCost << endl << endl;
				return;
			}
		}
	}
	cout << "UNKNOW ERROR\n\n";
}

template<class T, class E>
int directedGraph<T, E>::FindRoot(int parent[], int v)
{
	int t = v;
	while (parent[t] != -1)
		t = parent[t];
	return t;
}

template<class T, class E>
void directedGraph<T, E>::BreakCycle()
{//undirectedG 破圈法  arc->MST_arc !!!!!!
	//init
	struct visitV
	{
		int parent, visit;
	}visitV[MAXV];//id of vertex
	for (int i = 0; i < numV; i++)
		visitV[i].visit = 0;
	int top = -1;
	int stack[MAXV];//id of vertex
	int count = numE - numV + 1;
// 	E arc_copy[MAXV][MAXV];
// 	for (int i = 0; i < MAXV; i++)
// 		for (int j = 0; j < MAXV; j++)
// 			arc_copy[i][j] = arc[i][j];

	//visit first vertex
	stack[++top] = 0;
	visitV[0].parent = -1;//be careful this
	visitV[0].visit = 1;
	//DFS
	cout << "delete egde:\n";
	while (count > 0)
	{
		int vnow = stack[top];
		int vnext;
		bool isFindNext = false;
		for (int i = 0; i < numV; i++)
		{// try to find next
			//can not visit itself, road exist, can not visit predecessor or successor
			if (i!=vnow && arc[vnow][i] != INF && i!=visitV[vnow].parent && visitV[i].visit != 2)
			{//vnow->i exist &
				vnext = i;
				isFindNext = true;
				break;
			}
		}
		if (isFindNext)
		{//find next
			if (visitV[vnext].visit == 1)
			{//find cycle
				E maxcost;
				int maxbegin, maxend, nowbegin, nowend;
				maxcost = arc[vnow][vnext];
				maxbegin = vnext; maxend = vnow;
				nowbegin = vnext; nowend = vnow;
				while (nowend!=vnext)
				{//find max cost in the cycle
					nowbegin = nowend;
					nowend = visitV[nowend].parent;
//					visitV[nowbegin].parent = -1;
//					visitV[nowbegin].visit = 0;
					if (arc[nowbegin][nowend]!=INF && arc[nowbegin][nowend] >maxcost)
					{
						maxcost = arc[nowbegin][nowend];
						maxbegin = nowbegin;
						maxend = nowend;
					}
				}
				cout << "(" << nameV[maxbegin] << ", " << nameV[maxend] << ") " << arc[maxbegin][maxend] << endl;
				arc[maxbegin][maxend] = INF;
				arc[maxend][maxbegin] = INF;
//				visitV[maxbegin].parent = -1;
				count--;
				//back to begining point and countinue to find another cycle
				for (int i = 0; i < numV; i++)
				{
					visitV[i].parent = -1;
 					visitV[i].visit = 0;
				}
				top = 0;
			}
			else
			{
				stack[++top] = vnext;
				visitV[vnext].visit = 1;
				visitV[vnext].parent = vnow;
			}
		}
		else
		{//not find next
			visitV[stack[top]].visit = 2;
			top--;
		}
	}
	cout << "finish\n\n";
}

template<class T, class E>
void directedGraph<T, E>::Dijkstra(int v)
{//v begin
	//init
	E dist[MAXV];
	T path[MAXV];
	T s[MAXV];
	for (int i = 0; i < numV; i++)
	{
		dist[i] = arc[v][i];
		if (dist[i] != INF)
			path[i] = nameV[v] + nameV[i];
		else
			path[i] = "";
	}
	s[0] = v;
	dist[v] = 0;
	int num = 1;
	//end init
	while (num < numV)
	{
		int k = 0;
		for (int i = 0; i < numV; i++) //在dist中查找最小元素
			//以下行课本代码：if (dist[i] && dist[i] < dist[k]) 错误
			if (dist[i] && (!dist[k] || dist[i] < dist[k]))
				k = i;
		if (dist[k] != INF)
			cout << dist[k] << " " << path[k] << endl;
		else
			cout << "Can not find road to " << nameV[k] << endl;
		s[num++] = k;
		for (int i = 0; i < numV; i++)
		{//更新dist path
			if (dist[i] > dist[k] + arc[k][i])
			{ 
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + nameV[i];
			}
		}
		dist[k] = 0;  //已生成终点
	}
}

template<class T, class E>
void directedGraph<T, E>::Floyd()
{//reference: 大话数据结构
	E dist[MAXV][MAXV];
	int path[MAXV][MAXV];
	//init
	for (int i = 0; i < numV; i++)
		for (int j = 0; j < numV; j++)
		{
			dist[i][j] = arc[i][j];
			path[i][j] = j;
		}
	//end init
	//floyd
	for (int k = 0; k < numV; k++)
		for (int i = 0; i < numV; i++)
			for (int j = 0; j < numV; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
			}
	//printf
	cout << "from\tto\tdist\tpath\n";
	for (int i = 0; i < numV; i++)
	{
		for (int j = 0; j < numV; j++)
		{//from i to j dist
			if (i == j);
			else if (dist[i][j] < INF)
			{
				cout << i << "\t" << j << "\t" << dist[i][j] << "\t";
				//path
				cout << nameV[i]; //print begin vertex
				int next = path[i][j]; //get id of next vertex
				while (next != j)//next vertex not end of path
				{
					cout << nameV[next];
					next = path[next][j];//continue to find next
				}
				cout << nameV[j] << endl; //print end of path
			} 
			else
				cout << i << "\t" << j << "\t" <<"INF\n";
		}
	}
}

template<class T, class E>
double directedGraph<T, E>::randd()
{//Generates a random number in range [0, 1)
	random_device rd;
	mt19937 gen(rd());
	return generate_canonical<double, 1>(gen);
}

template<class T, class E>
double directedGraph<T, E>::rand_v1()
{
	static unsigned int seed = 0;
	seed = seed * seed + nameV[seed%numV] * 99;
	srand((unsigned)time(NULL) + seed);
	return (double)rand() / (RAND_MAX + 1.0);
	//double i= (double)rand() / (RAND_MAX + 1.0);
	//cout << i;
	//return i;
}
