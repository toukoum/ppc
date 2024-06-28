/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:46 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/28 23:00:47 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    iter(arr1, 5, &display);
	std::cout << std::endl;
    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    iter(arr2, 5, &display);
	std::cout << std::endl;

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    iter(arr3, 5, &display);
	std::cout << std::endl;

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    iter(arr4, 5, &display);
	std::cout << std::endl;

    return 0;
}