#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;

/////////////////////
//? Symbol Class
/////////////////////
class Symbol
{
private:
    //* Attributes
    char symbol;
    int color;

public:
    //* Consturctors
    Symbol() {}
    Symbol(char symbol, int color) : symbol(symbol), color(color) {}

    //* Getters
    char get_symbol()
    {
        return symbol;
    }

    int get_color()
    {
        return color;
    }
};

//* Function - Set Color
void setColor(int color);

//* Function - Clear Screen
void clrscr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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

    //* Method - Average
    int get_center()
    {
        return (row + column) / 2;
    }

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
    char direction;
    int score, length;
    Symbol symbol;
    Position current_position;
    vector<Position> positions;

    //* Method - Take input for movement
    void take_movement_input()
    {
        if (kbhit())
        {
            char input = tolower(getch());

            switch (input)
            {
            //! Upward
            case 'w':
                if (direction != 's')
                    direction = input;
                break;

            //! Downward
            case 's':
                if (direction != 'w')
                    direction = input;
                break;

            //! Left
            case 'a':
                if (direction != 'd')
                    direction = input;
                break;

            //! Right
            case 'd':
                if (direction != 'a')
                    direction = input;
                break;
            }
        }
    }

    //* Method - Switch snake's direction
    void switch_direction()
    {
        switch (direction)
        {
        //! Upward
            case 'w':
                current_position.row--;
                break;

            //! Downward
            case 's':
                current_position.row++;
                break;

            //! Left
            case 'a':
                current_position.column--;
                break;

            //! Right
            case 'd':
                current_position.column++;
                break;
        }
    }

public:
    //* Constructor
    Snake(Symbol symbol)
    {
        this->symbol = symbol;
        score = 0;
        length = 3;
        current_position = Position(5, 5);
        direction = 'd'; //? w-Up, a-Left, d-Right, s-Down
    }

    //* Getters
    Position get_position()
    {
        return current_position;
    }

    char get_direction()
    {
        return direction;
    }

    Symbol get_symbol()
    {
        return symbol;
    }

    int get_score()
    {
        return score;
    }

    //* Method - Handle movement based on its direction
    void handle_movement()
    {
        //! Take Input
        take_movement_input();
        
        //! Switch Direction
        switch_direction();
    }

    //* Meethod - Grow Snake
    void grow(Food &food)
    {
        if (food.get_position() == current_position)
        {
            food.is_spawned = false;
            length++;
        }
    }

    //* Method - Remove Tail
    void remove_tail();

    //* Method - Store Position
    void store_position();

    //* Method - Wrap Indices (Ensure snake stays within bounds)
    void wrap_indices();
};

///////////////////
//? Food Class
///////////////////
class Food
{
private:
    //* Attributes
    Position position;
    Symbol symbol;

public:
    bool is_spawned;

    //* Constructor
    Food(Symbol symbol)
    {
        this->symbol = symbol;
        is_spawned = false;
    }

    //* Getters
    Position get_position()
    {
        return position;
    }

    //* Method - Spawn randomly inside given space
    void spawn(Grid &grid)
    {
        if (!is_spawned)
        {
            do
            {
                //! Get random position of the food
                position.row = rand() % grid.get_size().get_center();
                position.column = rand() % grid.get_size().get_center();

            } while (grid.get_symbol(position).get_symbol() != grid.get_symbol().get_symbol());
            
            grid.set_symbol(position, symbol);
            is_spawned = true;
        }
    }
};

///////////////////
//? Grid Class
///////////////////
class Grid
{
private:
    //* Attributes
    Position size;
    Symbol symbol;
    vector<vector<Symbol>> grid;

public:
    //* Constructor
    Grid(Position size, Symbol symbol) : size(size), symbol(symbol)
    {
        //! Fill the grid with symbol
        for (int i = 0; i < size.row; i++)
        {
            vector<Symbol> row;

            for (int j = 0; j < size.column; j++)
            {
                row.push_back(symbol);
            }

            grid.push_back(row);
        }
    }

    //* Getters
    Position get_size()
    {
        return size;
    }

    Symbol get_symbol()
    {
        return symbol;
    }

    Symbol get_symbol(Position position)
    {
        return grid[position.row][position.column];
    }

    //* Setter
    void set_symbol(Position position, Symbol symbol)
    {
        grid[position.row][position.column] = symbol;
    }

    //* Method - Initialize / Fill
    void initialize();

    //* Method - Display grid
    void display();
};

///////////////////
//? Game Class
///////////////////
class Game
{
private:
    //* Attributes
    Snake *snake;
    Food *food;
    Grid *grid;
    bool game_over;
    int speed;

    //* Method - Game Loop
    void game_loop()
    {
        do
        {
            //! Clear screen
            clrscr();

            //! Store position of the snake
            snake->store_position();

            //! Handle snake's movement
            snake->handle_movement();

            //! Wrap indices to prevent unbound
            snake->wrap_indices();

            //! Check for game over
            check_game_over();

            //! Grow the snake
            snake->grow(*food);

            //! Spawn food
            food->spawn(*grid);

            //! Set grid's symbol i.e. Snake
            grid->set_symbol(snake->get_position(), snake->get_symbol());

            //! Move the snake
            snake->remove_tail();

            //! Clear Screen
            clrscr();

            //! Display game grid
            grid->display();

            Sleep(speed);
        } while (snake->get_direction() != '0');
    }

    //* Method - Check gameover
    void check_game_over()
    {
        if (grid->get_symbol(snake->get_position()).get_symbol() == snake->get_symbol().get_symbol())
        {
            //! Display message with score
            cout << "Game Over! Final Score: " << snake->get_score() << endl;
            Sleep(speed * 2);

            //! Restart the game
            play();
        }
    }

public:
    //* Constructor
    Game(Snake &snake, Food &food, Grid &grid)
    {
        this->snake = &snake;
        this->food = &food;
        this->grid = &grid;
        game_over = false;
        speed = 300;
    }

    //* Method - Start Game
    void play()
    {
        //! Initialize the grid
        grid->initialize();

        //! Game loop
        game_loop();
    }
};

//* Function - Entry Point
int main()
{
    //! Game Objects
    Snake snake(Symbol('O', 10));
    Food food(Symbol('*', 12));
    Grid grid(Position(15, 15), Symbol('-', 15));

    //! Game
    Game game(snake, food, grid);
    game.play();
}
