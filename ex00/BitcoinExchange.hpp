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

	std::multimap<std::string, double>&	getValue();
	std::multimap<std::string, double>&	getExchangeRate();

	void	printMultipledResult() const;
	//double	multiplyValueAndExchangeRate() const;

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	std::multimap<std::string, double>	value;
	std::multimap<std::string, double>	exchange_rate;
};

#endif
