#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{

public:
	Array();
	Array(const unsigned int n);
	Array(Array const &src);
	~Array();

	Array &operator=(Array const &rhs);

	T &operator[](int index);
	const T &operator[](int index) const;

	unsigned int size() const;

	class IndexOutOfBounds : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Index is out of bounds !";
		}
	};

private:
	T *_array;
	unsigned int _size;
};


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {} // ? faire un New ici ?

template <typename T>
Array<T>::Array(const unsigned int n) : _size(n)
{
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	_size = src._size;
	_array = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
unsigned int Array<T>::size() const{
	return (_size);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */

#endif /* *********************************************************** ARRAY_H */