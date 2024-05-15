#include <iostream>

using namespace std;

int main()
{
    // Name/Title
    system("title TicTacToe");

    // Variables
    char board[9] = {'1', '2', '3',
                     '4', '5', '6',
                     '7', '8', '9'};
    char sign[2] = {'X', 'O'};
    int turn = 1, index;
    bool game_over = false;

    // Game-Loop
    while (!game_over)
    {

        // Show-Board
        for (int i = 0; i < 9; i++)
        {
            cout << "\t" << board[i];
            if ((i + 1) % 3 == 0)
                cout << endl;
        }

        // Check for won
        // Row
        for (int r = 0; r < 7; r += 3)
        {
            if (board[r] == board[r + 1] && board[r + 1] == board[r + 2])
            {
                cout << sign[turn % 2] << " Won";
                game_over = true;
            }
        }
        // Column
        for (int c = 0; c < 3; c++)
        {
            if (board[c] == board[c + 3] && board[c + 3] == board[c + 6])
            {
                cout << sign[turn % 2] << " Won";
                game_over = true;
            }
        }
        // Diagnol
        if (board[0] == board[4] && board[4] == board[8])
        {
            cout << sign[turn % 2] << " Won";
            game_over = true;
        }
        else if (board[2] == board[4] && board[4] == board[6])
        {
            cout << sign[turn % 2] << " Won";
            game_over = true;
        }

        // Check if someone won/game draw or not
        if (game_over)
            continue;

        // Display Message for Turn
        cout << sign[turn % 2] << " Turn:" << endl;

        // Get index of the board
        do
        {
            cout << "Enter index number>> ";
            cin >> index;
            // Update board
            if (board[index - 1] != 'O' && board[index - 1] != 'X')
                board[index - 1] = sign[turn % 2];
        } while (board[index - 1] == 'O' && board[index - 1] == 'X');

        // Other
        system("cls");
        turn++;
    }
    return 0;
}