//程序说明：2019-03-18
//约瑟夫环
//最后修改：2019-03-31
#include<iostream> 
using namespace std;

//additional function for checking input
void testF_input(int i)
{
	if (i <= 0)
		throw '0';
}

//additional function for checking input
void testF_input2()
{
	if (cin.get() == '.')
		throw 1;
}

//additional function for checking input
int checkinput()
{
	// have failbit cause an exception to be thrown 
	cin.exceptions(ios_base::failbit);
	int input;
	try
	{
		cin >> input;
		testF_input(input);
		testF_input2();
	}
	catch (ios_base::failure &bf)
	{// input contains char
		cout << bf.what() << endl; //throw
		cout << "Illegal Parameter! Need Numbers!\n";
//		cout << "Error!\n";
		return 0;
	}
	catch (char)
	{// Input lower than 1
		cout << "Trigger an exception! Input lower than 1!\n";
//		cout << "Error!\n";
		return 0;
	}
	catch (int)
	{// input decimal
		cout << "Illegal Parameter! Need Integer!\n";
//		cout << "Error!\n";
		return 0;
	}
	return input;
}

//以下是作业内容，上面的可以不用看
struct Node 
{
	int number;
	Node *next;
};

class josephus_ring 
{
public:
	josephus_ring() { m = 0; n = 0; first = NULL; }
	bool create();
	void show();

private:
	int n;
	int m;
	Node *first;
};

bool josephus_ring::create() 
{
	cout << "请按照提示输入总人数n和抽签序号m；\n";
	cout << "n=";
//	cin >> n;
	n = checkinput();
	if (n == 0)
	{
		cout << "重新开始！\n";
		//clear failbit 
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return false;
	}
	cout << "m=";
//	cin >> m;
	m = checkinput();
	if ( m == 0)
	{
		cout << "重新开始！\n";
		//clear failbit 
		cin.clear();
		while (cin.get() != '\n')
			continue;
		return false;
	}

	//事实上从这里开始看就行了

	Node *p1, *p2;
	p2 = nullptr; // if delete this : error C4703  For Dev delete this line!
	for (int i = 1; i <= n; i++) 
	{
		p1 = new Node;
		p1->number = i;

		if (i == 1) 
		{
			first = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;         
			p2 = p2->next;
		}
	}
	p2->next = first;          //circular linked list 
	return true;
}

void josephus_ring::show() 
{
	cout << "出圈顺序为：";
	if (m == 1) 
	{
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << endl;
		return;
	}
	Node *p1, *p2, *p;
	p1 = first;
	p2 = nullptr; // if delete this : error C4703  For Dev delete this line!
	for (int i = 1; i <= n; i++) 
	{
		int count = 1;
		while (count++ < m) 
		{
			p2 = p1;
			p1 = p1->next;
		}

		cout << p1->number << " ";
		p = p1;
		p2->next = p1->next;
		p1 = p1->next;
		delete p;
	}
	cout << endl;
}

int main() 
{
	while (true)
	{
		josephus_ring j;
		if(j.create()==true)
			j.show();
		cout << "输入‘*’退出, 输入‘+’继续 \n";
		char i;
		cin >> i;
		if (i == '*')
			break;
	}
	system("pause");
	return 0;
}
