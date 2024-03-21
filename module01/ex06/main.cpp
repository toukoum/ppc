/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:08:41 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/21 22:35:18 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"


void setColor(const std::string& level) {
    if (level == "DEBUG")
        std::cout << "\033[36m";
    else if (level == "INFO")
        std::cout << "\033[32m";
    else if (level == "WARNING")
        std::cout << "\033[33m";
    else if (level == "ERROR")
        std::cout << "\033[31m";
}

int main(int argc, char *argv[]) {

	if (argc != 2){
		std::cerr << "\033[31mError:\033[0m Incorrect number of arguments.\n"
          << "Usage: " << argv[0] << " <log_level> (DEBUG/INFO/WARNING/ERROR)\n" << std::endl;
		return (1);
	}
	
    Karen karen;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
		if (argv[1] == levels[i]){
			karen.complain(i);
			return (0);
		}
        setColor(levels[i]);
    }
	std::cerr << "\033[31m[ Probably complaining about insignificant problems ]" << std::endl;
    return (1);
}