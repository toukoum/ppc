/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/04 12:08:16 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>



int main() {
	// part1
	{
		std::cout << "\n============Part 1===================\n" << std::endl;

		// constructeur par défaut
		ClapTrap defaultTrap;
		// constructeur avec nom
		ClapTrap namedTrap("Bob");
		// Attaque
		namedTrap.attack("Enemy");
		// subit des dégâts
		namedTrap.takeDamage(50);
		// réparé
		namedTrap.beRepaired(3);
		// Copie de ClapTrap
		ClapTrap copyTrap(namedTrap);
		// ClapTrap copié
		copyTrap.attack("Another Enemy");
		// assignation
		defaultTrap = namedTrap;
		// attaque
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

    return 0;
}
