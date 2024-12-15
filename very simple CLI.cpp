#include <iostream>
#include <cstring>

using namespace std;

string to_lower(string);

int main()
{
	string command;
	
	system("title Talha CLI v1.0");
	system("color 02");
	
	while(true){
		cout << "> ";
		getline(cin, command);
		if (to_lower(command) == "exit")
			break;
		system(command.c_str());
	}
	
	exit(0);
}

string to_lower(string statement)
{
	string lower = "";
	for (char& c : statement) {
		lower += tolower(c);
	}
	return lower;
}
