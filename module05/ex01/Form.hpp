/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:17:28 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/20 15:06:09 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	Form();
	Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	Form &operator=(const Form &rhs);

	~Form();
	
	void beSigned(const Bureaucrat &bureaucrat);

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

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};


std::ostream& operator<<(std::ostream& os, const Form& form);


#endif