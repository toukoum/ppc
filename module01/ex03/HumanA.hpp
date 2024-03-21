/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:35:36 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 23:18:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA__
#define __HUMANA__

#include "Weapon.hpp"

class HumanA{
private:
	std::string _name;
	Weapon& _weapon;

public:
	HumanA( std::string name, Weapon& weapon);
	~HumanA();

	void attack() const;
};

#endif