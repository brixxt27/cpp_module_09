#include "BitcoinExchange.hpp"

/**
 * public
 */

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

float	BitcoinExchange::getValue() const
{
	return mValue;
}

float	BitcoinExchange::getExchangeRate() const
{
	return mExchangeRate;
}

void	BitcoinExchange::setValue(float value)
{
	mValue = value;
}

void	BitcoinExchange::setExchangeRate(float exchangeRate)
{
	mExchangeRate = exchangeRate;
}


void	BitcoinExchange::printMultipledResult() const
{
	//std::cout << value.
}

/**
 * private
 */

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: mValue(other.mValue)
	, mExchangeRate(other.mExchangeRate)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;

	mValue = rhs.mValue;
	mExchangeRate = rhs.mExchangeRate;
	return *this;
}
