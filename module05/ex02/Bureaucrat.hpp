/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:33:44 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 16:52:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	
public:
	Bureaucrat(); // default constructor
	Bureaucrat(std::string name, int grade); // parameter constructor
	~Bureaucrat(); // destructor
	Bureaucrat(Bureaucrat const &other); // copy
	Bureaucrat &operator=(const Bureaucrat &rhs); // assignation
	

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form);
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Grade too high my G !";
			}
	};
	
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "Grade too low my G !";
			}
	};
	
	void executeForm(AForm const & form) const;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i);


#endif