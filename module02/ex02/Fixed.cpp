/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:27:12 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/29 17:17:52 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// constructor / destructor
Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value) : _value(value << _fractBits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value) : _value(roundf(value * (1 << _fractBits))){ // arrondir au nombre entier le plus grand pour que ce soit plus fidele de la realite
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



std::ostream & operator<<( std::ostream & o, Fixed const & i ){
	
	o << i.toFloat();
	return (o);
}

//conversion
float Fixed::toFloat( void )const{
	return (static_cast<float>(_value) / (1 << _fractBits)); // convertir value en float pour s'assurer d'avoir un resultat avec des virgules
}

int Fixed::toInt( void )const{
	return (_value >> _fractBits);
}

// surcharge operator
Fixed & Fixed::operator=( Fixed const & rhs ){
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &rhs){
		this->_value = rhs._value;
	}
	return (*this);
}

bool Fixed::operator>( Fixed const &rhs ) const{
	return (this->_value > rhs._value);
}

bool Fixed::operator<( Fixed const &rhs ) const{
	return (this->_value < rhs._value);
}

bool Fixed::operator>=( Fixed const &rhs ) const{
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=( Fixed const &rhs ) const{
	return (this->_value <= rhs._value);
}

bool Fixed::operator==( Fixed const &rhs ) const{
	return (this->_value == rhs._value);
}

bool Fixed::operator!=( Fixed const &rhs ) const{
	return (this->_value != rhs._value);
}

Fixed Fixed::operator+( Fixed const &rhs ) const{
	Fixed result;
	result.setRawBits( this->_value + rhs._value );
	return (result);
}

Fixed Fixed::operator-( Fixed const &rhs ) const{
	Fixed result;
	result.setRawBits( this->_value - rhs._value );
	return (result);	
}

Fixed Fixed::operator*( Fixed const &rhs ) const{
	Fixed result;
	result.setRawBits( static_cast<float>(this->_value) / (1 << _fractBits) * rhs._value );
	return (result);
}

Fixed Fixed::operator/( Fixed const &rhs ) const{
	Fixed result;
	if (!rhs._value){
		std::cout << "Error: Division by zero" << std::endl;
	}
	result.setRawBits( (this->_value << _fractBits) / rhs._value );
	return (result);	
}

// pre incrementation
Fixed &Fixed::operator++( void ){
	this->_value++;
	return (*this);
}

// post incrementation, on renvoit une copie de this tout en ayant incremente la vrai valeur
Fixed Fixed::operator++( int ){
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

// pre decrementation
Fixed &Fixed::operator--( void ){
	this->_value--;
	return (*this);
}

// post decrementation, on renvoit une copie de this tout en ayant incremente la vrai valeur
Fixed Fixed::operator--( int ){
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}


Fixed &Fixed::min(Fixed &ref1, Fixed &ref2) {
    return (ref1._value > ref2._value ? ref2 : ref1);
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2) {
    return (ref1._value < ref2._value ? ref2 : ref1);
}

const Fixed &Fixed::min(Fixed const &ref1, Fixed const &ref2) {
    return (ref1._value > ref2._value ? ref2 : ref1);
}

const Fixed &Fixed::max(Fixed const &ref1, Fixed const &ref2) {
    return (ref1._value < ref2._value ? ref2 : ref1);
}
