/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:25:26 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:07:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs); // assignation
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
	
	
};

#endif