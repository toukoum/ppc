/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:43:14 by rgiraud           #+#    #+#             */
/*   Updated: 2024/07/03 15:46:42 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &file_db)
{
	loadDataBase(file_db);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db(src._db) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_db = rhs._db;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::loadDataBase(const std::string file_db)
{
	std::string line;
	std::string date;
	std::string srate;
	float rate;
	std::ifstream file(file_db);

	if (!file.is_open())
		throw ErrorDataBaseFile();

	getline(file, line);
	while (getline(file, line))
	{
		date = line.substr(0, line.find(","));
		srate = line.substr(line.find(",") + 1, line.size());
		std::stringstream ss(srate);
		ss >> rate;
		_db.insert(std::pair<std::string, float>(date, rate));
	}

	file.close();
}

void BitcoinExchange::display_db()
{
	std::map<std::string, float>::iterator it = _db.begin();
	while (it != _db.end())
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "Date: " << it->first
				  << ", Rate: " << it->second << std::endl;
		++it;
	}
}

void BitcoinExchange::convert(const std::string &input_file)
{
	std::ifstream file(input_file);
	std::string line;

	if (!file.is_open())
		throw ErrorInputFile();

	getline(file, line);
	if (line != "date | value")
	{
		throw InvalidInputFile();
	}

	while (getline(file, line))
		makeConversion(line);

	file.close();
}

#include <string>
#include <cctype>

bool BitcoinExchange::is_valid_date(std::string date) {
    if (date[4] != '-' || date[7] != '-') return false;

    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    if (year_str.size() != 4 || month_str.size() != 2 || day_str.size() != 2)
        return false;

    for (int i = 0; i < 4; i++)
		if (!std::isdigit(year_str[i]))
			return (false);
	
	for (int i = 0; i < 2; i++)
		if (!std::isdigit(month_str[i]) || !std::isdigit(day_str[i]))
			return (false);
	
    int year = std::stoi(year_str);
    int month = std::stoi(month_str);
    int day = std::stoi(day_str);

    if (month < 1 || month > 12) return false;

    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int days_in_month[] = { 31, (is_leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1 || day > days_in_month[month - 1]) return false;

	std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int current_year = now->tm_year + 1900;
    int current_month = now->tm_mon + 1;
    int current_day = now->tm_mday;

    // Comparaison avec la date actuelle
    if (year > current_year ||
        (year == current_year && month > current_month) ||
        (year == current_year && month == current_month && day > current_day)) {
        return false;
    }
    
	if (year < 2009 ||
        (year == 2009 && month == 01 && day < 02)) {
        return false;
    }

    return true;
}

bool BitcoinExchange::is_valid_value(float value)
{
	if (value > 1000){
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	} else if (value < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return (false);
	}
	return (true);
}

float BitcoinExchange::getRateFromDate(const std::string& date){
	// take the firt lower date of date in _db
	std::map<std::string, float>::iterator it = _db.lower_bound(date);
	
	// if dont find date of not exactly the same, take the previous one
	if (it == _db.end() || it->first != date){
		if (it == _db.begin())
			return (0.0);
		--it;
	}

	// return the rate
	return (it->second);
}

void BitcoinExchange::makeConversion(const std::string &line)
{
	if (line.find("|") == std::string::npos){
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string date = line.substr(0, line.find("|"));
	if (!is_valid_date(date)){
		std::cout << "Error: invalid Date => " << date << std::endl;
		return ;
	}

	std::string svalue = line.substr(line.find("|") + 1, line.size());
	std::stringstream ss(svalue);
	float value;
	float rate;
	ss >> value;

	if (!is_valid_value(value))
		return;

	rate = getRateFromDate(date);

	std::cout << date << " => " << value << " = " << rate * value << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */