#include <iostream>


// note - known issue: when user inputs a letter or string, the loop runs infinitely.


int main () {

    int menuOption;
    float balance = 1000;
    float deposit;
    float withdraw;

    // while loop to make the menu pop up after each user choice
    while (menuOption != 1 || menuOption != 2 || menuOption != 3 || menuOption != 4) {

        // the menu
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Exit the Program" << std::endl;

        std::cout << "Choose an option from the menu." << std::endl;
        std::cin >> menuOption;

        // if/else for menu options
        if (menuOption == 1) {
            std::cout << "Your current balance is: " << balance << std::endl;;
        } else if (menuOption == 2) {
            std::cout << "Enter deposit amount: " << std::endl;
            std::cin >> deposit;
            balance = balance + deposit;
        } else if (menuOption == 3) {
            std::cout << "Enter withdraw amount: " << std::endl;
            std::cin >> withdraw;
            if (balance < withdraw) {
                std::cout << "Insufficient funds." << std::endl;
            } else {
                balance = balance - withdraw;
            }
        } else if (menuOption == 4) {
            return 0; // end program
        } else {
            std::cout << "Invalid input. Please enter a valid number (1, 2, 3, or 4)." << std::endl;
        }    
    }
    
    return 0;

}
