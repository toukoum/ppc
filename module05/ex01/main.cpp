/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:44 by rgiraud           #+#    #+#             */
/*   Updated: 2024/06/22 20:26:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 1, 5);
        Form formB("FormB", 3, 5);

        bob.signForm(formA); // Should sign successfully
        bob.signForm(formB); // Should fail to sign

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
