//程序说明：2019-04-01
//中缀算术表达式的求值：算术表达式的四则运算的规则是：
//	1）先乘除，后加减；2）从左算到右；3）先括号内，后括号外
//最后修改：2019-04-05
#include <iostream>
#include "SeqStack.cpp"
#include <string>
using namespace std;
const int Max = 100; //max of expression array

int calculate(int a, int b, char c)
{//be careful here! 
//解释：因为栈，所以从右至左调用，故中间的pop是最先被弹出的数据，第一个pop是第二个被弹出的数据！ 
//	cout << "calculate" << a << c << b << endl;
	switch (c) 
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	default:
		throw "unknown exception.";
		return 0;
	}
}

int prior(char a) 
{//prior: */ > +- > ( 
	if (a == '+' || a == '-')
		return 1;
	else if (a == '*' || a == '/')
		return 2;
	else if (a == '(')
		return 0;
	else
//		cout <<"a a"<< a<<"a";
		throw "unidentifiable parameter!";
	return 0;
}

bool compare(char a, char b) 
{// compare OPER, return a > b;
	return prior(a) > prior(b);
}

void CoreFunction(char exprs[]) 
{
	SeqStack<char> OPTR;
	SeqStack<int> OPND;
	const char* p = &exprs[1];
	while (*p != '#')
	{// until p == #
		if ('0' <= *p && *p <= '9')
		{//if p = OPND
			int x = *p - 48;
			p++;
			while ('0' <= *p && *p <= '9')
			{//thus we can calculate without the limitation of digits
				x = x * 10 + *p - 48;
				p++;
			}
			if (x < 0)
				throw"overflow";
			OPND.Push(x);
		}
		else if (*p == '(')
		{
			OPTR.Push(*p);
			p++;
		}
		else if (*p == ')')
		{ //pop until find first (
			while (OPTR.GetTop() != '(')
			{ 				
				OPND.Push(calculate(OPND.Pop(), OPND.Pop(), OPTR.Pop()));
			}
			OPTR.Pop(); // pop ( 
			p++;
		}
		else if (*p <= '/' && *p >= '*')
		{ //p = OPTR
			if (OPTR.isEmpty())
			{
				OPTR.Push(*p);
				p++;
			}
			else //!OPTR.isEmpty();
				if (compare(*p, OPTR.GetTop()))
				{//*p>top
					OPTR.Push(*p);
					p++;
				}
				else //*p<=top
					OPND.Push(calculate(OPND.Pop(), OPND.Pop(), OPTR.Pop()));
		}
		else
		{
			p++;
			throw"unknow exceptions.";
		}
	}
	//clear the stack of optr
	while (!OPTR.isEmpty())
	{
		OPND.Push(calculate(OPND.Pop(), OPND.Pop(), OPTR.Pop()));
	}
	//cout ans
	cout << "ans=" << OPND.Pop() << endl;
	cout << "按格式输入算式继续运算，或输入\"*\"退出!" << endl;
}

int main() 
{
	cout << "输入格式: #3*(4+5)-6/2#\t英文输入！" << endl;
	while (true) 
	{
		char exprs[Max]; //expression
		cin >> exprs;
		if (exprs[0] == '#')
		{
			try
			{
				CoreFunction(exprs);
			}
			catch (char* e)
			{
				cout << e;
			}
		}
		else if (exprs[0] == '*') //exit
			break;
		else cout << "Unidentifiable parameter! Try again." << endl;
	}
	system("pause");
	return 0;
}
