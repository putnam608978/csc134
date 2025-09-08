/*
csc 134

Putnam
9/8/2025
*/




 #include <iostream>
using namespace std;
int main (){




    // set up the variables
    double length, width, height, volume; // size of crate
    double cost_to_make, charge_to_customer; // pricing
    double profit;

    const double COST_PER_CUBIC_FOOT =0.23; // relates to cost
    const double CHARGE_PER_CUBIC_FOOT = 0.5; // relates to charge


    // Get the crate info
    // "Crate Length: ";
    cout << "Welcome to the crate program. " << endl;
    cout <<"Crate Length: ";
    cin >> length;
    cout <<" Crate Width: ";
    cin >> width;
    cout << "Crate Height: ";
    cin >> height;

    // Calculate the cost and prices
    volume = length * width * height; 
    cost_to_make        = volume * COST_PER_CUBIC_FOOT;
    charge_to_customer  = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge_to_customer - cost_to_make;
    //display the results
    cout << endl;
    cout << "Your crate is " << volume << " cubic feet. " << endl;
    cout << "Customer Price: $" << charge_to_customer << endl;
    cout << "Cost to build : $" << cost_to_make << endl;
    cout << "Profit        : $" << profit << endl;

    return 0; // no errors

    //Get the crate info

}
