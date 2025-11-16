
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ------------------------------------------------------------
// QUESTION 1 – Average Rainfall
// ------------------------------------------------------------
void question1() {
    string m1, m2, m3;
    double r1, r2, r3;

    cout << "Enter month: ";
    cin >> m1;
    cout << "Enter rainfall for " << m1 << ": ";
    cin >> r1;

    cout << "Enter month: ";
    cin >> m2;
    cout << "Enter rainfall for " << m2 << ": ";
    cin >> r2;

    cout << "Enter month: ";
    cin >> m3;
    cout << "Enter rainfall for " << m3 << ": ";
    cin >> r3;

    double avg = (r1 + r2 + r3) / 3.0;

    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << m1 << ", " << m2 << ", and "
         << m3 << " is " << avg << " inches.\n\n";
}

// ------------------------------------------------------------
// QUESTION 2 – Hyperrectangle Volume
// ------------------------------------------------------------
void question2() {
    double width, length, height;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter height: ";
    cin >> height;

    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Error: All dimensions must be greater than zero.\n\n";
        return;
    }

    double volume = width * length * height;

    cout << "The volume of the block is: " << volume << endl << endl;
}

// ------------------------------------------------------------
// QUESTION 3 – Roman Numerals
// ------------------------------------------------------------
void question3() {
    int num;
    cout << "Enter a number (1 - 10): ";
    cin >> num;

    if (num < 1 || num > 10) {
        cout << "Error: The number must be between 1 and 10.\n\n";
        return;
    }

    cout << "The Roman numeral version of " << num << " is ";

    switch (num) {
        case 1: cout << "I"; break;
        case 2: cout << "II"; break;
        case 3: cout << "III"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VI"; break;
        case 7: cout << "VII"; break;
        case 8: cout << "VIII"; break;
        case 9: cout << "IX"; break;
        case 10: cout << "X"; break;
    }

    cout << ".\n\n";
}

// ------------------------------------------------------------
// QUESTION 4 – Geometry Calculator
// ------------------------------------------------------------
void question4() {
    int choice;

    cout << "Geometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "The valid choices are 1 through 4. Run the program again and select one of those.\n\n";
        return;
    }

    double radius, length, width, base, height;

    switch (choice) {
        case 1:
            cout << "Enter the circle's radius: ";
            cin >> radius;
            if (radius < 0) {
                cout << "The radius cannot be less than zero.\n\n";
                return;
            }
            cout << "The area is " << 3.14159 * radius * radius << endl << endl;
            break;

        case 2:
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter width: ";
            cin >> width;
            if (length < 0 || width < 0) {
                cout << "Only enter positive values for length and width.\n\n";
                return;
            }
            cout << "The area is " << length * width << endl << endl;
            break;

        case 3:
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter height: ";
            cin >> height;
            if (base < 0 || height < 0) {
                cout << "Only enter positive values for base and height.\n\n";
                return;
            }
            cout << "The area is " << base * height * 0.5 << endl << endl;
            break;

        case 4:
            cout << "Exiting Geometry Calculator...\n\n";
            return;
    }
}

// ------------------------------------------------------------
// QUESTION 5 – Distance Traveled
// ------------------------------------------------------------
void question5() {
    double speed;
    int hours;

    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;

    if (speed < 0) {
        cout << "Speed cannot be negative.\n\n";
        return;
    }

    cout << "How many hours has it traveled? ";
    cin >> hours;

    if (hours < 1) {
        cout << "Hours must be at least 1.\n\n";
        return;
    }

    cout << "Hour   Distance Traveled\n";
    cout << "---------------------------\n";

    for (int i = 1; i <= hours; i++) {
        cout << " " << i << "        " << speed * i << endl;
    }

    cout << endl;
}

// ------------------------------------------------------------
// QUESTION 6 – MENU SYSTEM
// ------------------------------------------------------------
int main() {
    int choice;

    do {
        cout << "MAIN MENU\n";
        cout << "1. Question 1 – Average Rainfall\n";
        cout << "2. Question 2 – Block Volume\n";
        cout << "3. Question 3 – Roman Numerals\n";
        cout << "4. Question 4 – Geometry Calculator\n";
        cout << "5. Question 5 – Distance Traveled\n";
        cout << "6. Exit Program\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: question1(); break;
            case 2: question2(); break;
            case 3: question3(); break;
            case 4: question4(); break;
            case 5: question5(); break;
            case 6: cout << "Exiting program...\n"; break;
            default:
                cout << "Invalid choice. Please select 1–6.\n\n";
        }

    } while (choice != 6);

    return 0;
}
