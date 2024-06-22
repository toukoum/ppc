/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:26:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:14:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, false, 72, 45), _target(target)
{
	std::cout << "(RobotomyRequestForm) Parameters constructor called !" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "(RobotomyRequestForm) Destructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("foo"){
	std::cout << "(RobotomyRequestForm) Default constructor called !" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other._target, false, 72, 45), _target(other._target){	
	std::cout << "(RobotomyRequestForm) Copy constructor called !" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){

	if (&rhs != this){
		AForm::operator=(rhs);
	}
	std::cout << "(RobotomyRequestForm) Assignation operator called !" << std::endl;

	return (*this);

}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw NotSigned();
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	}
	std::cout << "(RobotomyRequestForm) Makes some drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}
