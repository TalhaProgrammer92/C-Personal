#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;

///////////////////////
//? Position Class
///////////////////////
class Position
{
public:
    //* Attributes
    int row, column;

    //* Constructor
    Position() {}                                               //! Default
    Position(int row, int column) : row(row), column(column) {} //! Parameterized

    //* Operator == overloaded
    bool operator==(const Position &other) const
    {
        return row == other.row && column == other.column;
    }
};

//* Function - Get random position
Position get_random_position(Position &space);

////////////////////
//? Snake Class
////////////////////
class Snake
{
private:
    //* Attributes
    char body, direction;
    int score, length, color;
    Position current_position;
    vector<Position> positions;

public:
    //* Constructor
    Snake(char body)
    {
        this->body = body;
        score = 0;
        length = 3;
        current_position = Position(5, 5);
        direction = 'd'; //? w-Up, a-Left, d-Right, s-Down
        color = 15;      //! White
    }

    //* Getters
    Position get_position()
    {
        return current_position;
    }

    //* Method - Handle movement based on its direction
    void handle_movement();

    //* Meethod - Grow Snake
    void grow();

    //* Method - Remove Tail
    void remove_tail();
};

///////////////////
//? Food Class
///////////////////
class Food
{
private:
    //* Attributes
    char symbol;
    Position position;
    bool is_spawned;
    int color;

public:
    //* Constructor
    Food(char symbol)
    {
        this->symbol = symbol;
        is_spawned = false;
        color = 12; //! Red
    }

    //* Getters
    Position get_position()
    {
        return position;
    }

    //* Method - Spawn randomly inside given space
    void spawn(Position &space);
};

///////////////////
//? Grid Class
///////////////////
class Grid
{
private:
    //* Attributes
    Position size;
    char bg;
    int color;

public:
    //* Constructor
    Grid(Position size, char bg) : size(size), bg(bg), color(10 /* Green */) {}

    //* Method - Display grid
    void display_grid();
};

//* Function - Entry Point
int main()
{
}