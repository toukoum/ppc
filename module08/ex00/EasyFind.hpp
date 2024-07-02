/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:57:41 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/30 12:19:57 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

template <typename T>
typename T::const_iterator easyFind(const T& container, int value){
	
	if (std::find(container.begin(), container.end(), value) != container.end())
		return (it);
	else
		return container.end();
	
}

#endif /* ******************************************************** EASYFIND_H */