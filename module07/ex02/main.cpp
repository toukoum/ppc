/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:01:33 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 16:26:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> tab1(5);

	try
	{
		tab1[-1] = 1;
		for (size_t i = 0; i < tab1.size(); i++)
			std::cout << tab1[i] << " ";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
