#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::multimap<std::string, int>&	BitcoinExchange::getInputData()
{
	return input_data;
}

std::multimap<std::string, int>&	BitcoinExchange::getCsvData()
{
	return csv_data;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{

}
