/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:15:56 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/15 14:56:10 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";

class PhoneBook {
public :
	PhoneBook(); // Constructeur
	~PhoneBook(); // Destructeur;
	void add_contact();
	void search_contact();

	std::string getName() const;

	// Display
	void displayAllContact() const;
	void displayColumn(const std::string &text) const;
	void displayContact(int index) const;
	void clearScreen();


private:
	Contact _contacts[8];
	int	_currentSize;
};

#endif

