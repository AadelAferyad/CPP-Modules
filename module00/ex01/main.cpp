#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook phone;
	phone.add("addel", "dd", "sad", "231231", "dasdasdas");
	std::cout << phone.GetFirstName();
	return 0;
}
