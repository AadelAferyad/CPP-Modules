#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	AddToPhonBook(PhoneBook& phone)
{
	std::string name;
	std::string lname;
	std::string nname;
	std::string phonen;
	std::string secret;

	std::cout << "Fill the next following information\nFirst name: ";
	std::cin >> name;

	std::cout << "\nLast name: ";
	std::cin >> lname;

	std::cout << "\nNickname: ";
	std::cin >> nname;

	std::cout << "\nPhone number: ";
	std::cin >> phonen;

	std::cout << "\nDarkest secret: ";
	std::cin >> secret;
	phone.SetContact(name, lname, nname, phonen, secret);
}

void	SearchInPhoneBook(PhoneBook& phone)
{
	Contact cn;
	int	i;
	i = 0;

	while (i < 8)
	{
		cn = phone.GetContacts(i);
		std::cout << "First name: " << cn.GetFirstName() << " | " << "Last name: "<<cn.GetLastName()<< " | "<< "Nickname: " << cn.GetNickName() << " | " <<"Phone number: "<<cn.GetPhoneNumber()<< " | " << "Darkest secrect: "<<cn.GetSecret();
		std::cout<< "\n";
		i++;
	}
}

int	main(void)
{
	std::string inputs;
	PhoneBook phone;

	
	while (1)
	{
		std::cin >> inputs;
		if (!inputs.compare("ADD"))
			AddToPhonBook(phone);
		else if (!inputs.compare("SEARCH"))
			SearchInPhoneBook(phone);
		else if (!inputs.compare("EXIT"))
			break ;
	}
	return 0;
}
