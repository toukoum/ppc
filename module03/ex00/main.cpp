/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/02 11:05:19 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Utilisation du constructeur par défaut
    ClapTrap defaultTrap;
    // Utilisation du constructeur avec nom
    ClapTrap namedTrap("Bob");

    // Affichage d'une attaque
    namedTrap.attack("Enemy");

    // Le ClapTrap subit des dégâts
    namedTrap.takeDamage(50);

    // Le ClapTrap est réparé
    namedTrap.beRepaired(3);

    // Copie de ClapTrap
    ClapTrap copyTrap(namedTrap);

    // Attaque par le ClapTrap copié
    copyTrap.attack("Another Enemy");

    // Utilisation de l'opérateur d'assignation
    defaultTrap = namedTrap;

    // defaultTrap après assignation, attaque
    defaultTrap.attack("Assigned Enemy");

    return 0;
}
