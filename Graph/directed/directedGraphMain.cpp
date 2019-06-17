//实验八2019-05-20 实验九2019-05-27 实验十2019-06-03
//基于有向图(有权重)的邻接矩阵实现图的各种算法;
//最后修改2019-06-06
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "directedGraph.cpp"
using namespace std;

int main()
{//Init
	int numV;
	int arc[MAXV*MAXV];
	//read data
	fstream fin;
	cout << "Open file:";
	string filename;
	cin >> filename;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Can not open file:"<<filename;
		cout << " Now, open file:datasp.txt\n";
		filename = "datasp.txt";
		fin.open(filename);
	}
	if (!fin.fail())
	{
		cout << "Reading file:"<<filename<<"...\n";
		fin >> numV;
		for (int i = 0; i < numV*numV; i++)
			fin >> arc[i];
	}
	else
		throw"can not open file";
	
	string name[MAXV];
	if (fin.get()!=-1)
	{
		for (int i = 0; i < numV ; i++)
			fin >> name[i];
	} 
	else
	{
		char tempname[2] = {'0','\0'};
		for (int i = 0; i < numV ; i++)
		{
			tempname[0] = 'A' + i;
			name[i] = tempname;
		}
	}
	directedGraph<string, int>mygraph(numV, name, arc);
	fin.close();
	//------------------------- 第一题------------------------------
// 	if(!mygraph.isCity())
// 	{
// 		mygraph.Info();
// 		cout << "DFS:";
// 		mygraph.Traverse(0, 1);
// 		cout << "BFS:";
// 		mygraph.Traverse(0, 0);
// 		cout << "D&BFS:";
// 		mygraph.Traverse(0, 0.4);
// 		cout << "DFS_Tree:\n";
// 		mygraph.DFS_T(0);
// 	}
// 	//--------------------------第二题-----------------------------
// 	cout << "Prim:\n";
// 	mygraph.Prim();
// 	cout << "Kruskal:\n";
// 	mygraph.Kruskal();
// 	cout << "another method of MST\n";
// 	mygraph.BreakCycle();
// 	//上面这个函数把邻接矩阵改为最小生成树的邻接矩阵
// 	//--------------------------第三题-------------------------------
// 	cout << "Approximate TSP:\n";
// 	mygraph.Traverse(0, 1);
//------------------------------实验十第一题--------------------------
	cout << "Dijkstra:\n";
	mygraph.Dijkstra(1);
	cout << "\nFloyd:\n";
	mygraph.Floyd();
	  
	system("pause");
	return 0;
}
