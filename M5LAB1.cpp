/*
Putnam,Elijah
11/5/2025
*/

#include <iostream>
using namespace std;

// Function declarations
int getPlayerChoice(int maxChoice); // let player choose options

// main()
void main(){
    int choice;
    int max = 3;
    cout << "TESTING: CHOOSE 1, 2, OR 3. " << endl;
    choice = getPlayerChoice(max);
    cout << "You chose: " << choice << endl;

    //ending
    return 0;
}
// ============================================================================
// GAME LOGIC FUNCTIONS
// ============================================================================
// These functions handle the mechanics of running the game.

/**
 * Get a valid choice from the player.
 *
 * @param maxChoice Highest valid choice number
 * @return Zero-based index of the chosen option
 *
 */
int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice: ";
        cin >> choice;

        // Validate range (remember: player sees 1-N, we need 0-(N-1))
        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}
