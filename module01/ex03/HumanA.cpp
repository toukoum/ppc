/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:50:49 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/20 19:47:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
}

HumanA::~HumanA(){
}

void HumanA::attack() const{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}