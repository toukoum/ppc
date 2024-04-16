/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:28:51 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/16 15:37:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\n========= PART 1 =========" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete(i);
		delete(j);
		delete(meta);
	}
	{
		std::cout << "\n\n========= PART 2 =========" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete(i);
		delete(meta);
	}

	{
		std::cout << "\n\n========= PART 3 =========" << std::endl;
		Animal animal;
		std::cout << animal << std::endl;
		animal.makeSound();
		
		Cat cat;
		std::cout << cat << std::endl;
		cat.makeSound();
		
		Dog dog;
		std::cout << dog << std::endl;
		dog.makeSound();

		animal = cat;
		std::cout << animal << std::endl;
		animal.makeSound();	
	}
	
}
