// Unit Tests for RPG Battle Simulator

#include <iostream>
#include <cassert>
#include "../src/main.cpp"

void testCharacterCreation() {
    Player p("TestHero");
    Enemy e("Testgoblin", 80, 15, 5);

    assert(p.getName() == "TestHero");
    assert(e.getName() == "Testgoblin");
    std::cout << "✅ testCharacterCreation passed\n";
}

void testDamageCalculation() {
    Enemy e("Goblin", 50, 20, 5);
    Player p("Hero");

    int startingHP = 100;
    p.takeDamage(20); // Should be reduced by defense = 10, so 10 damage
    assert(p.isAlive());
    std::cout << "✅ testDamageCalculation passed\n";
}

void TestbattleoutCome() {
    Player p("Hero");
    Enemy e("WeakGoblin", 10, 1, 0);

    // Simulate battle (force player to attack)
    while (p.isAlive() && e.isAlive()) {
        e.takeDamage(p.getAttack());
    }

    assert(!e.isAlive());
    std::cout << "✅ testBattleOutcome passed\n";
}

int main() {
    std::cout << "Running tests...\n";
    testCharacterCreation();
    testDamageCalculation();
    TestbattleoutCome();
    std::cout << "All tests passed.\n";
    return 0;
}
