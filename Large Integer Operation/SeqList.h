#pragma once
#include <iostream>
const int MaxSize = 1000;          //1000只是示例性的数据，可以根据实际问题具体定义

template <class DataType>        //定义模板类SeqList
class SeqList
{
public:
	//构造 析构
	SeqList() { length = 0; sign = 0; }            //无参构造函数，建立一个空的顺序表
	SeqList(DataType a[], int n);       //有参构造函数，建立一个长度为n的顺序表
	SeqList(SeqList&p);
	~SeqList() { }                   //析构函数为空

	void CheckIndex(int Index) const;
	int Length() const { return length; }        //求线性表的长度
	void Change(int i, DataType y);         //把第i位改为y
	void Insert(int i, const DataType& x);       //插入操作，在线性表中第i个位置插入值为x的元素
	DataType Delete(int i);              //删除操作，删除线性表的第i个元素
	void PrintList() const;                     //遍历操作，按序号依次输出各元素

	//Adtional
	void OverTurn(int h, int r);  //翻转
	void Reserve() { OverTurn(1, length); }
	friend SeqList<int> myAdd(const SeqList<int>& x, const SeqList<int>& y);
	friend SeqList<int> mySub(const SeqList<int>& x, const SeqList<int>& y);
	friend SeqList<int> myMul(const SeqList<int>& x, const SeqList<int>& y);
	friend struct StrofDiv myDiv(const SeqList<int>& x, const SeqList<int>& y);
	friend SeqList<int> Multiply_x(int x, SeqList<int> A);
	friend SeqList<int> div2(SeqList<int>& x);
	friend int Compare(const SeqList<int>& x, const SeqList<int>& y);

	//overload operator
	SeqList<int> operator +(const SeqList<int>&x) const;
	SeqList<int> operator -(const SeqList<int>&x) const;
	SeqList<int> operator *(const SeqList<int>&x) const;
	struct StrofDiv operator /(const SeqList<int>&x) const;

	DataType data[MaxSize];           //存放数据元素的数组
	int length;                        //线性表的长度
	bool sign; //+:0; -:1 用于解决减法符号问题
};

// store ans of /
struct StrofDiv
{
	SeqList<int>quotient;
	SeqList<int>mod;
	StrofDiv() {} //constructor
	StrofDiv(const StrofDiv&p)
	{//copy constructor
		*this = p;
	}
};

// store input 
struct myINPUT
{
	SeqList<int>x;
	SeqList<int>y;
	char op;  //operation +-*/
	myINPUT() {}
	myINPUT(const myINPUT&p) { *this = p; }
};
