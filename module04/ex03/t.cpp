#include <iostream>

class A
{
	public:
		virtual void	f() = 0;
};

class B: public A
{
	public:
		void	f() {std::cout << "B" << std::endl;};
};

int	main()
{
	A a = B();
	a.f();
	return (0);
}
