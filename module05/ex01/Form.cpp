/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:18:07 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/20 15:08:10 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("foo"), _isSigned("false"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "(Form) Default Constructor Called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "(Form) Parameters Constructor Called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "(Form) Destructor Called" << std::endl;
}

Form::Form(Form const &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "(Form) Copy Constructor Called" << std::endl;
}

Form & Form::operator=(const Form &rhs){
	std::cout << "(Form) Assignation operator Called" << std::endl;
	if (this != &rhs){
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_gradeToSign){
		throw GradeTooLowException();
	}
	_isSigned = true;
}



std::string Form::getName() const{
	return (_name);
}

bool Form::getIsSigned() const{
	return (_isSigned);
}

int Form::getGradeToSign() const{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const{
	return (_gradeToExecute);
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", signed: " << std::boolalpha << form.getIsSigned()
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}