
#include "Zombie.hpp"

int main( void ) {
   std::string name;

    std::cout << "\033[32mCreating zombie on the stack.\033[0m" << std::endl;
    std::cout << "\033[36mZombie name: \033[0m" << std::flush;
    std::cin >> name;

    Zombie zombie1(name);
    
    std::cout << "\033[32mCreating zombie on the heap.\033[0m" << std::endl;
    std::cout << "\033[36mZombie name: \033[0m" << std::flush;
    std::cin >> name;

    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    std::cout << "\033[36mCalling randomChump().\033[0m" << std::endl;
    randomChump("Zidane");

    return 0;
}
