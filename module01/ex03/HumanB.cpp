/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:03:27 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/22 15:48:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){
}

HumanB::~HumanB( void ){	
}

void HumanB::setWeapon( Weapon& newWeapon ){
	_weapon = &newWeapon;
}

void HumanB::attack() const{
	if (!this->_weapon)
		std::cout << _name << " attacks without weapon" << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}