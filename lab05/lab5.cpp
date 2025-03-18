#include <iostream>
#include <string>
#include <cstdlib> // for rand functions
#include <ctime> // for time function
using namespace std; // so i don't have to type "std::"


/*
You will create a Car class that represents a single car. Each car has:

- A make, model, and year
- An originalPrice (set to $10,000 for all cars)
- A currentPrice (initially $10,000, but decreases with each transaction)
- A boolean isOwned indicating whether or not the user owns the car

The user starts with $100,000. You will perform 10 random transactions, each either buying or selling one of the three cars. After 10 transactions, the program should display each car’s original and current prices, whether it’s owned, and the user’s final balance.

** Breakdown **

1. Define the Car Class
    1. Public members for make, model, year, originalPrice, currentPrice, and isOwned.
    2. A constructor setting originalPrice and currentPrice to $10,000, isOwned to false.
    3. A method getCarInfo() returning a string like "2010 Toyota Camry".
    4. Two methods, buyCar(double &userMoney) and sellCar(double &userMoney), each checking if the transaction is valid (e.g., not already owned if buying, or currently owned if selling). If valid:
        1. Update userMoney appropriately.
        2. Toggle isOwned.
        3. Reduce currentPrice by 10% of originalPrice.
    5. A private helper method (optional) to reduce the current price by 10% of original price.
2. Implement main()
    1. Initialize the user’s money to $100,000.
    2. Create 3 Car objects (e.g., car1, car2, car3), each with different make/model/year but the same initial price of $10,000.
    3. Perform 10 random transactions:
        1. Randomly pick one of the three cars.
        2. Randomly choose whether to buy or sell.
        3. Print messages indicating success/failure and update userMoney.
    4. After these transactions, print a final summary:
        1. User’s final balance
        2. Each car’s originalPrice and currentPrice
        3. Whether the user owns each car
*/


// -------------------------------------------------------------------------------------------------------------


class Car {
    public:
        string brand;
        string model;
        int year;
        double originalPrice;
        double currentPrice;
        double price;
        bool isOwned;

    // 2) Constructor: sets originalPrice/currentPrice to 10000, isOwned to false
    //    TODO: Car(const string &mk, conststring &md, int yr) { ... }

    // 3) Method getCarInfo() returning something like "2010 Toyota Camry"
    //    TODO: string getCarInfo() { ... }

    // 4) buyCar(double &userMoney)
    //    - If not owned and userMoney >= currentPrice:
    //      - set isOwned = true
    //      - userMoney -= currentPrice
    //      - reduce currentPrice by 10% of originalPrice
    //      - return true
    //    - else return false

    int buyCar () {
        if (isOwned == false && userMoney >= currentPrice) {
            isOwned = true;
            userMoney = userMoney - currentPrice;
            currentPrice = currentPrice * 0.10;
            return true;
        } else {
            return false;
        }
    }


    // 5) sellCar(double &userMoney)
    //    - If owned:
    //      - set isOwned = false
    //      - userMoney += currentPrice
    //      - reduce currentPrice by 10% of originalPrice
    //      - return true
    //    - else return false

    int sellCar () {
        if (isOwned == true) {
            isOwned = false;
            userMoney = userMoney + currentPrice;
            currentPrice = currentPrice * 0.10;
            return true;
        } else {
            return false;
        }
    }

    
    // 6) reducePriceByTenPercentOfOriginal()
    //    - currentPrice -= 0.10 * originalPrice
    //    - clamp currentPrice at 0 if it goes negative

    int reducePriceByTenPercentOfOriginal () {
        currentPrice = currentPrice - (originalPrice * 0.10);
        // something else here
    }


};

int main() {

    // seed random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // user starts with $100k
    double userMoney = 100000.0;
    string brand;
    string model;
    int price;
    int year;

    Car car1;
    car1.year = 2010;
    car1.brand = "Toyota";
    car1.model = "Camry";
    car1.price = 10000;

    Car car2;
    car2.year = 2022;
    car2.brand = "Tesla";
    car2.model = "Model 3";
    car2.price = 10000;

    Car car3;
    car3.year = 1967;
    car3.brand = "Ford";
    car3.model = "Mustang";
    car3.price = 10000;

    // Perform 10 transactions
    for (int i = 1; i <= 10; ++i) {
        cout << endl << "--- Transaction " << i << " ---" << endl;

        // random index 0 to 2
        int carIndex = rand() % 3;
        // random action; 0 = buy, 1 = sell
        int action = rand() % 2;


        if (carIndex == 0) {
            // operate on car1
        } else if (carIndex == 1) {
            // operate on car2
        } else {
            // operate car3
        }


            // For each case, check:
        //   if (action == 0) call buyCar(...)
        //   else call sellCar(...)
        // Print messages accordingly

        for () {
            if (action == 0) {
                buyCar();
                cout << "";
            } else {
                sellCar();
                cout << "";
            }
        }


        // Print updated user balance
        cout << "You have $" << userMoney << " left." << endl;
    }

    // final Report
    cout << "\n\n--- Final Report After 10 Transactions ---\n";
    // print userMoney
    cout << userMoney << endl;
    // print each car's originalPrice, currentPrice, and ownership status
    cout << "Original price: " << car1.originalPrice << endl << "Current price: " << car1.currentPrice << endl << "Owned: " << car1.isOwned << endl;
    cout << "Original price: " << car2.originalPrice << endl << "Current price: " << car2.currentPrice << endl << "Owned: " << car2.isOwned << endl;
    cout << "Original price: " << car3.originalPrice << endl << "Current price: " << car3.currentPrice << endl << "Owned: " << car3.isOwned << endl;

    return 0;
}