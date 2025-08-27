/*
csc 134
m1lab
putnam
8/27/2025
purpose: The "Bolter" (replace noun) sales program.
*/


//magic words
#include <iostream>
using namespace std;

int main(){
    //strat program
    //declare all of our variables ("whiteboards")
    string item_name = "Bolter"; // replace with your item
    int num_items = 10 ;
    double cost_per = 0.25;

    // Give our sales pitch
    //cout << "Welcome to the " << item_name << " store!" << endl;
    cout << "Welcome to the " << item_name << " store!" << endl;
    cout << "We have " << num_items << " total." << endl;
    cout << "Each Bolter cost " << cost_per << endl;
    // do the processing
    double total_cost = num_items * cost_per;
    // Print the output
    cout << "Buying them all will cost: $" << total_cost << endl;
    cout << "Thanks for shopping with us!" << endl;

    //end program
    return 0;
}
