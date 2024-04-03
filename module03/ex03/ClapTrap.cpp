/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:07:39 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/02 14:56:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("foo"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Default constructor called !" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Parameters constructor called !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called !" << std::endl;	
}

ClapTrap::ClapTrap(ClapTrap const & other): _name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _attackDamage(other._attackDamage){
	std::cout << "ClapTrap: Copy constructor called !" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs){
	std::cout << "Assignation overload called !" << std::endl;

	if (this != &rhs){
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}


// ============== member function =================

void ClapTrap::attack(const std::string& target){
	if (_energyPoint && _hitPoint){
		std::cout << "CalpTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
	else if (!_energyPoint){
		std::cout << "ClapTrap: Sorry, no enough energy..." << std::endl;
	}
	else{
		std::cout << "ClapTrap: Sorry, no enough hit Point..." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (!_hitPoint){
		std::cout << _name << " already dead..." << std::endl;
	}
	else if (amount >= _hitPoint){
		std::cout << _name << " killed by " << amount << " of damage..." << std::endl;
		_hitPoint = 0;
	}
	else{
		_hitPoint -= amount;
		std::cout << _name << " take " << amount << " of damage, left: " << _hitPoint << " of hit Point" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (!_energyPoint){
		std::cout << "Sorry, no enough energy..." << std::endl;
	}
	else if (!_hitPoint){
		std::cout << "Sorry, no enough hit Point..." << std::endl;
	}
	else{
		_hitPoint += amount;
		std::cout << _name << " was repaired of " << amount << ", left: " << _hitPoint << std::endl;
		_energyPoint--;
	}
}
