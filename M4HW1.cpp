/*
M4HW1
Putnam, Elijah
*/

#include <iostream>
#include <limits> // Required for input validation

int main() {
    int table_number;
    const int MIN_VAL = 1;
    const int MAX_VAL = 12;
    int multiplier = 1; // Counter starts at 1

    std::cout << "--- Multiplication Table Generator ---\n";
    
    // Part Three: Gold - Input Validation Loop
    // Loop continues until a valid number (1-12) is entered.
    do {
        std::cout << "\nEnter a number from " << MIN_VAL << " to " << MAX_VAL << " to create its times table: ";
        
        // 1. Check for non-numeric input (e.g., letters or symbols)
        if (!(std::cin >> table_number)) {
            std::cout << "Error: Invalid input! Please enter a whole number.\n";
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the bad input
        } 
        // 2. Check for out-of-range input
        else if (table_number < MIN_VAL || table_number > MAX_VAL) {
            std::cout << "Error: The number must be between " << MIN_VAL << " and " << MAX_VAL << ".\n";
        }
    } while (table_number < MIN_VAL || table_number > MAX_VAL);

    std::cout << "\n✅ Generating the '" << table_number << " times' table:\n";
    std::cout << "---------------------------------------\n";

    // Part Two: Silver - Times Table Generation Loop
    // The loop runs 12 times (for 1 times the number up to 12 times the number).
    while (multiplier <= MAX_VAL) {
        int result = table_number * multiplier;
        
        // Output format: X times Y is Z.
        std::cout << table_number << " times " << multiplier << " is " << result << ".\n";
        
        // Increment the multiplier
        multiplier++;
    }

    std::cout << "---------------------------------------\n";
    
    return 0;
}

