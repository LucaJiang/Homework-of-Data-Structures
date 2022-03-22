//动态存储分配
#include <iostream>
using namespace std;

int main()
{
    //! new
    // case 1
    int *a;
    a = new int;
    *a = 1;
    // case 2
    int *b = new int;
    *b = 1;
    // case 3
    int *c = new int(1);

    //! delete
    delete a, b, c;

    return 0;
}

//! 异常捕获
double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int f1()
{
    int z, x, y;
    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    
}