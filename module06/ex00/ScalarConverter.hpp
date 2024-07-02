/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:17:40 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 13:40:56 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cmath>

enum TypeInput
{
	FLOAT,
	INTEGER,
	DOUBLE,
	CHARACTER,
	SPECIAL,
	WRONG
};

class ScalarConverter
{

	public:
		static void convert(const std::string& s);

	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

};


#endif /* ************************************************* SCALARCONVERTER_H */