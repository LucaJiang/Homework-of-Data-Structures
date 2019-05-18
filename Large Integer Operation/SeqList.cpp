// cpp of SeqList
// overload operator +-*/
#include "SeqList.h"
#include <algorithm>

using namespace std;

template <class DataType>
SeqList<DataType> ::SeqList(DataType a[], int n)
{
	if (n > MaxSize) throw "Illegal parameter value";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
	sign = 0;
}

template<class DataType>
SeqList<DataType>::SeqList(SeqList & p)
{
	length = p.length;
	for (int i = 0; i < length; i++)
		data[i] = p.data[i];
	sign = p.sign;
}

template<class DataType>
void SeqList<DataType>::CheckIndex(int Index) const
{//Make sure the Index is valid. Index 1 : length
	if (Index < 1 || Index > length)
	{
		cout << "Input Number = " << Index << "; length = " << length << endl;
		throw "Illegal Input";
	}
}

template<class DataType>
void SeqList<DataType>::Change(int i, DataType y)
{
	CheckIndex(i);
	data[i - 1] = y;
}

template <class DataType>
void SeqList<DataType> ::Insert(int i, const DataType& x)
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

template <class DataType>
DataType SeqList<DataType> ::Delete(int i)
{
	if (length == 0) throw "underflow";
	CheckIndex(i);
	DataType x = data[i - 1];              //取出位置i的元素
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];        //注意此处j已经是元素所在的数组下标
	length--;
	return x;
}

template <class DataType>
void SeqList<DataType> ::PrintList() const
{
	if (sign == 1)
		cout << "-";
	for (int i = 0; i < length; i++)
		cout << data[i];                   //依次输出线性表的元素值
	//cout << endl;
}

template<class DataType>
void SeqList<DataType>::OverTurn(int h, int r)
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

template<class DataType>
SeqList<int> SeqList<DataType>::operator+(const SeqList<int>& p) const
{
	SeqList<int> x1;
	//x1.data = this->data;
	////(this->data, this->length);
	//x1 = myAdd(x1, x);
	//return x1;
	x1.length = length;
	for (int i = 0; i < length; i++)
		x1.data[i] = data[i];
	x1.sign = sign;
	x1 = myAdd(x1, p);
	return x1;
}

template<class DataType>
SeqList<int> SeqList<DataType>::operator-(const SeqList<int>& p) const
{
	SeqList<int> x1;
	x1.length = length;
	for (int i = 0; i < length; i++)
		x1.data[i] = data[i];
	x1.sign = sign;
	x1 = mySub(x1, p);
	return x1;
}

template<class DataType>
SeqList<int> SeqList<DataType>::operator*(const SeqList<int>& p) const
{
	SeqList<int> x1;
	x1.length = length;
	for (int i = 0; i < length; i++)
		x1.data[i] = data[i];
	x1.sign = sign;
	x1 = myMul(x1, p);
	return x1;
}

template<class DataType>
StrofDiv SeqList<DataType>::operator/(const SeqList<int>& p) const
{
	return myDiv(*this, p);
}
