#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


//////////////////
////// ANSI //////
//////////////////
enum class ForegroundColor {
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White,
	Reset
};

enum class BackgroundColor {
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White,
	Reset
};

enum class Style {
	Bold,
	Dim,
	Underline,
	Blink,
	Reverse,
	Hidden,
	Strikethrough,
	Reset
};

// Function to get ANSI escape code for foreground color
string getForegroundColor(ForegroundColor color) {
	switch (color) {
		case ForegroundColor::Black:     return "\033[30m";
		case ForegroundColor::Red:       return "\033[31m";
		case ForegroundColor::Green:     return "\033[32m";
		case ForegroundColor::Yellow:    return "\033[33m";
		case ForegroundColor::Blue:      return "\033[34m";
		case ForegroundColor::Magenta:   return "\033[35m";
		case ForegroundColor::Cyan:      return "\033[36m";
		case ForegroundColor::White:     return "\033[37m";
		case ForegroundColor::Reset:     return "\033[39m"; 
	}
	return "";
}

// Function to get ANSI escape code for background color
string getBackgroundColor(BackgroundColor color) {
	switch (color) {
		case BackgroundColor::Black:     return "\033[40m";
		case BackgroundColor::Red:       return "\033[41m";
		case BackgroundColor::Green:     return "\033[42m";
		case BackgroundColor::Yellow:    return "\033[43m";
		case BackgroundColor::Blue:      return "\033[44m";
		case BackgroundColor::Magenta:   return "\033[45m";
		case BackgroundColor::Cyan:      return "\033[46m";
		case BackgroundColor::White:     return "\033[47m";
		case BackgroundColor::Reset:     return "\033[49m"; 
	}
	return "";
}

// Function to get ANSI escape code for style
string getStyle(Style style) {
	switch (style) {
		case Style::Bold:          return "\033[1m";
		case Style::Dim:           return "\033[2m";
		case Style::Underline:     return "\033[4m";
		case Style::Blink:         return "\033[5m";
		case Style::Reverse:       return "\033[7m";
		case Style::Hidden:        return "\033[8m";
		case Style::Strikethrough: return "\033[9m";
		case Style::Reset:         return "\033[0m"; 
	}
	return "";
}


//////////////////
/// Decoration ///
//////////////////
class Decoration{
private:
	string foreground, background;
	vector<string> styles;
public:
	// Setters
	void setForeground(ForegroundColor color){
		foreground = getForegroundColor(color);
	}
	void setBackground(BackgroundColor color){
		background = getBackgroundColor(color);
	}
	void addStyle(Style style){
		styles.push_back(getStyle(style));
	}
	
	// Clear style
	void clearStyle(){
		styles.clear();
	}
	
	// Get Code
	string getCode(){
		string code = "";
		
		if (foreground.length() > 0) code += foreground;
		if (background.length() > 0) code += background;
		if(styles.size() > 0) 
			for (unsigned int i = 0; i < styles.size(); i++) 
				code += styles.at(i);
		
		return code;
	}
};



int main()
{
	Decoration decor;
	decor.setForeground(ForegroundColor::Blue);
	decor.setBackground(BackgroundColor::Green);
	decor.addStyle(Style::Bold);
	decor.addStyle(Style::Underline);
	cout << "\033[31mHello, World!" << endl;
}
