#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN					"Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS	"Error: There are not appropriate arguments"
#define MSG_ERR_NOT_OPEN_CSV_FILE			"Error: There is not a data.csv. Please download a file!"
#define MSG_ERR_NOT_EXIST_FIRST_LINE_CSV	"There is a not first line in csv file."

#include "fstream"
#include <map>
#include <iostream>


class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	//float	getValue() const;
	//float	getExchangeRate() const;

	void	setValue(float value);
	void	setExchangeRate(float exchange_rate);

	void	printMultipledResult() const;
	//double	multiplyValueAndExchangeRate() const;

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	//std::string	mDate;
	float	_value;
	float	_exchange_rate;
};

#endif
