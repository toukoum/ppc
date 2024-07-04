/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:59:04 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/04 10:05:01 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2){
		std::cerr << "Error\n=> Usage: ./btc <file>" << std::endl;
		return (1);
	}
	
	try
	{
		BitcoinExchange broker("data.csv");
		broker.convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	return 0;
}

