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
void city_center(); // A possible path
void governor_palace(); // Another path
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
cout << "\n'You gather your forces and lead a fighting withdraw back to the city center. During the withdraw your forces are harassed by enemy jet bikes and aircraft trying to break up your formation. But you keep your forces together and repel each enemy attack and make it to the city center to rejoin what remains of the planetary defense forces. !'" << endl;
city_center(); // Go to city_center function
}
else
{
cout << "\n'The fighting intensifies and you organize your soldiers into a formidable defense but your heavy bolters run out of ammo and a sudden high pitched screech rings out and a flash of light speeds though the air and hits your chimera destroying it. The enemy quickly overcomes your forces and the planet falls.  !'" << endl;
gameOver(); // Go to game over
}
}
void city_center()
{
cout << "\n[As you approach the city center you call your higher command to request covering fire to suppress the Dark Eldar forces attacking your convoy. “ This is Captain Lewis continue straight and are gunners will engage the enemy as soon as they enter range. Heavy bolter fires suddenly starts flying overhead and drives the Dark Eldar back They take minimal losses in the exchange.   ]" << endl; 
governor_palace(); // go to governor palace
}

void governor_palace()
{
// TODO: Add your castle scene here!
cout << "\n[Your forces enter the defensive perimeter and you tell your men to resupply and join the defenses. Captain Lewis approaches you “LT Smith I need you to come with me, we taken heavy casualties and need to speak with the governor about the situation and plan our next move.]" << endl;
cout << "You walk into the palace next to Captain Lewis and approach the governor. He is clearly panicking and speaking to himself. Captain Lewis speaks loudly “ Sir we need to call for reinforcements.” The governor ignors the Captin"
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




