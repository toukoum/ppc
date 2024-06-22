/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:18:07 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 20:24:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name("foo"), _isSigned("false"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "(Form) Default Constructor Called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "(Form) Parameters Constructor Called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "(Form) Destructor Called" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "(Form) Copy Constructor Called" << std::endl;
}

AForm & AForm::operator=(const AForm &rhs){
	std::cout << "(Form) Assignation operator Called" << std::endl;
	if (this != &rhs){
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_gradeToSign){
		throw GradeTooLowException();
	}
	_isSigned = true;
	std::cout << "(Form) The form is signed !" << std::endl;
}



std::string AForm::getName() const{
	return (_name);
}

bool AForm::getIsSigned() const{
	return (_isSigned);
}

int AForm::getGradeToSign() const{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const{
	return (_gradeToExecute);
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", signed: " << std::boolalpha << form.getIsSigned()
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}