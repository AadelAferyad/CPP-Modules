#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : counter(0){};
PmergeMe::PmergeMe(const PmergeMe &obj){ *this = obj;};
PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void) obj;
	return *this;
}
PmergeMe::~PmergeMe() {};

std::vector<int> PmergeMe::insertionOrder(int size) const
{
	std::vector<int> order;
	int	prev = 1;
	int	curr = 3;
	int	last = 0;

	if (size <= 0)
		return (order);
	while (last < size)
	{
		int max;
		if (curr > size)
			max = size;
		else
			max = curr;
		for (int i = max; i > last; --i)
			order.push_back(i);
		last = max;
		int next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return (order);
}

