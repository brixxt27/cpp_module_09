#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN					"Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS	"Error: There are not appropriate arguments"
#define MSG_ERR_NOT_OPEN_CSV_FILE			"Error: There is not a data.csv. Please download a file!"

#include <map>
#include <iostream>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	float	getValue() const;
	float	getExchangeRate() const;

	void	setValue(float value);
	void	setExchangeRate(float exchangeRate);

	void	printMultipledResult() const;
	//double	multiplyValueAndExchangeRate() const;

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	//std::string	mDate;
	float	mValue;
	float	mExchangeRate;
};

#endif
