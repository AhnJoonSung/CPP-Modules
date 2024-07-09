#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }
int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void)
{
	const int size = 4;
	std::string items[size] = {"accounts", "total", "deposits", "withdrawals"};
	int values[size] = {getNbAccounts(), getTotalAmount(), getNbDeposits(), getNbWithdrawals()};

	_displayTimestamp();
	for (int i = 0; i < size; i++)
	{
		std::cout << items[i] << ":" << values[i];
		if (i != size - 1)
			std::cout << ";";
	}
	std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created";
	std::cout << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	const int size = 5;
	std::string items[size] = {"index", "p_amount", "deposit", "amount", "nb_deposits"};
	int values[size] = {_accountIndex, p_amount, deposit, _amount, _nbDeposits};

	_displayTimestamp();
	for (int i = 0; i < size; i++)
	{
		std::cout << items[i] << ":" << values[i];
		if (i != size - 1)
			std::cout << ";";
	}
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool refused = false;
	int p_amount = _amount;

	if (p_amount < withdrawal)
		refused = true;
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
	}

	const int size = 5;
	std::string items[size] = {"index", "p_amount", "withdrawal", "amount", "nb_withdrawals"};
	int values[size] = {_accountIndex, p_amount, withdrawal, _amount, _nbWithdrawals};

	_displayTimestamp();
	for (int i = 0; i < size; i++)
	{
		std::cout << items[i] << ":";
		if (i == 2 && refused)
		{
			std::cout << "refused" << std::endl;
			return (false);
		}
		std::cout << values[i];
		if (i != size - 1)
			std::cout << ";";
	}
	std::cout << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	const int size = 4;
	std::string items[size] = {"index", "amount", "deposits", "withdrawals"};
	int values[size] = {_accountIndex, _amount, _nbDeposits, _nbWithdrawals};

	_displayTimestamp();
	for (int i = 0; i < size; i++)
	{
		std::cout << items[i] << ":" << values[i];
		if (i != size - 1)
			std::cout << ";";
	}
	std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "["
			  << 1900 + ltm->tm_year
			  << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << ltm->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << ltm->tm_hour
			  << std::setw(2) << std::setfill('0') << ltm->tm_min
			  << std::setw(2) << std::setfill('0') << ltm->tm_sec
			  << "] ";
}
