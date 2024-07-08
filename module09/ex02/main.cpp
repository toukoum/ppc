/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:30:45 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/08 21:31:24 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char const *argv[])
{
	if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" << std::endl;
        return 1;
    }

	PmergeMe merge;

	try
	{
		merge.parse(argv);
		std::cout << "Before:\t";
		merge.display();

		merge.sortVector();
		merge.sortList();

		std::cout << "After:\t";
		merge.display();

		merge.showTime();
		if (merge.isSorted()){
			std::cout << "Both List are Sorted!" << std::endl;
		}else{
			std::cout << "Error, List aren't sorted!" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
