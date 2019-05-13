#pragma once
#include <iostream>
using namespace std;
const int MAX = 30;
template <class T>
struct BiNode   //二叉树的结点结构
{
	T data;
	BiNode<T> *lchild = NULL;
	BiNode<T> *rchild = NULL;
};

template <class T>
class BiTree
{
public:
	BiTree();             //构造函数，初始化一棵二叉树，其前序序列由键盘输入
	~BiTree(void);         //析构函数，释放二叉链表中各结点的存储空间
	void PreOrder(BiNode<T> *root);     //前序遍历二叉树
	/*这样写会好一些
	void PreOrder(){PreOrder(root);}
	*/
	bool Delete(T);
	void info(T x);
	void Release(BiNode<T> *root);   //析构函数调用 
	void InOrder(BiNode<T> *root);      //中序遍历二叉树
	void PostOrder(BiNode<T> *root);    //后序遍历二叉树
	void LeverOrder(BiNode<T> *root);   //层序遍历二叉树
	void PrintTree() { PrintTree(root); }
	int countLeaves();
	int pos(T, T[], int, int);   //4Creat2
	int countNode() { int num = 0; countNode(root, num); return num; }
	int countOnlyLchild() { int num = 0; countOnlyLchild(root, num); return num; }
	BiNode<T>* Getroot()const;  //获得指向根结点的指针
	BiNode<T> *FindParent(T x) { if (root == NULL) return root; return FindParent(x, root); }

private:
	/*这样写会好一些
	void PreOrder(BiNode<T>*bt)const;
	*/
	T pin[MAX]; //4Creat2
	T pre[MAX]; //4Creat2
	BiNode<T> *root;         //指向根结点的头指针
	BiNode<T> *Creat();     //有参构造函数调用
	BiNode<T> *Creat2();     //有参构造函数调用
	BiNode<T> *FindParent(T x, BiNode<T> *bt);
	BiNode<T> *subCreat2(BiNode<T>*&root, int i1, int i2, int k);     //有参构造函数调用
	bool info(T x, BiNode<T> *bt);
	void PrintTree(BiNode<T>*);
	void countNode(BiNode<T>*root, int &num) const;
	void countLeaves(BiNode<T>*root, int &num) const;
	void countOnlyLchild(BiNode<T>*root, int &num) const;
};
