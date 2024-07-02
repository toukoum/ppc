#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _n(0)
{
}

Span::Span(const unsigned int &N) : _n(N), _size(0)
{
}

Span::Span(const Span &src) : _n(src._n), _numbers(src._numbers), _size(src._size)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_numbers = rhs._numbers;
		this->_size = rhs._size;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Span::addNumber(int n)
{
	if (_numbers.size() >= _n)
		throw NumbersFull();
	_numbers.insert(n);
	_size++;
}

int Span::shortestSpan() const
{
	if (_size <= 1)
		throw DistanceImpossible();
	int shortest = *_numbers.rbegin();

	std::multiset<int>::iterator itr;
	for (itr = _numbers.begin(); std::next(itr) != _numbers.end(); ++itr)
	{
		if (shortest == 0)
			return (shortest);
		else if (*std::next(itr) - *itr < shortest)
			shortest = *std::next(itr) - *itr;
	}
	return (shortest);
}

int Span::longestSpan() const
{
	if (_size <= 1)
		throw DistanceImpossible();

	return (*(_numbers.rbegin()) - *(_numbers.begin()));
}

void Span::display() const
{
	std::multiset<int>::iterator itr;
	
	std::cout << std::endl;
	for (itr = _numbers.begin(); itr != _numbers.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getN() const
{
	return _n;
}

/* ************************************************************************** */