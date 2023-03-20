#include "BitcoinExchange.hpp"

static bool	isValidDate(std::string str_date)
{
	std::istringstream	iss(str_date);

	int	year;
	int	month;
	int	day;
	char	del1;
	char	del2;

    std::tm timeinfo = {};

	iss >> year >> del1 >> month >> del2 >> day;


    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
	std::mktime(&timeinfo);
    
	if (del1 != '-' 
		|| del2 != '-'
		|| timeinfo.tm_year != year - 1900
		|| timeinfo.tm_mon != month - 1
		|| timeinfo.tm_mday != day
	)
		return false;
	return true;
}

static bool	isValidRate(double rate)
{
	return rate >= 0;
}

static bool	isLargeNumber(double value)
{
	return (value < 1000);
}

static bool isPositiveNumber(double value)
{
	return (value > 0);
}

int	main(int argc, char* argv[])
{
	std::ifstream	fin_input;
	std::ifstream	fin_first_csv;
	std::ifstream	fin_second_csv;

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

	fin_first_csv.open(default_csv_path, std::ifstream::in);
	if (fin_first_csv.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN_CSV_FILE << std::endl;
		return EXIT_FAILURE;
	}

	if (argc == 3)
	{
		csv_path = argv[2];
		fin_second_csv.open(csv_path, std::ifstream::in);
		if (fin_second_csv.is_open() == false)
		{
			std::cout << MSG_ERR_NOT_OPEN_CSV_FILE << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	/**
	 * Get data to make map of first data.csv
	 */
	std::string	str_getline;
	const std::string	first_line_of_data = "date,exchange_rate";

	std::map<std::string, double>	map_csv;

	std::getline(fin_first_csv, str_getline);
	if (str_getline != first_line_of_data)
	{
		std::cout << MSG_ERR_NOT_EXIST_FIRST_LINE << std::endl;
		return EXIT_FAILURE;
	}
	while (std::getline(fin_first_csv, str_getline))
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

	/**
	 * Get data to make map of second data.csv
	 */
	
	if (argc == 3)
	{
		std::getline(fin_second_csv, str_getline);
		if (str_getline != first_line_of_data)
		{
			std::cout << MSG_ERR_NOT_EXIST_FIRST_LINE << std::endl;
			return EXIT_FAILURE;
		}
		while (std::getline(fin_second_csv, str_getline))
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
	}


	/**
	 * multiply exchange rate and value and print this
	*/
	const std::string	first_line_of_input = "date | value";

	std::getline(fin_input, str_getline);
	if (str_getline != first_line_of_input)
	{
		std::cout << MSG_ERR_NOT_EXIST_FIRST_LINE << std::endl;
		return EXIT_FAILURE;
	}
	while (std::getline(fin_input, str_getline))
	{
		std::string	str_date;
		std::string	del;
		std::string	str_value;
		std::istringstream iss(str_getline);

		double	value;

		iss >> str_date >> del >> str_value;

		if (isValidDate(str_date) == false)
		{
			std::cout << "Error: bad input => " << str_date << std::endl;
			continue;
		}

		value = std::strtod(str_value.c_str(), NULL);
		if (isLargeNumber(value) == false)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (isPositiveNumber(value) == false)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (del != "|")
		{
			std::cout << "It's not a correct delimeter." << std::endl;
			continue;
		}
		std::cout << str_date << " => " << str_value << " = " << std::endl;

	}

	return 0;
}
