#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::multimap<std::string, double>&	BitcoinExchange::getValue()
{
	return mValue;
}

std::multimap<std::string, double>&	BitcoinExchange::getExchangeRate()
{
	return mExchangeRate;
}

void	BitcoinExchange::printMultipledResult() const
{
	//std::cout << value.
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
