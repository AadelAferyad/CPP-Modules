#include "Harl.hpp"


void	Harl::debug(void)
{
	std::cout << "[ DEBUG ] level: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ] level: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ] level: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ] level: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (; i < 4; i++)
		if (level == levels[i])
			break ;
	i++;
	switch (i){
		case 1:
			Harl::debug();
			break;
		case 2:
			Harl::info();
			break;
		case 3:
			Harl::warning();
			break;
		case 4:
			Harl::error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
			break;
	}

}
