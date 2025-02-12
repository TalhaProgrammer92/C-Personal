#include <iostream>
#include <fstream>

/* 
Classes for File handling:
 > fstreambase - file stream (The base class)
 > ifstream - input file stream (Derived class from fstreambase)
 > ofstream - output file stream (Another derived class from fstreambase)

Opening a file:
 > By using constructor
 > By using open() member function
*/

using namespace std;

int main()
{
	// Writing to a file
	string text = "This is a text file.\nMy name is Talha Ahmad.";
	ofstream file_o("sample.txt");		// Open the text file
	file_o << text;						// Writing the 'text' string to the file
	
	// Reading from a file
	ifstream file_i("sample.txt");		// Open the text file
	string read;						// A string variale to store data of the file
	getline(file_i, read);				// Reading from the file and store the data in 'read' variable
	cout << read << endl;				// Print the value stored in 'read'
}

