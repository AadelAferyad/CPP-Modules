#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <iostream>

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
		template <typename T>
		void	insertAll(T begin, T end)
		{
			int	count = std::distance(begin, end);
			if (count  < 0 || storage.size() + static_cast<unsigned int>(count) > capacity)
				throw (std::out_of_range("Range is out of bound !"));
			storage.insert(storage.end(), begin, end);
		}
		class	NoEnoughStorage: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
