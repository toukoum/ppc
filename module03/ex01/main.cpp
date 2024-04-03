/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/02 15:09:18 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>



int main() {
	// part1
	{
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
		// Création d'une instance de ClapTrap
		ClapTrap clap("Clappy");
		std::cout << "------ ClapTrap Actions ------" << std::endl;
		clap.attack("un ennemi");
		clap.takeDamage(5);
		clap.beRepaired(3);

		// Séparation visuelle pour les sorties console
		std::cout << "\n===============================\n" << std::endl;

		// Création d'une instance de ScavTrap
		ScavTrap scav("Scavvy");
		std::cout << "------ ScavTrap Actions ------" << std::endl;
		scav.attack("un autre ennemi"); // Doit montrer ScavTrap utilisant sa propre version de attack
		scav.takeDamage(10); // Hérité de ClapTrap, devrait fonctionner de la même manière
		scav.beRepaired(5); // Hérité de ClapTrap, devrait fonctionner de la même manière
		scav.guardGate(); // Fonction spécifique à ScavTrap, montre un comportement unique
	}

    return 0;
}
