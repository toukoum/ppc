/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:35:34 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 12:23:18 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB__
#define __HUMANB__

#include "Weapon.hpp"
#include <iostream>

class HumanB{
private:
	std::string _name;
	Weapon* _weapon;

public:
	HumanB(std::string name);
	~HumanB( void );
	void setWeapon( Weapon& weapon );
	void attack() const;
};
#endif
