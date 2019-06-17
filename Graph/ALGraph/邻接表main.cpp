//graphmain.cpp
#include <iostream>
#include <string>
#include "ALGraph.cpp"
#include <fstream>
using namespace std;
const int MAXV = 40;

int main()
{
	//==================================================
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
//	int which;
//	int j;
//	string name;
	int choose = 1;
//	string a[5] = { "北大","清华","复旦","吉林大学","长春工大" };
	ALGraph<char> algraphTest(name, numV, MaxSize, arc);        //构造图
// 	while (choose == 1)                                      //控制
// 	{
// 		cout << "需要输出顶点信息请按0" << endl;		         //输入所要进行的操作的序号
// 		cout << "需要输出任意一个顶点信息请按1" << endl;
// 		cout << "需要插入顶点请按2" << endl;
// 		cout << "需要修改顶点请按3" << endl;
// 		cout << "需要删除顶点请按4" << endl;
// 		cout << "需要深度优先遍历请按5" << endl;
// 		cout << "需要广度优先遍历请按6" << endl;
// 		cout << "需要退出请按7" << endl;
// //		cin >> which;
// // 		switch (which)                                        //功能选择
// // 		{
// // 		case 0:
// // 			for (j = 0; j < numV; j++)
// // 				cout << algraphTest.GetVex(j) << " ";              //输出顶点
// // 			cout << endl;
// // 			break;
// // 		case 1:
// // 			int i;
// // 			cout << "请输入顶点：" << endl;
// // 			cin >> i;
// // 			try
// // 			{
// // 				cout << algraphTest.GetVex(i) << endl;              //输出i顶点的数据域
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 2:                                               //在图中的i位置插入一顶点值为name
// // 			cout << "请输入顶点及名字：" << endl;
// // 			cin >> i >> name;
// // 			try
// // 			{
// // 				//algraphTest.InsertVex(i, name);
// // 
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 3:                                               //修改图中一顶点的值
// // 			cout << "请输入顶点及名字：" << endl;
// // 			cin >> i >> name;
// // 			try
// // 			{
// // 				//algraphTest.PutVex(i, name);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 4:                                               //删除图中一顶点的值
// // 			cout << "请输入顶点：" << endl;
// // 			cin >> i;
// // 			try
// // 			{
// // 				algraphTest.DeleteVex(i);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 5:                                               //图的深度优先搜索
// // 			cout << "请输入顶点：" << endl;
// // 			cin >> i;
// // 			cout << endl << "从第" << i << "个顶点深度优先遍历图" << endl;
// // 			try
// // 			{
// // 				for (int ii = 0; ii < MaxSize; ii++) algraphTest.visited[ii] = 0;
// // 				algraphTest.DFSTraverse(i);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 6:                                               //图的广度优先搜索
// // 			cout << "请输入顶点：" << endl;
// // 			cin >> i;
// // 			cout << endl << "从第" << i << "个顶点广度优先遍历图" << endl;
// // 			try
// // 			{
// // 				for (int ii = 0; ii < MaxSize; ii++) algraphTest.visited[ii] = 0;
// // 				algraphTest.BFSTraverse(i);
// // 			}
// // 			catch (char*s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 7:                                             //退出
// // 			choose = 0;
// // 			break;
// // 		}
// 	}

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
