/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:03:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 19:42:40 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();
		
		AForm* makeForm(const std::string& nameForm, const std::string& target) const;

		Intern &		operator=( Intern const & rhs );

	private:

};

typedef AForm* (*FormCreator)(const std::string&);

#endif /* ********************************************************** INTERN_H */