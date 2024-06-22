/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:25:26 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:07:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs); // assignation
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
	
	
};

#endif