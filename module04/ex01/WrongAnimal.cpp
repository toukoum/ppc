/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:21:15 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/08 12:22:58 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Created ! (default constructor)" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) : _type(src._type)
{
	std::cout << "WrongAnimal Created ! (copy constructor)" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type){
	std::cout << "WrongAnimal Created ! (Parameters constructor)" << std::endl;
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal KILLED ! (destructor)" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal assigned ! (assignation)" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "(WrongAnimal) Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound( void ) const{
	std::cout << "(WrongAnimal) no sound..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &WrongAnimal::getType( void ) const{
	return(this->_type);
}


/* ************************************************************************** */