/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:34:07 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 23:17:28 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ){
	this->_type = "fork";
}
Weapon::Weapon( std::string type ){
	this->_type = type;
}

Weapon::~Weapon( void ){
	return ;
}

std::string const & Weapon::getType() const{
	return (_type);
}

void Weapon::setType( std::string newName ){
	this->_type = newName;
}
