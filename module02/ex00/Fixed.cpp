/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:27:12 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/26 15:45:21 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0), _fractBits(8){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ){
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
	return ;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ){
	this->_value = raw; 
}

Fixed & Fixed::operator=( Fixed const & newFixed ){
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &newFixed){
		this->_value = newFixed.getRawBits();
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i){
	
	o << "The value of _value is: " << i.getRawBits();
	return (o);
}