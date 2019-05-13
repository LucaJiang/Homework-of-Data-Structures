//定义类中的成员函数，文件名为bitree.cpp
#include "BiTree.h"
#include<iostream>
#include <ctime>
#ifndef nullptr
#define nullptr 0 //define nullptr NULL
#endif
using namespace std;

/*
 *前置条件：二叉树不存在
 *输    入：无
 *功    能：构造一棵二叉树
 *输    出：无
 *后置条件：产生一棵二叉树
 */
template<class T>
BiTree<T>::BiTree()
{
	srand((unsigned)time(NULL));
	int t = rand() % 2;
//	if (t == 0)
	if (true)
	{
		cout << "使用方法一建树，";
		cout << "请输入创建一棵二叉树的结点数据（扩展二叉树）：" << endl;
		this->root = Creat();
	} 
	else
	{
		cout << "使用方法二建树：\n";
		this->root = Creat2();
	}
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：释放二叉链表中各结点的存储空间
 *输    出：无
 *后置条件：二叉树不存在
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：获取指向二叉树根结点的指针
 *输    出：指向二叉树根结点的指针
 *后置条件：二叉树不变
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot()const
{
	return root;
}
template<class T>
void BiTree<T>::ExchangeChild(BiNode<T>* root)
{
	if (root)
	{
		BiNode<T>*temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;
		ExchangeChild(root->lchild);
		ExchangeChild(root->rchild);
	}
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：前序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if (root == NULL)  return;
	else {
		cout << root->data ;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：中序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::InOrder(BiNode<T> *root)
{
	if (root == NULL)  return;      //递归调用的结束条件	          
	else {
		InOrder(root->lchild);    //中序递归遍历root的左子树
		cout << root->data ;    //访问根结点的数据域
		InOrder(root->rchild);    //中序递归遍历root的右子树
	}
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：后序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{
	if (root == NULL)   return;       //递归调用的结束条件
	else {
		PostOrder(root->lchild);    //后序递归遍历root的左子树
		PostOrder(root->rchild);    //后序递归遍历root的右子树
		cout << root->data ;      //访问根结点的数据域
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：层序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //采用顺序队列，并假定不会发生上溢

	BiNode<T>* Q[MaxSize];
	BiNode<T>* q;

	if (root == NULL) return;
	else {
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			cout << q->data ;
			if (q->lchild != NULL)    Q[rear++] = q->lchild;
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}

/*
 *前置条件：空二叉树
 *输    入：数据ch;
 *功    能：初始化一棵二叉树,构造函数调用
 *输    出：无
 *后置条件：产生一棵二叉树
 */
template <class T>
BiNode<T>* BiTree<T>::Creat()
{
	BiNode<T>* root;
	T ch;
//	cout << "请输入创建一棵二叉树的结点数据" << endl;
	cin >> ch;
	if (ch == '#') root = NULL;
	else
	{
		root = new BiNode<T>;       //生成一个结点
		root->data = ch;
		root->lchild = Creat();    //递归建立左子树
		root->rchild = Creat();    //递归建立右子树
	}
	return root;
}

template<class T>
int BiTree<T>::pos(T data, T pin[], int i2, int k)
{
	for (int i = i2; i < i2 + k ; i++)
	{
		if (pin[i]==data)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
void BiTree<T>::info(T x)
{//如果第一次查找成功&&第二次查找失败，就会出现小bug，不过问题不大
	BiNode<T>*bt;
	bt = root;
	bool isRoot = false;
	if (bt == nullptr)
	{
		cout << "空树";
		return;
	}
	if (bt->data==x)
	{//find -> root
		isRoot = true;
		cout << "该节点为根节点，左右子结点信息域为";
		if (bt->lchild != NULL)
			cout << bt->lchild->data;
		else
			cout << "NULL";
		cout << " ";
		if (bt->rchild != NULL)
			cout << bt->rchild->data;
		else
			cout << "NULL";
	} 
	//else //search
	bool Find = info(x, bt);
	if (!Find && !isRoot)
		cout << "找不到!";
}

template<class T>
BiNode<T> *BiTree<T>::Creat2()
{//i1为前序起始下标，i2中序起始下标，k序列长度
	int n;
	cout << "输入序列长度\n";
	cin >> n;
	cout << "输入前序序列\n";
	for (int i = 0; i < n ; i++)
	{
		cin >> pre[i];
	}
	cout << "输入中序序列\n";
	for (int i = 0; i < n; i++)
	{
		cin >> pin[i];
	}
	BiNode<T>* root;
	root = nullptr;//without this error: C4700
	root = subCreat2(root, 0, 0, n);
	return root;
}

template<class T>
//BiNode<T> * BiTree<T>::subCreat2(BiNode<T>*root, int i1, int i2, int k)
BiNode<T> * BiTree<T>::subCreat2(BiNode<T>*&root, int i1, int i2, int k)
{//i1为前序起始下标，i2中序起始下标，k序列长度
	if (k <= 0) root = NULL;
	else
	{
		root = new BiNode<T>;
		root->data = pre[i1];
		int m = pos(pre[i1], pin, i2, k);
		int leftlen = m - i2;
		int rightlen = k - (leftlen + 1);

		if (k >= 2)
		{ // 解决了有两个重复元素的问题
			while (true)
			{
				int m_next=pos(pre[i1], pin, m + 1, rightlen);
				if (m_next != -1)//有重复元素
				{
					int check = pos(pre[i1], pre, i1, leftlen);
					if (check != -1)//矛盾！
					{
						m = m_next;
						leftlen = m - i2;
						rightlen = k - (leftlen + 1);
					}
					else
						break;
				}
				else
					break;
			}
		}
		subCreat2(root->lchild, i1 + 1, i2, leftlen);
		//root->lchild = subCreat2(root->lchild, i1 + 1, i2, leftlen);
		subCreat2(root->rchild, i1 + leftlen + 1, m + 1, rightlen);
		//root->rchild = subCreat2(root->rchild, i1 + leftlen + 1, m + 1, rightlen);
	}
	return root;
}

template<class T>
int BiTree<T>::countLeaves()
{
	int num = 0; 
	if (root == nullptr)
		return 0;
	else if (root != NULL)
		countLeaves(root, num);
	else
		num++;
	return num;
}

/*
 *前置条件：二叉树已经存在
 *输    入：无
 *功    能：释放二叉树的存储空间，析构函数调用
 *输    出：无
 *后置条件：二叉树不存在
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
	if (root != NULL)
	{
		Release(root->lchild);   //释放左子树
		Release(root->rchild);   //释放右子树
		delete root;
	}
}

template<class T>
bool BiTree<T>::Delete(T x)
{
	if (root == nullptr)
	{
		cout << "空树";
		return true;
	}
	if (root->data == x)
	{
		Release(root);
		root = nullptr;
	}
	else
	{
		BiNode<T>*ft = FindParent(x);
		if (ft == NULL)
			return false;
		if (ft->lchild != NULL && ft->lchild->data == x)
		{
			Release(ft->lchild);
			ft->lchild = NULL;
		}
		if (ft->rchild != NULL && ft->rchild->data==x)
		{
			Release(ft->rchild);
			ft->rchild = NULL;
		}
	}
	return true;
}

template<class T>
bool BiTree<T>::info(T x, BiNode<T>* bt)
{
	static bool isFind = false;//之前提到的小bug和这行有关
	if (bt!=NULL)
	{
		if (bt->lchild != NULL && bt->lchild->data == x)
		{//find!
			cout << "父节点为" << bt->data << " 左右子结点信息域为";
			bt = bt->lchild;
			if (bt->lchild != NULL)
				cout << bt->lchild->data;
			else
				cout << "NULL";
			cout << " ";
			if (bt->rchild != NULL)
				cout << bt->rchild->data;
			else
				cout << "NULL";
			cout << endl;
			isFind = true;
		}
		else if (bt->rchild != NULL && bt->rchild->data == x)
		{//find!
			cout << "父节点为" << bt->data << " 左右子树信息域为";
			bt = bt->rchild;
			if (bt->lchild != NULL)
				cout << bt->lchild->data;
			else
				cout << "NULL";
			if (bt->rchild != NULL)
				cout << bt->rchild->data;
			else
				cout << "NULL";
			cout << endl;
			isFind = true;
		}
		else
		{
			info(x, bt->lchild);
			info(x, bt->rchild);
		}
	}
	return isFind;
}

template<class T>
BiNode<T>* BiTree<T>::FindParent(T x, BiNode<T>* bt)
{
	int top = -1;
	BiNode<T>* S[MAX];
	while (bt != NULL || top != -1)
	{
		while (bt != NULL)
		{
			if (bt->lchild != NULL && bt->lchild->data == x)
				return bt;
			if (bt->rchild != NULL && bt->rchild->data == x)
				return bt;
			S[++top] = bt;
			bt = bt->lchild;
		}
		if (top != -1)
		{
			bt = S[top--];
			bt = bt->rchild;
		}
	}
	return NULL;
}

template<class T>
void BiTree<T>::countNode(BiNode<T>* root, int &num) const
{
//	if (root != NULL)
	if (root)
	{
		num++;
		countNode(root->lchild, num);
		countNode(root->rchild, num);
	}
}

template<class T>
void BiTree<T>::countLeaves(BiNode<T>* root, int & num) const
{ //前置条件： root!=NULL
	if (root->lchild == NULL && root->rchild == NULL)
		num++;
	else
	{
		if(root->lchild!=NULL)
			countLeaves(root->lchild, num);
		if (root->rchild != NULL)
			countLeaves(root->rchild, num);
	}
}

template<class T>
void BiTree<T>::countOnlyLchild(BiNode<T>* root, int & num) const
{
	if (root == NULL) return;
	else if (root->lchild != NULL && root->rchild == NULL)
	{
		num++;
		countOnlyLchild(root->lchild, num);
	}
	else
	{
		if (root->lchild != NULL)
			countOnlyLchild(root->lchild, num);
	//	if (root->rchild != NULL)                    
			countOnlyLchild(root->rchild, num);
	}
}

template<class T>
void BiTree<T>::PrintTree(BiNode<T>* root)
{
	cout << "PrintTree:\n\n";
	if (root == nullptr)
		return;
	struct Node4Print
	{//记录深度和左子树是否已经输出
		int deep;
		bool isLchildPrt = false;
		BiNode<T>*p;
	}Node4Print[MAX]; //最大数量 
	int top = -1;//top pointer Node4Print
	BiNode<T>*at = root; //当前结点
	Node4Print[++top].p = at; //root 入栈 
	Node4Print[top].deep = 0;
	cout << " " << at->data << endl;

	int vertline[MAX]; // 记录垂线位置
	int ttop = -1; //top pointer vertline

	while (top != -1) //栈不空
	{
		at = Node4Print[top].p;
		if (at->lchild != NULL && !Node4Print[top].isLchildPrt)
		{//cout & enNode4Print at->lchild
			BiNode<T>*ft = at;//ft 用于记录父结点
			at = at->lchild;
//		    cout<<"deep="<<Node4Print[top].deep<<";";
			for (int i = 0; i <= Node4Print[top].deep; i++)
			{
				bool check = 0; //判断是否输出垂线
				for (int j = 0; j <= ttop; j++)
				{
					if (i == vertline[j] - 1)
					{
						cout << "│";
						check = 1;
						break;
					}
				}
				if (check == 0)
					cout << " ";
			}
			if (ft->rchild == NULL) //at没有兄弟
			{//ft出栈，at入栈
				Node4Print[top].p = at;
				Node4Print[top].deep++;
				cout << "└ " << Node4Print[top].p->data<< endl;
			}
			else
			{//at入栈，ft不出栈，因为还要找ft->rchild
				Node4Print[top].isLchildPrt = true;//标记ft为已输出左子树
				Node4Print[++top].p = at;
				Node4Print[top].deep = Node4Print[top - 1].deep + 1;
				vertline[++ttop] = Node4Print[top].deep + 1;
				cout << "├ " << Node4Print[top].p->data<< endl;
			}
			/*for (int j = 0; j <= ttop; j++)
				cout << vertline[j]; 
			cout << endl;*/
		}

		else if (at->rchild != NULL)
		{//cout & enNode4Print at->rchild
			BiNode<T>*ft = at;//ft 用于记录父结点
			at = at->rchild;
			Node4Print[top].p = at;//ft出栈，at入栈
			Node4Print[top].deep++;
			Node4Print[top].isLchildPrt = false;
//		    cout<<"deep="<<Node4Print[top].deep<<";";
			for (int i = 0; i < Node4Print[top].deep; i++)
			{
				bool check = 0;
				for (int j = 0; j <= ttop; j++)
				{
					if (i == vertline[j] - 1)
					{
						cout << "│";
						check = 1;
					}
				}
				if (check == 0)
					cout << " ";
			}
			cout << "└ " << Node4Print[top].p->data << endl;
			//for (int j = 0; j <= ttop; j++)
			//	cout << vertline[j]; 
			//cout << endl;
		}

		else
		{//at是叶子，此时at已经作为子结点输出，故直接出栈
			Node4Print[--top].p;
			ttop--;
		}
	}
}
