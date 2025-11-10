/*
M5T2
Putnam, Elijah
11/10/25
*/


#include <iostream>
#include <iomanip> // For formatting output

/**
 * @brief Calculates the square of an integer.
 *
 * This is a value-returning function.
 *
 * @param number The integer to be squared.
 * @return The square of the input number.
 */
int square(int number) {
    // Returns the result of number multiplied by itself
    return number * number;
}

/**
 * @brief Prints a single line of the output table.
 *
 * This is a void function (it does not return a value).
 *
 * @param number The original number.
 * @param squaredValue The square of the number.
 */
void printAnswerLine(int number, int squaredValue) {
    // Set width for nice column alignment
    std::cout << "Number: " << std::setw(3) << number
              << " | Square: " << std::setw(4) << squaredValue
              << std::endl;
}

/**
 * @brief Main function to drive the program.
 *
 * It iterates from 1 to 10, calls the square function, and then
 * calls the printAnswerLine function for each number.
 *
 * @return 0 upon successful execution.
 */
int main() {
    std::cout << "🔢 Squares of Numbers from 1 to 10 🔢" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // Loop from 1 up to and including 10
    for (int i = 1; i <= 10; ++i) {
        // 1. Call the value-returning function to get the square
        int result = square(i);

        // 2. Call the void function to print the line
        printAnswerLine(i, result);
    }

    std::cout << "-------------------------------------" << std::endl;
    return 0;
}


