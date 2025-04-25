#include <iostream>

using namespace std;

template <class A, class B>
class Link
{
	public:
		A a;
		B b;
};

int main() {
	//! Variables
	int num = 4; char chr = 'T'; float point = 1.02; string str = "Text";

	//! Objects
	Link<int, char> l1;
	l1.a = num; l1.b = chr;

	Link<float, string> l2;
	l2.a = point; l2.b = str;

	Link<Link<int, char>, Link<float, string>> list;
	list.a = l1; list.b = l2;

	cout << "List: {";

	//! num
	cout << list.a.a << ", ";

	//! chr
	cout << list.a.b << ", ";

	//! point
	cout << list.b.a << ", ";

	//! str
	cout << list.b.b << '}' << endl;

	return 0;
}