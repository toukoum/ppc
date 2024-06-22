/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:17:28 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 16:50:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
	AForm(AForm const &other);
	AForm &operator=(const AForm &rhs);

	virtual ~AForm();
	
	virtual void beSigned(const Bureaucrat &bureaucrat);

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
	
	class NotSigned : public std::exception{
		public:
			virtual const char* what() const throw(){
				return "This form isn't signed my G !";
			}
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	virtual void execute(Bureaucrat const & executor) const = 0;
};


std::ostream& operator<<(std::ostream& os, const AForm& form);


#endif