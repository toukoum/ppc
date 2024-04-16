/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:31 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 15:57:49 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	for (int i = 0; i < 100; i++){
		_ideas[i] = "foo";
	}
	std::cout << "Brain Created ! (default constructor)" << std::endl;
}	

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++){
		_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain KILLED ! (destructor)" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++) {
        	_ideas[i] = rhs._ideas[i];
    	}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void Brain::changeIdea(int index, const std::string& newIdea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = newIdea;
    } else {
        std::cerr << "Index out of bounds in changeIdea" << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return _ideas[index];
    } else {
        std::cerr << "Index out of bounds in getIdea" << std::endl;
        return "";
    }
}


/* ************************************************************************** */