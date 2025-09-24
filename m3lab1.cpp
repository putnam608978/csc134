/*
CSC 134
M3LAB1 - build a game
Putnam, Elijah
9/24/25
*/


#include <iostream>
using namespace std;
// ========== FUNCTION PROTOTYPES ==========
// Declare all your "rooms" up here
void fighting_postion_Kilo(); // Starting location
void forest(); // A possible path
void castle(); // Another path
void gameOver(); // An ending
void victory(); // Another ending
// ========== MAIN FUNCTION ==========
int main()
{
cout << "==================================" << endl;
cout << " WELCOME TO YOUR ADVENTURE " << endl;
cout << "==================================" << endl;
cout << endl;
// Start the adventure!
fighting_postion_Kilo();
cout << "\n=== THE END ===" << endl;
return 0;
}
// ========== LOCATION FUNCTIONS ==========
// Each function is one "node" in your story
void fighting_postion_Kilo()
{
cout << "\nYour vison slowly returns to you and you hear lasgun fire and explosions all around you. Your soldiers are screaming and fighting to hold the enemy back. You hear your commander hailing you on your vox. "  << endl;
cout << "Lt Smith, gather your forces and fallback to the city center to secure the Governor." << endl;
cout << "Will you fallback? (1 = Yes, 2 = No): ";
int choice;
cin >> choice;
if (choice == 1)
{
cout << "\n'You gather your forces and lead a fighting withdraw back to the city center. During the withdraw your forces are harassed by enemy jet bikes and aircraft trying to break up your formation. But you keep your forces tougher and repel each enemy attack and make it to the city center to rejoin what remains of the planetary defense forces. !'" << endl;
forest(); // Go to forest function
}
else
{
cout << "\n'The fighting intensifies and you organize your soldiers into a formidable defense but your heavy bolters run out of ammo and a sudden high pitched screech rings out and a flash of light speeds though the air and hits your chimera destroying it. The enemy quickly overcomes your forces and the planet falls.  !'" << endl;
gameOver(); // Go to game over
}
}
void forest()
{
// TODO: Add your forest scene here!
cout << "\n[Forest scene not yet written]" << endl;
}
void castle()
{
// TODO: Add your castle scene here!
cout << "\n[Castle scene not yet written]" << endl;
}
void gameOver()
{
cout << "\n💀 GAME OVER 💀" << endl;
cout << "Your adventure ends here." << endl;
}
void victory()
{
cout << "\n💀 VICTORY! 💀" << endl;
cout << "You saved the kingdom!" << endl;
}




