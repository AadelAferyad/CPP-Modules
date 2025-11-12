#include "ClapTrap.hpp"


#include <iostream>

int main() {
    std::cout << "===== Constructors =====" << std::endl;
    ClapTrap a;                // Default constructor
    ClapTrap b("Bender");      // Param constructor
    ClapTrap c = b;            // Copy constructor

    std::cout << "\n===== Attacks =====" << std::endl;
    b.attack("Enemy 1");
    b.attack("Enemy 2");

    std::cout << "\n===== Taking Damage =====" << std::endl;
    b.takeDamage(5);
    b.takeDamage(10);          // Should hit 0 or go below

    std::cout << "\n===== Repairs =====" << std::endl;
    b.beRepaired(3);
    b.beRepaired(10);

    std::cout << "\n===== Energy Depletion Test =====" << std::endl;
    ClapTrap c3("EnergyBot");
    for (int i = 0; i < 12; i++) {
        c3.attack("Target");
    }

    std::cout << "\n===== Copy Assignment =====" << std::endl;
    a = b;

    std::cout << "\n===== Destructors =====" << std::endl;
    return 0;
}
