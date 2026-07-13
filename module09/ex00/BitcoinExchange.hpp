#pragma once

#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

class Btc
{
	private:
		std::map<std::string, float> in;
	public:
		Btc();
		Btc(const Btc &obj);
		Btc &operator=(const Btc &obj);
		~Btc();
		void	loadDataBase();
		void	loadInpute(char *filename);
		const std::map<std::string, float> &getMap() const;
};

std::ostream	&operator<<(std::ostream &out, const Btc &obj);
