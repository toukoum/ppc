/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 19:02:05 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap: Default constructor called !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap: Parameters constructor called !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called !" << std::endl;	
}

ScavTrap::ScavTrap(ScavTrap const & other): ClapTrap(other){
	std::cout << "ScavTrap: Copy constructor called !" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs){
	std::cout << "Assignation overload called ! (ScavTrap)" << std::endl;

	if (this != &rhs){
		ClapTrap::operator=(rhs);
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}

// ============== member function =================

void ScavTrap::attack(const std::string& target){
	if (_energyPoint && _hitPoint){
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
	else if (!_energyPoint){
		std::cout << "ScavTrap: Sorry, no enough energy..." << std::endl;
	}
	else{
		std::cout << "ScavTrap: Sorry, no enough hit Point..." << std::endl;
	}
}

void ScavTrap::guardGate(){
	std::cout << _name << " is now in Gate keeper mode !" << std::endl;
}