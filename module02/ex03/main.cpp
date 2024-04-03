/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:16:20 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/01 12:17:07 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

    // inside
    Point pointInside(1, 1);

    // arrete
    Point pointEdgeAB(0, 2.5);
    Point pointEdgeBC(2.5, 2.5);
    Point pointEdgeCA(2.5, 0);

    // sommet
    Point pointOnA(0, 0);
    Point pointOnB(0, 5);
    Point pointOnC(5, 0);

    // exterieur
    Point pointNearA(-1, -1);
    Point pointNearB(0, 6);
    Point pointNearC(6, 0);
    Point pointFarOutside(10, 10);

    std::cout << "Point Inside: " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Point Edge AB: " << bsp(a, b, c, pointEdgeAB) << std::endl;
    std::cout << "Point Edge BC: " << bsp(a, b, c, pointEdgeBC) << std::endl;
    std::cout << "Point Edge CA: " << bsp(a, b, c, pointEdgeCA) << std::endl;
    std::cout << "Point On A: " << bsp(a, b, c, pointOnA) << std::endl;
    std::cout << "Point On B: " << bsp(a, b, c, pointOnB) << std::endl;
    std::cout << "Point On C: " << bsp(a, b, c, pointOnC) << std::endl;
    std::cout << "Point Near A (Outside): " << bsp(a, b, c, pointNearA) << std::endl;
    std::cout << "Point Near B (Outside): " << bsp(a, b, c, pointNearB) << std::endl;
    std::cout << "Point Near C (Outside): " << bsp(a, b, c, pointNearC) << std::endl;
    std::cout << "Point Far Outside: " << bsp(a, b, c, pointFarOutside) << std::endl;

    return 0;
}
