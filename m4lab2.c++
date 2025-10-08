/*
CSC 134
M4LAB2 - 
Putnam, Elijah
10/8/25

Task: Draw a rectangle.
*/

#include <iostream>
using namespace std;


int main(){

//Declare variable
int length = 10;
int height = 10;
string tile = "🐯"; // Use any character or emoji

// Example 1: Print horizontally (a row)
for (int i = 0; i < length; i++) {
    cout << tile;
}
cout << endl;

// Example 2: Same thing , with a while loop
int count =0;
while (count < length) {
cout << tile;
count++; // count from 0 to just before length
}
cout << endl;

// Example 3: For loop, but printing in a colum (vertically)
for (int i = 0; i < height; i++){
    cout << tile << endl;
}
// Example 4: Draw the entire rectangle
cout << endl << endl; // white space
cout << "Draw a Rectangle" << endl;
cout << "length? ";
cin >> length;
cout << "height? ";
cin >> height;
cout << "Rectangle " << length << " x" << height << endl;
// Outer Loop handles printing [height] number of lines.
// Inner Loop handles printing each line as [length] number of tiles.
for (int i=0; i < height; i++) {
    //print the line
    for (int j=0; j < length; j++) {
        cout << tile;
    }
    cout << endl;
}

return 0; // no errors

}







