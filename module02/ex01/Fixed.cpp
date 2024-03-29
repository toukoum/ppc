/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:27:12 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/27 15:25:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value) : _value(value << _fractBits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value) : _value(std::roundf(value * (1 << _fractBits))){ // arrondir au nombre entier le plus grand pour que ce soit plus fidele de la realite
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

int Fixed::getRawBits( void ) const{
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
	
	o << i.toFloat	();
	return (o);
}

float Fixed::toFloat( void )const{
	return (static_cast<float>(_value) / (1 << _fractBits)); // convertir value en float pour s'assurer d'avoir un resultat avec des virgules
}

int Fixed::toInt( void )const{
	return (_value >> _fractBits);
}