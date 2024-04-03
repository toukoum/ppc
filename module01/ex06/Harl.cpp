/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:39:28 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 22:38:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}
	
void Harl::info( void ){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Harl::error( void ){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}
	
void Harl::complain( int level ){
	void (Harl::*complains[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	switch (level)
	{
	case (0):
		(this->*complains[level])();
		level++;
	case (1):
		(this->*complains[level])();
		level++;
	case (2):
		(this->*complains[level])();
		level++;
	case (3):
		(this->*complains[level])();
		level++;
	}
}
