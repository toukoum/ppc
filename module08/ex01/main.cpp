/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:24:54 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/01 11:48:06 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	{
		Span sp = Span(5);
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			int size = 10;
			std::vector<int> numbers(size);
			Span span2(size);
			span2.addNumber(numbers.begin(), numbers.end(), 10000);

			std::cout << "\n\nshortest span: " << span2.shortestSpan() << std::endl;
			std::cout << "longest span: " << span2.longestSpan() << std::endl;

			span2.display();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
