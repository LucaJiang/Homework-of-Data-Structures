//程序说明：2019-03-11
//大整数基本运算；
//最后修改时间：2019-07-13
#include <iostream>
#include "SeqList.cpp"           //引用顺序表的类声明和定义  
#include "Operation.h"       // 四则运算 重载输入输出流

using namespace std;
//const int MaxSize = 100;  in "SeqList.h"

void mainfunction() 
{
	myINPUT myinput;
	cout << ">";
	cin >> myinput;
	cout << "=";
	switch (myinput.op)
	{
	case '+':
	{
		cout << myinput.x + myinput.y << endl;
		break;
	}
	case '-':
	{
		cout << myinput.x - myinput.y << endl;
		break;
	}
	case '*':
	{
		cout << myinput.x * myinput.y << endl;
		break;
	}
	case '/':
	{
		cout << myinput.x / myinput.y << endl;
		break;
	}
	default:
	{
		throw"UNKNOW ERROR\n";
		break;
	}
	}

	cout << "输入'+'继续，输入'-'退出\n";
	char isExit;
	cin >> isExit;
	if (isExit == '+')
		mainfunction(); //continue to calculate
	else
		return;
}

int main() 
{
	cout << "大整数四则运算\n演示程序\n";
	cout << "输入：\n 123456789/5456432\n";
	cout << "输出：\n=";
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int b[7] = { 5,4,5,6,4,3,2 };
	SeqList<int> ary(a, 9);
	SeqList<int> bry(b, 7);
	cout<<ary / bry<<endl;
	cout << "现在，开始你的输入！\n\n";
	mainfunction();
	cout << "退出\n";
	system("pause");
	return 0;
}
