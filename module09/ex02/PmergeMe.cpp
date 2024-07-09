/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:52:26 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/09 14:23:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() : _timeVector(0), _timeList(0) {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int getInt(const std::string &s)
{
	errno = 0;
	char *end = NULL;
	if (s.size() == 0)
		return (-1);
	long value = std::strtol(s.c_str(), &end, 10);
	if (*end == '\0')
	{
		if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) || (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()))
			return (-1);
		return (value);
	}
	return (-1);
}

void PmergeMe::parse(char const *argv[])
{
	int i = 1;
	int value = 0;

	while (argv[i])
	{
		value = getInt(argv[i]);
		if (value < 0)
		{
			throw InvalidInput();
			return;
		}
		_vector.push_back(value);
		_list.push_back(value);
		i++;
	}
}

void PmergeMe::display()
{
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::showTime()
{
	std::cout << "Time to process a range of 3000 elements with std::vector<int> : " << _timeVector << " us" << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::List<int> : " << _timeList << " us" << std::endl;
}

bool PmergeMe::isSorted() const{
	 if (_vector.size() != _list.size()) {
        std::cout << "List and vector sizes do not match!" << std::endl;
        return false;
    }

    std::list<int>::const_iterator it = _list.begin();
    for (size_t i = 0; i < _vector.size() - 1; ++i, ++it) {
        if (_vector[i + 1] < _vector[i])
			return (false);
		if (*myNext(it, 1) < *it)
			return (false);

        if (_vector[i] != *it) {
            std::cout << "Value not equal in both list and vector at index " << i << "!" << std::endl;
            return false;
        }
    }

    if (_vector.back() != *it) {
        std::cout << "Last value not equal in both list and vector!" << std::endl;
        return false;
    }

    return true;
}


void PmergeMe::merge(std::vector<int>& leaders, int left, int mid, int right){
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	std::vector<int> leftArray(subArrayOne);
	std::vector<int> rightArray(subArrayTwo);

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = leaders[left + i];
	for (int i = 0; i < subArrayTwo; i++)
		rightArray[i] = leaders[mid + i + 1];

	
	int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged sub-array

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
			leaders[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}else{
			leaders[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne)
	{
		leaders[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		leaders[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}



void PmergeMe::mergeSort(std::vector<int>& leaders, int begin, int end){
	if (begin >= end)
		return ;
	
	int mid = begin + (end - begin) / 2;
	mergeSort(leaders, begin, mid);
	mergeSort(leaders, mid + 1, end);
	merge(leaders, begin, mid, end);
}

int PmergeMe::dichotomie(std::vector<int>& leaders, int value){
	int start = 0;
	int end = leaders.size() - 1;
	int mid;
	
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (value == leaders[mid])
			return (mid);
		if (value <= leaders[mid]){
			end = mid;
		}else{
			start = mid + 1;
		}
	}

	return (start);
	
}


void PmergeMe::sortVector()
{
   struct timeval start, end;
   gettimeofday(&start, NULL);


	std::vector<int> followers;
	std::vector<int> leaders;
	
	int lenght = _vector.size();
	if (lenght % 2){
		lenght--;
		leaders.push_back(_vector[_vector.size() - 1]);
	}
	for (int i = 0; i < lenght; i += 2)
	{
		if (_vector[i] > _vector[i + 1]){
			leaders.push_back(_vector[i]);
			followers.push_back(_vector[i + 1]);
		} else{
			followers.push_back(_vector[i]);
			leaders.push_back(_vector[i + 1]);
		}
	}
	

	// etape 2: trier les leaders avec un mergeSort
	mergeSort(leaders, 0, leaders.size() - 1);



	// etape 3: insere les followers avec une recherche dichotomique
	int idxInsert;
	
	for (size_t i = 0; i < followers.size(); i++)
	{
		idxInsert = dichotomie(leaders, followers[i]);
		leaders.insert(leaders.begin() + idxInsert, followers[i]);
	}
	
	
	_vector = leaders;
	
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    _timeVector = (seconds * 1000000) + end.tv_usec - start.tv_usec;

}



// ========================== List Sort ===================================

std::list<int>::iterator PmergeMe::myNext(std::list<int>::iterator it, int distance){
	std::advance(it, distance);
	return (it);
}

std::list<int>::const_iterator PmergeMe::myNext(std::list<int>::const_iterator it, int distance) const{
	std::advance(it, distance);
	return (it);
}


void PmergeMe::mergeList(std::list<int>& leaders, int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    std::list<int> leftArray;
    std::list<int> rightArray;

    std::list<int>::iterator itLeader = myNext(leaders.begin(), left);
    for (int i = 0; i < subArrayOne; i++) {
        leftArray.push_back(*itLeader);
        ++itLeader;
    }

    itLeader = myNext(leaders.begin(), mid + 1);
    for (int i = 0; i < subArrayTwo; i++) {
        rightArray.push_back(*itLeader);
        ++itLeader;
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;

    itLeader = myNext(leaders.begin(), left);
    std::list<int>::iterator itLeft = leftArray.begin();
    std::list<int>::iterator itRight = rightArray.begin();

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (*itLeft <= *itRight) {
            *itLeader = *itLeft;
            ++itLeft;
            indexOfSubArrayOne++;
        } else {
            *itLeader = *itRight;
            ++itRight;
            indexOfSubArrayTwo++;
        }
        ++itLeader;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        *itLeader = *itLeft;
        ++itLeft;
        ++itLeader;
        indexOfSubArrayOne++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        *itLeader = *itRight;
        ++itRight;
        ++itLeader;
        indexOfSubArrayTwo++;
    }
}

void PmergeMe::mergeSortList(std::list<int>& leaders, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSortList(leaders, begin, mid);
    mergeSortList(leaders, mid + 1, end);
    mergeList(leaders, begin, mid, end);
}

int PmergeMe::dichotomieList(std::list<int>& leaders, int value) {
    int start = 0;
    int end = leaders.size() - 1;
    int mid;
    int midValue;

    while (start < end) {
        mid = start + (end - start) / 2;
        midValue = *myNext(leaders.begin(), mid);
        if (value == midValue)
            return mid;
        if (value <= midValue) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

void PmergeMe::sortList() {
		
	struct timeval start, end;
   gettimeofday(&start, NULL);

	
    std::list<int> followers;
    std::list<int> leaders;

    int i = 0;
    int length = _list.size();
    if (length % 2) {
        length--;
        leaders.push_back(*_list.rbegin());
    }

    std::list<int>::iterator it = _list.begin();
    while (i < length) {
        if (*it > *myNext(it, 1)) {
            leaders.push_back(*it);
            followers.push_back(*myNext(it, 1));
        } else {
            followers.push_back(*it);
            leaders.push_back(*myNext(it, 1));
        }
        i += 2;
        it = myNext(it, 2);
    }

    // etape 2: trier les leaders avec un mergeSort
    mergeSortList(leaders, 0, leaders.size() - 1);

    // etape 3: inserer avec la dichotomie les valeurs
    it = followers.begin();
    std::list<int>::iterator itInsert;

    while (it != followers.end()) {
        itInsert = myNext(leaders.begin(), dichotomieList(leaders, *it));
        leaders.insert(itInsert, *it);
        ++it;
    }

    _list = leaders;

	gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    _timeList = (seconds * 1000000) + end.tv_usec - start.tv_usec;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */