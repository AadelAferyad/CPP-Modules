#pragma once
#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <climits>


typedef struct Node
{
	int	value;
	std::vector <int> in;

	Node() : value(0) {};
	Node(int n) : value(n) {};

	bool operator>(const Node &obj) const
	{return (value > obj.value);}
} node;

typedef struct compareAndCount{
  unsigned int &c;
  compareAndCount(unsigned int &c) : c(c) {}

  bool operator()(const node& a, const node& b) const {
    c++;
    return b > a;
  }
} compare;

class PmergeMe
{
	public:
		unsigned int	counter;
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
		template <typename T>
		void	sortVecotrContainer(T &data);
		template <typename T>
		void	sortDequeContainer(T &data);
		template <typename T>
		void	printer(T &data) const;
		template <typename T>
		void	createPaires(T &main, T &pend);
		template <typename T>
		void	sortRecurion(T &main);
		template <typename T>
		void	fordJhonson(T &main, T &pend);
		std::vector<int> insertionOrder(int size) const;
};
#include "PmergeMe.tpp"
