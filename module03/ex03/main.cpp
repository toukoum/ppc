/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/04 12:28:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	// // part1
	{
		std::cout << "\n============Part 1===================\n" << std::endl;

		ClapTrap defaultTrap;
		ClapTrap namedTrap("Bob");
		namedTrap.attack("Enemy");
		namedTrap.takeDamage(50);
		namedTrap.beRepaired(3);
		ClapTrap copyTrap(namedTrap);
		copyTrap.attack("Another Enemy");
		defaultTrap = namedTrap;
		defaultTrap.attack("Assigned Enemy");
		std::cout << std::endl << std::endl;
	}
	// part 2
	{
		std::cout << "\n============Part 2===================\n" << std::endl;

		ClapTrap clap("Clappy");
		std::cout << "------ ClapTrap Actions ------" << std::endl;
		clap.attack("un ennemi");
		clap.takeDamage(5);
		clap.beRepaired(3);

		std::cout << "\n===============================\n" << std::endl;

		ScavTrap scav("Scavvy");
		std::cout << "------ ScavTrap Actions ------" << std::endl;
		scav.attack("un autre ennemi");
		scav.takeDamage(10);
		scav.beRepaired(5);
		scav.guardGate();
	}
	// Part 3
	{
		std::cout << "\n============Part 3===================\n" << std::endl;

		ClapTrap clap("Clappy");
		std::cout << "------ ClapTrap Actions ------" << std::endl;
		clap.attack("un ennemi");
		clap.takeDamage(5);
		clap.beRepaired(3);

		std::cout << "\n===============================\n" << std::endl;

		FragTrap frag("fragvy");
		std::cout << "------ fragTrap Actions ------" << std::endl;
		frag.attack("un autre ennemi");
		frag.takeDamage(10);
		frag.beRepaired(5);
		frag.highFivesGuys();
	}
	// Part 4
	{
		std::cout << "\n============Part 4===================\n" << std::endl;
		DiamondTrap dt("DiamondBoy");

		dt.whoAmI();

		// Test des fonctions héritées de ClapTrap, FragTrap, et ScavTrap
		dt.attack("enemy");
		dt.takeDamage(30);
		dt.beRepaired(20);

		std::cout << std::endl;
		dt.highFivesGuys(); // from FragTrap
		dt.guardGate();     // from ScavTrap
		
		std::cout << std::endl;
		DiamondTrap original("Original");
		std::cout << "\n\n=== Testing Copy Constructor ===" << std::endl;
		DiamondTrap copyConstructed(original);
		copyConstructed.whoAmI();

		std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
		DiamondTrap assigned;
		assigned = original;
		assigned.whoAmI();

		std::cout << std::endl;
		std::cout << std::endl;
		
	}


    return 0;
}
