/*
CSC 134
M2HW1 
Putnam, Elijah
9/28/25
*/

#include <iostream>
#include <iomanip>  // for fixed and setprecision
#include <string>   // for string type
#include <cstdlib>  // for rand()
#include <ctime>    // for seeding rand()

using namespace std;

int main() {
    // ---------- Question 1 ----------
    cout << "Question 1: Banking Transactions" << endl;
    
    string name;
    double startingBalance, deposit, withdrawal;
    int accountNumber;

    cout << "Enter the account holder's name: ";
    getline(cin, name);   // allows spaces in the name
    
    cout << "Enter starting balance ($): ";
    cin >> startingBalance;

    cout << "Enter deposit amount ($): ";
    cin >> deposit;

    cout << "Enter withdrawal amount ($): ";
    cin >> withdrawal;

    // Generate random account number
    srand(time(0));
    accountNumber = rand() % 90000 + 10000; // random 5-digit number

    double finalBalance = startingBalance + deposit - withdrawal;

    cout << fixed << setprecision(2);  // print dollars with 2 decimals
    cout << "\nAccount Summary:" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Final Balance: $" << finalBalance << endl;
    cout << "\n------------------------------\n" << endl;

    // ---------- Question 2 ----------
    cout << "Question 2: General Crates" << endl;

    // Constants
    const double COST_PER_CUBIC_FOOT = 0.30;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    double length, width, height;
    cout << "Enter the dimensions of the crate (feet)." << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    double volume = length * width * height;
    double cost = volume * COST_PER_CUBIC_FOOT;
    double charge = volume * CHARGE_PER_CUBIC_FOOT;
    double profit = charge - cost;

    cout << fixed << setprecision(2);
    cout << "\nCrate Volume: " << volume << " cubic feet" << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Charge: $" << charge << endl;
    cout << "Profit: $" << profit << endl;
    cout << "\n------------------------------\n" << endl;

    // ---------- Question 3 ----------
    cout << "Question 3: Pizza Party" << endl;

    int pizzas, slicesPerPizza, visitors;
    cout << "How many pizzas are ordered? ";
    cin >> pizzas;
    cout << "How many slices per pizza? ";
    cin >> slicesPerPizza;
    cout << "How many visitors are coming? ";
    cin >> visitors;

    int totalSlices = pizzas * slicesPerPizza;
    int slicesNeeded = visitors * 3;
    int leftovers = totalSlices - slicesNeeded;

    cout << "Total slices: " << totalSlices << endl;
    cout << "Slices needed: " << slicesNeeded << endl;
    cout << "Leftover slices: " << leftovers << endl;
    cout << "\n------------------------------\n" << endl;

    // ---------- Question 4 ----------
    cout << "Question 4: Cheering Program" << endl;

    string letsGo = "Let's go ";
    string school = "FTCC";
    string team = "Trojans";

    string cheerOne = letsGo + school;
    string cheerTwo = letsGo + team;

    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;

    cout << "\n------------------------------\n" << endl;

    return 0;
}