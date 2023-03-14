#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN "Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS "Error: There are not appropriate arguments"

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
};

#endif
