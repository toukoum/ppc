/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:06:26 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/20 14:09:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	std::cout << "\n\n==== Test case 1 ====" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade(); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n\n==== Test case 2 ====" << std::endl;

    try {
        Bureaucrat jim("Jim", 149);
        std::cout << jim << std::endl;

        jim.decrementGrade();
        std::cout << jim << std::endl;

        jim.decrementGrade(); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n\n==== Test case 3 ====" << std::endl;

    try {
        Bureaucrat invalidHigh("InvalidHigh", 0); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "\n\n==== Test case 4 ====" << std::endl;

    try {
        Bureaucrat invalidLow("InvalidLow", 151); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
