/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:35:39 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/20 19:20:21 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON__
#define __WEAPON__

#include <iostream>

class Weapon{
private:
	std::string _type;

public:
	Weapon( void );
	Weapon( std::string type);
	~Weapon( void );

	std::string const& getType() const;
	void setType( std::string newName );
};

#endif