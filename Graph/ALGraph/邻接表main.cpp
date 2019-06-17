//graphmain.cpp
#include <iostream>
#include <string>
#include "ALGraph.cpp"
#include <fstream>
using namespace std;
const int MAXV = 40;

int main()
{
	int numV;
	int arc[MAXV][MAXV];
	char name[MAXV];
	//read data
	fstream fin;
	cout << "Open file:";
	string filename;
	cin >> filename;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Can not open file:" << filename;
		cout << " Now, open file:data26.txt\n";
		fin.open("data26.txt");
	}
	if (!fin.fail())
	{
		cout << "Reading file:" << filename << "...\n";
		fin >> numV;
		for (int i = 0; i < numV; i++)
			for (int j = 0; j < numV ; j++)
			{
				fin >> arc[i][j];	
			}
		fin.close();
	}
	else
	{
		throw"can not open file";
	}

	for (int i = 0; i < numV; i++)
		name[i] = 'A' + i;

	//========================================================
	int choose = 1;
	ALGraph<char> algraphTest(name, numV, MaxSize, arc);        //构造图
	cout << "matrix\n";
	algraphTest.List2Matrix();
	cout << "degree0:";
	cout<<algraphTest.CountOutdegree0();
	cout << "\n";
	algraphTest.InverseList();
	cout << "\nDFS:";
	algraphTest.DFS_nonrec();
	cout << endl;
	cout << algraphTest.hasPath_BFS(0, 3) << endl;
	cout << algraphTest.hasPath_DFS(0, 3) << endl;
	system("pause");
	return 0;
}
