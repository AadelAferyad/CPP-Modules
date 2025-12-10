#include <iostream>

class Test
{
	private:
		int	*age;
	public:
		Test(int a)
		{
			std::cout << "defualt constructor called" << std::endl;
			this->age = new int;
			*this->age = a;
		};
		Test	&operator=(const Test &rhs)
		{
			std::cout << "copy assignment operator called" << std::endl;
			delete this->age;
			this->age = new int(*rhs.age);
			return *this;
		}
		void	get_age() {std::cout << "add: " << this->age << " age: " << *this->age << std::endl;}
		~Test()
		{
			std::cout << "object has ben freed" << std::endl;
			delete this->age;
		}
};

int	main(void)
{
	Test	a(2);
	Test	b(10);
	a.get_age();	
	b.get_age();
	b = a;
	b.get_age();
	a = a;
	a.get_age();	
	return (0);
}
