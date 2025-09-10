#ifndef PHONBOOK_H
#define PHONBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook : public Contact
{
	private:
		Contact contacts[8]; 
	public:
		void add(std::string fname, std::string lname, std::string nickname, std::string phone, std::string scret)
		{

			if (GetCounter() >= 8)
				contacts[7].SetAll(fname, lname, nickname, phone, scret);
			else
				contacts[GetCounter()].SetAll(fname, lname, nickname, phone, scret);
		}
};

#endif
