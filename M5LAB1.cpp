/*
Putnam,Elijah
11/5/2025 - Updated for Rogue Trader
*/

#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits and streamsize for robust input

using namespace std;

// --- Global Game State (Rogue Trader features) ---
// These variables track your current standing and are modified by story events.
int g_profit_factor = 50;   // Represents wealth, rank, and reputation (Higher is better)
int g_crew_morale = 15;     // Affects success chance and choices (Range 0-20)
bool g_has_heretical_relic = false; // A key item that changes the ending


// --- Function Prototypes ---
// Utility functions
int getPlayerChoice(int maxChoice); // let player choose options
void showChoices(string choice1, string choice2, string choice3); // display the player choice menus
void show_status();

// Story node functions (Replaces original game_start placeholder)
void start_expedition();
void event_pirate_attack();
void event_ancient_ruins();
void event_xenos_contact();
void ending_state_check();


// --- Main Function ---
int main(){
    // Start the adventure from the main game node
    start_expedition();

    // Ending is handled within the story functions
    return 0;
}


// --- Utility Function Definitions ---

/**
 * Get a valid choice from the player, with robust input validation.
 *
 * @param maxChoice Highest valid choice number (1-indexed)
 * @return The 1-based index of the chosen option
 *
 */
int getPlayerChoice(int maxChoice) {
    int choice;

    while (true) {
        cout << "\nYour choice: ";

        // 1. Check for non-integer input (Robust Validation)
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // Clear the error flags
            // Ignore the rest of the line from the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go back to the start of the loop
        }

        // 2. Validate range (must be between 1 and maxChoice)
        if (choice >= 1 && choice <= maxChoice) {
            return choice; // Valid choice found
        }

        // If input was a number but out of range
        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}

void showChoices(string choice1, string choice2, string choice3) {
    // A quick menu. If a choice is empty ("") it's not shown
    int num = 1;

    // Choice 1 is always required
    cout << num << ". " << choice1 << endl;
    num++;

    if (choice2 != ""){
        cout << num << ". " << choice2 << endl;
        num++;
    }

    if (choice3 != "") {
        cout << num << ". " << choice3 << endl;
        num++;
    }
}

void show_status() {
    cout << "\n--- IMPERIAL STATUS REPORT ---\n";
    cout << "Profit Factor: " << g_profit_factor << "\n";
    cout << "Crew Morale:   " << g_crew_morale << " / 20\n";
    if (g_has_heretical_relic) {
        cout << "Inventory:     Heretical Relic (RISKY)\n";
    } else {
        cout << "Inventory:     Standard Wares\n";
    }
    cout << "------------------------------\n";
}


// --- Story Node Definitions (Replaces original game_start placeholder) ---

void start_expedition() {
    // This now serves as the main menu/entry point
    cout << "\n--- HAIL, ROGUE TRADER! ---\n";
    cout << "You are the master of the *Dauntless Purity*, plotting a course into the Expanse.\n";
    show_status();
    cout << "\nYour Navigator presents two courses of action:\n";

    // Use showChoices with up to 3 options
    showChoices("Initiate Warp Jump toward the established trade route (safer).",
                "Chart a new, dangerous route through an uncharted nebula (high risk).",
                "Contact the local Administratum for a mandate (slow, but guaranteed protection).");
    cout << "4. Quit the game." << endl; // Manual 4th option display

    int max = 4;
    int choice = getPlayerChoice(max);

    if (choice == 1) {
        event_pirate_attack();
    } else if (choice == 2) {
        event_ancient_ruins();
    } else if (choice == 3) {
        event_xenos_contact();
    } else { // choice == 4
        cout << "\nIn the name of the Emperor, may your soul find peace. Expedition aborted.\n";
    }
}

void event_pirate_attack() {
    cout << "\n*** EVENT: Chaos Pirate Attack ***\n";
    cout << "Mid-warp, you are ambushed by a small flotilla of heretic raiders!\n";
    cout << "What is your decree?\n";

    // Two choices offered using showChoices
    showChoices("Order the crew to fight them off and seize their cargo (Risks Morale/Hull).",
                "Broadcast a high Profit Factor offer for their surrender (Risks Profit).",
                ""); // choice3 is empty

    int max = 2; // Only two options are displayed
    int choice = getPlayerChoice(max);

    if (choice == 1) {
        if (g_crew_morale > 10) {
            cout << "Your loyal Voidsmen fight with righteous fury! +5 Profit Factor!\n";
            g_profit_factor += 5;
        } else {
            cout << "The crew falters. The fight is messy and costly. -5 Profit Factor and -5 Crew Morale.\n";
            g_profit_factor -= 5;
            g_crew_morale -= 5;
        }
    } else { // choice == 2 (Bribe/Surrender)
        cout << "You offer 10 Profit Factor worth of trade goods. -10 Profit Factor.\n";
        g_profit_factor -= 10;
    }
    ending_state_check();
}

void event_ancient_ruins() {
    cout << "\n*** EVENT: Uncharted Ancient Ruins ***\n";
    cout << "Your crew finds a vault containing two items: a Xenos device, or a stasis pod of human DNA.\n";
    cout << "Do you...\n";

    // Two choices offered using showChoices
    showChoices("Take the strange, glowing Xenos Relic (Potential Heresy/Value).",
                "Collect the pure Human DNA for the Mechanicus (Safe Profit).",
                ""); // choice3 is empty

    int max = 2; // Only two options are displayed
    int choice = getPlayerChoice(max);

    if (choice == 1) {
        cout << "You secure the Xenos device. The Mechanicus would call this **Heresy**...\n";
        g_has_heretical_relic = true;
    } else { // choice == 2 (DNA)
        cout << "You collect the DNA. A safe, clean profit is guaranteed. +8 Profit Factor.\n";
        g_profit_factor += 8;
    }
    ending_state_check();
}

void event_xenos_contact() {
    cout << "\n*** EVENT: Xenos Contact ***\n";
    cout << "The Administratum route led you straight to a trading post operated by the Kroot.\n";
    cout << "Your options are to engage in trade or cleanse the area with orbital bombardment.\n";
    cout << "What is your action, Rogue Trader?\n";

    // Two choices offered using showChoices
    showChoices("Attempt to trade with the Kroot for rare materials (Risks Morale).",
                "Purge the Xenos in the name of the Emperor! (Risks Profit).",
                ""); // choice3 is empty

    int max = 2; // Only two options are displayed
    int choice = getPlayerChoice(max);

    if (choice == 1) {
        if (g_crew_morale > 18) {
             cout << "The crew is disciplined and the trade is successful. +10 Profit Factor.\n";
             g_profit_factor += 10;
        } else {
             cout << "The crew is fearful and refuses to approach the Xenos. Mutiny! -10 Crew Morale. -5 Profit Factor.\n";
             g_crew_morale -= 10;
             g_profit_factor -= 5;
        }
    } else { // choice == 2 (Purge)
        cout << "The orbital bombardment is costly, but righteous. -7 Profit Factor, but +2 Crew Morale.\n";
        g_profit_factor -= 7;
        g_crew_morale += 2;
    }
    ending_state_check();
}


void ending_state_check() {
    cout << "\n\n*******************************************************\n";
    cout << "--- END OF EXPEDITION: RETURN TO IMPERIAL SPACE ---\n";
    show_status();

    // Check for extreme conditions first
    if (g_crew_morale <= 0) {
        cout << "RESULT: MUTINY AND DISASTER\n";
        cout << "Your crew's morale broke. They seize the *Dauntless Purity* and flee into the void.\n";
    } else if (g_profit_factor <= 20) {
        cout << "RESULT: BANKRUPT AND DISGRACED\n";
        cout << "Your Warrant of Trade is revoked! You are left a pauper in the slums of a Hive World.\n";
    }
    // Now check for main endings
    else if (g_has_heretical_relic) {
        cout << "RESULT: THE DARK TRADER\n";
        cout << "You return with forbidden technology! You are now marked for death by the Inquisition. You operate outside the law.\n";
    } else if (g_profit_factor >= 60) {
        cout << "RESULT: IMPERIAL HERO\n";
        cout << "Your expedition was a glorious success! Your name is written in gold leaf in the Administratum records.\n";
    } else {
        cout << "RESULT: AVERAGE SERVANT\n";
        cout << "Your run was adequate. You broke even and satisfied your Warrant. You live to trade another day.\n";
    }

    cout << "*******************************************************\n";
}
