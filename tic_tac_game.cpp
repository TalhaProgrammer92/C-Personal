#include <iostream>		// Include this for standard I/O and other functions
#include <cstring>		// Include this for getline function
#include <cctype> 		// Include this for isalpha function
#include <conio.h>		// Include this for getche function

using namespace std;

/////////////////////////////
// Functions (Prototype)
/////////////////////////////
bool isValidName(string);
bool isValidSymbol(char);
void clear();
void printChars(char, int);


/////////////////////////////
// Player (Class)
/////////////////////////////
class Player {
private:
	string name;
	char symbol;
public:
	// Setters
	void setName();
	void setSymbol();
	// Getters
	string getName();
	char getSymbol();
};


/////////////////////////////
// Board (Class)
/////////////////////////////
class Board {
private:
	char board[3][3];
public:
	void clearBoard();
	void showBoard();
	void placeSymbol(char);
	char getSymbol(int, int);
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
	char findWinner();
	void showResult(char);
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
	for (unsigned int i = 0; i < _name.length(); i++) {
		if (!isalpha(_name[i]))
			return false;
	}
	return true;
}

// Function to check whether the symbol is valid or not
bool isValidSymbol(char _symbol) {
	if (isalpha(_symbol))
		return true;
	return false;
}

// Funciton to print chars in specific range
void printChars(char character, int range) {
	for (int i = 0; i < range; i++) {
		cout << character;
	}
	cout << endl;
}

// Function to clear the screen
void clear() {
	system("cls");
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
		cout << "Enter name>> ";
		getline(cin, nm);
		valid = isValidName(nm);
		if (nm.length() > 0 && valid)
			this->name = nm;
		else
			cout << "Each letter of name must be in A-Z or a-z!" << endl;
	} while (nm.length() == 0 || !valid);
}

// Function to set valid symbol of the player
void Player::setSymbol() {
	// Variables
	char sm;
	bool valid;

	// Force the player to enter valid symbol
	do {
		cout << "Enter symbol>> ";
		sm = getche();
		valid = isValidSymbol(sm);
		if (valid)
			this->symbol = sm;
		else
			cout << "Symbol must be in A-Z or a-z!" << endl;
	} while (!valid);
}

// Function to get name of the player
string Player::getName() {
	return this->name;
}

// Function to get symbol of the player
char Player::getSymbol() {
	return this->symbol;
}

////////////////////////////////////////
// Functions (Definition) - Board
////////////////////////////////////////

// Function to clear the board
void Board::clearBoard() {
	char num = '1';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->board[i][j] = num;
			num++;
		}
	}
}

// Function to print the board
void Board::showBoard() {
	for (int i = 0; i < 3; i++) {
		// Print symbol
		for (int j = 0; j < 3; j++) {
			cout << ' ' << this->board[i][j] << ' ';
			if (j < 2)
				cout << '|';
		}
		cout << endl;

		// Print line-break
		for (int j = 0; j < 3; j++) {
			cout << "---";
			if (j < 2)
				cout << '|';
		}
		cout << endl;
	}
}

// Function to place symbol at desired location and return true if succeed
void Board::placeSymbol(char symbol) {
	int i, j, num;
	bool valid;
	// Force player to enter valid number
	do {
		// Get location
		cout << "Enter a number (1-9)>> ";
		cin >> num;

		// Caculcate coordinates
		i = (num - 1) / 3;
		j = (num - 1) % 3;

		// Check validity
		valid = !isValidSymbol(this->getSymbol(i, j));

		// Prints a warning
		if (!valid)
			cout << "Please enter valid number or make sure that the desired place is empty!\n" << num << " is incorrect." << endl;
	} while (!valid);
	this->board[i][j] = symbol;
}

// Function to get symbol from desired location
char Board::getSymbol(int i, int j) {
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
		printChars('*', 30);
		cout << "Data of Player " << i + 1 << endl;
		printChars('*', 30);

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

void Game::showResult(char symbol) {
	clear();
	this->board.showBoard();
	cout << '\n';
	if (symbol == 'D')	// Draw
		cout << "The game is draw";
	else {				// Winner
		cout << "Winner is ";

		// Decide who is winner
		(symbol == this->players[0].getSymbol()) ?
		cout << this->players[0].getName() : cout << this->players[1].getName();
	}
	cout << '!' << endl;
}

// Function to play the game
void Game::playGame() {
	// Variable
	char winner;

	// Setting up the environment
	this->setEnvironment();

	// Game-loop
	while (!this->game_over) {
		// Clear the screen
		clear();

		// Show the name of the player
		printChars('*', 20);
		cout << this->players[this->getTurn()].getName() << "'s Turn" << endl;
		printChars('*', 20);
		cout << endl;

		// Show the board
		board.showBoard();

		// Place symbol
		board.placeSymbol(this->players[this->getTurn()].getSymbol());

		// Check for a winner
		winner = this->findWinner();

		// Increment the move variable
		this->move++;

		// Check for game over
		if (winner != '~')
			this->game_over = true;
	}

	// Result
	this->showResult(winner);
}

// Function to get the winner of this game
// '!' for Draw
// '~' for niether draw nor won
// A-Z or a-z found a winner
char Game::findWinner() {
	// Variable
	char winner = '~';

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
	if (this->board.isFilled() && winner == '~')
		winner = '!';

	return winner;
}
