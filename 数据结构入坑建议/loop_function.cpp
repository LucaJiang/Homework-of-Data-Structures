// 讲解循环和函数
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
//! 传值参数
int f1(int a)
{//a: 形式参数
	return a + 1;
}
// f1(x); x: 实际参数

//!模板函数
template<class T>
T f2(T a)
{
	return a + 1;
}
// f2<int>(x);

//!参数引用
int f3(int &a)
{	
	return a + 1;
}

//!常量引用参数
template<class T>
T f4(const T &a)
{
	return a + 1;
}


//? option
//? 引用的声明
void fr()
{
	int a = 1;
	int &b = a;
}

//? 指针的声明
void fp()
{
	int a = 1;
	int *p;
	p = &a;
	// or
	int *q = &a;
}
