//实验十一:2019-06-17
//给定数据文件:数据结构与算法实验学生名单.xls, 利用排序算法，实现对各字段分别排序。
//最后修改:2019-06-19
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "course.h"
using namespace std;
//const int MAX = 100;	//max num of student

int cmp_id(student a, student b)
{
	if (a.id > b.id)
		return 1;
	else if (a.id == b.id)
		return 0;
	else
		return -1;
}

int cmp_name(student a, student b)
{
	if (a.name > b.name)
		return 1;
	else if (a.name == b.name)
		return 0;
	else
		return -1;
}

int cmp_gender(student a, student b)
{
	if (a.gender > b.gender)
		return 1;
	else if (a.gender == b.gender)
		return 0;
	else
		return -1;
}

int cmp_school(student a, student b)
{
	if (a.school > b.school)
		return 1;
	else if (a.school == b.school)
		return 0;
	else
		return -1;
}

int cmp_class_(student a, student b)
{
	if (a.class_ > b.class_)
		return 1;
	else if (a.class_ == b.class_)
		return 0;
	else
		return -1;
}

int cmp_grade_department(student a, student b)
{
	if (a.grade_department > b.grade_department)
		return 1;
	else if (a.grade_department == b.grade_department)
		return 0;
	else
		return -1;
}

bool cmp_test(student a, student b)
{
	if (a.school > b.school)
		return 1;
	else
		return 0;
}

int main()
{
	string filename;
	filename = "datastu";	//change filename
	filename += ".txt";		//change type of file
	ifstream fin(filename);

	course DataStr;
	student inputstu;
	if (fin.is_open())
	{
		string type;
		int ordernum;
		getline(fin, type);
//		int count = 0;
//		while (!fin.fail()&&count<10) //for test
		while (!fin.fail())
		{
//			count++;
			fin >> ordernum;
			fin >> inputstu.id >> inputstu.name >> inputstu.gender
				>> inputstu.school >> inputstu.grade_department >> inputstu.class_;
			DataStr.Insert(inputstu);
// 			cout << inputstu.id<<"  " << inputstu.name<<"  " << inputstu.gender<<"  "
// 				<< inputstu.school << inputstu.grade_department<<"*" << inputstu.class_ <<"*"<< endl;
		}
		cout << "数据录入成功\n";
	}
	cout << "原始数据:\n";
	DataStr.Printcourse();

	CompareFunction<student> cmp[9];
	cmp[5] = cmp_id; cmp[1] = cmp_name; cmp[2] = cmp_gender; 
	cmp[8] = cmp_grade_department; cmp[0] = cmp_school; cmp[4] = cmp_class_;

	while (true)
	{
		cout << "输入排序字段: 学号 姓名 性别 院系 年级专业 班级； 或输入 退出\n";
//		cout << "排序字段:";
		string aim;
		cin >> aim;
		int choose = (-(int)aim.at(1)) % 14;
		if (choose == 11)
			break;
// 		else if (choose < 0 || choose>8 )
// 			choose = 5;
//		cout <<(int)aim.at(1) <<" "<<choose;
		//sort
		clock_t start = clock();
		QuickSort<student>(DataStr.getStuData(),DataStr.getNum(),cmp[4]);
		cout << clock() - start << endl;
//		InsertSort<student>(DataStr.getStuData(),DataStr.getNum(),cmp[choose]);
		
		start = clock();
		InsertSort<student>(DataStr.getStuData(),DataStr.getNum(),cmp[1]);
		cout << clock() - start << endl;

		start = clock();
//		sort(DataStr.getStuData() + 1, DataStr.getStuData() + DataStr.getNum() + 1, cmp_test);
		stable_sort(DataStr.getStuData() + 1, DataStr.getStuData() + DataStr.getNum() + 1, cmp_test);
		cout << clock() - start << endl;

//		DataStr.Printcourse();
	}
	cout << "成功退出!\n";
	system("pause");
	return 0;
}
