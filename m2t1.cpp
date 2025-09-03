/*
Csc 134, M2T1
Putnam
9/3/25
Revision of "sales" program from m1, now with user input.
*/

 #include <iostream>
using namespace std;

int main(){
    // Declare our variables ("the truth")
    string item = "bolters";
    double cost_per = 1000;
    int amount = 30000;
    // variables for user input
    int amount_purchased;
    double total_cost;

    // Greet the user
    cout << "Hello! Welcome to our " << item << " store." << endl;
    // Ask for information
    cout << "Each of the " << item << " cost $" << cost_per << endl;
    cout << "We have " << amount << " for sale." << endl;
    cout << endl;
    cout << " How many would you like to buy" << endl;
    // cin: put information from the Keyboard into a variable
    cin >> amount_purchased;

    // Do some processing
    // I say single equal as "gets"
    total_cost = amount_purchased * cost_per;
    // TODO
    // Output the answer
    cout << "You are buying " << amount_purchased << " " << item << endl;
    cout <<  "The total is: $" << total_cost << endl;
    cout << "Thank you for shopping with us." << endl;
        return 0;
}