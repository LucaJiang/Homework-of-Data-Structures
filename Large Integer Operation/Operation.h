//operation: +-*/
// overload operator << >>
#pragma once
#include "SeqList.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Compare(const SeqList<int>& x, const SeqList<int>& y)
{ // x>y 1;  x=y -1;  x<y 0;
	if (x.length > y.length) return 1;
	else if (x.length < y.length) return 0;
	else
	{
		for (int i = 0; i < x.length; i++)
		{
			if (x.data[i] > y.data[i]) return 1;
			else if (x.data[i] < y.data[i]) return 0;
		}
	}
	return -1;
}

SeqList<int> myAdd(const SeqList<int>& x, const SeqList<int>& y)
{// +
	SeqList<int> C; //存储答案 C = A + B
	int flag = 0;  //进位标志
	int i = 0;    //位数
	SeqList<int> A;
	A= x;
	SeqList<int> B;
	B = y;
	int m = A.Length(); int n = B.Length();
	A.Reserve(); B.Reserve();
	while (i < m&&i < n) 
	{
		C.data[i] = (A.data[i] + B.data[i] + flag) % 10;
		flag = (A.data[i] + B.data[i] + flag) / 10;
		i++;
	}
	while (i < m) 
	{
		C.data[i] = (A.data[i] + flag) % 10;
		flag = (A.data[i] + flag) / 10;
		i++;
	}
	while (i < n) 
	{
		C.data[i] = (B.data[i] + flag) % 10;
		flag = (B.data[i] + flag) / 10;
		i++;
	}
	C.length = max(m, n) + flag;
	if (flag == 1) C.data[i] = 1;
	C.Reserve();
	return C;
}

SeqList<int> mySub(const SeqList<int>& x, const SeqList<int>& y)
{// -
	int flag = 0;  //进位标志
	int i = 0;    //位数
	bool negflag = false;
	SeqList<int> A, B;//make sure A>B
	if (Compare(x, y) == -1)
	{
		int ZERO[1] = { 0 };
		SeqList<int>zero(ZERO, 1);
		return zero;
//		throw"Illegal Parameter";
	}
	else if (Compare(x, y) == 0)
	{
		negflag = true;
		A = y; B = x;
	}
	else
	{
		A = x; 
		B = y;
	}
	A.Reserve(); B.Reserve();
	for (; i < B.length; i++)
	{
		A.data[i] += flag;
		if (A.data[i] < B.data[i])
		{
			A.data[i] = A.data[i] + 10 - B.data[i];
			flag = -1;
		}
		else
		{
			A.data[i] -= B.data[i];
			flag = 0;
		}
	}
	if (flag==-1)
	{
		A.data[i]--;
	}
	while (true)
	{
		if (A.data[A.length - 1] == 0)
		{
//			cout << "d\n";
			A.Delete(A.length);
		}
		else break;
	}
	A.Reserve();
	if (negflag == true)
		A.sign = 1;
	return A;
}

SeqList<int> Multiply_x(int x, SeqList<int> A) 
{//C=x*A  ATT: A had been reserve! return reserve C
	int flag = 0;  //进位标志
	int i = 0;    //位数
	int m = A.Length();
	SeqList<int> C;
	while (i < m) 
	{
		C.data[i] = (x*A.data[i] + flag) % 10;
		flag = (x*A.data[i] + flag) / 10;
		i++;
	}
	C.length = m;
	if (flag > 0) 
	{
		C.length = m + 1;
		C.data[m] = flag;
	}
	return C;
}

SeqList<int> myMul(const SeqList<int>& x, const SeqList<int>& y)
{// *
	SeqList<int>A;
	A = x;
	SeqList<int>B;
	B = y;
	//A.len >= B.len  for efficiency
	if (A.length < B.length)
	{
		SeqList<int> temp;
		temp = A;
		A = B;
		B = temp;
	}

	int flag = 0;  //进位标志
	int i = 0;    //位数
	A.Reserve();
	B.Reserve();
	SeqList<int> C;  //存储 B.data[i]*A
	SeqList<int> D;  //存储乘法结果 
	int n = B.Length();
	while (i < n) 
	{
		C = Multiply_x(B.data[i], A);   //C=B.data[i]*A
		if (i == 0)
			D = C;
		else 
		{
			for (int j = i; j > 0; j--)
				C.Insert(1, 0);
			C.Reserve();
			D.Reserve();
			D = C + D;
			D.Reserve();
		}
		i++;
	}
	D.Reserve();
	return D;
}

SeqList<int> div2(SeqList<int>& x)
{// x/2 inf
	SeqList<int> A = x;
	int n = x.length;
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		A.data[i] += 10 * flag;
		flag = A.data[i] % 2 == 0 ? 0 : 1;
		A.data[i] /= 2;
	}
	if (A.data[0] == 0)
		A.Delete(1);
	return A;
}

struct StrofDiv myDiv(const SeqList<int>& x, const SeqList<int>& y)
{// x/y
	//二分法
	//x>y
	SeqList<int>A;
	A = x;
	SeqList<int>B;
	B = y;

	if (Compare(A, B) == 0)
	{
//		throw"Illegal Parameter";
		int ZERO[1] = { 0 };
		SeqList<int>zero(ZERO, 1);
		StrofDiv ANS;
		ANS.quotient = zero;
		ANS.mod = A;
		return ANS;
	}
	if (B.length == 1 && B.data[0] == 0)
	{
		cout << "Integer Division by Zero";
//		throw"Integer Division by Zero";
		StrofDiv re;
		return re;
	}
	//构造二分法两个端点
	int n = A.length - B.length;
	int arrayC1[MaxSize];
	arrayC1[0] = { 1 };
	int arrayC2[MaxSize];
	arrayC2[0] = { 1 };
	for (int i = 1; i < n + 2; i++)
	{
		arrayC1[i] = 0;
		arrayC2[i] = 0;
	}
	SeqList<int> C1(arrayC1, n);
	SeqList<int> C2(arrayC2, n + 2); //二分法的两个端点
	SeqList<int> C; //二分法中点,猜测答案
	SeqList<int> oldC; //判断C是否改变
	SeqList<int> D; //和A比较

	while (true)
	{
		oldC = C;
		C = C1 + C2;
		C = div2(C); //二分法中点
		if (Compare(oldC, C) == -1) //no change C
			break;
		D = C * B;
		int w = Compare(D, A);
		if (w == 0) //A>D, right
			C1 = C;
		else if (w == 1) //A<D, left
			C2 = C;
		else //A == D
		{
			StrofDiv ANS;
			ANS.quotient = C;
			ANS.mod.length = 1;
			ANS.mod.data[0] = 0;
			return ANS;
		}
	}

	// mod != 0;
	int ONE[1] = { 1 };
	SeqList<int>one(ONE, 1);

	D = B * C;
	int w = Compare(D, A);
	if (w == 1) //A<B*C
		C = C - one;

	StrofDiv ANS;
	ANS.quotient = C;
	D = B * C;
	ANS.mod = A - D;
	return ANS;
}

// to print ans of + - *
template <class T>
ostream& operator<<(ostream& out, const SeqList<T>& x)
{
	x.PrintList(); return out;
}

// to print ans of /
ostream& operator<<(ostream& out, const StrofDiv& x)
{
	if (x.mod.data[0] != 0)
	{
		out << x.quotient << "..." << x.mod;
		return out;
	}
	else
	{
		out << x.quotient;
		return out;
	}
}

istream& operator>>(istream& in, myINPUT& myinput)
{
	char Input[MaxSize * 2 + 1];
	char*p = &Input[0];
	in >> Input;
	int a[MaxSize];
	int m = 0;
	for (; '0' <= *p&&*p <= '9'; p++, m++)
		a[m] = *p - 48;
	SeqList<int>j(a, m);
	myinput.x = j;
	myinput.op = *p;
	p++;
	m = 0;
	for (; '0' <= *p&&*p <= '9'; p++, m++)
		a[m] = *p - 48;
	SeqList<int>w(a, m);
	myinput.y = w;
	return in;
}
