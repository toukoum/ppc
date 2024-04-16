#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : _type("animal")
{
	std::cout << "Animal Created ! (default constructor)" << std::endl;
}

Animal::Animal( const Animal & src ) : _type(src._type)
{
	std::cout << "Animal Created ! (copy constructor)" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type){
	std::cout << "Animal Created ! (Parameters constructor)" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal KILLED ! (destructor)" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &	Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal assigned ! (assignation)" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "(Animal) Type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Animal::getType( void ) const{
	return(this->_type);
}

/* ************************************************************************** */