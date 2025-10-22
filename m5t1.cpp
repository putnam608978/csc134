/*
csc 134
M5T1 - Basic Functions
Putnam, Elijah
10/22/25
*/


#include <iostream>
using namespace std;

// Function Declarations
void say_hello();

int get_the_answer();

double double_a_number(double);

int main(){

        double my_num;
        int another_num;
    say_hello();
    cout << "Welcome to the best program ever!" << endl;
    cout << "Please enter a number (with or without decimal place)." << endl;
    cin >> my_num;
    my_num = my_num * 2;
    cout << "Double the number is: " << my_num << endl;
    cout << "But the only answer you need is: ";
    cout << get_the_answer() << endl;

}


// function definitions 
void say_hello(){
    // says hi
    cout << "Welcome to the best program ever!" << endl;
}

int get_the_answer(){
    // provides the answer to everything
    return 42;
}

double double_a_number(double the_num){
// num times two
double answer = the_num * 2;
return answer;

}
