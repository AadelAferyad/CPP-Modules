#ifndef PHONBOOK_H
#define PHONBOOK_H

#include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8]; 
		static int contact_counter;
	public:
		static int GetCounter();
		void	IncCounter();
		Contact GetContacts(int index);
		void SetContact(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret);
};

#endif
