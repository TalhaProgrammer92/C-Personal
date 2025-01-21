#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char getUpperCase(){
	return static_cast<char>(rand() % 26 + 65); // 65 is ASCII for 'A'
}

char getNumber(){
	return static_cast<char>(rand() % 26 + 48); // 48 is ASCII for '0'
}

char getLowerCase(){
	return static_cast<char>(rand() % 26 + 97); // 97 is ASCII for 'a'
}

// Text class to print some text magically
class Text{
private:
	string text;
	
	string empty_string(int size){
		string empty = "";
		for(int i=0;i<size;i++)
			empty += ' ';
		return empty;
	}
public:
	Text(string text){
		srand(time(nullptr));
		this->text = text;
	}
	
	void display(bool line_break = true)
	{
		string disp_str = this->empty_string(text.length());
		
		// Display the string
		while(disp_str != text)
		{	
			// Loop each character
			for(unsigned int i=0;i<text.length();i++){
				do{
					char rand_chr;
					
					if (text[i] >= 'a' && text[i] <= 'z'){
						rand_chr = getLowerCase();
					}
					
					else if (text[i] >= 'A' && text[i] <= 'Z'){
						rand_chr = getUpperCase();
					}
					
					else if (text[i] >= '0' && text[i] <= '9'){
						rand_chr = getNumber();
					}
					
					else {
						rand_chr = text[i];
					}
					
					disp_str[i] = rand_chr;
					
					// Display
					system("cls");
					for (unsigned int j = 0; j < disp_str.length(); j++)
						cout << disp_str[j];
				}while(disp_str[i] != text[i]);
			}
		}
		
		if (line_break)
			cout << endl;
		
//		cout << disp_str << endl;
	}
};

int main()
{
	Text msg("Hello, World!");
	msg.display();
}

