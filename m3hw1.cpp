// CSC 134
// M3HW1 - Gold
// Elijah Putnam
// 10/10/2025

#include <iostream>
#include <iomanip>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    // Question 1: Simple Chatbot
    cout << "Question 1" << endl;
    cout << "Hello, I’m a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no." << endl;

    string answer;
    cin >> answer;

    if (answer == "yes") {
        cout << "That’s great! I’m sure we’ll get along." << endl;
    } else if (answer == "no") {
        cout << "Well, maybe you’ll learn to like me later." << endl;
    } else {
        cout << "If you’re not sure… that’s OK." << endl;
    }

    cout << endl;

    // Question 2: Receipt Calculator
    cout << "Question 2" << endl;

    double mealPrice, tax, tip = 0, total;
    int dineType;

    cout << "Enter the price of your meal: $";
    cin >> mealPrice;
    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> dineType;

    tax = mealPrice * 0.07;  // assuming 7% sales tax
    if (dineType == 1) {
        tip = mealPrice * 0.15;
    }

    total = mealPrice + tax + tip;

    cout << fixed << setprecision(2);
    cout << "-----------------------------" << endl;
    cout << "Meal:   $" << setw(8) << mealPrice << endl;
    cout << "Tax:    $" << setw(8) << tax << endl;
    cout << "Tip:    $" << setw(8) << tip << endl;
    cout << "-----------------------------" << endl;
    cout << "Total:  $" << setw(8) << total << endl;
    cout << "-----------------------------" << endl;

    cout << endl;

    // Question 3: Choose Your Own Adventure
    cout << "Question 3" << endl;

    string choice1, choice2;

    cout << "You wake up in a dark forest. Do you go LEFT or RIGHT? ";
    cin >> choice1;

    if (choice1 == "left" || choice1 == "Left") {
        cout << "You find a peaceful river. Do you DRINK the water or KEEP walking? ";
        cin >> choice2;

        if (choice2 == "drink" || choice2 == "Drink") {
            cout << "Oh no! The water was poisoned. Game over." << endl;
        } else if (choice2 == "keep" || choice2 == "Keep") {
            cout << "You find a cabin with food and shelter. You survive! Victory!" << endl;
        } else {
            cout << "You hesitate too long and get lost forever. Game over." << endl;
        }
    } else if (choice1 == "right" || choice1 == "Right") {
        cout << "You run into a hungry bear. Game over." << endl;
    } else {
        cout << "You stand still until night falls. Game over." << endl;
    }

    cout << endl;

    // Question 4: Math Practice
    cout << "Question 4" << endl;

    srand(time(0));  // seed random number generator
    int num1 = rand() % 10;  // random number 0–9
    int num2 = rand() % 10;
    int userAnswer;

    cout << "What is " << num1 << " plus " << num2 << "?" << endl;
    cin >> userAnswer;

    if (userAnswer == num1 + num2) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The right answer is " << num1 + num2 << "." << endl;
    }

    cout << endl;
    cout << "End of program." << endl;

    return 0;
}
