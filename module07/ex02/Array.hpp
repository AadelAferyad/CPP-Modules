#ifndef __ARRAY__
#define __ARRAY__

#include <stdexcept>
#include <cstdlib>
template <typename T>

class Array
{
	private:
		T *arr;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		Array& operator=(const Array &obj);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		~Array();
		unsigned int size();
};

template <typename T>
Array<T>::Array(): arr(0), _size(0){};
template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]), _size(n){};
template <typename T>
Array<T>::Array(const Array &obj)
{
	arr = new T[obj._size];
	_size = obj._size;
	for (unsigned int i = 0; i < _size; i++)
		arr[i] = obj.arr[i];
};
template <typename T>
Array<T>& Array<T>::operator=(const Array &obj)
{
	if (this != &obj)
	{
		delete [] arr;
		arr = new T[obj._size];
		_size = obj._size;
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = obj.arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::out_of_range("Index out of range"));
	return (arr[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)	
		throw (std::out_of_range("Index out of range"));
	return (arr[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
}
template <typename T>
unsigned int Array<T>::size()
{
	return (_size);
}

#endif
