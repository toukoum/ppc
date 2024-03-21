/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:04:24 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 23:14:22 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string s =  "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;
	
	std::cout << "Adresse of s (value): " << &s << std::endl;
	std::cout << "Adresse of s (pointer): " << stringPTR << std::endl;
	std::cout << "Adresse of s (REF): " << &stringREF << std::endl;

	std::cout << std::endl << "Value of s (pointer): " << *stringPTR << std::endl;
	std::cout << "Value of s (ref): " << stringREF << std::endl;
	
	return (0);
}
