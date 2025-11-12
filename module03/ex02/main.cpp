#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Constructors =====" << std::endl;
    ClapTrap clap("Clappy");
    FragTrap frag("Fragger");
    FragTrap copyFrag(frag);  // Copy constructor
    FragTrap assignFrag("Temp");
    assignFrag = frag;        // Copy assignment operator

    std::cout << std::endl << "===== Basic Actions =====" << std::endl;
    frag.attack("Enemy");
    clap.takeDamage(30);
    clap.beRepaired(20);

    std::cout << std::endl << "===== Special Ability =====" << std::endl;
    frag.highFivesGuys();

    std::cout << std::endl << "===== Damage and Repair Test =====" << std::endl;
    frag.takeDamage(50);
    frag.beRepaired(40);
    frag.takeDamage(120); // Should drop HP to 0
    frag.beRepaired(10);  // Should fail because HP = 0

    std::cout << std::endl << "===== Energy Depletion Test =====" << std::endl;
    for (int i = 0; i < 105; ++i)
        frag.attack("Target");

    std::cout << std::endl << "===== Destructors =====" << std::endl;
    return 0;
}
