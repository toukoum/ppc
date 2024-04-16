/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:31 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 16:18:25 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat Created ! (default constructor)" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Cat KILLED ! (destructor) and Brain too" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		delete (this->_brain);
		this->_brain = new Brain(*rhs._brain);
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "(Cat) Type: " << i.getType();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound( void ) const{
	std::cout << "(Cat make Sound) Miaou Miaou !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain& Cat::getBrain() const{
    return *_brain;
}

/* ************************************************************************** */