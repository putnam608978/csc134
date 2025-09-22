/*
CSC 134
M3t2  craps part 1
Putnam, Elijah
9/22/25
*/


#include <iostream>
#include <cstdlib> // for rand() srand()
#include <ctime> // for time()


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
    // Seed RNG before roll
    srand(time(0)); 
  // roll the dice
  roll1 = roll();
  roll2 = roll();
   int sum = roll1+roll2;
   cout << "ROLL: " << sum << end;
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
    int my_roll;
    my_roll + (rand() % 6) +1; // 1-6
    return my_roll;
}







