/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:22:19 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/15 14:52:40 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_items[4];
public:
		Character(); // default
		Character(const Character &src); // copy
		Character(const std::string& name); // parameters
		
		Character &operator=(const Character &rhs); // assignation

		virtual ~Character(); // destructor
		std::string const & getName() const ;
		void equip(AMateria* m) ;
		void unequip(int idx) ;
		void use(int idx, ICharacter& target) ;
};

#endif