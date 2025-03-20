#include <iostream>		// For standard I/O and other functions
#include <cstring>		// For getline function
#include <cctype> 		// For isalpha function
#include <conio.h>		// For getche function
#include <limits>		// For numeric_limits function

using namespace std;

/////////////////////////////
// Functions (Prototype)
/////////////////////////////
bool isValidName(string);
bool isValidSymbol(char);
string getCharsSequence(char, int);
void clear();
void printChars(char, int);
void printColoredText(string, string, string, bool, bool, bool);


/////////////////////////////
// Player (Class)
/////////////////////////////
class Player {
private:
	string name;
	string symbol;
public:
	// Setters
	void setName();
	void setSymbol();
	// Getters
	string getName();
	string getSymbol();
};


/////////////////////////////
// Board (Class)
/////////////////////////////
class Board {
private:
	string board[3][3];
	int getValidLocation();
public:
	void clearBoard();
	void showBoard();
	void placeSymbol(string);
	string getSymbol(int, int);
	bool isFilled();
};


/////////////////////////////
// Game (Class)
/////////////////////////////
class Game {
private:
	Board board;
	Player players[2];
	int move;
	bool game_over;

	void setEnvironment();
	int getTurn();
	string findWinner();
	void showResult(string);
public:
	void playGame();
};


/////////////////////////////
// Function (Main Code)
/////////////////////////////
int main() {
	// Game Object
	Game tic_tac;

	// Play the game
	tic_tac.playGame();
}


/////////////////////////////
// Functions (Definition)
/////////////////////////////

// Function to check whether the name is valid or not
bool isValidName(string _name) {
	int countWhitespace = 0;
	for (unsigned int i = 0; i < _name.length(); i++) {
		if (countWhitespace == 0 && _name[i] == ' ')
			countWhitespace++;
		else if (!isalpha(_name[i]))
			return false;
	}
	return true;
}

// Function to check whether the symbol is valid or not
bool isValidSymbol(string _symbol) {
	if (isalpha(_symbol[0]) && _symbol.length() == 1)
		return true;
	return false;
}

// Funciton to print chars in specific range
string getCharsSequence(char character, int range) {
	string seq = "";
	for (int i = 0; i < range; i++) {
		seq += character;
	}
	return seq;
}

// Function to clear the screen
void clear() {
	#ifdef _WIN32
        	system("cls");
    	#else
        	system("clear");
    	#endif
}

// Function to print heading
void printHeading(string title, int line_size)
{
	string stars = getCharsSequence('*', line_size);
	printColoredText(stars, "34", "40", false, false, false);
	cout << endl;
	printColoredText(title, "32", "40", true, false, false);
	cout << endl;
	printColoredText(stars, "34", "40", false, false, false);
	cout << "\n\n";
}

// Function to display colored output
void printColoredText(string text, string fg_color, string bg_color, bool bold, bool italic, bool underline) {
/*

	Foreground Colors:
	
	30: Black
	31: Red
	32: Green
	33: Yellow
	34: Blue
	35: Magenta
	36: Cyan
	37: White
	
	Background Colors:
	
	40: Black
	41: Red
	42: Green
	43: Yellow
	44: Blue
	45: Magenta
	46: Cyan
	47: White
	
*/
	string color_code = "\033[";
	if (bold) color_code += "1;";
	if (italic) color_code += "3;";
	if (underline) color_code += "4;";
	color_code += fg_color + ";" + bg_color + "m";
	cout << color_code << text << "\033[0m";
	// Example: printColoredText("This text is red and bold.", "31", "40", true, false, false);
}


////////////////////////////////////////
// Functions (Definition) - Player
////////////////////////////////////////

// Function to set valid name of the player
void Player::setName() {
	// Variables
	string nm;
	bool valid;

	// Force the player to enter valid name
	do {
		printColoredText("Enter name>> ", "36", "40", false, false, false);
		getline(cin, nm);
		valid = isValidName(nm);
		if (nm.length() > 0 && valid)
			this->name = nm;
		else
			printColoredText("Each letter of a name must be in A-Z or a-z, and multiple consecutive whitespaces are not acceptable!\n", "31", "40", false, true, true);
	} while (nm.length() == 0 || !valid);
}

// Function to set valid symbol of the player
void Player::setSymbol() {
	// Variables
	string sm;
	bool valid;

	// Force the player to enter valid symbol
	do {
		printColoredText("Enter symbol>> ", "36", "40", false, false, false);
		getline(cin, sm);
		valid = isValidSymbol(sm);
		if (valid)
			this->symbol = sm;
		else
			printColoredText("Symbol must be in A-Z or a-z!\n", "31", "40", false, true, true);
	} while (!valid);
}

// Function to get name of the player
string Player::getName() {
	return this->name;
}

// Function to get symbol of the player
string Player::getSymbol() {
	return this->symbol;
}

////////////////////////////////////////
// Functions (Definition) - Board
////////////////////////////////////////

// Function to get a valid location to place a symbol
int Board::getValidLocation(){
	int number;
	while(true){
		printColoredText("Enter the location (1-9)>> ", "36", "40", false, false, false);
		cin >> number;
		
		// Error case
		if (cin.fail()){
			cin.clear();	// Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Discard the invalid input
		}
		// Check if the number is in range or not
		else if (number > 0 && number <= 9) {
			break;
		}
	}
	return number;
}

// Function to clear the board
void Board::clearBoard() {
	string num = "1";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->board[i][j] = num;
			num[0]++;
		}
	}
}

// Function to print the board
void Board::showBoard() {
	for (int i = 0; i < 3; i++) {
		// Print symbol
		for (int j = 0; j < 3; j++) {
			printColoredText(" " + this->board[i][j] + " ", "34", "40", true, false, false); 
			if (j < 2)
				printColoredText("|", "33", "40", true, false, false);
		}
		cout << endl;

		// Print line-break
		for (int j = 0; j < 3; j++) {
			printColoredText("---", "33", "40", true, false, false);
			if (j < 2)
				printColoredText("|", "33", "40", true, false, false);
		}
		cout << endl;
	}
}

// Function to place symbol at desired location and return true if succeed
void Board::placeSymbol(string symbol) {
	int i, j, num;
	bool is_empty;
	// Force player to enter valid number
	do {
		// Get Location
		num = this->getValidLocation();

		// Caculcate coordinates
		i = (num - 1) / 3;
		j = (num - 1) % 3;

		// Check validity
		is_empty = !isValidSymbol(this->getSymbol(i, j));

		// Prints a warning
		if (!is_empty){
			string msg = "Please make sure that the desired place is empty!\nThe board at " + to_string(i) + ", " + to_string(j) + " already contain " + "\"" + this->getSymbol(i, j) + "\"";
			printColoredText(msg, "31", "40", false, true, false);
		}
	} while (!is_empty);
	this->board[i][j] = symbol;
}

// Function to get symbol from desired location
string Board::getSymbol(int i, int j) {
	return this->board[i][j];
}

// Function to check whether the board is totally filled or not
bool Board::isFilled() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!isValidSymbol(this->getSymbol(i, j)))
				return false;
		}
	}
	return true;
}

////////////////////////////////////////
// Functions (Definition) - Game
////////////////////////////////////////

// Function to set environment for the game
void Game::setEnvironment() {
	// Getting players information
	for (int i = 0; i < 2; i++) {
		// Message
		printHeading("Data of Player " + to_string(i+1), 30);

		// Get data
		players[i].setName();
		players[i].setSymbol();
		cout << "\n\n";
	}
	this->move = 0;
	this->game_over = false;
	this->board.clearBoard();
}

// Function to get the turn of a player
int Game::getTurn() {
	return this->move % 2;
}

void Game::showResult(string symbol) {
	clear();
	string msg;
	printHeading("Result", 35);
	this->board.showBoard();
	cout << '\n';
	if (symbol == "~")	// Draw
		msg = "It is a Tie";
	else {				// Winner
		msg = "Winner is ";

		// Decide who is winner
		(symbol == this->players[0].getSymbol()) ?
		msg += this->players[0].getName() : msg += this->players[1].getName();
	}
	msg += "!";
	printColoredText(msg, "35", "40", true, true, false);
}

// Function to play the game
void Game::playGame() {
	// Variable
	string winner;

	// Setting up the environment
	this->setEnvironment();

	// Game-loop
	while (!this->game_over) {
		// Clear the screen
		clear();

		// Show the name of the player
		printHeading(this->players[this->getTurn()].getName() + "'s Turn", 35);

		// Show the board
		board.showBoard();

		// Place symbol
		board.placeSymbol(this->players[this->getTurn()].getSymbol());

		// Check for a winner
		winner = this->findWinner();

		// Increment the move variable
		this->move++;

		// Check for game over
		if (winner != "~")
			this->game_over = true;
	}

	// Result
	this->showResult(winner);
}

// Function to get the winner of this game
// '!' for Draw
// '~' for niether draw nor won
// A-Z or a-z found a winner
string Game::findWinner() {
	// Variable
	string winner = "~";

	// Row & Column
	for (int i = 0; i < 3; i++) {
		if (isValidSymbol(this->board.getSymbol(i, 0)) || isValidSymbol(this->board.getSymbol(0, i))) {
			if (this->board.getSymbol(i, 0) == this->board.getSymbol(i, 1) && this->board.getSymbol(i, 1) == this->board.getSymbol(i, 2))
				winner = this->board.getSymbol(i, 1);
			else if (this->board.getSymbol(0, i) == this->board.getSymbol(1, i) && this->board.getSymbol(1, i) == this->board.getSymbol(2, i))
				winner = this->board.getSymbol(1, i);
		}
	}

	// Diagonal
	if (isValidSymbol(this->board.getSymbol(1, 1))) {
		if (this->board.getSymbol(0, 0) == this->board.getSymbol(1, 1) && this->board.getSymbol(1, 1) == this->board.getSymbol(2, 2))
			winner = this->board.getSymbol(1, 1);
		else if (this->board.getSymbol(0, 2) == this->board.getSymbol(1, 1) && this->board.getSymbol(1, 1) == this->board.getSymbol(2, 0))
			winner = this->board.getSymbol(1, 1);
	}

	// Draw
	if (this->board.isFilled() && winner == "~")
		winner = "!";

	return winner;
}
