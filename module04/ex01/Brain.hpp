#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );
		void changeIdea(int index, const std::string& newIdea); 
    	std::string getIdea(int index) const;

	private:
		std::string _ideas[100];
};


#endif /* *********************************************************** BRAIN_H */