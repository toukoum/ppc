/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:05:55 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 12:16:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
int main()
{
	std::vector<int> tab;
	int value = -1;
	
	for (int i = 0; i < 10; i++)
		tab.push_back(i);

	std::vector<int>::const_iterator it = easyFind(tab, value);
	if (it != tab.end()) {
        std::cout << "Value " << value << " found at position: " << it - tab.begin() << std::endl;
    } else {
        std::cout << "Value " << value << " not found " << tab.end() - tab.begin() << std::endl;
    }
	return 0;
}
