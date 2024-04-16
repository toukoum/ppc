/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:28:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 12:06:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{

	{
		std::cout << "========= PART 1 =========\n" << std::endl;
		Cure *cure = new Cure();
		Ice *ice = new Ice();
		Ice *ice3 = new Ice();
		Ice *ice2 = new Ice();
		Cure *cure2 = new Cure();
		//Cure *cure2 = new Cure();
		Character me = Character("toukoum");
		std::cout << std::endl;
		Character other = Character("bob");
		std::cout << std::endl;
		me.equip(cure);
		me.equip(ice);
		me.equip(ice2);
		me.equip(cure2);
		me.unequip(3);
		me.equip(ice3);
		me.use(0, other);
		me.use(1, other);
		std::cout << std::endl;
		std::cout << std::endl;

	}
	{
		std::cout << "\n\n========= PART 2 =========\n" << std::endl;
		Ice* ice = new Ice();
		Cure* cure = new Cure();
		std::cout << std::endl;
		// clone
		AMateria* clonedIce = ice->clone();
		AMateria* clonedCure = cure->clone();

		// check clone
		std::cout << "Cloned Ice type: " << clonedIce->getType() << std::endl;
		std::cout << "Cloned Cure type: " << clonedCure->getType() << std::endl;

		Character* character = new Character("Hero");

		character->equip(ice);
		character->equip(cure);

		Character* target = new Character("Villain");

		std::cout << std::endl;
		character->use(0, *target);
		character->use(1, *target);

		character->unequip(0);
		character->equip(ice); // verify if not delete !

		character->use(0, *target);

		delete character;
		delete target;
		delete clonedIce;
		delete clonedCure;

	}
	{
		std::cout << "\n\n========= PART 3 =========\n" << std::endl;

		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
		
		src->learnMateria(new Ice());
		
		std::cout << std::endl;
		std::cout << std::endl;
		
		src->learnMateria(new Cure());
		std::cout << std::endl;
		
		std::cout << std::endl;
		
		
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << std::endl;
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		std::cout << std::endl;
		std::cout << std::endl;

		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
}
