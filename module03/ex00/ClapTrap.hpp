/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:06:39 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/02 10:50:51 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP__
#define __CLAPTRAP__

#include <string>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;
	 
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & other); // copy
	ClapTrap & operator=(const ClapTrap &rhs); // assignation
	~ClapTrap(); // destructor

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif