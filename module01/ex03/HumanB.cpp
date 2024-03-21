/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:03:27 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 12:57:12 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr){
}

HumanB::~HumanB( void ){	
}

void HumanB::setWeapon( Weapon& newWeapon ){
	_weapon = &newWeapon;
}

void HumanB::attack() const{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}