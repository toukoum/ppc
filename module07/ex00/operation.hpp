/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:56:00 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/28 14:06:18 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <iostream>
#include <string>

template <typename T>
const T &max(const T &x, const T &y)
{
	return (x >= y ? x : y);
}

template <typename T>
const T &min(const T &x, const T &y)
{
	return (x <= y ? x : y);
}

template <typename T>
void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

#endif /* ******************************************************* OPERATION_H */