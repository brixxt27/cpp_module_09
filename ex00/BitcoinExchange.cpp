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

//float	BitcoinExchange::getValue() const
//{
//	return _value;
//}

//float	BitcoinExchange::getExchangeRate() const
//{
//	return _exchange_rate;
//}
void	BitcoinExchange::setDate(std::string date)
{
	_date = date;
}

void	BitcoinExchange::setValue(float value)
{
	_value = value;
}

void	BitcoinExchange::setExchangeRate(float exchange_rate)
{
	_exchange_rate = exchange_rate;
}


void	BitcoinExchange::printMultipledResult() const
{
	//std::cout << value.
}

/**
 * private
 */

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _value(other._value)
	, _exchange_rate(other._exchange_rate)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;

	_value = rhs._value;
	_exchange_rate = rhs._exchange_rate;
	return *this;
}
