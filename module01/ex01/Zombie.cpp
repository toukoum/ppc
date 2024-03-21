/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:49:37 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/20 16:45:59 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("foo"){	
}

Zombie::Zombie( std::string name ) : _name(name){
}

void Zombie::announce( void ){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void){
	std::cout << _name << " has been destroyed." << std::endl;
}

void Zombie::setName( std::string name ){
	this->_name = name;
	return ;
}
