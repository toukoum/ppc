/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:23:11 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/20 12:49:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>


class Contact{

public:
	
	Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret);
	Contact();
	~Contact( void );

	// Accessors
	std::string getFirstName( void ) const;
	std::string getLastName( void ) const;
	std::string getPhoneNumber( void ) const;
	std::string getSecret( void ) const;
	std::string getNickname( void ) const;
	
private:
	
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _secret;
};

#endif
