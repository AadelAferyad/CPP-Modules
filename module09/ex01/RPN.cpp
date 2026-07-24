#include "RPN.hpp"

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
RPN::RPN() :op('0'){};
RPN::RPN(const std::string &str)
{
	std::istringstream	s(str);
	std::string dumy;

	while (s >> dumy)
	{
		if (dumy == "+" || dumy == "-" || dumy == "/" || dumy == "*")
		{
			op = dumy[0];
			eval();
		}
		else if (dumy.size() != 1 || !std::isdigit(dumy[0]))
			throw std::runtime_error("Invalid argument");
		else
			container.push(dumy[0] - '0');
	}
	if (container.size() != 1)
		throw std::runtime_error("error");

}
int	RPN::getStack()const
{
	return (container.top());
}
RPN::RPN(const RPN &obj) : container(obj.container), op(obj.op){};
RPN &RPN::operator=(const RPN &obj) 
{
	if (this != &obj)
	{
		container = obj.container;
		op = obj.op;
	}
	return (*this);
}
RPN::~RPN() {};

int	calc(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		return (a / b);
	}
	return (0);
}

int	RPN::eval()
{
	int	resualt = 0;
	int	a = 0;
	int	b = 0;

	if (container.size() < 2)
		throw std::runtime_error("Error: not enough operands");
	a = container.top();
	container.pop();
	b = container.top();
	container.pop();
	resualt = calc(b, a, op);
	container.push(resualt);
	return (container.top());
}

std::ostream &operator<<(std::ostream &out, const RPN &obj)
{
	out << obj.getStack();
	return out;
}
