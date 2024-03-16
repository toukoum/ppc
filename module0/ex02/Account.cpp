/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:23:44 by rgiraud           #+#    #+#             */
/*   Updated: 2024/03/16 20:54:19 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	// static
	_totalAmount += initial_deposit;
	_nbAccounts++;

	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return ;
};

void	Account::_displayTimestamp( void )
{
	std::time_t tempsActuel = std::time(nullptr);
    std::tm* tempsLocal = std::localtime(&tempsActuel);
    std::ostringstream oss;
    oss << std::put_time(tempsLocal, "[%Y%m%d_%H%M%S] ");
	std::cout << oss.str();
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}
	
void Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}

int		Account::checkAmount( void ) const{
	return (0);
}

bool	Account::makeWithdrawal( int withdrawal ){
	
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal<< ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals--;
	_nbWithdrawals++;
	return (true);
}
