/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:54:30 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/19 15:17:42 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

/*
   	static int 	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals
*/


int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int	Account::getNbAccounts( void )
{ return (Account::_nbAccounts); }

int	Account::getTotalAmount( void )
{ return (Account::_totalAmount); }

int	Account::getNbDeposits( void )
{ return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals( void )
{ return (Account::_totalNbWithdrawals); }

int	Account::checkAmount(void) const
{ return (this->_amount); }

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
			";amount:" << this->checkAmount() << \
			";closed" << std::endl;
}


void	Account::_displayTimestamp(void)
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout << "[" << timenow.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << timenow.tm_hour <<
	std::setfill('0') << std::setw(2) << timenow.tm_min <<
	std::setfill('0') << std::setw(2) << timenow.tm_sec <<
	"] ";
}

void	Account::displayAccountsInfos( void )
{	
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << \
		";total:" << Account::getTotalAmount() << \
		";deposits:" << Account::getNbDeposits() << \
		";withdrawals:" << Account::getNbWithdrawals() << std::endl;	
}

Account::Account( int initial_deposit )
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts++;	
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
			";amount:" << this->checkAmount() << \
			";deposits:" << this->_nbDeposits << \
			";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
			";p_amount:" << this->_amount << \
			";deposit:" << deposit << \
			";amount:" << this->_amount + deposit << \
			";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
			";p_amount:" << this->_amount << \
			";withdrawal:";
	if(withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return(false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << \
		";amount:" << this->checkAmount() - withdrawal << \
		";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}
