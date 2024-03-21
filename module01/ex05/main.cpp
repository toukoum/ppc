/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:08:41 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/22 00:09:18 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


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

int main() {
    Harl karen;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        setColor(levels[i]);
        std::cout << "[ " << levels[i] << " ]" << std::endl;
        karen.complain(levels[i]);
        std::cout << "\033[0m";
        std::cout << std::endl;
    }

    return 0;
}