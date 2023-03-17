#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::multimap<std::string, double>&	BitcoinExchange::getValue()
{
	return value;
}

std::multimap<std::string, double>&	BitcoinExchange::getExchangeRate()
{
	return exchange_rate;
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
