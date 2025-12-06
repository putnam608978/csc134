#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
======================================================
 PART 1 — Struct Example (Simple Grouping of Data)
======================================================
*/

struct CharacterStruct
{
    string name;
    int currentHP;
    int maxHP;
    int strength;
    int dexterity;
    int intelligence;
    int level;
    int experience;
    int gold;
};

void displayStruct(const CharacterStruct &c)
{
    cout << "\n=== (Struct) " << c.name << " ===" << endl;
    cout << "HP: " << c.currentHP << "/" << c.maxHP << endl;
    cout << "STR: " << c.strength << "  DEX: " << c.dexterity 
         << "  INT: " << c.intelligence << endl;
    cout << "Level " << c.level << " | XP: " << c.experience 
         << " | Gold: " << c.gold << endl;
}


/*
======================================================
 PART 2 — Class Example (Encapsulation & Safety)
======================================================
*/

class Character
{
private:
    string name;
    int currentHP;
    int maxHP;
    int strength;
    int dexterity;
    int intelligence;
    int level;
    int experience;
    int gold;

    // Helper used internally
    void checkLevelUp()
    {
        int xpNeeded = level * 100;

        while (experi
