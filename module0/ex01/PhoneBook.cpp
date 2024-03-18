/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:15:59 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/18 16:43:00 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentSize(0) {
	//std::cout << "Constructor Phonebook called !" << std::endl;
}

PhoneBook::~PhoneBook(){
	//std::cout << "Destructor Phonebook called !" << std::endl;
}

void PhoneBook::add_contact(){
	std::string name;
	std::string lname;
	std::string nname;
	std::string phone;
	std::string secret;

	do{
		std::cout << "Enter your first Name: ";
		if (!std::getline(std::cin, name))
			return ;
	} while (!name.length());

	do{
		std::cout << "Enter your last Name: ";
		if (!std::getline(std::cin, lname))
			return ;
	} while (!lname.length());

	do{
		std::cout << "Enter your nickname: ";
		if (!std::getline(std::cin, nname))
			return ;
	} while (!nname.length());

	do{
		std::cout << "Enter your phone number: ";
		if (!std::getline(std::cin, phone))
			return ;
	} while (!phone.length());

	do{
		std::cout << "Enter your darkest secret: ";
		if (!std::getline(std::cin, secret))
			return ;
	} while (!secret.length());
	
	Contact newContact(name, lname, nname, phone, secret);
	
	if (_currentSize == 8)
	{
		for (int i = 1; i < 8; i++)
			_contacts[i - 1] = _contacts[i];
		_currentSize--;
	}
	this->_contacts[_currentSize] = newContact;
	_currentSize++;
	return ;
}


void PhoneBook::displayColumn(const std::string &text) const{
	
	std::string result = text;
	if (text.length() > 10)
		result = text.substr(0, 9) + '.';
	std::cout << std::setw(10) << std::right << result << "|";
	return ;
}

void PhoneBook::displayContact(int index) const{
	std::string str_index;

	str_index = index + 49;
	displayColumn(str_index);
	displayColumn(_contacts[index].getFirstName());
	displayColumn(_contacts[index].getLastName());
	displayColumn(_contacts[index].getNickname());
}

void PhoneBook::displayAllContact() const{
	std::cout << std::setfill('_') << std::setw(44) << "" << std::setfill(' ') <<std::endl;
	displayColumn("Index");
	displayColumn("First Name test");
	displayColumn("Last Name");
	displayColumn("Nickname");
	std::cout << std::endl;
	std::cout << std::setfill('_') << std::setw(44) << "" << std::setfill(' ') << std::endl;

	for (int j = 0; j < _currentSize; j++){
		displayContact(j);
		std::cout << std::endl;
	}
}

void PhoneBook::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void PhoneBook::search_contact(){
	int index;
	
	if (_currentSize == 0){
		std::cout << RED << "No entry for the moment..." << RESET << std::endl;
		return ;
	}
	clearScreen();
	displayAllContact();
	while (true) {
        std::cout << std::endl << "Enter the index of your Search: ";
        std::cin >> index;

		if (std::cin.eof())
			return ;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED << "Please enter a valid integer index." << RESET << std::endl;
        } else if (index <= 0 || index > _currentSize) {
            std::cout << RED << "Please, enter a correct index!" << RESET << std::endl;
        } else {
            break;
        }
    }
	
	std::cout << std::endl;
	clearScreen();
	std::cout << YELLOW << "Perfect Here is the information of this person" << RESET << std::endl;
	std::cout << std::setfill('_') << std::setw(30) << "" << std::setfill(' ') <<std::endl;
	std::cout << MAGENTA << "First name: " << RESET << _contacts[index - 1].getFirstName() << std::endl;
	std::cout << MAGENTA << "Last name: " << RESET << _contacts[index - 1].getLastName() << std::endl;
	std::cout << MAGENTA << "Nickname: " << RESET << _contacts[index - 1].getNickname() << std::endl;
	std::cout << MAGENTA << "Phone numbers: " << RESET << _contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << MAGENTA << "Secret: " << RESET << _contacts[index - 1].getSecret() << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string PhoneBook::getName() const{
	return (_contacts[0].getFirstName());
}