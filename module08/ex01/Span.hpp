#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

class Span
{
	private:
		std::vector<int> storage;
		unsigned int	capacity;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		~Span();
		void	addNumber(const int n);
		int	shortestSpan(void);
		int	longestSpan(void);
		class	NoEnoughStorage: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
