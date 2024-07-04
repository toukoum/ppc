/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:07:11 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/04 11:54:57 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(const RPN &src) : _stack(src._stack) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool RPN::validInput(char c) const
{
	return (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/');
}


void RPN::addition(int v1, int v2)
{
	_stack.push(v1 + v2);
}

void RPN::substraction(int v1, int v2){
	_stack.push(v2 - v1);
}

void RPN::multiplication(int v1, int v2){
	_stack.push(v2 * v1);
}

void RPN::division(int v1, int v2){
	_stack.push(v2 / v1);
}

void RPN::calcul(char token)
{
	int v1 = _stack.top();
	_stack.pop();
	int v2 = _stack.top();
	_stack.pop();
	if (token == '+')
		addition(v1, v2);
	else if (token == '-')
		substraction(v1, v2);
	else if (token == '*')
		multiplication(v1, v2);
	else if (token == '/')
		division(v1, v2);
}

/// @brief
/// @param expression ./RPN "1 2 * 2 / 2 * 2 4 - +"
/// @return result = 0
int RPN::compute(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string s;
	char token;
	while (std::getline(iss, s, ' '))
	{
		if (s.size() > 1 || !validInput(s[0]))
		{
			throw InvalidInput();
			return (-1);
		}
		token = s[0];
		if (isdigit(token))
			_stack.push(token - '0');
		else
			calcul(token);
	}
	return (_stack.top());
}