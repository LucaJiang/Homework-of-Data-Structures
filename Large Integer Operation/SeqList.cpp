// cpp of SeqList
// overload operator +-*/
//Last Modification Time: 2019-07-13
#include "SeqList.h"
#include <algorithm>
using namespace std;

template <class T>
SeqList<T> ::SeqList(T a[], int n)
{
	if (n > MaxSize) throw "Illegal parameter value";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
	sign = 0;
}

template<class T>
SeqList<T>::SeqList(SeqList & p)
{
	this->length = p.length; 
	for (int i = 0; i < length; i++)
		this->data[i] = p.data[i];
	this->sign = p.sign;
}

template<class T>
void SeqList<T>::CheckIndex(int Index) const
{//Make sure the Index is valid. Index 1 : length
	if (Index < 1 || Index > length)
	{
		cout << "Input Number = " << Index << "; length = " << length << endl;
		throw "Illegal Input";
	}
}

template<class T>
void SeqList<T>::Change(int i, T y)
{//change data[i-1] to y
	CheckIndex(i);
	data[i - 1] = y;
}

template <class T>
void SeqList<T> ::Insert(int i, const T& x)
{
	if (length >= MaxSize) throw "overflow";
	if (i == length + 1)
	{
		data[i - 1] = x;
		length++;
		return;
	}
	else CheckIndex(i);
	
	if (i <= length)
		for (int j = length; j >= i; j--)
			data[j] = data[j - 1];             //注意第j个元素存在数组下标为j-1处
	data[i - 1] = x;
	length++;
}

template <class T>
T SeqList<T> ::Delete(int i)
{
	if (length == 0) throw "underflow";
	CheckIndex(i);
	T x = data[i - 1];              //取出位置i的元素
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];        //注意此处j已经是元素所在的数组下标
	length--;
	return x;
}

template <class T>
void SeqList<T> ::PrintList() const
{
	if (sign == 1)
		cout << "-"; //negtive num
	for (int i = 0; i < length; i++)
		cout<< data[i];                   //依次输出线性表的元素值
	//cout << endl;
}

template<class T>
void SeqList<T>::OverTurn(int h, int r)
{//head, rear
	CheckIndex(r);
	CheckIndex(h);
	if (r-- > h--)
	{
		int n = r - h + 1;
		for (int i = 0; i < n / 2; i++)
		{
			swap(data[i + h], data[r - i]);
		}
	}
	
}

template<class T>
SeqList<int> SeqList<T>::operator+(const SeqList<int>& p) const
{
	SeqList<int> x;
	x = myAdd(p, *this);
	return x;
}

template<class T>
SeqList<int> SeqList<T>::operator-(const SeqList<int>& p) const
{
	SeqList<int> x;
	x = mySub(*this, p);
	return x;
}

template<class T>
SeqList<int> SeqList<T>::operator*(const SeqList<int>& p) const
{
	SeqList<int> x;
	x = myMul(*this, p);
	return x;
}

template<class T>
StrofDiv SeqList<T>::operator/(const SeqList<int>& p) const
{
	return myDiv(*this, p);
}
