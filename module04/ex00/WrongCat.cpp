#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Created ! (default constructor)" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
	std::cout << "WrongCat Created ! (copy constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat KILLED ! (destructor)" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "(WrongCat) Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound( void ) const{
	std::cout << "(WrongCat make Sound) Miaou Miaou !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */