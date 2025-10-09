#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
	public:
		std::string GetFirstName();
		void SetFirstName(std::string name);

		std::string GetLastName();
		void SetLasttName(std::string LastName);

		std::string GetNickName();
		void SetNickName(std::string NickName);

		std::string GetPhoneNumber();
		void SetPhone(std::string phone);

		std::string GetSecret();
		void SetSecret(std::string secret);

};

#endif
