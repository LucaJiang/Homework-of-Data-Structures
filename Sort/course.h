#pragma once
//struct student 
//class course
#include <string>
#include <iomanip>
#include "sort_cmp.h"
using namespace std;
const int MAX = 100;	//max num of student
struct student
{
	int id;				//student id
	string name;
	string school;
	string grade_department;
	string class_;
	string gender;		//0: male 1: female
};

class course
{
public:
	course() :Num_Student(0) {};
	void Insert(student a) { classmate[++Num_Student] = a; }
	void Printcourse();
	int getNum() { return Num_Student; }
	student* getStuData() { return classmate; }
private:
	student classmate[MAX];
	int Num_Student; 
};

void course::Printcourse()
{
	cout << "\ntotal number: " << Num_Student << endl;
	cout << "学号" << "\t\t" << "姓名" << "\t" << "性别" << "\t"
		<< "院系" << "\t\t" << "年级专业" << "\t\t" << "班级" << endl;
	for (int i = 1; i <= Num_Student; i++)
	{
		cout << classmate[i].id << "\t" << classmate[i].name << "\t" << classmate[i].gender;
//		printf("%15.15s", classmate[i].school);
		cout << "\t" << classmate[i].school;
		cout<<"\t" <<classmate[i].grade_department << "\t" << classmate[i].class_ << endl;
	}
	cout << "end\n\n";
}
