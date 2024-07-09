/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:07:08 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/09 14:07:17 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{

public:
	RPN();
	RPN(RPN const &src);
	~RPN();

	int compute(const std::string &expression);
	RPN &operator=(RPN const &rhs);

	class InvalidInput : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error";
		}
	};

private:
	std::stack<int> _stack;

	bool validInput(char c) const;
	void calcul(char token);

	void addition(int v1, int v2);
	void substraction(int v1, int v2);
	void division(int v1, int v2);
	void multiplication(int v1, int v2);


};

#endif /* ************************************************************* RPN_H */