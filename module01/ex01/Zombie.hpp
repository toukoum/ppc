/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:49:33 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/20 15:21:24 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <string>
#include <iostream>

class Zombie{
private:
	std::string _name;

public:
	Zombie();
	Zombie( std::string name );
	~Zombie();
	void announce( void );
	
	void setName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif
