/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:55:31 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/29 17:04:01 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.cpp"
#include <string>

void convert_char(std::string s){
	char c = s[0];
	displayChar(c);
	displayInteger(static_cast<int>(c));
	displayFloat(static_cast<float>(c));
	displayDouble(static_cast<double>(c));
}

void convert_int(std::string s){
	int i = atoi(s.c_str());
	char c = static_cast<char>(i);
	if (i >= 32 && i  <= 126)
		displayChar(c);
	else
		std::cout << "char: Non displayable" << std::endl;
	
	displayInteger(i);
	displayFloat(static_cast<float>(i));
	displayDouble(static_cast<double>(i));
}


void convert_float(std::string s){
	float i = strtof(s.c_str(), NULL);
	if (i >= 32 && i  <= 126)
		displayChar(i);
	else
		std::cout << "char: Non displayable" << std::endl;

	errno = 0;
	long value = std::strtol(s.c_str(), NULL, 10);
	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) || (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		displayInteger(static_cast<int>(i));
	displayFloat(i);
	displayDouble(static_cast<double>(i));
}

void convert_double(std::string s){
	double i = std::strtod(s.c_str(), NULL);
	if (i >= 32 && i  <= 126)
		displayChar(i);
	else
		std::cout << "char: Non displayable" << std::endl;

	errno = 0;
	long value = std::strtol(s.c_str(), NULL, 10);
	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) || (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		displayInteger(static_cast<int>(i));
	displayFloat(static_cast<float>(i));
	displayDouble(i);
}
