//graph.cpp
#include<iostream>
#include "ALGraph.h"//引入头文件

/*
 *前置条件：图不存在
 *输    入：无
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个有向图
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e, int arc[MaxSize][MaxSize])
{
	arcNum = e;                             //边数
	vertexNum = n;                            //顶点数
	int i;
	for (i = 0; i < vertexNum; i++)
	{
		VertexNode<T> tempvertex;
		tempvertex.vertex = a[i];
		tempvertex.firstedge = NULL;
		adjlist[i] = tempvertex;
	}
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{//i->j
			if (j != i && arc[i][j] != 0)
			{
				ArcNode *s = new ArcNode; 
				s->adjvex = j;  //生成一个边表结点s
				s->next = adjlist[i].firstedge;      //将结点s插入到结点i的边表的表头  
				adjlist[i].firstedge = s;
			}
		}
	}



	//for (int k = 0; k < arcNum; k++)           //依次输入每一条边，并在相应边表中插入结点
	//{
	//	cout << "请输入边所依附的两个顶点的序号";
	//	cin >> i >> j;                         //输入边所依附的两个顶点的序号
	//	ArcNode *s = new ArcNode; s->adjvex = j;  //生成一个边表结点s
	//	s->next = adjlist[i].firstedge;      //将结点s插入到结点i的边表的表头  
	//	adjlist[i].firstedge = s;
	//}
	//InsertArc(0, 1);                   //插入边
	//InsertArc(0, 2);
	//InsertArc(0, 3);
	//InsertArc(1, 3);
	//InsertArc(1, 4);
	//InsertArc(2, 0);
	//InsertArc(2, 4);
	//InsertArc(3, 1);
	//InsertArc(3, 4);
	//InsertArc(4, 2);
	//InsertArc(4, 3);
}
/*   前置条件：图已存在
 *   输    入：无
 *   功    能：销毁图
 *   输    出：无
 *   后置条件：释放图所占用的存储空间
 */
template <class T>
ALGraph<T>::~ALGraph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode * p = adjlist[i].firstedge;
		while (p != NULL)                                              //循环删除
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //释放结点空间
			p = adjlist[i].firstedge;
		}
	}
}
/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：输出图中顶点i的数据信息
 *输    出：图中顶点i的数据信息
 *后置条件：图保持不变
 */
template <class T>
T ALGraph<T>::GetVex(int i)
{
	if (i > vertexNum || i < 0) throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	return adjlist[i].vertex;                               //返回第i个顶点的数据域  
}

/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：将图中顶点i的数据域置为value
 *输    出：无
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::PutVex(int i, T value)
{
	if (i > vertexNum || i < 0) throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	adjlist[i].vertex = value;                              //第i个顶点的数据域置为value
}
/*
 *前置条件：图已存在
 *输    入：顶点value,位置i
 *功    能：在图中i位置插入一个顶点name
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void ALGraph<T>::InsertVex(int i, T value)
{
	if (i > vertexNum || i<0 || i>MaxSize) throw "输入顶点的位置不正确"; //顶点i不存在则抛出异常
	vertexNum++;                                            //顶点数加1
	VertexNode<T> tempvertex;
	tempvertex.vertex = value;
	tempvertex.firstedge = NULL;
	adjlist[i] = tempvertex;  	                    //第i个顶点的数据域置为value	
}
/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：在图中删除顶点i
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void ALGraph<T>::DeleteVex(int i)
{
	if (i<0 || i>MaxSize) throw "位置";       //顶点输入错误则抛出异常
	int k;
	for (k = 0; k < vertexNum; k++)               //删掉入度边
		if (k != i)	 DeleteArc(k, i);
	ArcNode *s;                                //生成一个边表结点s
	if (adjlist[i].firstedge != NULL)
	{
		ArcNode *s;
		s = adjlist[i].firstedge->next;
		while (s != NULL)
		{
			ArcNode *p;
			p = s;
			adjlist[i].firstedge->next = s->next;
			s = s->next;
			delete p;                        //删除p结点
		}
		s = adjlist[i].firstedge;
		adjlist[i].firstedge = NULL;
		delete s;
	}
	for (k = i; k < vertexNum; k++)
	{
		adjlist[k] = adjlist[k + 1];             //存储顶点信息       
	}
	vertexNum--;                             //顶点数减1
	for (k = 0; k < vertexNum; k++)
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;                //将结点s插入到结点i的边表的表头
			while (s != NULL)
			{
				if (s->adjvex > i)                  //搜索i结点
					s->adjvex--;
				s = s->next;
			}
		}
}
/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中插入顶点i、j及其所依附的边
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一条边
 */
template <class T>
void ALGraph<T>::InsertArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "位置";//顶点输入错误则抛出异常
	ArcNode *s = new ArcNode; s->adjvex = j;      //生成一个边表结点s
	s->next = adjlist[i].firstedge;             //将结点s插入到结点i的边表的表头  
	adjlist[i].firstedge = s;
}
/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中删除顶点i、j 依附的边
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一条边
*/
template <class T>
void ALGraph<T>::DeleteArc(int i, int j)
{
	if (i > MaxSize || j > MaxSize) throw "位置";  //顶点输入错误则抛出异常
	ArcNode *s;
	ArcNode *tempnode;
	s = adjlist[i].firstedge;
	tempnode = adjlist[i].firstedge;
	while (s != NULL && s->adjvex != j)
	{
		tempnode = s;
		s = s->next;
	}
	if (s != NULL)
	{
		tempnode->next = s->next;
		delete s;
	}
}
/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发深度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if (v > vertexNum) throw "位置";                          //顶点输入错误则抛出异常
	ArcNode * p;
	int j;
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p)                                                //依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;
	}
}
/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发广度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum) throw "位置";                           //顶点输入错误则抛出异常
	int front, rear, j;
	ArcNode * p;                                              //生成一个边表结点p
	int Q[MaxSize];
	front = rear = -1;                                            //初始化队列, 假设队列采用顺序存储且不会发生溢出
	cout << adjlist[v].vertex << " ";  
	visited[v] = 1;
	Q[++rear] = v; //被访问顶点入队
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex << " "; 
				visited[j] = 1; 
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
}

template<class T>
void ALGraph<T>::List2Matrix()
{
	int arc[MaxSize][MaxSize];
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	//事实上，作为无向图，只用arc的上三角部分就行
	ArcNode*p;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		while (p)
		{
			int j = p->adjvex;
			arc[i][j] = 1;
			arc[j][i] = 1;
			p = p->next;
		}
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
			cout<<arc[i][j]<<" ";
		cout << endl;
	}
}

template<class T>
int ALGraph<T>::CountOutdegree0()
{
	int count = 0;
	ArcNode*p;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		if (!p)
			count++;
	}
	return count;
}

template<class T>
void ALGraph<T>::DFS_nonrec()
{
	int v = 0;
	int top, j;
	ArcNode * p;                                              //生成一个边表结点p
	for (int i = 0; i < vertexNum; i++)
		visited[i] = 0;
	int S[MaxSize];
	top = -1;                                            //初始化队列, 假设stack采用顺序存储且不会发生溢出
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	S[++top] = v; //被访问顶点入s
	while (top != -1)
	{
		v = S[top];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) 
			{//find next
				cout << adjlist[j].vertex << " ";
				visited[j] = 1;
				S[++top] = j;
				break;
			}
			p = p->next;
		}
		if (!p)
			top--;
	}
}

template<class T>
void ALGraph<T>::InverseList()
{
	VertexNode<T>Inv[MaxSize];
	for (int i = 0; i < vertexNum; i++)
		Inv[i].firstedge = NULL;
	ArcNode*p;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		while(!p)
		{
			ArcNode*s = p;
			int j = p->adjvex;
			s = new ArcNode; 
			s->adjvex = i;								//生成一个边表结点s
			s->next = Inv[j].firstedge;             //将结点s插入到结点i的边表的表头  
			Inv[j].firstedge = s;
			p = p->next;
		}
	}
}

template<class T>
bool ALGraph<T>::hasPath_DFS(int x, int y)
{
	int v = x;
	int top, j;
	ArcNode * p;                                              //生成一个边表结点p
	for (int i = 0; i < vertexNum; i++)
		visited[i] = 0;
	int S[MaxSize];
	top = -1;                                            //初始化队列, 假设stack采用顺序存储且不会发生溢出
//	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	S[++top] = v; //被访问顶点入s
	while (top != -1)
	{
		v = S[top];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0)
			{//find next
				cout << adjlist[j].vertex << " ";
				if (j == y)
					return true;
				visited[j] = 1;
				S[++top] = j;
				break;
			}
			p = p->next;
		}
		if (!p)
			top--;
	}
	return false;
}

template<class T>
bool ALGraph<T>::hasPath_BFS(int x, int y)
{
	for (int i = 0; i < vertexNum; i++)
		visited[i] = 0;
	int front, rear, j;
	int v = x;
	ArcNode * p;                                              //生成一个边表结点p
	int Q[MaxSize];
	front = rear = -1;                                            //初始化队列, 假设队列采用顺序存储且不会发生溢出
//	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	Q[++rear] = v; //被访问顶点入队
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) 
			{
				cout << adjlist[j].vertex << " ";
				if (j == y)
					return true;
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
	return false;
}
