/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:06:58 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/02 10:14:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

// la classe MutantStack va heriter de stack. Mutant stack va etre stocke dans 
// un deque pour pouvoir etre iterable. 
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:
	MutantStack() : std::stack<T, Container>(){};
	MutantStack(MutantStack<T, Container> const &src) : std::stack<T, Container>(src){};
	~MutantStack(){};

	MutantStack<T> &operator=(MutantStack<T, Container> const &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T, Container>::operator=(rhs);
		}
		return (*this);
	}

	/// @brief on redefini Container::iterator en iterator

	
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

private:
};

#endif /* ***************************************************** MUTANTSTACK_H */