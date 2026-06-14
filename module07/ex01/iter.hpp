#ifndef __ITER__
#define __ITER__
template <typename T>
void	iter(T *arr, const unsigned int size, void (*f)(T &))
{
	if (!arr || !f)
		return ;
	for (unsigned int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	iter(T *arr, const unsigned int size, void (*f)(const T &))
{
	if (!arr || !f)
		return ;
	for (unsigned int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}
#endif
