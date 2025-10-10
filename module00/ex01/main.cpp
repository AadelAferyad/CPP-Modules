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

int	check_digits(std::string str)
{
	if (str.empty())
		return (0);
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << "This fields must be digit !\n\n";
			return (1);
		}
	}
	return (0);
}

int	is_empty(std::string str)
{
	bool	is_space = true;

	if (str.empty())
		return (1);
	for (int i = 0; str[i]; i++)
	{
		if (!isspace(str[i]))
			is_space = false;
	}
	return (is_space == true ? 1 : 0);
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
	std::cout << "\nLast name: ";
	lname = _read();
	std::cout << "\nNickname: ";
	nname = _read();
	std::cout << "\nPhone number: ";
	phonen = _read();
	if (check_digits(phonen))
		return ;
	std::cout << "\nDarkest secret: ";
	secret = _read();
	if (is_empty(name) || is_empty(lname) || is_empty(nname) || is_empty(phonen) || is_empty(secret))
	{
		std::cout << "Invalid phone contact, fields can't be empty\n\n";
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

void	display_search()
{

	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|\n";
}

void	SearchInPhoneBook(PhoneBook& phone)
{
	Contact cn;
	std::string	input;
	int	n;

	if (!phone.GetCounter())
		return ;
	display_search();
	for (int i = 0; i < phone.GetCounter() && i < 8; i++)
	{
		cn = phone.GetContacts(i);
		std::cout << std::right << std::setw(10) << i + 1 << "|";
		std::cout << std::right << std::setw(10) << truncate(cn.GetFirstName()) << "|";
		std::cout << std::right << std::setw(10) << truncate(cn.GetLastName()) << "|";
		std::cout << std::right << std::setw(10) << truncate(cn.GetNickName()) << "|";
		std::cout<< "\n";
	}
	std::cout << "Chose the contact index: ";
	input = _read();
	if (is_empty(input))
	{
		std::cout << "Contact index can't be empty!\n\n";
		return ;
	}
	if (check_digits(input))
		return ;
	n = std::stoi(input, NULL);
	if (!n || n >= 9 || n > phone.GetCounter())
		std::cout << "The index is out of range Please chose between 1 to 8\n\n";
	else
		display(phone, n - 1);
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
