/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:39:37 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/03 17:36:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & other); // copy
	FragTrap & operator=(const FragTrap &rhs); // assignation
	~FragTrap(); // destructor

	void attack(const std::string& target);
	void highFivesGuys();
};

#endif