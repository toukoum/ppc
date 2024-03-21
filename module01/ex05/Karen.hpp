/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:39:30 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 16:09:39 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KAREN__
#define __KAREN__

#include <iostream>

class Karen{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Karen();
	~Karen();
	void complain( std::string level );

};

#endif