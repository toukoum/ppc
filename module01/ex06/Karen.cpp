/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:39:28 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 22:38:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"


Karen::Karen(){
}

Karen::~Karen(){
}

void Karen::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}
	
void Karen::info( void ){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Karen::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Karen::error( void ){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}
	
void Karen::complain( int level ){
	void (Karen::*complains[4])( void ) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	switch (level)
	{
	case (0):
		for (int i = 0; i < 4; i++)	
			(this->*complains[i])();
		break;
	case (1):
		for (int i = 1; i < 4; i++)
			(this->*complains[i])();
		break ;
	case (2):
		for (int i = 2; i < 4; i++)
			(this->*complains[i])();
		break ;
	case (3):
		for (int i = 3; i < 4; i++)
			(this->*complains[i])();
		break ;
	}
}
