#include <iostream>

using namespace std;

string sequence(int n);
string pattern(int size);

int main() {
	const int size = 7;		//! Changeable
	cout << pattern(size) << endl;
	return 0;
}

string sequence(int n)
{
	if (n == 1) return "*";
	return "*" + sequence(n - 1);
}

string pattern(int size)
{
	if (size == 1) return sequence(1);
	return sequence(size) + "\n" + pattern(size - 1);
}