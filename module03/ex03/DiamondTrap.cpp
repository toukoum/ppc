/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:04:10 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 18:58:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>


DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), _name("foo")
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap: Parameters constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other): ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs){
	std::cout << "Assignation overload called ! (DiamondTrap)" << std::endl;

	if (this != &rhs){
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
	}
	return (*this);
}

void DiamondTrap::whoAmI(){
	std::cout << "(DiamondTrap): I'm " << this->_name << " / ClapTrap name: " << ClapTrap::_name << std::endl;
}