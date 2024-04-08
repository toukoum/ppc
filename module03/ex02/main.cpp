/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/04 12:15:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>



int main() {
	// part1
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
		std::cout << "\n------ fragTrap Actions ------" << std::endl;
		frag.attack("un autre ennemi");
		frag.takeDamage(10);
		frag.beRepaired(5);
		frag.highFivesGuys();
	}

    return 0;
}
