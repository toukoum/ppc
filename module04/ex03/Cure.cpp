/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:00:53 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/15 19:44:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "iostream"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	std::cout << "(Cure) Default Constructor called" << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria(src)
{
	std::cout << "(Cure) Copy Constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "(Cure) Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure & Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs ){
		AMateria::operator=(rhs);
	}
	return (*this);
}

//std::ostream &			operator<<( std::ostream & o, Cure const & i )
//{
//	//o << "Value = " << i.getValue();
//	return o;
//}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "* heals "<< target.getName() <<"’s wounds *" << std::endl;
}

/*0
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */