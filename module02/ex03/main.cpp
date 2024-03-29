/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:16:20 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/29 16:49:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
    Point a(1, 1);
    Point b(0, 5);
    Point c(5, 0);

    // Tests supplémentaires
    Point pointEdgeAB(0.5, 3); // Sur l'arête AB
    Point pointEdgeBC(2.5, 2.5); // Sur l'arête BC
    Point pointEdgeCA(3, 1); // Sur l'arête CA
    Point pointNearA(1.1, 1); // Proche de A, à l'extérieur
    Point pointNearB(0, 4.9); // Proche de B, à l'extérieur
    Point pointFar(10, 10); // Loin, clairement à l'extérieur

    // Effectuer les tests
    Point pointsToTest[] = {pointEdgeAB, pointEdgeBC, pointEdgeCA, pointNearA, pointNearB, pointFar};

    for (int i = 0; i < 6; ++i) {
        bool result = bsp(a, b, c, pointsToTest[i]);
        std::cout << "Point (" << pointsToTest[i].getX() << "," << pointsToTest[i].getY() << ") => in triangle ABC? : " << (result ? "Yes" : "No") << std::endl;
    }
}
