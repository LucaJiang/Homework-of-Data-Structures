//这个程序能帮助辨析几个很重要的概念
//教材有一些无法正常运行的程序就是忽略了这个细节
#include<iostream>
using namespace std;

struct str
{
	int data;
	str*next;
};

void fun(str*&p1, str*p2, str*p3)
{
	cout << "\nIn the function:\n";
	cout << "address of p1:" << &p1 << endl;
	cout << "data of p1:" << p1->data << endl;
	cout << "address of p1->next:" << p1->next << endl;
	cout << "address of p2:" << &p2 << endl;
	cout << "p2 point to:" << p2 << endl;
	cout << "change data in function!\n\n";
	p1->data = 3;
	p2->data = 4;
//	p3->next->data = 5;
	return;
}

int main()
{
	str s1, s2;
	str*p1 = &s1;
	str*p2 = &s2;
	s1.data = 1;
	s2.data = 2;
	s1.next = &s2;//p2
	s2.next = NULL;
	cout << "address of p1:" << &p1 << endl;
	cout << "p1 point to:" << p1 << endl << endl;
	cout << "p1->next:" << p1->next << endl;
	cout << "address of p2:" << &p2 << endl;
	cout << "p2 point to:" << p2 << endl;
	fun(p1, p2, p1);
	cout << "In main:\n";
	cout << "p1->data:" << p1->data << " p2->data:" << p2->data << endl;
	system("pause");
	return 0;
}
