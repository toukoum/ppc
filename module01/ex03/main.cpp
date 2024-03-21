/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:27:43 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 23:21:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    std::cout << std::endl << "\033[32m====> Creating Bob with Ref Weapon\033[0m" << std::endl << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	HumanA bob("Bob", club2);
	bob.attack();
	club2.setType("some other type of club");
	bob.attack();

	
    std::cout << std::endl << "\033[32m===> Creating Jim with a Pointer Weapon\033[0m" << std::endl << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}