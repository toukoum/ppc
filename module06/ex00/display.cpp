/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:15:04 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/27 13:08:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

void displayChar(char c){
	std::cout << "char: '" << c << "'" << std::endl;
}

void displayInteger(int s){
	std::cout << "int: " << s << std::endl;
}

void displayFloat(float s){
    std::cout << std::fixed << std::setprecision(1) << "float: " << s << "f" << std::endl;
}

void displayDouble(double s){
    std::cout << std::fixed << std::setprecision(1) << "double: " << s << std::endl;
}

void displayError(std::string s){
	std::cout << "Wrong input. The input does not match any type: " << s << std::endl;
}

void handle_special(std::string s){
	std::cout<< "char: impossible" << std::endl;
	std::cout<< "int: impossible" << std::endl;
	if (s == "nan"){
		std::cout<< "float: nanf" << std::endl;
		std::cout<< "double: nan" << std::endl;
	}
	else if (s == "-inff" || s == "-inf"){
		std::cout<< "float: -inff" << std::endl;
		std::cout<< "double: -inf" << std::endl;
	}
	else{
		std::cout<< "float: inff" << std::endl;
		std::cout<< "double: inf" << std::endl;
	}
	(void)s;
}