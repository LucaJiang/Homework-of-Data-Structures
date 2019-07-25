//graph.cpp
#include<iostream>
#include "ALGraph.h"
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

}

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

template <class T>
void ALGraph<T>::DeleteVex(int i)
{
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

template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum) throw "illegal input";                           //顶点输入错误则抛出异常
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
