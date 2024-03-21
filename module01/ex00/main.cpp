
#include "Zombie.hpp"

int main( void ) {
   std::string name;

    std::cout << "\033[32mCreating zombie on the stack.\033[0m" << std::endl;
    std::cout << "\033[36mZombie name: \033[0m" << std::flush;
    std::cin >> name;
    randomChump(name);

    std::cout << "\033[32m\nCreating zombie on the heap.\033[0m" << std::endl;
    std::cout << "\033[36mZombie name: \033[0m" << std::flush;
    std::cin >> name;

    Zombie *zombie2 = newZombie(name);
    delete zombie2;

    return 0;
}
