//sort with user-define type
//qsort(type A[], int num, CompareFunction)
//
//2019-06-18
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
using CompareFunction= int (*)(T, T);
//return 1:> 0:= -1:<

template<class T>
void qsort(T s[], int l, int r, CompareFunction<T> cmp)
{
	if(l < r) 
	{
		int i = l, j = r;
		T x = s[l];
		while (i < j)
		{
			while (i < j && cmp(x, s[j])!=1) //s[j] >= x 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && cmp(x, s[i])==1) //s[i] < x 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		qsort(s, l, i - 1, cmp); // 递归调用  
		qsort(s, i + 1, r, cmp);
	}
}

template<class T>
void QuickSort(T A[], int n, CompareFunction<T> cmp)
{
	qsort(A, 1, n, cmp);
}

template<class T>
void InsertSort(T arr[], int n, CompareFunction<T> cmp)
{//sort from arr[1] to arr[n]
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (cmp(arr[j], arr[j - 1]) == -1) //arr[j] < arr[j - 1]
			{
				T temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}