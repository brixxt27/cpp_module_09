#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define MSG_ERR_NOT_OPEN "Error: could not open file."
#define MSG_ERR_NOT_APPROPRIATE_ARGUMENTS "Error: There are not appropriate arguments"
#define MSG_ERR_NOT_OPEN_CSV_FILE "Error: There is not a data.csv. Please download a file!"

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	std::multimap<std::string, int>&	getInputData();
	std::multimap<std::string, int>&	getCsvData();

private:
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	std::multimap<std::string, int>	input_data;
	std::multimap<std::string, int>	csv_data;
};

#endif
