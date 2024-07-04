/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:43:09 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/04 10:05:35 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream> // read from file
#include <sstream> // std::stringstream
#include <iomanip>
#include <ctime>



class BitcoinExchange
{

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &file_db);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	
	void convert(const std::string& input_file);

	void display_db();


	class ErrorDataBaseFile : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error with opening dataBase File";
		}
	};

	class ErrorInputFile : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Error with opening input File";
		}
	};

	class InvalidInputFile : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "File doesn't start with this line: date | value";
		}
	};

	
private:
	std::map<std::string, float> _db;
	
	void makeConversion(const std::string& line);
	void loadDataBase(const std::string file_db);
	bool is_valid_value(float value);
	bool is_valid_date(std::string date);
	float getRateFromDate(const std::string& date);
};

//std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

#endif /* ************************************************* BITCOINEXCHANGE_H */