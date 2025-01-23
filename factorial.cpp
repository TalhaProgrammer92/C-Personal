#include<iostream>
using namespace std;
int main()
{
	double num, fact = 1;
	cout << "Enter number>> ";
	cin >> num;
	for (int n = 1; n <= num; n++)
		fact *= n;
	cout << "Factorial>> " << fact << endl;	
	return 0;
}
