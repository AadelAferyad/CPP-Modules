#include "PhoneBook.hpp"
#include <iostream>

int PhoneBook::contact_counter = 0;

std::string Contact::GetFirstName()
{
	return (this->first_name);
}

void Contact::SetFirstName(std::string name)
{
	this->first_name = name;
}

std::string Contact::GetLastName()
{
	return (this->last_name);
}

void Contact::SetLasttName(std::string LastName)
{
	this->last_name = LastName;
}

std::string Contact::GetNickName()
{
	return (this->nickname);
}

void Contact::SetNickName(std::string NickName)
{
	this->nickname = NickName;
}

std::string Contact::GetPhoneNumber()
{
	return (this->phone_number);
}

void Contact::SetPhone(std::string phone)
{
	this->phone_number = phone;
}

std::string Contact::GetSecret()
{
	return (this->secret);
}
void Contact::SetSecret(std::string secret)
{
	this->secret = secret;
}

int	PhoneBook::GetCounter()
{
	return (contact_counter);
}

void	PhoneBook::IncCounter()
{
	this->contact_counter++;
}

Contact PhoneBook::GetContacts(int index)
{
	if (index >= 7)
		index = 7;
	return (this->contacts[index]);
}

void	PhoneBook::SetContact(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret)
{
	int	i;
	Contact cn;

	i = this->contact_counter % 8;
	this->contacts[i].SetFirstName(fname); 
	this->contacts[i].SetLasttName(lname); 
	this->contacts[i].SetNickName(nname); 
	this->contacts[i].SetPhone(phone); 
	this->contacts[i].SetSecret(secret); 
	this->contact_counter++;
}
