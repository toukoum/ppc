/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 16:19:41 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog Created ! (default constructor)" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete(_brain);
	std::cout << "Dog KILLED ! (destructor) and brain too" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		delete (this->_brain);
		this->_brain = new Brain(*rhs._brain);
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Dog const & i )
{
	o << "(Dog) Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound( void ) const{
	std::cout << "(Dog make Sound) Wouaf Wouaf !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain & Dog::getBrain( void ) const{
	return (*_brain);
}

/* ************************************************************************** */