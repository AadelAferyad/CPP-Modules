#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

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

std::string	truncate(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	display(PhoneBook& phone, int i)
{
	Contact	cn;

	cn = phone.GetContacts(i);
	std::cout << "First Name: " << cn.GetFirstName() << "\n";
	std::cout << "Last Name : " << cn.GetLastName() << "\n";
	std::cout << "NickName  : " << cn.GetNickName() << "\n";
	std::cout << "Phone     : " << cn.GetPhoneNumber() << "\n";
	std::cout << "Secret    : " << cn.GetSecret() << "\n";
}

void	SearchInPhoneBook(PhoneBook& phone)
{
	Contact cn;
	int	i;
	int	len;
	i = 0;

	std::cout << "Index" << std::setw(5) << " | " << "First Name" << " | " << "Last Name " << " | " << " Nickname " << " | \n";
	while (i < phone.GetCounter())
	{
		cn = phone.GetContacts(i);
		std::cout << std::setw(5) << i + 1 << std::setw(5)<< " | ";
		len = 13 - cn.GetFirstName().length();
		std::cout << truncate(cn.GetFirstName()) << std::setw(len < 0 ? 0 : len) << " | ";
		len = 13 - cn.GetLastName().length();
		std::cout << truncate(cn.GetLastName()) << std::setw(len < 0 ? 0 : len) << " | ";
		len = 13 - cn.GetNickName().length();
		std::cout << truncate(cn.GetNickName()) << std::setw(len < 0 ? 0 : len) << " | ";
		std::cout<< "\n";
		i++;
	}
	std::cout << "Chose the contact index: ";
	std::cin >> i;
	if (i >= 9 || i > phone.GetCounter())
		std::cout << "The index is out of range Please chose between 1 to 8";
	else
		display(phone, i - 1);
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
