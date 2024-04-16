/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:33:29 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 11:42:53 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("foo")
{
	for (int i = 0; i < 4; i++){
		_items[i] = nullptr;
	}
	std::cout << "(Character) Default Constructor called" << std::endl;
}

Character::Character( const Character & src ) : _name(src._name)
{
	for (int i = 0; i < 4; i++){
		if (src._items[i] != nullptr)
			this->_items[i] = src._items[i]->clone();
		else
			this->_items[i] = nullptr;
	}
	std::cout << "(Character) Copy Constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name){
	for (int i = 0; i < 4; i++){
		_items[i] = nullptr;
	}
	std::cout << "(Character) Parameters Constructor called" << std::endl;
} // parameters


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_items[i] != nullptr)
			delete(_items[i]);
	}
	
	std::cout << "(Character) Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++){
			if (rhs._items[i] != nullptr)
				this->_items[i] = rhs._items[i]->clone();
			else
				this->_items[i] = nullptr;
		}
	}
	return *this;
}



//std::ostream &			operator<<( std::ostream & o, Character const & i )
//{
//	//o << "Value = " << i.getValue();
//	return o;
//}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m) {
	int i = 0;
	while (i < 4)
	{
		if (_items[i] == m){
			std::cout << "(Character) You already have this Materia !" << std::endl;
			return ;
		}
		if (_items[i] == nullptr){
			std::cout << "(Character) " << _name << " well equip with " << m->getType() << std::endl;
			_items[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "(Character) equip => no enough place !" << std::endl;
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
	if (_items[idx] == nullptr)
		std::cout << "(Character) unequip => no materia !" << std::endl;
	else{
		std::cout << "(Character) " << _name << " well unequip: " << _items[idx]->getType() << std::endl;
		_items[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
	if (_items[idx] == nullptr)
		std::cout << "(Character) use => no materia !" << std::endl;
	else
		_items[idx]->use(target);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const{
	return (this->_name);
}

/* ************************************************************************** */