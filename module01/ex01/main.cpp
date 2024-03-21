
#include "Zombie.hpp"

int main( void ) {
   
	int numberZombie;
	std::string name;
	Zombie* zombieH;
    std::cout << "\033[32mCreating horde of zombie\033[0m" << std::endl;
    std::cout << "\033[36mNumber of Zombie: \033[0m" << std::flush;
    std::cin >> numberZombie;    
	std::cout << "\033[36mName of each Zombie: \033[0m" << std::flush;
    std::cin >> name;

	zombieH = zombieHorde(numberZombie, name);

	for (int i = 0; i < numberZombie; i++)
		zombieH[i].announce();

	delete [] zombieH;
    return 0;
}