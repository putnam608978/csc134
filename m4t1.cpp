// CSC 134 
// M4T1 - While
// Putnam
// 3/10/2025

#include <iostream>
using namespace std;

int main()
{
    // Part 1: Say "Hello" five times
    int count = 1;
    while (count <= 5) {             // loop until count reaches 5
        cout << "Hello number " << count << endl;
        count++;                      // increment count to avoid infinite loop
    }

    return 0; // done
}
