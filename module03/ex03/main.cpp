/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 19:06:26 by rgiraud          ###   ########.fr       */
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
	// Part 3
	{
		std::cout << "\n============Part 4===================\n" << std::endl;
		// Création d'un objet DiamondTrap
		DiamondTrap dt("DiamondBoy");

		// Affichage des noms pour vérifier l'initialisation correcte
		dt.whoAmI();

		// Test des fonctions héritées de ClapTrap, FragTrap, et ScavTrap
		dt.attack("the air"); // Doit utiliser ScavTrap::attack
		dt.takeDamage(30);
		dt.beRepaired(20);

		// Test de la capacité spéciale de FragTrap et ScavTrap via DiamondTrap
		dt.highFivesGuys(); // Héritée de FragTrap
		dt.guardGate();     // Héritée de ScavTrap

		DiamondTrap original("Original");
		std::cout << "\n\n=== Testing Copy Constructor ===" << std::endl;
		DiamondTrap copyConstructed(original);
		copyConstructed.whoAmI();

		std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
		DiamondTrap assigned = original; // Utilisation du constructeur par copie pour initialiser `assigned`
		assigned = copyConstructed; // Test de l'opérateur d'assignation
		assigned.whoAmI();
	}


    return 0;
}
