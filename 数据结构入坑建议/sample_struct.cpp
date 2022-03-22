#include<iostream>
using namespace std;

struct student
{
    int id = 0;
    string name;
};

struct group
{
    student people[3];
    string groupname;
};

int main()
{
    student A;
    A.id = 65535;
    A.name = "Tony";
    student B;
    cout << A.name << " " << B.id << endl;
    return 0;
}