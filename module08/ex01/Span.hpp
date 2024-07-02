#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <set>
#include <stdexcept>
#include <cstdlib> 
#include <time.h> 

class Span
{

public:
	Span();
	Span(const unsigned int &N);
	Span(Span const &src);
	~Span();

	Span &operator=(Span const &rhs);

	void addNumber(int n);

	class NumbersFull : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The array is full !";
		}
	};

	class DistanceImpossible : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The array contain not enough number to find a distance !";
		}
	};
	
	int shortestSpan() const;
	int longestSpan() const;

	unsigned int getN() const;

	void display() const;

	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end, size_t randMax)
	{
		srand(time(0)); 

		for (InputIterator it = begin; it != end; ++it)
			addNumber(rand() % randMax);
	}

private:
	unsigned int _n;
	std::multiset<int> _numbers;
	unsigned int _size;
};

#endif /* ************************************************************ SPAN_H */