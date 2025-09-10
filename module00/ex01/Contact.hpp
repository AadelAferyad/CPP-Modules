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
		static int contact_counter;
	public:
		std::string GetFirstName() {return this->first_name;}
		void SetFirstName(std::string name) {first_name = name;}
		std::string GetLastName() {return this->last_name;}
		void SetLasttName(std::string LastName) {last_name = LastName;}
		std::string GetNickName() {return this->nickname;}
		void SetNickName(std::string NickName) {nickname = NickName;}
		std::string GetPhoneNumber() {return this->phone_number;}
		void SetPhone(std::string phone) {phone_number = phone;}
		std::string GetSecret() {return this->secret;}
		void SetSecret(std::string secret) {secret = secret;}
		static int GetCounter() {return contact_counter;}
		Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), secret("") {}
		Contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string scrt) :
			first_name(fname), last_name(lname), nickname(nname), phone_number(phone), secret(scrt) {this->contact_counter++;}
		void	SetAll(std::string fname, std::string lname, std::string nname, std::string phone, std::string scrt)
		{
			first_name = fname;
			last_name = lname;
			nickname = nname;
			phone_number = phone;
			secret = scrt;
			this->contact_counter++;
		}
};

#endif
