#include "BitcoinExchange.hpp"

static bool	isValidDate(std::string str_date)
{
	static_cast<void>(str_date);
	return true;
}

static bool	isValidRate(double rate)
{
	return rate >= 0;
}

int	main(int argc, char* argv[])
{
	std::ifstream	fin_input;
	std::ifstream	fin_csv;

	const char*		input_path = argv[1];
	const char*		default_csv_path = "./data.csv";
	char*			csv_path;

	BitcoinExchange	btc;

	/**
	 * Control files
	 */
	if (argc > 3)
	{
		std::cout << MSG_ERR_NOT_APPROPRIATE_ARGUMENTS << std::endl;
		return EXIT_FAILURE;
	}

	fin_input.open(input_path, std::ifstream::in);
	if (fin_input.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN << std::endl;
		return EXIT_FAILURE;
	}

	if (argc == 3)
	{
		csv_path = argv[2];
		fin_csv.open(csv_path, std::ifstream::in);
	}
	else
	{
		fin_csv.open(default_csv_path, std::ifstream::in);
	}

	if (fin_csv.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN_CSV_FILE << std::endl;
		return EXIT_FAILURE;
	}
	
	/**
	 * Get data to make map of data.csv
	 */
	std::string	str_getline;
	const std::string	first_line_of_data = "date,exchange_rate";


	std::map<std::string, double>	map_csv;
	std::map<std::string, double>::iterator	it;


	std::getline(fin_csv, str_getline);
	if (str_getline != first_line_of_data)
	{
		std::cout << MSG_ERR_NOT_EXIST_FIRST_LINE_CSV << std::endl;
		return EXIT_FAILURE;
	}
	while (std::getline(fin_csv, str_getline))
	{
		std::string	str_date;
		std::string	str_exchange_rate;
		std::istringstream iss(str_getline);

		double	exchange_rate;

		std::getline(iss, str_date, ',');
		if (isValidDate(str_date) == false)
		{
			std::cout << MSG_ERR_NOT_VALID_DATE << std::endl;
			return EXIT_FAILURE;
		}

		std::getline(iss, str_exchange_rate, '\0');
		exchange_rate = std::strtod(str_exchange_rate.c_str(), NULL);
		if (isValidRate(exchange_rate) == false)
		{
			std::cout << MSG_ERR_NOT_VALID_VALUE << std::endl;
			return EXIT_FAILURE;
		}
		map_csv.insert(std::pair<std::string, double>(str_date, exchange_rate));
	}

	return 0;
}
