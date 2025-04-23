// RPG Battle Simulator - Final Project
// Demonstrates: Classes/Inheritance, Pointers, Streams, Basic Sorting

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

class Character {
protected:
    string name;
    int health, attack, defense;

public:
    Character(string n, int hp, int atk, int def)
        : name(n), health(hp), attack(atk), defense(def) {}

    virtual void takeTurn(Character* target) = 0;

    void takeDamage(int dmg) {
        int damageTaken = max(0, dmg - defense);
        health -= damageTaken;
        cout << name << " takes " << damageTaken << " damage. Remaining HP: " << health << endl;
    }

    bool isAlive() const { return health > 0; }

    string getName() const { return name; }

    void printStats() const {
        cout << name << " | HP: " << health << " | ATK: " << attack << " | DEF: " << defense << endl;
    }

    int getAttack() const { return attack; }
};

class Player : public Character {
private:
    vector<string> inventory;

public:
    Player(string n) : Character(n, 100, 20, 10) {
        inventory = {"Potion", "Elixir"};
    }

    void takeTurn(Character* target) override {
        cout << "\n" << name << "'s Turn!\n";
        cout << "1. Attack\n2. Use Item\nChoose action: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 1;
        }

        if (choice == 2 && !inventory.empty()) {
            useItem();
        } else {
            cout << name << " attacks!\n";
            target->takeDamage(attack);
        }
    }

    void useItem() {
        cout << "Used a " << inventory.back() << "! Healed 20 HP.\n";
        health += 20;
        inventory.pop_back();
    }
};

class Enemy : public Character {
public:
    Enemy(string n, int hp, int atk, int def) : Character(n, hp, atk, def) {}

    void takeTurn(Character* target) override {
        cout << "\n" << name << " attacks!\n";
        target->takeDamage(attack);
    }
};

void battle(Player& player, Enemy& enemy) {
    ofstream log("battle_log.txt");
    while (player.isAlive() && enemy.isAlive()) {
        player.takeTurn(&enemy);
        log << player.getName() << " attacks " << enemy.getName() << "\n";

        if (!enemy.isAlive()) break;

        enemy.takeTurn(&player);
        log << enemy.getName() << " attacks " << player.getName() << "\n";
    }

    cout << "\nBattle Over!\n";
    if (player.isAlive()) cout << player.getName() << " wins!\n";
    else cout << enemy.getName() << " wins!\n";

    log.close();
}

int main() {
    Player p("Hero");
    Enemy e("Goblin", 80, 15, 5);

    cout << "Initial Stats:\n";
    p.printStats();
    e.printStats();

    battle(p, e);

    return 0;
}
