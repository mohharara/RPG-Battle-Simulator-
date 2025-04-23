# RPG-Battle-Simulator-

A simple turn-based combat simulator written in C++. Built for a Computer Science II final project.

## 🕹️ What It Does

- Lets a player and an enemy take turns in battle.
- Each has HP, attack, and defense stats.
- The player can attack or use healing items.
- The enemy always attacks.
- A battle log is written to a file (`battle_log.txt`).

## 🧠 Concepts Used

- **Classes and Inheritance** (`Character`, `Player`, `Enemy`)
- **Pointers** (targets passed using pointers during turns)
- **Streams** (file I/O for battle logs)
- **Sorting** (item list sorted)

## 🧪 How to Compile & Run

```bash
g++ -std=c++17 -o battle src/main.cpp
./battle
