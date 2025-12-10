#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "===== Constructors =====" << std::endl;
    ClapTrap s0;
    ScavTrap s1("Guardian");
    ScavTrap s2(s1);          // Copy constructor
    ScavTrap s3;              // Default constructor
    s3 = s1;                  // Assignment

    std::cout << "\n===== Basic Actions =====" << std::endl;
    s1.attack("Intruder");
    s1.takeDamage(20);
    s1.beRepaired(10);
    s0.attack("this");

    std::cout << "\n===== Gate Keeper Mode =====" << std::endl;
    s1.guardGate();
    std::cout << "\n===== Energy Test =====" << std::endl;
    for (int i = 0; i < 55; i++) {
        s1.attack("Target");
    }

    std::cout << "\n===== Destructors =====" << std::endl;
    return 0;
}
