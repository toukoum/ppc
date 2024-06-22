/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:26:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 17:24:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, false, 145, 137), _target(target)
{
	std::cout << "(ShrubberyCreationForm) Parameters constructor called !" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(ShrubberyCreationForm) Destructor called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(), _target("foo"){
	std::cout << "(ShrubberyCreationForm) Default constructor called !" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other._target, false, 145, 137), _target(other._target){	
	std::cout << "(ShrubberyCreationForm) Copy constructor called !" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){

	if (&rhs != this){
		AForm::operator=(rhs);
	}
	std::cout << "(ShrubberyCreationForm) Assignation operator called !" << std::endl;
	
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw NotSigned();
	if (executor.getGrade() > getGradeToExecute()){
		throw GradeTooLowException();
	}
	std::cout << "(ShrubberyCreationForm) execute the form, created file" << std::endl;
	
	std::ofstream myFile(_target + "_shrubbery");
	myFile << "       _-_" << std::endl;
    myFile << "    /~~   ~~\\" << std::endl;
    myFile << " /~~         ~~\\" << std::endl;
    myFile << "{               }" << std::endl;
    myFile << " \\  _-     -_  /" << std::endl;
    myFile << "   ~  \\\\ //  ~" << std::endl;
    myFile << "_- -   | | _- _" << std::endl;
    myFile << "  _ -  | |   -_" << std::endl;
    myFile << "       // \\\\" << std::endl;

	myFile.close();
}
