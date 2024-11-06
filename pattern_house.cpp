#include <iostream>
#include <iomanip>

using namespace std;

// Prototype
void printRoof();
void printBody();
void printName();

int main() {
	// Printing the pattern of a house
	printRoof();
	printBody();
	printName();
}

// Definition
void printRoof(){
	// Variables
	int roof_width = 23, decrement = 5;
	string line = "";

	// Top
	for(int i=0;i<17;i++){
		line += '=';
	}
	cout << setw(roof_width) << line << endl;
	
	// Set Default
	line = "";
	roof_width++;
	
	// Body - 1st, 2nd Rows
	for(int i=0;i<2;i++){
		for(int j=0;j<roof_width - decrement;j++){
			if (j == 0)
				line += ')';
			else if (j == roof_width - (decrement + 1))
				line += '(';
			else{
				if (j % 2 == 0)
					line += ' ';
				else
					line += 'V';
			}
		}
		cout << setw(roof_width) << line << endl;
		line = "";
		roof_width++;
		decrement--;
	}
	
	// Body - 3rd Row
	for(int i=0;i<roof_width - decrement;i++){
		if (i == 0)
			line += ')';
		else if (i == roof_width - (decrement + 1))
			line += '(';
		else{
			if (i == 10)
				line += '/';
			else if (i == 11)
				line += '^';
			else if (i == 12)
				line += '\\';
			else if (i % 2 == 0)
				line += ' ';
			else
				line += 'V';
		}
	}
	cout << setw(roof_width) << line << endl;
	line = "";
	roof_width++;
	decrement--;
	
	// Body - 4th Row
	for(int i=0;i<roof_width - decrement;i++){
		if (i == 0)
			line += ')';
		else if (i == roof_width - (decrement + 1))
			line += '(';
		else{
			if (i == 9)
				line += '/';
			else if (i > 9 && i < 14){
				if (i == 12)
					line += '_';
				else
					line += ' ';
			}
			else if (i == 15)
				line += '\\';
			else if (i % 2 == 0)
				line += ' ';
			else
				line += 'V';
		}
	}
	cout << setw(roof_width) << line << endl;
	line = "";
	roof_width++;
	decrement--;
	
	// Body - 5th Row
	for(int i=0;i<roof_width - decrement;i++){
		if (i == 0)
			line += ')';
		else if (i == roof_width - (decrement + 1))
			line += '(';
		else{
			if (i == 10 || i == 12 || i == 14 || i == 16)
				line += '|';
			else if (i > 10 && i < 16){
				if (i == 13)
					line += '#';
				else
					line += ' ';
			}
			else if (i % 2 == 0)
				line += ' ';
			else
				line += 'V';
		}
	}
	cout << setw(roof_width) << line << endl;
	line = "";
	roof_width++;
	decrement--;
	
	// Body - last (6th) Row
	for(int i=0;i<roof_width - decrement;i++){
		if (i == 0)
			line += ')';
		else if (i == roof_width - (decrement + 1))
			line += '(';
		else{
			if (i == 11 || i == 17)
				line += '|';
			else if (i > 10 && i < 16){
				if (i == 14)
					line += '~';
				else
					line += ' ';
			}
			else if (i % 2 == 0)
				line += ' ';
			else
				line += 'V';
		}
	}
	cout << setw(roof_width) << line << endl;
	line = "";
	roof_width++;
	decrement--;
	
	// Bottom
	roof_width--;
	for(int i=0;i<roof_width;i++){
		line += '~';
	}
	cout << setw(roof_width) << line << endl;
}

void printBody(){
	int width = 29;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<width;j++){
			// Window
			if (i < 7 && i != 3){
				if ((j > 4 && j < 9) || (j > 19 && j < 24))
					cout << '#';
				else if (j > 11 && j < 17){
					if (i < 3)
						cout << '#';
					// Door
					else if (i > 3){
						if (j == 12 || j == 16)
							cout << 'I';
						else if (j > 12 && j < 16 && i == 4)
							cout << '~';
						else if (j == 13 && i == 6)
							cout << '\'';
						else
							cout << ' ';
					}
					// Wall
					else
						cout << ':';
				}
				// Wall
				else
					cout << ':';
			} 
			else if (i == 7){
				// Door - bottom
				if (j >= 12 && j <= 16){
					if (j == 12 || j == 16)
						cout << 'I';
					else
						cout << '_';
				}
				// Wall
				else
					cout << ':';
			}
			// Wall
			else
				cout << ':';
		}
		cout << endl;
	}
}

void printName(){
	cout << endl << setw(17) << "House" << endl;
}
