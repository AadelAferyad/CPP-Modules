#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n===== Creating Diamond A =====\n";
    DiamondTrap A("Alpha");

    std::cout << "\n===== Testing basic identity =====\n";
    A.whoAmI();                     // Should print both DiamondTrap name and ClapTrap name

    /*std::cout << "\n===== Testing inherited attributes =====\n";*/
    /*std::cout << "Hit: " << A.getHit() << "\n";*/
    /*std::cout << "Energy: " << A.getEnergy() << "\n";*/
    /*std::cout << "Attack Damage: " << A.getDamage() << "\n";*/

    std::cout << "\n===== Testing ScavTrap attack =====\n";
    A.attack("TestDummy");

    std::cout << "\n===== Testing FragTrap special ability =====\n";
    A.highFivesGuys();

    std::cout << "\n===== Testing ScavTrap special ability =====\n";
    A.guardGate();

    std::cout << "\n===== Creating Diamond B by copy constructor =====\n";
    DiamondTrap B(A);

    std::cout << "\n===== B identity =====\n";
    B.whoAmI();

    std::cout << "\n===== Creating Diamond C and assigning B to C =====\n";
    DiamondTrap C;
    C = B;

    std::cout << "\n===== C identity after assignment =====\n";
    C.whoAmI();

    std::cout << "\n===== Attacking with C =====\n";
    C.attack("SpareDummy");

    std::cout << "\n===== End of program, destructors should fire in reverse order =====\n";
}

