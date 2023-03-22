#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN	"Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS	"Error: There are not appropriate arguments"
#define MSG_ERR_NOT_OPEN_CSV_FILE	"Error: There is not a data.csv. Please download a file!"
#define MSG_ERR_NOT_EXIST_FIRST_LINE	"There is not a first line."
#define MSG_ERR_NOT_EXIST_COMMA	"There is not a comma in the csv file."
#define MSG_ERR_NOT_VALID_DATE	"It's not valid date in csv file"
#define MSG_ERR_NOT_VALID_VALUE	"It's not valid value"

#include "fstream"
#include <map>
#include <iostream>
#include <sstream>


class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	void	setDate(std::string date);
	void	setValue(double value);
	void	setExchangeRate(double exchange_rate);

	void	printMultipledResult() const;

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	double	multiplyValueAndExchangeRate() const;

	std::string	_date;
	double	_value;
	double	_exchange_rate;
};

#endif
