#include <iostream>
#include <vector>

using namespace std;


//////////////
// Position //
//////////////
class Position {
private:
	unsigned int row_position, column_position;
public:
	Position(unsigned int row, unsigned int column) {
		row_position = row;
		column_position = column;
	}

	// Getters
	unsigned int row() {
		return row_position;
	}
	unsigned int column() {
		return column_position;
	}
};


//////////
// Grid //
//////////
class Grid {
private:
	vector<vector<char>> cells;
	unsigned int size;
public:
	Grid(unsigned int size) {
		this->size = size;
		for (unsigned int i = 0; i < size; i++) {
			vector<char> row;
			for (unsigned int j = 0; j < size; j++) {
				row.push_back(' ');
			}
			cells.push_back(row);
		}
	}

	// Draw filled rectangle
	void filledRectangle(Position start, Position end, char character) {
		if (start.row() >= 0 && end.row() < size) {
			for (unsigned int i = start.row(); i <= end.row(); i++) {
				for (unsigned int j = start.column(); j <= end.column(); j++) {
					cells.at(i).at(j) = character;
				}
			}
		}
	}

	// Draw follow rectangle
	void hollowRectangle(Position start, Position end, char character) {
		if (start.row() >= 0 && end.row() < size) {
			for (unsigned int i = start.row(); i <= end.row(); i++) {
				for (unsigned int j = start.column(); j <= end.column(); j++) {
					if (i == start.row() || i == end.row()) cells.at(i).at(j) = character;
					else if (j == start.column() || j == end.column()) cells.at(i).at(j) = character;
				}
			}
		}
	}

	// Draw Line
	void line(Position start, Position end, char character) {
		if (start.row() >= 0 && end.row() < size) {
			// Vertical
			if (start.column() == end.column()) {
				// Top to Bottom
				if (start.row() < end.row()) {
					for (unsigned int i = start.row(); i <= end.row(); i++) {
						cells.at(i).at(start.column()) = character;
					}
				}
				// Bottom to Top
				else if (start.row() > end.row()) {
					for (unsigned int i = start.row(); i >= end.row(); i--) {
						cells.at(i).at(start.column()) = character;
					}
				}
			}
			// Horizontal
			else if (start.row() == end.row()) {
				// Left to Right
				if (start.column() < end.column()) {
					for (unsigned int i = start.column(); i <= end.column(); i++) {
						cells.at(start.row()).at(i) = character;
					}
				}
				// Right to Left
				else if (start.column() > end.column()) {
					for (unsigned int i = start.column(); i >= end.column(); i--) {
						cells.at(start.row()).at(i) = character;
					}
				}
			}
			// Diagonol
			else {
				// Top-Left to Bottom-Right
				if (start.column() < end.column()) {
					unsigned int i = start.row(), j = start.column();
					while (i <= end.row() && j <= end.column()) {
						cells.at(i++).at(j++) = character;
					}
				}
				// Top-Right to Bottom-Left
				else if (start.column() > end.column()) {
					unsigned int i = start.row(), j = start.column();
					while (i <= end.row() && j >= end.column()) {
						cells.at(i++).at(j--) = character;
					}
				}
			}
		}
	}
	
	// To insert a character at specific location
	void insert(Position position, char character){
		if (position.row() < size && position.column() < size)
			cells.at(position.row()).at(position.column()) = character;
	}
	
	// To insert a word
	void word(Position position, string word){
		if (position.row() < size && position.column() < size && word.length() <= size) {
			for (unsigned int i = 0; i < word.length(); i++)
				cells.at(position.row()).at(position.column() + i) = word[i];
		}
	}

	// To draw the pattern
	void draw() {
		for (unsigned int i = 0; i < size; i++) {
			vector<char> row = cells.at(i);
			for (unsigned int j = 0; j < size; j++) {
				cout << row.at(j);
			}
			cout << endl;
		}
	}
};


int main() {
	Grid pattern(16);

	pattern.hollowRectangle(Position(0, 0), Position(15, 15), '*');
	pattern.hollowRectangle(Position(2, 2), Position(13, 13), '~');

	pattern.line(Position(5, 5), Position(10, 5), '@');
	pattern.line(Position(10, 10), Position(5, 10), '$');
	pattern.line(Position(5, 6), Position(5, 9), '%');
	pattern.line(Position(10, 9), Position(10, 6), '&');
	pattern.line(Position(6, 6), Position(9, 9), '#');
	pattern.line(Position(6, 9), Position(9, 6), '?');
	
	pattern.word(Position(14, 2), "Talha Ahmad!");
	
	pattern.draw();
}
