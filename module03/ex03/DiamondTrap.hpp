/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:56:29 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 18:17:00 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP__
#define __DIAMONDTRAP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
	
public:
	DiamondTrap();
	DiamondTrap(std::string const& name);
	DiamondTrap(DiamondTrap const& other);
	~DiamondTrap();

	DiamondTrap & operator=(DiamondTrap const & rhs);

	void whoAmI();

	using ScavTrap::attack;
};



#endif