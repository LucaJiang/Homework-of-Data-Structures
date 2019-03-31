//程序说明：2019-03-18
//一元多项式相加
//最后修改：2019-03-18

#include <iostream>
using namespace std;

struct Node
{
	int coef;    //coef field
	int exp;      //exp field
	Node *next;
};

class LinkList {
public:
	LinkList();
	~LinkList(); 
	void Insert(int x_exp, int x_coef);
	void PrintList();
	friend void myAdd(LinkList A, LinkList B);
private:
	Node *first;  //ATTENTION: head pointer without data
};

LinkList::LinkList() 
{
	first = new Node;
	Node*p;
	p = new Node;
	first->next = p;
	p->exp = 0;
	p->coef = 0;
	p->next = NULL;
}

LinkList:: ~LinkList()
{
	Node *q;
	while (first != NULL)
	{
		q = first;
		first = first->next;
	}
	delete first;
}

void LinkList::Insert(int x_exp, int x_coef) 
{//insert in order
	Node* p = first->next;
	Node*pre = first;
	while (x_exp > p->exp && p->next != NULL) 
	{
		p = p->next;
		pre = pre->next;
	}
	if (x_exp == p->exp) 
		p->coef = x_coef + p->coef;
	else if (x_exp > p->exp && p->next == NULL) 
	{//p->s->NULL build new node 
		Node* s;
		s = new Node;
		s->exp = x_exp;
		s->coef = x_coef;
		s->next = NULL;
		p->next = s;
	}
	else 
	{//pre->s->p build new node
		Node* s;
		s = new Node;
		s->exp = x_exp;
		s->coef = x_coef;
		s->next = p;
		pre->next = s;
	}
}

void LinkList::PrintList() 
{
	Node*p; 
	p = first->next;
	if (p == NULL)
	{
		return;
	}
	else
	{
		if (p->coef != 0 && p->exp == 0)
			cout << p->coef << "+ ";
		p = p->next;
		while (p->next != NULL)
		{
			if (p->coef != 0)
			{
				if(p->exp==1)
					cout << p->coef << "x" << "+ ";
				else
					cout << p->coef << "x^" << p->exp << "+ ";
				p = p->next;
			}
			else
				p = p->next;
		}
		cout << p->coef << "x^" << p->exp << endl;
	}
	
}

void myAdd(LinkList A, LinkList B) 
{
	Node*p=B.first->next;
	while(p!=NULL)
	{
		A.Insert(p->exp, p->coef);
		p = p->next;
	}

	cout << "A + B = ";
	A.PrintList();
}

int main()
{
	cout << "请按如下格式输入多项式（可以不按顺序）：coef  exp\n结束输入符号 “* ”" << endl;
	cout << "输入A的每一项" << endl;
	LinkList A;
	while (true) 
	{
		char m, n;
		cin >> m;
		if (m != '*') 
		{
			cin >> n;
			int p, q;
			p = m - '0';
			q = n - '0';
			A.Insert(q, p);  //exp coef
			cout << q << "x^" << p << endl;
		}
		else 
		{ 
			cout << "break" << endl; 
			break; 
		}
	}
	cout << "A = ";
	A.PrintList();
	cout << endl;

	cout << "输入B的每一项" << endl;
	LinkList B;
	while (true) 
	{
		char m, n;
		cin >> m;
		if (m != '*') 
		{
			cin >> n;
			int p, q;
			p = m - '0'; 
			q = n - '0';
			B.Insert(q, p);  //exp coef 
			cout << q << "x^" << p << endl;
		}
		else 
		{ 
			cout << "break" << endl; 
			break; 
		}
	}
	cout << "B =";
	B.PrintList();
	cout << endl;

	myAdd(A, B);
	system("pause");
}
