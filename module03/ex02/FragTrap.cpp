/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/04 12:11:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
	std::cout << "FragTrap: Default constructor called !" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
	std::cout << "FragTrap: Parameters constructor called !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called !" << std::endl;	
}

FragTrap::FragTrap(FragTrap const & other): ClapTrap(other){
	std::cout << "FragTrap: Copy constructor called !" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs){
	std::cout << "Assignation overload called ! (FragTrap)" << std::endl;

	if (this != &rhs){
		ClapTrap::operator=(rhs);
	}

	return (*this);
}

// ============== member function =================

void FragTrap::attack(const std::string& target){
	if (_energyPoint && _hitPoint){
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
	}
	else if (!_energyPoint){
		std::cout << "FragTrap: Sorry, no enough energy..." << std::endl;
	}
	else{
		std::cout << "FragTrap: Sorry, no enough hit Point..." << std::endl;
	}
}

void FragTrap::highFivesGuys( void ){
	std::cout << "HIGH FIVE MY BOYSSSS !" << std::endl;
}