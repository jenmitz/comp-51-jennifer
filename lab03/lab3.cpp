// jennifer mitzman sonnad - lab 3

#include <iostream>
#include <cstdlib> // for rand function
#include <ctime> // for time function

using namespace std;

int main () {

    // declare variables
    int userGuess; // user's guess
    int randomNum; // randomly generated number
    int numOfGuesses; // current number of guesses
    int continuePlay; // play again or end the game

    srand(time(NULL)); // seed random number generator 

    // while loop to run the game until user exits
    while (true) {

        // generate a random number
        randomNum = (rand() % 100) + 1;
        numOfGuesses = 0; // reset guess count

        // ask user to guess a number, store that value
        cout << "Guess a number from 1 to 100. You get five attempts." << endl;
        cin >> userGuess;

        // for loop to keep track of number of guesses
        for (int i = 1; i <= 4; i++) {

            numOfGuesses++; // update the number of guesses

            // compare numbers; provide hints if guess is incorrect
            if (randomNum > userGuess) {
                cout << "Too low!" << endl << "Guess again." << endl;
                cin >> userGuess;
            } else if (randomNum < userGuess) {
                cout << "Too high!" << endl << "Guess again." << endl;
                cin >> userGuess;
            } else if (randomNum == userGuess){
                cout << "Congratulations! You guessed the number." << endl << "Play again? Type 1 for yes, or 2 to exit." << endl;
                cin >> continuePlay; // exit the loop if user wins
            
                if (continuePlay == 1) {
                    break; // restart the game from the beginning
                } else {
                    return 0; // stop the game
                }
            }

        }

        // if the user doesn't guess the number, ask to play again
        if (randomNum != userGuess) {
            cout << "You lose! The number was " << randomNum << "." << endl << "Try again? Type 1 for yes, or 2 to exit." << endl;
            cin >> continuePlay;
        }

        // if the user does not want to continue, exit the game
        if (continuePlay != 1) {
            return 0;
        }
    }

}