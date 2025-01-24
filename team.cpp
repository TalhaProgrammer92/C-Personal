#include <iostream>
#include <string>

using namespace std;

/*
todo: Implement a class Team and Players. Each player has name and runs. Design parametrized constructor for it.

* Team class will have 11 players. Implement a function add that adds a player to team. This function takes a player 
* sequence number, his name, and runs made by him as an argument. Implement a function showALL() that prints the details 
* (name, sequence number, runs) of all the players in a team. Also implement a function show(int) that print the details 
* of a player whose sequence number is passed in arguments. You need to perform validation check to see if the sequence 
* number has a record of player that has not been set yet (i.e. if it is null).
*/

// Player Class
class Player {
public:
    string name;    // ? Name of the player
    int runs;       // ? Runs made by the player

    // ? Constructor
    Player(string name, int runs) {
        this->name = name;
        this->runs = runs;
    }

    // ? Display the player's information
    void display() {
        cout << "Name: " << name << ", Runs: " << runs << endl;
    }
};

// Team Class
class Team {
private:
    Player* players[11];    // ? Players array

public:
    // ? Constructor
    Team() {
        // * Initialize players array with null pointers
        for (int i = 0; i < 11; ++i) {
            players[i] = nullptr;   // * Add the nul pointer to players' array
        }
    }

    // ? Add a player to the team
    void addPlayer(int seqNum, string name, int runs) {
        // * Validate sequence number and add player if valid
        if (seqNum >= 0 && seqNum < 11) {
            // * Check if player at the sequence number already exists and add if not
            if (players[seqNum] == nullptr) {
                players[seqNum] = new Player(name, runs);
            } else {
                cout << "Player at sequence number " << seqNum << " already exists." << endl;
            }
        
        // * Display success message
        } else {
            cout << "Sequence number must be between 0 and 10." << endl;
        }
    }

    // ? Display all players information
    void showAll() {
        // * Reading all players in the array
        for (int i = 0; i < 11; ++i) {
            // * Contain a player
            if (players[i] != nullptr) {
                cout << "Seq " << i << ": ";
                players[i]->display();
            }

            // * Null Pointer found => No player found
            else {
                cout << "Seq " << i << ": No player" << endl;
            }
        }
    }

    // ? Display player information by sequence number
    void show(int seqNum) {
        // * Validate sequence number and display player information if valid
        if (seqNum >= 0 && seqNum < 11) {
            // * Contain a player
            if (players[seqNum] != nullptr) {
                cout << "Seq " << seqNum << ": ";
                players[seqNum]->display();
            } else {
                cout << "Seq " << seqNum << ": No player" << endl;
            }

        // ! Display error message
        } else {
            cout << "Sequence number must be between 0 and 10." << endl;
        }
    }

    // * Destructor to delete dynamically allocated memory
    ~Team() {
        // * Delete dynamically allocated memory of players array
        for (int i = 0; i < 11; ++i) {
            delete players[i];
        }
    }
};

// * Main function to test the implementation
int main() {
    // * Create a new team and add players to it
    Team team;

    // todo: Adding neccessary data in team object
    team.addPlayer(0, "Player One", 150);
    team.addPlayer(1, "Player Two", 120);

    // ? Display all players information
    cout << "All players:" << endl;
    team.showAll();

    // ? Display player information at specific sequence
    cout << "\nDetails of player at sequence 1:" << endl;
    team.show(1);

    // * Attempt to add a player at sequence 11
    cout << "\nAttempt to add a player at sequence 0 again:" << endl;
    team.addPlayer(0, "Player Three", 200);

    return 0;
}
