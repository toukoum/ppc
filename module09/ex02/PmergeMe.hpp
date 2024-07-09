#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sys/time.h>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <limits>

class PmergeMe
{

public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	void parse(char const *argv[]);

	void display();
	void showTime();
	void sortVector();
	void sortList();

	bool isSorted() const;

	class InvalidInput : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error";
		}
	};

private:

	std::vector<int> _vector;
	std::list<int> _list;
	long _timeVector;
	long _timeList;
	
	std::list<int>::iterator myNext(std::list<int>::iterator it, int distance);
	std::list<int>::const_iterator myNext(std::list<int>::const_iterator it, int distance) const;
	
	void mergeSort(std::vector<int>& leaders, int begin, int end);
	void merge(std::vector<int>& leaders, int begin, int mid, int end);
	int dichotomie(std::vector<int>& leaders, int value);
	
	void mergeSortList(std::list<int>& leaders, int begin, int end);
	void mergeList(std::list<int>& leaders, int begin, int mid, int end);
	int dichotomieList(std::list<int>& leaders, int value);
};

#endif /* ******************************************************** PMERGEME_H */