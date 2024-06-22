/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:26:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:14:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, false, 72, 45), _target(target)
{
	std::cout << "(PresidentialPardonForm) Parameters constructor called !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "(PresidentialPardonForm) Destructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm(), _target("foo"){
	std::cout << "(PresidentialPardonForm) Default constructor called !" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other._target, false, 72, 45), _target(other._target){	
	std::cout << "(PresidentialPardonForm) Copy constructor called !" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs){

	if (&rhs != this){
		AForm::operator=(rhs);
	}
	std::cout << "(PresidentialPardonForm) Assignation operator called !" << std::endl;

	return (*this);

}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw NotSigned();
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
