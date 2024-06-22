/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:03:28 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 20:37:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target) const
{
	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"};

	FormCreator formCreators[] = {
		createRobotomy,
		createPardon,
		createShrubbery
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (nameForm == formNames[i])
		{
			AForm *form = formCreators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cerr << "No Form find with this name !" << std::endl;
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */