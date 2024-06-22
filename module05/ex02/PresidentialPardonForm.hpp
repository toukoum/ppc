/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:25:26 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:07:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs); // assignation
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
	
	
};

#endif