#include <iostream>

int main () {

    int temperature;
    int weatherCode;
    double budget;
    

    std::cout << "Enter your temperature in degrees.";
    std::cin >> temperature;

    std::cout << "Enter your budget in dollars.";
    std::cin >> budget;

    std::cout << "Enter your weather condition (1 = sunny, 2 = rainy, 3 = cloudy).";
    std::cin >> weatherCode;
    
    if (weatherCode == 1) {
        if ((temperature > 75) && (budget > 20)) {
            std::cout << "Go the the beach!";
        } else {
            std::cout << "Have a picnic.";
        }
    } else if (weatherCode == 2) {
        if (budget > 15) {
            std::cout << "Go to a museum.";
        } else {
            std::cout << "Go watch a movie.";
        }
    } else {
        std::cout << "Visit a coffee shop.";
    }

}
    