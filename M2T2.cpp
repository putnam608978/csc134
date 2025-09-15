/*
CSC 134
M2T2 Receipt
Elijah Putnam
9/15/25
*/

#include <iostream>
#include <iomanip>
using namespace std;


int main(){

// Declare variables
string item = "Bolters";
double menu_price = 5.99;
double tax_percent = 0.08; // this is 8/100 or 8%
double tax_amount;         // how much tax in $
double total_price;

// Calculate the values
cout << "Order up" << endl;
cout << item << " (x1)";
cout << "\t" << menu_price << endl;

    tax_amount = menu_price * tax_percent; // add sales tax
    total_price = menu_price + tax_amount;

    // Print the results
    cout << setprecision(2) << fixed; // Set 2 decimal places
    cout << "Tax: \t\t$" << tax_amount << endl;
    cout << "Total:\t$" << total_price << endl;

}

