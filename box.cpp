#include<iostream>
using namespace std;
int main()
{
	// Variables
	int width, height;
	// Get data
	cout << "Enter width height of the box>> ";
	cin >> width >> height;
	//Procceed
	for (int c = 1; c <= width; c++)
	{
		for (int r = 1; r <= height; r++)
		{
			if (r > 1 && r < width)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
	// End
	return 0;
}
