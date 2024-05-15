#include<iostream>

/*
--------------------------------------------------
Ludo Cono - All rights are reserved - (c)
--------------------------------------------------
Created By:		Talha Ahmad
Technology:		C++
Type:			Board-Console
--------------------------------------------------
Intro:
This game is very similar to ludo and this game has
four players. Each player is playable by human and
it has to reach the goal of 56. It has also safe
zones at 8,13,21,26,34,39,47 and you can also kill
others coin for 5 pts, just for fun.
--------------------------------------------------
*/

using namespace std;

class player{
	public:
		// Properties
		int goal, current, pts;
		bool safe, won, playable;
		// Constructor
		void init(void)
		{
			this->pts = 0;
			this->goal = 56;
			this->current = -1;
			this->safe = false;
			this->playable = false;
			this->won = false;
		}
		// Functions declaration
		void move(int);
};

void player :: move(int dice)
{
	// As coin starts at 6
	if (dice == 6 && !this->playable)
	{
		this->playable = true; // Permission to get in the line
		this->current++; // Get in the line
	}
	// Normal
	if (this->playable)
	{
		int temp = dice + this->current; // check
		if (temp < this->goal) // Before won
		{
			this->current += dice;
			// Safe-zones: 8,13,21,26,34,39,47
			if (temp == 8 || temp == 13 || temp == 21 || temp == 26 || temp == 34 || temp == 39 || temp == 47)
				this->safe = true;
			else
				this->safe = false;
		}
		else if (temp == this->goal) // After won
			this->won = true;
	}
}

// Functions for the main function
//void menu(player* group[])
//{
//	// Attributes
//	for (int i = 0; i < 4; i++)
//	{
//		cout << "Coin-" << i+1 << "\t";
//	}
//	// current
//	for (int i = 0; i < 4; i++)
//	{
//		cout << group[i].current << "\t";
//	}
//	// Playable
//	for (int i = 0; i < 4; i++)
//	{
//		cout << "P-" << group[i].playable << "\t";
//	}
//	// Safe-zones
//	for (int i = 0; i < 4; i++)
//	{
//		cout << "s-" << group[i].safe << "\t";
//	}
//}

// Main function
int main()
{
	// Variables
	string turn[4] = {"Red", "Green", "Yellow", "BLue"};
	// Objects
	player red[4], green[4], blue[4], yellow[4];
	// Cunstruct properties
	red[4].init();
	green[4].init();
	blue[4].init();
	yellow[4].init();

//	cout << red[1].goal << endl;

	return 0;
}
