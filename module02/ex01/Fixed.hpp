/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:23:01 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/27 14:06:09 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
#define __FIXED__

#include <iostream>

class Fixed{

private:
	int _value;
	static const int _fractBits = 8;

public:
	// canonical form
	Fixed();					// constructor
	~Fixed();					// desctructor
	Fixed( Fixed const & src ); // copy constructor, copy src in this
	Fixed & operator=( Fixed const & newFixed ); // operator assignation, m.a.j of value
	
	Fixed( int const value);
	Fixed( float const value);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	float toFloat( void ) const;	
	int toInt( void ) const;	
};

std::ostream & operator<<( std::ostream & o, Fixed const & i);

#endif