#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
using namespace std;

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();
void LevelUp();

string name = " ", race = " ", sex = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;
int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

string monsterName[] = { "Goblin", "Dwarf", "Ogre", "Witch", "Wizard" };
int currentMonsterNames = 5;
string currentMonster = " ";

int counter = 0;
string playerRace[] = { "Elf", "Dwarf", "Firelord", "Goblin", "Human" };

int main() {

    level = 1;
    xp = 0;
    nextLevel = 76;

    // basic character creation
    cout << "Enter your character's name: ";
    cin >> name;

    cout << "Character race choices:\n";
    cout << "Elf\n";
    cout << "Dwarf\n";
    cout << "Firelord\n";
    cout << "Goblin\n";
    cout << "Human\n";
    cout << "Type your character's race below. \n\n";
    cin >> race;

    for_each(race.begin(), race.end(), [](char & c) {
        c = ::tolower(c);
    });

    for (int i = 0; i <sizeof(playerRace); i++) {
        if (race == "Elf") {
            health = 80;
            break;
        }
        if (race == "Drawf") {
            health = 120;
            break;
        }
        if (race == "Firelord") {
            health = 150;
            break;
        }
        if (race == "Goblin") {
            health = 82;
            break;
        }
        if (race == "Human") {
            health = 68;
            break;
        }
        else {
            health = 100;
            break;
        }
    }

    cout << "\n";
    cout << "Enter your character's sex: ";
    cin >> sex;

    // creation
    for (int i = 0; i < counter; i++) {
        if (counter == 0) {
            cout << "Creating character.\n";
        }
        if (counter == 1) {
            cout << "Creating character..\n";
        }
        if(counter == 2) {
            cout << "Creating character...\n";
            break;
        }
        counter++;
    }

    name[0] = toupper(name[0]);
    race[0] = toupper(race[0]);
    sex[0] = toupper(sex[0]);

    totalHealth = health;
    maxHealth = totalHealth;
 
    HUD();
    Moving();

    return 0;

}

void HUD() {
    cout << "Name: " <<  name << "      Health: " << totalHealth << "\nRace: " << race << "\nSex: " << sex << "\nLevel: " << level << "\nXP: " << xp << "." << "\nXP to Level: " << nextLevel << endl;
    Moving();
}

void CombatHUD() {
    cout << "Name: " << name << "   |   Monster Name: " << currentMonster << "\nHealth: " << totalHealth << "   |   Monster Health: " << monsterHp << "\nLevel: " << level << "    |    Monster Level: " << monsterLevel << endl;
}

void Combat() {

    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * level / 2;
    int monsterAttack = 6 * monsterLevel / 2;
    
    if (totalHealth >= 1 && monsterHp >= 1) {
        cout << "\n";
        cout << "1. Attack.\n";
        cout << "2. Block.\n";
        cout << "3. RUN!\n";
        cout << "\n";
        cin >> playerAttack;

        if (playerAttack == 1) {
            // attack
            cout << "Attacking... you did " << playerDamage << " damage to the " << currentMonster << endl;
            monsterHp = monsterHp - playerDamage;
            CombatHUD();
            if (monsterHp >= 1) {
                cout << "\n";
                cout << "Monster is attacking...\n";
                totalHealth = totalHealth - monsterAttack;
                cout << "You suffered " << monsterAttack << " damage. Your HP is now " << totalHealth << "." << endl;
                // change to function
                if (totalHealth <= 0) {
                    totalHealth = 0;
                    cout << "You died!\n You were level " << level << "." << " You got killed by " << currentMonster << "." << endl;
                    exit(0);
                }
            } else if (monsterHp <= 0) {
                monsterHp = 0;
                LevelUp();
                cout << "\n";
                cout << "You defeated " << currentMonster <<". You are rewarded with " << monsterXp << " XP.\n Well done!\n";
                HUD(); 

            }
            Combat();
        } else if (playerAttack == 2) {
            // block
            cout << "Blocking.\n";
            int i = rand() % 100 + 1;
            if (i >= 50) {
                cout << "You blocked the incoming attack.\n";
                heal = level * 10 / 2;
                cout << "You have healed for " << heal << " HP." << endl;
                totalHealth += heal;
                Combat();
            } else {
                cout << "You failed to block the attack.\n";
                totalHealth -= monsterAttack;
                cout << "You were hit for " << monsterAttack << " HP. Current HP: " << totalHealth << "." << endl; 
                Combat();
            }

        } else if (playerAttack == 3) {
            // run 
            cout << "You try to run.\n";
            int x = rand() % 100 + 1;
            if (x >= 50) {
                cout << "You run away.\n";
                HUD();
            } else {
                cout << "You failed to run away.\n";
                cout << "Monster takes an attack on you!\n";
                totalHealth -= monsterAttack + 10;
                cout << "You suffered " << monsterAttack + 10 << ". Your current health is: " << totalHealth << "." << endl;
                Combat();
            }
        } else {
            cout << "Invalid number.\n";
            Moving();
            Combat();
        }
    }

    if (totalHealth <= 1) {
        cout << "You died!\n";
        cout << "You were level " << level << ". You got killed by " << currentMonster << "." << endl;
        exit(0);
    }

    if (monsterHp <= 1) {
        HUD();
        LevelUp();
        cout << "\n";
        cout << "You defeeated " << currentMonster << ". You are rewarded with " << monsterXp << " XP. \nWell done!\n";
    }
} 

void Moving () {

    int choice;

    cout << "\n\n";
    cout << "1. Move forward.\n";
    cout << "2. Relax.\n";
    cout << "3. Move backwards.\n";
    cout << "\n";

    cin >> choice;

    if (choice == 1) {
        int temp = rand() % 100 + 1;
        cout << "You begin moving forward...\n";
        if (temp >= 50) {
            // Encounter a monster
            CreateMonster();
            string tempName = monsterName[rand() % currentMonsterNames];
            cout << "A " << tempName << " attacks you! Prepare to fight!\n";
            currentMonster = tempName;
            Combat();
        }
        cout << "You find nothing of interest.\n";
        HUD();
    } else if (choice == 2) {
        cout << "You want to set up camp for the evening.\n";
        if (totalHealth <= 99) {
            totalHealth += 10 * level;
        }
        cout << "You healed by resting. Health is now "  << totalHealth << "." << endl;
        HUD();
    } else if (choice == 3) {
        int temp = rand() % 100 + 1;
        cout << "You begin moving backwards...\n";
        if (temp >= 50) {
            // Encounter a monster
            CreateMonster();
            string tempName = monsterName[rand() % currentMonsterNames];
            cout << "A " << tempName << " attacks you! Prepare to fight!\n";
            currentMonster = tempName;
            Combat();
        }
        cout << "You find nothing of interest.\n";
        HUD();
    } else {
        cout << "Invalid number.\n";
        Moving();
    }

}

void LevelUp() {

    xp = xp + monsterXp;

    if (xp >= nextLevel) {
        level++;
        nextLevel = nextLevel * 3 / 2;
        totalHealth = totalHealth + 20;
        maxHealth = totalHealth;
        cout << "You level up! You are now level " << level << "." << endl;
        cout << "Your total health increased by 20 points. Max health is now " << totalHealth << " HP." << endl;
        HUD();
    }

}

void CreateMonster() {

    monsterHp = 30;

    monsterLevel = (rand() % 3) + level;
    monsterXp = (rand() % 30) * monsterLevel;

    monsterXp = monsterHp;

    if (monsterHp == 0) {
        CreateMonster();
    }

    if (monsterLevel == 0) {
        CreateMonster();
    }

}