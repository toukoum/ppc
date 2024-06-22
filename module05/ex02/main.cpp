#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 1);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Fry");

        std::cout << "\n\nTrying to sign and execute ShrubberyCreationForm:" << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        std::cout << std::endl;

        std::cout << "\n\nTrying to sign and execute RobotomyRequestForm:" << std::endl;
        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        alice.signForm(robotomy);
        alice.executeForm(robotomy);

        std::cout << std::endl;

        std::cout << "\n\nTrying to sign and execute PresidentialPardonForm:" << std::endl;
        bob.signForm(pardon);
        bob.executeForm(pardon);

        alice.signForm(pardon);
        alice.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
