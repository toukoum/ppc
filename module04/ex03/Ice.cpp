/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:00:53 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 12:02:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "iostream"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice() : AMateria("ice")
{
	std::cout << "(Ice) Default Constructor called" << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria(src)
{
	std::cout << "(Ice) Copy Constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "(Ice) Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice & Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs ){
		AMateria::operator=(rhs);
	}
	return (*this);
}

//std::ostream &			operator<<( std::ostream & o, Ice const & i )
//{
//	//o << "Value = " << i.getValue();
//	return o;
//}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/*0
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */