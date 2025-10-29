/*
M5LABA- Stats lvl up
Putnam
10/29/2025
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Step 1: Print the table header (BEFORE the loop)
    cout << "Level | STR | DEX | INT" << endl;
    cout << "------|-------|-------|-------" << endl;

    // Step 2, 3, 4: Set up the for loop, calculate stats, and print one row (INSIDE the loop)
    for (int level = 1; level <= 10; level++) {
        // Calculate stats for THIS level
        int strength = 10 + (level * 2);
        int dexterity = 8 + (level * 3);
        int intelligence = 12 + (level * 1);

        // Print one row of the table
        cout << " " << level << " | " << strength
             << " | " << dexterity << " | " << intelligence << endl;
    }

    cout << "------|-------|-------|-------" << endl; // Optional separator for clarity

    // Step 5: Calculate total growth (AFTER the loop)

    // Level 10 stats:
    int finalStr = 10 + (10 * 2); // = 30
    int finalDex = 8 + (10 * 3); // = 38
    int finalInt = 12 + (10 * 1); // = 22

    // Level 1 stats:
    int startStr = 10 + (1 * 2); // = 12
    int startDex = 8 + (1 * 3); // = 11
    int startInt = 12 + (1 * 1); // = 13

    // Growth:
    int strGrowth = finalStr - startStr; // 30 - 12 = 18
    int dexGrowth = finalDex - startDex; // 38 - 11 = 27
    int intGrowth = finalInt - startInt; // 22 - 13 = 9

    cout << "Total Growth: STR +" << strGrowth
         << ", DEX +" << dexGrowth
         << ", INT +" << intGrowth << endl;

    return 0;
}
