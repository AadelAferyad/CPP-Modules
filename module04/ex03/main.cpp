#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{

    std::cout << "Subject Test " << std::endl;
    {
	    IMateriaSource* src = new MateriaSource();
	    src->learnMateria(new Ice());
	    src->learnMateria(new Cure());
	    ICharacter* me = new Character("me");
	    AMateria* tmp;
	    tmp = src->createMateria("ice");
	    me->equip(tmp);
	    tmp = src->createMateria("cure");
	    me->equip(tmp);
	    ICharacter* bob = new Character("bob");
	    me->use(0, *bob);
	    me->use(1, *bob);
	    delete bob;
	    delete me;
	    delete src;
    }
    /*std::cout << "General logic Test " << std::endl;*/
    /*{    */
    /*    size_t materias_count = 5;*/
    /*    AMateria *materias[materias_count];*/
    /*    MateriaSource *src = new MateriaSource();*/
    /**/
    /*    Ice *ice = new Ice();*/
    /*    Cure *cure = new Cure();*/
    /*    ICharacter *me = new Character("me");*/
    /*    ICharacter *bob = new Character("bob");*/
    /*    std::cout << "[ learning materias with src]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*    {*/
    /*        if (i % 2)*/
    /*            src->learnMateria(cure);*/
    /*        else*/
    /*            src->learnMateria(ice);*/
    /*    }*/
    /*    std::cout << "[ Creating materias with src]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*        materias[i] = src->createMateria(i % 2 == 0 ? "ice" : "cure");*/
    /**/
    /*    std::cout << "[ Using materias without equiping ]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*        bob->use(i, *me);*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*        me->use(i, *bob);*/
    /**/
    /*    std::cout << "[ equiping " << materias_count << " materias" << " ]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*    {*/
    /*        bob->equip(materias[i]);*/
    /*    }*/
    /**/
    /*    std::cout << "[ Using equipment from 0 to " << materias_count << " ]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*    {*/
    /*        bob->use(i, *me);*/
    /*    }*/
    /*    std::cout << "[ unequip from 0 to " << materias_count << " ]" << '\n';*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*    {*/
    /*        bob->unequip(i);*/
    /*    }*/
    /*    std::cout << "[Deleting materias] :\n";*/
    /*    for (size_t i = 0; i < materias_count; i++)*/
    /*        delete materias[i];*/
    /**/
    /*    delete bob;*/
    /*    delete me;*/
    /*    delete ice;*/
    /*    delete cure;*/
    /*    delete src;*/
    /*}*/
    return 0;
}
