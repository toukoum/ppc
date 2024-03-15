/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:23:11 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/15 13:37:42 by rgiraud          ###   ########.fr       */
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
	void setFirstName(std::string firstName);
	std::string getLastName( void ) const;
	void setLastName(std::string lastName);
	std::string getPhoneNumber( void ) const;
	void setPhoneNumber(std::string phoneNumber);
	std::string getSecret( void ) const;
	void setSecret(std::string secret);
	std::string getNickname( void ) const;
	void setNickName(std::string secret);
	
	private:
	
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _secret;
};

#endif
