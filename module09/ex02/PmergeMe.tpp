#ifndef PM
#define PM

template <typename T> void	PmergeMe::printer(T &data) const
{
	for (int i = 0; i < static_cast<int>(data.size()); i++)
		std::cout << data[i].value << " ";
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::createPaires(T &main, T&pend)
{
	T paired;

	for (size_t i = 0; i + 1 < main.size(); i += 2)
	{
		counter++;
		if (main[i].value > main[i + 1].value)
		{
			paired.push_back(main[i]);
			pend.push_back(main[i + 1]);
		}
		else
		{
			paired.push_back(main[i + 1]);
			pend.push_back(main[i]);
		}
	}

	if (main.size() % 2 != 0)
		pend.push_back(main.back());
	main = paired;
}
template <typename T> void	PmergeMe::sortRecurion(T &main)
{
	if (main.size() <= 1)
		return ;
	T pend;
	createPaires(main, pend);
	for (size_t i = 0; i < main.size(); ++i)
		main[i].in.push_back(i);
	for (size_t i = 0; i < pend.size(); ++i)
		pend[i].in.push_back(i);
	sortRecurion(main);
  	fordJhonson(main, pend);
}

template <typename T> void	PmergeMe::fordJhonson(T &main, T &pend)
{
	T	mainChain;
	T	collect;

	for (size_t i = 0; i < main.size(); ++i)
	{
		int index = main[i].in.back();
		collect.push_back(pend[index]);
	}
	if (main.size() < pend.size())
		collect.push_back(pend.back());
	mainChain.push_back(collect[0]);
	for (size_t i = 0; i < main.size(); ++i)
		mainChain.push_back(main[i]);

	std::vector<int> order = insertionOrder(collect.size() - 1);
	for (size_t i = 0; i < order.size(); i++)
	{
		int	k = order[i];
		if (k >= static_cast<int>(collect.size()))
			continue ;
		typename T::iterator it = mainChain.end();
		if (k < static_cast<int>(main.size()))
		{
			for (typename T::iterator itr = mainChain.begin(); itr != mainChain.end(); ++itr)
			{
				if (itr->value == main[k].value)
				{
					it = itr;
					break ;
				}
			}
		}
		compare comp(counter);
		typename T::iterator pos = std::lower_bound(mainChain.begin(), it, collect[k], comp);
		mainChain.insert(pos, collect[k]);
	}
	main = mainChain;
	for (size_t i = 0; i < main.size(); ++i)
	{
		if (!main[i].in.empty())
			main[i].in.pop_back();
	}
}


template <typename T>
void	PmergeMe::sortVecotrContainer(T &data)
{
	if (data.empty())
		return ;
	struct timeval start;
	struct timeval end;
	double	time;

	counter = 0;
	std::cout << "Before: ";
	printer(data);

	gettimeofday(&start, NULL);
	sortRecurion(data);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) *1000000.0  + (end.tv_usec - start.tv_usec);

	std::cout << "After: ";
	printer(data);
	std::cout << "Time to process a range of " << data.size() << " elements with std::vector : "<< time << " us" << std::endl;
}

template <typename T>
void	PmergeMe::sortDequeContainer(T &data)
{
	if (data.empty())
		return ;
	struct timeval start;
	struct timeval end;
	double	time;

	counter = 0;
	gettimeofday(&start, NULL);
	sortRecurion(data);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) *1000000.0  + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << data.size() << " elements with std::deque : "<< time << " us" << std::endl;
}
#endif
