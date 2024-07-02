/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:56:46 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 13:43:42 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "conversion.cpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

 ScalarConverter::ScalarConverter()
{
 }

 ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}

///*
//** -------------------------------- DESTRUCTOR --------------------------------
//*/

 ScalarConverter::~ScalarConverter()
{
 }

/*
** --------------------------------- METHODS ----------------------------------
*/

bool isChar(const std::string &s) {
    return s.size() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool isDouble(const std::string &s) {
    errno = 0;
	char *end = NULL;
	double valued = std::strtod(s.c_str(), &end);
	if (*end == '\0'){
		if ((errno == ERANGE || (valued == HUGE_VAL || valued == -HUGE_VAL))){
			return (false);
		}
		size_t decimal_point = s.find('.');
        if (decimal_point != std::string::npos && decimal_point == s.size() - 2) {
            return true;
        }
	}
	return (false);
}

bool isFloat(const std::string &s) {
    errno = 0;
	char *end = NULL;
	float valuef = std::strtof(s.c_str(), &end);
	if (*end == 'f' && end == &s[s.size() - 1]){
		if ((errno == ERANGE || (valuef == HUGE_VALF || valuef == -HUGE_VALF)) ){
			return (false);
		}
		std::string numericPart = s.substr(0, end - s.c_str());
		size_t decimal_point = numericPart.find('.');
        if (decimal_point != std::string::npos && decimal_point == s.size() - 3) {
            return true;
        }
	}
	return (false);
}

bool isInt(const std::string &s) {
	errno = 0;
	char *end = NULL;
    long value = std::strtol(s.c_str(), &end, 10);
	if (*end == '\0')
	{
		if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) || (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()))
			return (false);
		return (true);
	}
	return (false);
}

TypeInput getType(const std::string &s) {
    if (s == "nan" || s == "inf" || s == "+inf" || s == "-inf" || 
	 s == "inff" || s == "+inff" || s == "-inff") {
        return SPECIAL;
    }

    if (isChar(s))
        return CHARACTER;
    if (isInt(s))
        return INTEGER;
    if (isFloat(s))
        return FLOAT;
    if (isDouble(s))
        return DOUBLE;

    return WRONG;
}


void ScalarConverter::convert(const std::string &s)
{
	if (s.empty())
		return (displayError(s));
	TypeInput typeInput = getType(s);
	
	switch (typeInput)
	{
	case CHARACTER:
		convert_char(s);
		break;
	case INTEGER:
		convert_int(s);
		break;
	case FLOAT:
		convert_float(s);
		break;
	case DOUBLE:
		convert_double(s);
		break;
	case SPECIAL:
		handle_special(s);
		break;
	case WRONG:
		displayError(s);
		break;
	default:
		break;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */