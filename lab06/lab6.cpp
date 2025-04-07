#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Constants for grid size and cell states
const int SIZE = 10;
const int EMPTY = 0;
const int SHIP = 1;
const int HIT = -1;
const int MISS = -2;
const int NUM_SHIPS = 6;
int shipSizes[NUM_SHIPS] = {2, 2, 3, 3, 5, 5}; // Ship lengths


// Step 1: Initialize the battlefield with all cells set to EMPTY
void initializeBattlefield(int battlefield[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          battlefield[i][j] = EMPTY;
        }
    }  

}


// Step 2: Check if a ship of given length can be placed at a position
bool canPlaceShip(int battlefield[SIZE][SIZE], int row, int col, int length, bool horizontal) {

    if (horizontal) {
        if (col + length > SIZE) {
            return false;
        }
        for (int i = col; i < col + length; i++) {
            if (battlefield[row][i] != EMPTY) {
                return false;
            }
        }
    } else if (!horizontal) {
        if (row + length > SIZE) {
            return false;
        }
        for (int i = row; i < row + length; i++) {
            if (battlefield[i][col] != EMPTY) {
                return false;
            }
        }
    }
    return true;

}


// Step 3: Place a ship on the grid by marking its cells with SHIP (1)
void placeShip(int battlefield[SIZE][SIZE], int row, int col, int length, bool horizontal) {

    if (horizontal) {
        for (int i = 0; i < length; i++) {
            battlefield[row][col + i] = SHIP;
        }
    } else if (!horizontal) {
        for (int i = 0; i < length; i++) {
            battlefield[row + i][col] = SHIP;
        }
    }

}


// Step 4: Place all ships randomly on the battlefield
void randomlyPlaceShips(int battlefield[SIZE][SIZE]) {

    srand(time(0));

    for (int i = 0; i < NUM_SHIPS; i++) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            bool horizontal = true;
            bool vertical = false;
        while (!canPlaceShip(battlefield, row, col, shipSizes[i], horizontal)) {
            row = rand() % SIZE;
            col = rand() % SIZE;
            horizontal = rand() % 2;
        }
        placeShip(battlefield, row, col, shipSizes[i], horizontal);
    }

}


// Step 5: Display the battlefield
void displayBattlefield(int battlefield[SIZE][SIZE], bool revealShips = false) {

    cout << " ";

    for (int j = 0; j < SIZE; j++) {
        cout << j << " ";
    }

    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (battlefield[i][j] == HIT) {
                cout << "H ";
            } else if (battlefield[i][j] == MISS) {
                cout << "M ";
            } else if (battlefield[i][j] == SHIP && revealShips) {
                cout << "S ";
            } else {
                cout << "~ ";
            }
        }
        cout << endl;
    }

}


// Step 6: Check if all ships are sunk
bool allShipsSunk(int battlefield[SIZE][SIZE]) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (battlefield[i][j] == SHIP) {
                return false;
            }
        }
    }
    return true;

}


// Main game logic
int main() {
    int battlefield[SIZE][SIZE];

    // Step 1: Initialize battlefield to all EMPTY
    initializeBattlefield(battlefield);

    // Step 2: Randomly place ships
    randomlyPlaceShips(battlefield);

    cout << "Welcome to Battleship!\n";
    cout << "Enter coordinates to attack (row and column between 0–9).\n";
    cout << "Enter -1 -1 to reveal all ships on the grid.\n\n";

    // Step 3: Gameplay loop
    while (true) {
        // Step 3a: Show current grid
        displayBattlefield(battlefield);

        // Step 3b: Get input from user
        int row, col;
        cout << "Enter row and column: ";
        cin >> row >> col;

        // Step 3c: Reveal ships if -1 -1
        if (row == -1 && col == -1) {
            cout << "\n[DEBUG MODE] Revealing all ships:"; << endl;
            displayBattlefield(battlefield, true);
            continue;
        }

        // Step 3d: Validate input
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            cout << "Invalid coordinates. Try again." << endl;
            continue;
        }

        // Step 3e: Check for hit or miss
        if (battlefield[row][col] == SHIP) {
            battlefield[row][col] = HIT;
            cout << "Hit!" << endl;
        } else if (battlefield[row][col] == EMPTY) {
            battlefield[row][col] = MISS;
            cout << "Miss!" << endl;
        } else {
            continue;
        }

        // Step 3f: Check if game is over
        if (allShipsSunk(battlefield)) {
            break;
        }
    }

    // Step 4: Game over
    cout << endl << "All ships sunk! You win!" << endl;
    cout << "Final Battlefield:" << endl;
    displayBattlefield(battlefield, true);

    return 0;
}