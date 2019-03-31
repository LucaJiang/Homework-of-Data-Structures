#ifndef LinkList_H
#define LinkList_H

template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkList
{
public:
	LinkList();                     //无参构造函数，建立只有头结点的空链表
	LinkList(T a[], int n);      //有参构造函数，建立有n个元素的单链表
	~LinkList();                    //析构函数
	int Locate(T x);           //按值查找。在单链表中查找值为x的元素序号
	void Insert(int i, T x);      //插入操作，第i个位置插入元素值为x的结点
	T Delete(int i);           //删除操作，在单链表中删除第i个结点
	void PrintList();                 //遍历操作，按序号依次输出各元素
	bool isSubOf(Node<T>*);
	Node<T>* First();
//	friend int myisSub(LinkList<T>x, LinkList<T>y);
private:
	Node<T> *first;                     //单链表的头指针
};
#endif


#include "LinkList.h"
#include <iostream>

using namespace std;
template <class T>
LinkList<T> ::LinkList()
{
	first = new Node<T>;                        //生成头结点
	first->next = NULL;                      //头结点的指针域置空
}

template <class T>
LinkList<T> ::LinkList(T a[], int n)
{
	Node<T> *r, *s;  //s:work pointer; r:rear
	first = new Node<T>;                    //生成头结点
	r = first;                            //尾指针初始化
	r->data = a[0];
	for (int i = 1; i < n; i++)
	{
		s = new Node<T>;
		s->data = a[i];        //为每个数组元素建立一个结点
		r->next = s; r = s;                 //将结点s插入到终端结点之后
	}
	r->next = NULL;        //单链表建立完毕，将终端结点的指针域置空
}

template <class T>
LinkList<T> :: ~LinkList()
{
	Node<T> *q;
	while (first != NULL)        //释放单链表的每一个结点的存储空间
	{
		q = first;                 //暂存被释放结点
		first = first->next;         // first指向被释放结点的下一个结点
		delete q;
	}
	delete first;
}

template <class T>
void LinkList<T> ::Insert(int i, T x)
{
	Node<T> *p = first, *s;
	int count = 1;               //工作指针p应指向头结点
	if (i == 1)
	{
		s = new Node<T>;  s->data = x;     //申请一个结点s，head
		first = s;
		first->next = p;
	}
	else
	{
		while (p != NULL && count < i - 1)  //查找第i - 1个结点
		{
			p = p->next;                   //工作指针p后移
			count++;
		}
		if (p == NULL) throw "Illigeal Parameter";      //没有找到第i - 1个结点
		else {
			s = new Node<T>;  s->data = x;     //申请一个结点s，其数据域为x
			s->next = p->next; p->next = s;   //将结点s插入到结点p之后
		}
	}
}

template <class T>
T LinkList<T> ::Delete(int i)
{
	Node<T> *p, *q;
	T x;
	int count = 1;
	p = first;               //注意工作指针p要指向头结点
	if (i == 1)
	{
		q = first; x = q->data;         //暂存被删结点
		first = first->next;
		delete q;
		return x;
	}
	else
	{
		while (p != NULL && count < i - 1)  //查找第i-1个结点
		{
			p = p->next;
			count++;
		}
		if (p == NULL || p->next == NULL)  //结点p不存在或p的后继结点不存在
			throw "位置";
		else {
			q = p->next; x = q->data;         //暂存被删结点
			p->next = q->next;              //摘链
			delete q;
			return x;
		}
	}
}

template <class T>
int LinkList<T> ::Locate(T x)
{
	Node<T> *p = first;
	int count = 1;         //工作指针p和累加器count初始化
	while (p != NULL)
	{
		if (p->data == x) return count;     //查找成功，结束函数并返回序号
		p = p->next;
		count++;
	}
	return 0;                        //退出循环表明查找失败
}

template <class T>
void LinkList<T> ::PrintList()
{
	Node<T> *p = first;                 //工作指针p初始化
	while (p != NULL)
	{
		cout << p->data << "  ";
		p = p->next;                 //工作指针p后移，注意不能写作p++
	}
	cout << endl;
}

template <class T>
bool LinkList<T> ::isSubOf(Node<T>*y)
{// x belong to y? y is first of another set.
	Node<T>*p;
	p = y;
	while (p != NULL)
	{
		if (Locate(p->data) == 0)
			return false;
		p = p->next;
	}
	return true;
}

template<class T>
Node<T>* LinkList<T>::First()
{
	return first;
}

//程序说明：2019-03-18
//实现无头指针的线性表及判断子集
//最后修改：2019-03-19

#include <iostream>   //引用输入输出流库函数的头文件
#include "LinkList.cpp"  //引用单链表类的声明和定义
#include <string>
using namespace std;
const int Max = 50; //max num of input array

int init(char a[])
{
	int n;
	string input;
	cin >> input;
	if (input[0] == '*'&&input[1] == '*')
		return 0;
	n = input.length();
	int i = 0;
	for (; i < n; i++)
		a[i] = input[i];
	a[i] = '\0';
	return n;
}

void prob1() 
{
	cout << "\n第一题实现无头指针的线性表 及 第三题判断子集都在这里！！！！\n";
	int r[5] = { 1, 2, 3, 4, 5 };
	LinkList<int> L(r, 5);
	cout << "执行插入操作前数据为：" << endl;
	L.PrintList();                  //显示链表中所有元素
	try
	{
		L.Insert(2, 3);
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	cout << "执行插入操作后数据为：" << endl;
	L.PrintList();                  //显示链表中所有元素
	cout << "值为5的元素位置为:";
	cout << L.Locate(5) << endl;        //查找元素5，并返回在单链表中位置
	cout << "执行删除操作前数据为：" << endl;
	L.PrintList();                  //显示链表中所有元素
	try
	{
		L.Delete(3);                    //删除元素
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	cout << "执行删除操作后数据为：" << endl;
	L.PrintList();                  //显示链表中所有元素
}
 
bool prob2()
{
	cout << "请输入'**'退出, 或请输入第一个集合:\n";
	char array[Max];
	int n_a = init(array);
	if (n_a == 0)
		return false;
	LinkList<char>A(array, n_a);
	cout << "请输入第二个集合:\n";
	char brray[Max];
	int n_b = init(brray);
	LinkList<char>B(brray, n_b);
	if (B.isSubOf(A.First()))
		cout << "第一个集合是第二个的子集\n";
	else
		cout << "第一个集合不是第二个的子集\n";
	cout << endl;
	return true;
}


int main()
{
	prob1();
	cout << endl << endl << endl;
	cout << "第三题判断子集\n";
	while (prob2())
	{
		continue;
	}
	system("pause");
	return 0;
}
