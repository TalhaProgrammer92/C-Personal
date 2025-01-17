#include <iostream>

using namespace std;

class Student{
public:
	string name;
	int roll;
	float cgpa;
	
	// Overloaded << operator for custom output
	friend ostream& operator<<(ostream& os, const Student& obj) {
		return os << "Name:\t" << obj.name << '\n' << "Roll:\t" << obj.roll << '\n' << "CGPA:\t" << obj.cgpa;
	}
	
	// Overloaded >> operator for input
	friend istream& operator>>(istream& is, Student& obj) {
		cout << "Enter Name>> ";
		getline(is, obj.name); // Read the full name (including spaces)
		cout << "Enter Roll>> ";
		is >> obj.roll;
		is.ignore(); // Ignore the newline character left by previous input
		cout << "Enter CGPA>> ";
		is >> obj.cgpa; 
		return is;
	}
};

int main()
{
	Student s;
	
	cout << "**** Student Data ****" << endl;
	cin >> s;
	cout << s << endl;
}

