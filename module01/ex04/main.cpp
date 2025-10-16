#include <string>
//1
//2
#include <iostream>
#include <fstream>
#include <sstream>

void	createOutFile(std::string fileName, std::string content)
{
	if (content.empty())
		return ;
	std::ofstream file(fileName.c_str());
	file << content;
	file.close();
}

std::string	replaceS1(std::ifstream &file, std::string s1, std::string s2)
{
	size_t	found;
	std::string	tmp;
	size_t	pos = 0;

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();

	if (s1.empty())
	{
		return (content);
	}
	while (true) 
	{
		found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			tmp += content.substr(pos);
			break ;
		}
		tmp += content.substr(pos, found - pos);
		tmp += s2;
		pos = found + s1.length();
	}
	return (tmp);
}

int	main(int ac, char **av)
{

	std::string	fileName;


	if (ac != 4)
	{
		std::cout << "Error Please follow program usage\nUsage : <Filename> <S1> <S2>\n";
		return (0);
	}
	fileName = av[1];
	fileName += ".replace";
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cout << "Error faild to open file : " << fileName << std::endl;
		return (0);
	}
	createOutFile(fileName, replaceS1(file, av[2], av[3]));
	file.close();
	return (0);
}
