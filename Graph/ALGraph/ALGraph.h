//graph.h
#ifndef GRAPH_H                  //定义头文件
#define GRAPH_H                
using namespace std;
const int MaxSize = 40;
struct ArcNode                   //定义边表结点
{
	int adjvex;                    //邻接点域
	ArcNode *next;                 //指向下一个边结点的指针
};
template <class T>
struct VertexNode               //定义顶点表结点
{
	T vertex;                     //顶点的名称
	ArcNode *firstedge;           //边表的头指针
};
template <class T>
class ALGraph
{
public:
	ALGraph(T a[], int n, int e, int arc[MaxSize][MaxSize]);   //构造函数，初始化一个有n个顶点e条边的图
	~ALGraph();                      //析构函数，释放邻接表中各边表结点的存储空间
	T GetVex(int i);                 //取图中第i个顶点数据信息
	void PutVex(int i, T value);     //将图中第i个顶点的数据域置为value
	void InsertVex(int i, T value);  //在图中插入一个顶点，其编号为i，值为value
	void DeleteVex(int i);           //删除图中第i个顶点
	void InsertArc(int i, int j);    //在图中插入一条边，其依附的两个顶点的编号为i和j
	void DeleteArc(int i, int j);    //在图中删除一条边，其依附的两个顶点的编号为i和j
	void DFSTraverse(int v);         //深度优先遍历图
	void BFSTraverse(int v);         //广度优先遍历图
	int visited[MaxSize];
	//===============
	void List2Matrix(); //输出邻接矩阵
	int CountOutdegree0();//计算出度为0的顶点个数
	void DFS_nonrec(); //非递归深度
	void InverseList(); //建立逆邻接表
	bool hasPath_DFS(int x, int y); //有向图是否存在x->y的路径, DFS
	bool hasPath_BFS(int x, int y); //有向图是否存在x->y的路径, BFS
	//===============
private:
	VertexNode<T> adjlist[MaxSize];  //存放顶点表的数组
	int vertexNum, arcNum;           //图的顶点数和边数
};
#endif
