/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:38:15 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 13:53:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data random;

	random.name = "bob";
	random.age = 12;

	uintptr_t raw = Serializer::serialize(&random);

	std::cout << "raw value of serialize data: " << raw << std::endl;

	Data *random2 = Serializer::deserialize(raw);
	
	std::cout << "deserialize data name: " << random2->name << std::endl;
	std::cout << "deserialize data age: " << random2->age << std::endl;

	if (&random == random2) {
    std::cout << "\nSerialization and deserialization successful." << std::endl;
	} else {
		std::cout << "\nError in serialization and deserialization." << std::endl;
	}
	return 0;
}
