/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:19:37 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/15 19:23:53 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA__
#define __AMATERIA__

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(); //default
		AMateria(std::string const & type);
		AMateria(AMateria const & src); // copy
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		virtual ~AMateria();
		AMateria & operator=(AMateria const &rhs);
};

#endif

