#include <iostream>

using namespace std;

template <class A, class B>
class Link
{
public:
	A a;
	B b;
};

int num;
char chr;
float point;
string str;

class Program
{
private:
	Link<int, char> l1;
	Link<float, string> l2;
	Link<Link<int, char>, Link<float, string>> list;

public:
	Program(int n, char c, float p, string s)
	{
		num = n;
		chr = c;
		point = p;
		str = s;

		l1.a = num;
		l1.b = chr;
		l2.a = point;
		l2.b = str;

		list.a = l1;
		list.b = l2;
	}

	void printValue(int index)
	{
		switch (index)
		{
		case 0:
			cout << list.a.a;
			break;
		case 1:
			cout << list.a.b;
			break;
		case 2:
			cout << list.b.a;
			break;
		case 3:
			cout << list.b.b;
			break;
		}
	}

	void printList()
	{
		cout << "List: {";
		for (int i = 0; i < 4; i++)
		{
			printValue(i);

			if (i < 3)
				cout << ", ";
		}
		cout << '}' << endl;
	}
};

int main()
{
	Program p(4, 'C', 1.2, "String");

	p.printList();

	return 0;
}
