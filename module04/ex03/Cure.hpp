/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:58:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/15 19:23:59 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Cure : public AMateria
{

	public:
		Cure(); // default
		Cure( Cure const & src ); //copy
		virtual ~Cure(); // destructor

		Cure &		operator=( Cure const & rhs ); // assignation

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
	private:

};

//std::ostream &	operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */


