/*
CSC 134
M3t2  craps part 1
Putnam, Elijah
9/22/25
*/


#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

// Helper functions (todo)
int roll();

// main
int main(){
    int num = roll();
    cout << num << endl;
    // main craps cycle
    // for now:
    /*
    - roll 2d6 (2-12)
    -branch based on win, lose, or point
    - rest comes later
    */
   int roll1 = 2;
   int roll2 = 5;
   int point;      // roll if it doesn't immdiately win/lose

   // Blatanly cheat
   cout << "Enter two dice (press ENTER between) ";
   cin >> roll1;
   cin >> roll2;
   int sum = roll1+roll2;

   // win on 7 or 11
   if ((sum == 7) || (sum == 11)) {
    cout << "Lucky Seven or Eleven -- You Win!" << endl;
   }
   // lose on 2, 3, 12 
   else if ((sum == 2) || (sum == 3) || (sum == 12)) {
    cout << "2,3,12 -- Sorry, you lose." << endl;
   }
   else {
    // set the point
    point = sum;
    cout << "Rolled a point." << endl;
    cout << "Your point is : " << point << endl;
   }
    return 0;
}

// Define Helper Functions
int roll() {
    // rolls a six sidded dice
    // TODO
    return 6;
}







