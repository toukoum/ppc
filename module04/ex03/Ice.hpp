/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:58:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 10:47:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice : public AMateria
{

	public:
		Ice(); // default
		Ice( Ice const & src ); //copy
		virtual ~Ice(); // destructor

		Ice &		operator=( Ice const & rhs ); // assignation

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
	private:

};

//std::ostream &	operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************ Ice_H */


