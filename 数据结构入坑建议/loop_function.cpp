// ����ѭ���ͺ���
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World!";

	cout << "Hello World!";
	
	cout << "Hello World!";

	//* Loop & Condition
	// TODO: for
	// for (int j = 0; j < 10; j++)
	// {
	// 	cout << "Hello World!";
	// }
	
	// TODO: while
	
	// TODO: if

	
	// TODO: switch
	return 0;
}


//* Function
//! ��ֵ����
int f1(int a)
{//a: ��ʽ����
	return a + 1;
}
// f1(x); x: ʵ�ʲ���

//!ģ�庯��
template<class T>
T f2(T a)
{
	return a + 1;
}
// f2<int>(x);

//!��������
int f3(int &a)
{	
	return a + 1;
}

//!�������ò���
template<class T>
T f4(const T &a)
{
	return a + 1;
}


//? option
//? ���õ�����
void fr()
{
	int a = 1;
	int &b = a;
}

//? ָ�������
void fp()
{
	int a = 1;
	int *p;
	p = &a;
	// or
	int *q = &a;
}
