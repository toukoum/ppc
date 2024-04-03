/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:15:58 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/22 15:34:13 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int my_replace(std::string s1, std::string s2, std::string nameInFile){
	
	std::ifstream inFile(nameInFile.c_str());
	if (!inFile)
	{
		std::cerr << "\033[31mError:\033[0m Failed to open the file '" << nameInFile << "'.\n"
          << "Please check that the file exists, that you have permission to read it,\n"
          << "and that the file name is correct." << std::endl;
		return (1);	
	}
	
	bool is_find = false;
	std::ofstream outfile((nameInFile + ".replace").c_str());
	std::string line;
	std::size_t found = 0;
	
	if (!outfile) {
        std::cerr << "\033[31mError:\033[0m Failed to create the output file '" << nameInFile << ".replace'.\n"
                  << "Please check your permissions and the file name." << std::endl;
        return (1);
    }
	
	while (is_find || std::getline(inFile, line))
	{
		if (!is_find)
			found = line.find(s1);
		else
			found = line.find(s1, found + s2.length());
		is_find = false;
		if (found != std::string::npos){
			line.erase(found, s1.length());
			line.insert(found, s2);
			is_find = true;
		}
		else{
			outfile << line << "\n";
			found = 0;
		}
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	
	if (argc != 4)
	{
		std::cerr << "\033[31mError:\033[0m Incorrect number of arguments.\n"
          << "Usage: " << argv[0] << " <filename> <s1> <s2>\n"
          << "Please provide exactly three arguments: a filename and two non-empty strings (s1 and s2)." << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty() || s2.empty())
	{
		std::cerr << "\033[31mError:\033[0m The strings 's1' and 's2' cannot be empty.\n"
          << "Please ensure that both 's1' and 's2' are provided as non-empty arguments." << std::endl;
		return (1);
	}

	my_replace(s1, s2, argv[1]);
	
	return 0;
}
