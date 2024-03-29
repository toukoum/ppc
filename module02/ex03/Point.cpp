/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:27:59 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/29 15:29:13 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0){
}

Point::Point(float const x, float const y) : _x(x), _y(y){
}

Point::~Point(){
}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y) {
}

Point & Point::operator=(Point const & rhs){
	(void) rhs;
	return (*this);
}

float Point::getX() const{
	return (this->_x.toFloat());
}

float Point::getY() const{
	return (this->_y.toFloat());
}
