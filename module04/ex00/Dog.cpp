/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/08 12:26:20 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Created ! (default constructor)" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{
	std::cout << "Dog Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog KILLED ! (destructor)" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
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

/* ************************************************************************** */