/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/04 11:59:35 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap defaultTrap;
    ClapTrap namedTrap("Bob");
    namedTrap.attack("Enemy");
    namedTrap.takeDamage(5);
    namedTrap.beRepaired(3);
    ClapTrap copyTrap(namedTrap);
    copyTrap.attack("Another Enemy");
    defaultTrap = namedTrap;
    defaultTrap.attack("Assigned Enemy");

    return 0;
}
