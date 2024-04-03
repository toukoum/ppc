/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:39:37 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 17:36:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP__
#define __SCAVTRAP__

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & other); // copy
	ScavTrap & operator=(const ScavTrap &rhs); // assignation
	~ScavTrap(); // destructor

	void attack(const std::string& target);
	void guardGate();
};

#endif