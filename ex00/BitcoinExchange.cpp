#include "BitcoinExchange.hpp"

/**
 * public
 */

BitcoinExchange::BitcoinExchange()
	: _value(0)
	, _exchange_rate(0)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::setDate(std::string date)
{
	_date = date;
}

void	BitcoinExchange::setValue(double value)
{
	_value = value;
}

void	BitcoinExchange::setExchangeRate(double exchange_rate)
{
	_exchange_rate = exchange_rate;
}


void	BitcoinExchange::printMultipledResult() const
{
	std::cout << _date << " => " << _value << " = " << multiplyValueAndExchangeRate() << std::endl;
}

/**
 * private
 */

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _date(other._date)
	, _value(other._value)
	, _exchange_rate(other._exchange_rate)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;

	_date = rhs._date;
	_value = rhs._value;
	_exchange_rate = rhs._exchange_rate;
	return *this;
}

double	BitcoinExchange::multiplyValueAndExchangeRate() const
{
	return _value * _exchange_rate;
}
