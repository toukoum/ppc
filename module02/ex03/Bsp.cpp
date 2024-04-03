/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:25:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/01 12:10:26 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    float A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
  
    float A1 = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
  
    float A2 = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
  
    float A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
    
    float totalArea = A1 + A2 + A3;
    return (totalArea == A);
}
