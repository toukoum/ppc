/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:51:38 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 16:25:11 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:

		Animal(); // default
		Animal( Animal const & src ); // copy
		Animal(std::string const &type); // parameters
		virtual ~Animal(); // destructor

		Animal &		operator=( Animal const & rhs ); // assignation

		std::string const &getType( void ) const;

		virtual void makeSound( void ) const;


};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */