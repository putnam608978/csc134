/*
CSC 134
M4LAB1 - 
Putnam, Elijah
9/24/25
*/



#include <iostream>
using namespace std;




cout << "==================================" << endl;
cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
cout << "==================================" << endl;
cout << "1. Exercise 1: Health Regeneration" << endl;
cout << "2. Exercise 2: Level Up Stats" << endl;
cout << "3. Exercise 3: Inventory System" << endl;
cout << "4. Run All Exercises" << endl;
cout << "5. Exit" << endl;
cout << "==================================" << endl;
cout << "Choice: ";
cin >> choice;

switch(choice)
{
    case 1:
        exercise1_healthRegen();
        break;
    case 2:
        exercise2_levelUpStats();
        break;
    case 3:
        exercise3_inventorySystem();
        break;
    case 4:
        exercise1_healthRegen();
        cout << endl;
        exercise2_levelUpStats();
        cout << endl;
        exercise3_inventorySystem();
        break;
    case 5:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
}

return 0;








