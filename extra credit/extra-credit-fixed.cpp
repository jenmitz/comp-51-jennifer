#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character {
    public:
        string name;
        string race;
        string sex;
        string characterClass;
        int classChoice;
        int health;
        int level;
        int xp;
        int nextLevel;
        int totalHealth;
        int maxHealth;
        int strength;
        int intelligence;
        int agility;
    
        // Constructor to initialize default values
        Character() {
            level = 1;
            xp = 0;
            nextLevel = 76;
        }
    
        // Method to set race and health
        void setRace(string raceChoice) {
            transform(raceChoice.begin(), raceChoice.end(), raceChoice.begin(), ::tolower);
            race = raceChoice;
    
            if (race == "elf") {
                health = 90;
            } else if (race == "dwarf") {
                health = 110;
            } else if (race == "human") {
                health = 80;
            } else {
                health = 100;
                cout << "Unknown race entered. Default health assigned.\n";
            }
    
            totalHealth = health;
            maxHealth = totalHealth;
        }
    
        void setClass(int choice) {
            classChoice = choice;
            switch (choice) {
                case 1:
                    characterClass = "Warrior";
                    strength = 7;
                    intelligence = 2;
                    agility = 3;
                    break;
                case 2:
                    characterClass = "Mage";
                    strength = 2;
                    intelligence = 7;
                    agility = 3;
                    break;
                case 3:
                    characterClass = "Rogue";
                    strength = 3;
                    intelligence = 2;
                    agility = 7;
                    break;
                default:
                    characterClass = "Adventurer";
                    strength = 4;
                    intelligence = 4;
                    agility = 4;
                    cout << "Unknown class entered. Defaulting to Adventurer.\n";
                    break;
            }
        }
    
        // Method to display character info
        void displayCharacterInfo() {
            cout << "\nCharacter Info:\n";
            cout << "Name: " << name << "\n";
            cout << "Race: " << race << "\n";
            cout << "Sex: " << sex << "\n";
            cout << "Health: " << health << "\n";
            cout << "Level: " << level << "\n";
        }

};

void HUD(Character &character);
void Combat(Character &character);
void CombatHUD(Character &character);
void Moving();
void CreateMonster(Character &character);
void LevelUp(Character &character);
void DragonCombat(Character &character);
void InnkeeperInteraction(Character &character);
void CharacterCreation(Character &character);

int heal = 0, potionCount = 0, playerAttackPower = 0;
int monsterHp = 0, monsterXp = 0, monsterLevel = 0, monsterHealth = 0, monsterAttackPower = 0;
int forwardMoveCount = 0, counter = 0;
int currentMonsterNames = 5;
string monsterName[] = { "Goblin", "Orc", "Ogre", "Hag", "Scamp" };
string currentMonster = " ";

int main() {
    Character player;
    cout << "Welcome to the game!" << endl;
    CharacterCreation(player);   
    InnkeeperInteraction(player);
}

// Function for character creation
void CharacterCreation(Character &character) {
    srand(time(0)); // Seed random generator

    // Basic Info
    cout << "Enter your character's name: ";
    getline(cin, character.name);

    cout << "Enter your character's sex: ";
    cin >> character.sex;

    // Race selection
    cout << "\nCharacter race choices:\n";
    cout << "1. Elf\n2. Dwarf\n3. Human\n> ";
    string raceChoice;
    cin >> raceChoice;
    character.setRace(raceChoice); // Set the race and health

    // Class selection
    cout << "\nChoose a class:\n1. Warrior\n2. Mage\n3. Rogue\n> ";
    int classChoice;
    cin >> classChoice;
    cin.ignore(); // Clear newline from input buffer
    character.setClass(classChoice); // Set the class

    // Character polish
    for (int i = 0; i < 3; i++) {
        cout << "Creating character" << string(i + 1, '.') << "\n";
    }

    // Capitalize the first letter of each property
    character.name[0] = toupper(character.name[0]);
    character.race[0] = toupper(character.race[0]);
    character.sex[0] = toupper(character.sex[0]);

    // Final welcome message
    cout << "\nWelcome, " << character.name << " the " << character.characterClass;
    cout << " (" << character.race << ", " << character.sex << ")\n";

    // Display character info
    character.displayCharacterInfo();

}

// Innkeeper interaction to begin the quest
void InnkeeperInteraction(Character &character) {
    string playerChoice;

    cout << "You are an experienced adventurer looking for your next quest." << endl;
    cout << "You enter a local inn and spot a quest board covered with various requests." << endl;
    cout << "One particular quest catches your eye: 'Brave hero needed to slay a Dragon. Will reward handsomely.'" << endl;
    cout << "You rip the paper from the board and head to the location marked on it." << endl << endl;
    cout << "The paper leads you to a tavern in a different part of town." << endl;
    cout << "You walk inside and approach the barkeep for more details." << endl << endl;
    cout << "The barkeep looks at you with a knowing look and says, 'Ah, you must be here about the dragon. Terrible thing, that.'" << endl;
    cout << "The barkeep sighs heavily. 'A few other adventurers have gone to slay the damn thing, but... they haven't returned.'" << endl;
    cout << "'Maybe you'll have more luck? Here.'" << endl << endl;
    cout << "He slides a glistening, glowing red potion across the bar towards you. 'I believe this'll help you some.'" << endl;
    cout << "You receive a Health Potion. This should help you on your journey." << endl << endl;

    // Give the player a potion
    potionCount = 1;

    cout << "What will you do next?" << endl;
    cout << "1. Ask for more details about the dragon quest.\n";
    cout << "2. Leave the tavern and begin the journey.\n";
    cin >> playerChoice;

    if (playerChoice == "1") {
        cout << "The barkeep continues, 'The dragon has been terrorizing this region for weeks. It's a very dangerous beast.'\n";
        cout << "'If you manage to kill the thing, bring me proof of your victory and I'll get you the 5,000 gold we've pooled together.'\n";
        cout << "You nod, and decide that the quest sounds perilous, but worth the reward. You leave the tavern to prepare for the journey.\n";
    } else if (playerChoice == "2") {
        cout << "You leave the tavern and begin the journey toward the dragon's lair.\n";
    } else {
        cout << "Invalid choice! The barkeep just stares at you, waiting for you to decide.\n";
    }
}

// Ask player to play again
bool PlayAgain() {
    int choice;
    cout << "\nWould you like to play again? (1 = Yes, 2 = No): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nRestarting game...\n\n";
        return true;
    } else {
        cout << "\nThanks for playing!\n";
        exit(0); // Exit the program completely
    }

    return false; // fallback (shouldn’t ever be reached)
}

// Display HUD
void HUD(Character &character) {
    cout << "Name: " << character.name << "      Health: " << character.totalHealth << "\nRace: " << character.race << "\nSex: " << character.sex << "\nClass: " << character.classChoice << "\nLevel: " << character.level << "\nXP: " << character.xp << ".\nXP to Level: " << character.nextLevel << endl;
}

// Display combat HUD
void CombatHUD(Character &character) {
    cout << "Name: " << character.name << "   |   Monster Name: " << currentMonster << "\nHealth: " << character.totalHealth << "   |   Monster Health: " << monsterHp << "\nLevel: " << character.level << "    |    Monster Level: " << monsterLevel << endl;
}

// Function for combat
void Combat(Character &character) {
    while (character.totalHealth > 0 && monsterHp > 0) {
        CombatHUD(character);
        int playerAttack;
        int playerDamage = 8 * character.level / 2;
        int monsterAttack = 6 * monsterLevel / 2;

        if (character.totalHealth >= 1 && monsterHp >= 1) {
            cout << "\n1. Attack.\n2. Block.\n3. RUN!\n\n";
            cin >> playerAttack;

            switch (playerAttack) {
                case 1:
                    cout << "Attacking... you did " << playerDamage << " damage to the " << currentMonster << endl;
                    monsterHp -= playerDamage;
                    CombatHUD(character);
                    if (monsterHp > 0) {
                        cout << "\nMonster is attacking...\n";
                        character.totalHealth -= monsterAttack;
                        cout << "You suffered " << monsterAttack << " damage. Your HP is now " << character.totalHealth << "." << endl;
                        if (character.totalHealth <= 0) {
                            cout << "You died!\nYou were level " << character.level << ". You got killed by " << currentMonster << "." << endl;
                            exit(0);
                        }
                    } else {
                        monsterHp = 0;
                        cout << "\nYou defeated " << currentMonster << ". You are rewarded with " << monsterXp << " XP.\nWell done!\n";
                        LevelUp(character);
                        HUD(character);
                        return;
                    }
                    break;
                case 2:
                    cout << "Blocking.\n";
                    if (rand() % 100 + 1 >= 50) {
                        cout << "You blocked the incoming attack.\n";
                        heal = character.level * 10 / 2;
                        character.totalHealth += heal;
                        cout << "You have healed for " << heal << " HP.\n";
                    } else {
                        cout << "You failed to block the attack.\n";
                        character.totalHealth -= monsterAttack;
                        cout << "You were hit for " << monsterAttack << " HP. Current HP: " << character.totalHealth << ".\n";
                    }
                    break;
                case 3:
                    cout << "You try to run.\n";
                    if (rand() % 100 + 1 >= 50) {
                        cout << "You run away.\n";
                        HUD(character);
                        return;
                    } else {
                        cout << "You failed to run away.\nMonster takes an attack on you!\n";
                        character.totalHealth -= (monsterAttack + 10);
                        cout << "You suffered " << (monsterAttack + 10) << ". Your current health is: " << character.totalHealth << ".\n";
                    }
                    break;
                default:
                    cout << "Invalid number.\n";
                    return;
            }
        }
        if (character.totalHealth <= 0) {
            cout << "You died!\nYou were level " << character.level << ". You got killed by " << currentMonster << ".\n";
            exit(0);
        } else if (monsterHp <= 0) {
            LevelUp(character);
            HUD(character);
        } else {
            Combat(character);
        }
    }
}

// Move forward or rest
void Moving(Character &character) {
    int choice;
    cout << "\n\n1. Move forward.\n2. Relax.\n3. Move backwards.\n\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "You begin moving forward...\n";
            forwardMoveCount++;
        
            if (forwardMoveCount == 6) {
                cout << "You've reached the dragon's lair.'\n";
                DragonCombat(character); // Call the boss fight
                return;
            }
        
            if (rand() % 100 + 1 >= 50) {
                CreateMonster(character);
                currentMonster = monsterName[rand() % currentMonsterNames];
                cout << "A " << currentMonster << " attacks you! Prepare to fight!\n";
                Combat(character);
            } else {
                cout << "You find nothing of interest.\n";
                HUD(character);
            }
            break;
        }
        case 3: {
            cout << (choice == 1 ? "You begin moving forward...\n" : "You begin moving backwards...\n");
            if (rand() % 100 + 1 >= 50) {
                CreateMonster(character);
                currentMonster = monsterName[rand() % currentMonsterNames];
                cout << "A " << currentMonster << " attacks you! Prepare to fight!\n";
                Combat(character);
            } else {
                cout << "You find nothing of interest.\n";
                HUD(character);
            }
            break;
        }
        case 2:
            cout << "You want to set up camp for the evening.\n";
            if (character.totalHealth < character.maxHealth) {
                int recovery = 10 * character.level;
                character.totalHealth = min(character.totalHealth + recovery, character.maxHealth);
                cout << "You healed by resting. Health is now " << character.totalHealth << ".\n";
            } else {
                cout << "You are already at full health.\n";
            }
            HUD(character);
            break;
        default:
            cout << "Invalid number.\n";
            Moving(character);
            break;
    }
}

// Level up when certain conditions are met
void LevelUp(Character &character) {
    character.xp += monsterXp;
    if (character.xp >= character.nextLevel) {
        character.level++;
        character.nextLevel = character.nextLevel * 3 / 2;
        character.maxHealth += 20;
        character.totalHealth = character.maxHealth;
        cout << "You level up! You are now level " << character.level << ".\nYour total health increased by 20 points. Max health is now " << character.totalHealth << " HP.\n";
    }
}

// Create a random monster to fight
void CreateMonster(Character &character) {
    monsterHp = 30 + (rand() % 20);
    monsterLevel = (rand() % 3) + character.level;
    monsterXp = monsterHp;

    if (monsterHp <= 0) {
        CreateMonster(character);
    }
}

// Dragon combat function for final boss
void DragonCombat(Character &character) {

    // Reset move count so this boss battle doesn't happen again
    forwardMoveCount = -1;

    int playerChoice;
    cout << "\nAs you venture further inside the damp cave, you can hear the dragon's breathing." << endl;
    cout << "You approach the sound, and find the dragon sitting on a massive pile of gold. It sees you immediately!" << endl;
    cout << "The dragon roars, and you can see smoke coming from its nostrils. You unsheath your sword and prepare to fight." << endl;
    cout << "You must defeat the dragon to to complete your quest... or die trying. It's too late to turn back now!" << endl;

    // Dragon's stats
    monsterHealth = 100;  // Dragon is a tough enemy
    monsterAttackPower = 15;

    while (monsterHealth > 0 && character.totalHealth > 0) {
        // Player's turn
        cout << "\nYour Health: " << character.totalHealth << " | Dragon's Health: " << monsterHealth << endl;
        cout << "1. Attack\n2. Use Potion\n";
        cin >> playerChoice;

        if (playerChoice == 1) {
            // Player attacks
            int attack = rand() % playerAttackPower + 5;  // Dragon requires higher damage to defeat
            cout << "You strike the Dragon for " << attack << " damage!" << endl;
            monsterHealth -= attack;

            if (monsterHealth <= 0) {
                cout << "You have defeated the Dragon!" << endl;
                cout << "You have slain the dragon and claimed victory!\n";
                cout << "The land is safe once more...\n";
                PlayAgain();
            }
        } else if (playerChoice == 2 && potionCount > 0) {
            // Use health potion
            cout << "You use a health potion and heal 20 HP!" << endl;
            character.totalHealth += 20;
            potionCount--;
            if (potionCount == 0) {
                cout << "You have no more potions left!" << endl;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }

        // Dragon's turn
        if (monsterHealth > 0) {
            int dragonAttack = rand() % 15 + 5;
            cout << "The Dragon attacks you for " << dragonAttack << " damage!" << endl;
            character.totalHealth -= dragonAttack;

            if (character.totalHealth <= 0) {
                cout << "The dragon has defeated you...\n";
                PlayAgain();
                return;
            }
        }
    }

    if (character.totalHealth <= 0) {
        cout << "Game Over!" << endl;
        exit(0);
    }
}

