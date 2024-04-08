/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:04:31 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/08 12:26:11 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Created ! (default constructor)" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	std::cout << "Cat Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat KILLED ! (destructor)" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
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

/* ************************************************************************** */