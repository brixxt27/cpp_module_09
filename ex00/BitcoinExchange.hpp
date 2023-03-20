#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN	"Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS	"Error: There are not appropriate arguments"
#define MSG_ERR_NOT_OPEN_CSV_FILE	"Error: There is not a data.csv. Please download a file!"
#define MSG_ERR_NOT_EXIST_FIRST_LINE	"There is not a first line."
#define MSG_ERR_NOT_EXIST_COMMA	"There is not a comma in the csv file."
#define MSG_ERR_NOT_VALID_DATE	"It's not valid date"
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

	//float	getValue() const;
	//float	getExchangeRate() const;

	void	setDate(std::string date);
	void	setValue(float value);
	void	setExchangeRate(float exchange_rate);

	void	printMultipledResult() const;
	//double	multiplyValueAndExchangeRate() const;

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	std::string	_date;
	float	_value;
	float	_exchange_rate;
};

#endif
