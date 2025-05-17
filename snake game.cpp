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
    char get_symbol() const
    {
        return symbol;
    }

    int get_color() const
    {
        return color;
    }

    //* Operator == overloaded
    bool operator==(const Symbol &other) const
    {
        return symbol == other.get_symbol();
    }

    //* Operator != overloaded
    bool operator!=(const Symbol &other) const
    {
        return symbol != other.get_symbol();
    }
};

//* Function - Set Color
void setColor(int color)
{
    //! Set the color of console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//* Function - Clear Screen
void clrscr()
{
    system("cls");
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

    vector<Position> get_positions()
    {
        return positions;
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

    int get_length()
    {
        return length;
    }

    //* Setter
    Position set_position(const Position &position)
    {
        current_position = position;
    }

    //* Method - Increase Length
    void increase_length()
    {
        length++;
    }

    //* Method - Erase first element in positions
    void erase_begin()
    {
        positions.erase(positions.begin());
    }

    //* Method - Increase Score
    void increase_score(const int &multiple)
    {
        score += multiple;
    }

    //* Method - Handle movement based on its direction
    void handle_movement()
    {
        //! Take Input
        take_movement_input();

        //! Switch Direction
        switch_direction();
    }

    //* Method - Store Position
    void store_position()
    {
        positions.push_back(current_position);
    }
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

    Symbol get_symbol()
    {
        return symbol;
    }

    //* Method - Set random position based on given size of grid
    void set_random_position(const int& space_size)
    {
        position.row = rand() % space_size;
        position.column = rand() % space_size;
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
    void initialize()
    {
        for (int i = 0; i < size.row; i++)
            for (int j = 0; j < size.column; j++)
                grid[i][j] = symbol;
    }
};

////////////////////
//? Logic Class
////////////////////
class Logic
{
private:
    //* Attributes
    Snake *snake;
    Food *food;
    Grid *grid;

public:
    //* Constructor
    Logic(Snake &snake, Food &food, Grid &grid) : snake(&snake), food(&food), grid(&grid) {}

    //* Meethod - Grow Snake
    void grow_snake()
    {
        // if (food.get_position() == current_position)
        // {
        //     food.is_spawned = false;
        //     length++;   //! Increase size/length
        //     score += 5; //! Increase score
        // }

        if (food->get_position() == snake->get_position())
        {
            food->is_spawned = false;

            snake->increase_length();

            snake->increase_score(5);
        }
    }

    //* Method - Wrap Indices (Ensure snake stays within bounds)
    void wrap_indices()
    {
        // int size = grid.get_size().get_center();
        // current_position.row = (current_position.row + size) % size;
        // current_position.column = (current_position.column + size) % size;

        int size = grid->get_size().get_center();

        snake->set_position(Position(
                (snake->get_position().row + size) % size,      //! Wrap row
                (snake->get_position().column + size) % size    //! Wrap column
            ));
    }

    //* Method - Spawn food randomly inside given space
    void spawn_food()
    {
        // if (!is_spawned)
        // {
        //     do
        //     {
        //         //! Get random position of the food
        //         position.row = rand() % grid.get_size().get_center();
        //         position.column = rand() % grid.get_size().get_center();

        //     } while (grid.get_symbol(position).get_symbol() != grid.get_symbol().get_symbol());

        //     grid.set_symbol(position, symbol);
        //     is_spawned = true;
        // }

        if (!food->is_spawned)
        {
            do
            {
                //! Get random position
                food->set_random_position(grid->get_size().get_center());
            } while (grid->get_symbol() != grid->get_symbol(food->get_position()));
            
            grid->set_symbol(food->get_position(), food->get_symbol());
            food->is_spawned = true;
        }
    }

    //* Method - Remove snake's tail
    void remove_tail()
    {
        if (snake->get_positions().size() >= snake->get_length())
        {
            //! Get position of tail i.e. 1st element of snake's positions
            Position tail_position(snake->get_positions()[0]);

            //! Clear grid at tail's position
            grid->set_symbol(tail_position, grid->get_symbol());

            //! Erase the tail position
            snake->erase_begin();
        }
    }

    //* Method - Display grid
    void display_grid()
    {
        for (int i = 0; i < grid->get_size().row; i++)
        {
            for (int j = 0; j < grid->get_size().column; j++)
            {
                //! Set snake's color
                if (grid->get_symbol(Position(i, j)) == snake->get_symbol())
                    setColor(snake->get_symbol().get_color());

                //! Set food's color
                else if (grid->get_symbol(Position(i, j)) == food->get_symbol())
                    setColor(food->get_symbol().get_color());

                //! Set background color
                else
                    setColor(grid->get_symbol().get_color());

                //! Display the symbol
                cout << grid->get_symbol(Position(i, j)).get_symbol();
            }
            cout << endl;
        }

        setColor(15); //! Set color to white
    }
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
    Logic *logic;
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
            logic->wrap_indices();

            //! Check for game over
            check_game_over();

            //! Grow the snake
            logic->grow_snake();

            //! Spawn food
            logic->spawn_food();

            //! Set grid's symbol i.e. Snake
            grid->set_symbol(snake->get_position(), snake->get_symbol());

            //! Move the snake
            logic->remove_tail();

            //! Clear Screen
            clrscr();

            //! Display game grid
            logic->display_grid();

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
        this->logic = new Logic(*this->snake, *this->food, *this->grid);
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
