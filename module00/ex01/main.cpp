#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

std::string	_read()
{
	std::string	buff;

	if (!std::getline(std::cin, buff))
		exit(1);
	if (buff.empty())
		return ("");
	return (buff);
}

void	AddToPhonBook(PhoneBook& phone)
{
	std::string name;
	std::string lname;
	std::string nname;
	std::string phonen;
	std::string secret;

	std::cout << "Fill the next following information\nFirst name: ";
	name = _read();
	if (name.empty())
	{
		std::cout << "No empty fields in contact\n\n"; 
		return ;
	}
	std::cout << "\nLast name: ";
	lname = _read();
	if (lname.empty())
	{
		std::cout << "No empty fields in contact\n\n"; 
		return ;
	}
	std::cout << "\nNickname: ";
	nname = _read();
	if (nname.empty())
	{
		std::cout << "No empty fields in contact\n\n"; 
		return ;
	}
	std::cout << "\nPhone number: ";
	phonen = _read();
	if (phonen.empty())
	{
		std::cout << "No empty fields in contact\n\n"; 
		return ;
	}
	std::cout << "\nDarkest secret: ";
	secret = _read();
	if (secret.empty())
	{
		std::cout << "No empty fields in contact\n\n"; 
		return ;
	}
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
	std::string	input;
	int	len;
	i = 0;

	std::cout << "Index" << std::setw(5) << " | " << "First Name" << " | " << "Last Name " << " | " << "Nickname  " << " | \n";
	while (i < phone.GetCounter() && i < 8)
	{
		cn = phone.GetContacts(i);
		std::cout << std::right << std::setw(5) << i + 1 << std::setw(5)<< " | ";
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
	input = _read();
	if (input.empty() || !isdigit(input[0]))
		return ;
	i = std::stoi(input, NULL);
	if (!i || i >= 9 || i > phone.GetCounter())
		std::cout << "The index is out of range Please chose between 1 to 8\n";
	else
		display(phone, i - 1);
}

int	main(void)
{
	std::string inputs;
	PhoneBook phone;

	while (1)
	{
		std::cout << "Chose from the following the instructions : ADD | SEARCH | EXIT\n";
		if (!std::getline(std::cin, inputs))
			break ;
		if (!inputs.compare("ADD"))
			AddToPhonBook(phone);
		else if (!inputs.compare("SEARCH"))
			SearchInPhoneBook(phone);
		else if (!inputs.compare("EXIT"))
			break ;
	}
	return 0;
}
