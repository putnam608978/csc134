// CSC 134
// M3LAB - Grade Converter
// Elijah Putnam
// 10/10/2025

#include <iostream>
using namespace std;

int main() {
    double grade; // variable to store numerical grade

    cout << "Enter your numerical grade (0 - 100): ";
    cin >> grade;

    // Check if input is valid
    if (grade < 0 || grade > 100) {
        cout << "Error: Please enter a grade between 0 and 100." << endl;
    } 
    else if (grade >= 90 && grade <= 100) {
        cout << "Your letter grade is: A" << endl;
    } 
    else if (grade >= 80 && grade <= 89) {
        cout << "Your letter grade is: B" << endl;
    } 
    else if (grade >= 70 && grade <= 79) {
        cout << "Your letter grade is: C" << endl;
    } 
    else if (grade >= 60 && grade <= 69) {
        cout << "Your letter grade is: D" << endl;
    } 
    else { // grade < 60
        cout << "Your letter grade is: F" << endl;
    }

    return 0;
}
