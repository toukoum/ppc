/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:26:24 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/29 13:27:41 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT__
#define __POINT__

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(); //default
	Point(float const x, float const y); //numeric parameters
	Point(Point const &copy); // copy constructor
	~Point(); // destructor
	
	Point & operator=(Point const & rhs);
	
	float getX() const;
	float getY() const;
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif