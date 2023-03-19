#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[])
{
	std::ifstream	fin_input;
	std::ifstream	fin_csv;

	const char*		input_path = argv[1];
	const char*		default_csv_path = "./data.csv";
	char*			csv_path;

	BitcoinExchange	btc;

	std::map<std::string, float>	map_csv;

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

	//size_t	pos = 0;

	std::multimap<std::string, float>::iterator	it;

	std::getline(fin_csv, str_getline);
	if (str_getline != first_line_of_data)
	{
		std::cout << MSG_ERR_NOT_EXIST_FIRST_LINE_CSV << std::endl;
		return EXIT_FAILURE;
	}
	while (std::getline(fin_csv, str_getline))
	{
		//if ((pos = str_getline.find(' ')) == std::string::npos)
		//{
		//	std::cout << "There is not a space" << std::endl;
		//	return EXIT_FAILURE;
		//}
		//btc.getValue().insert(std::pair<std::string, double>(str_getline.substr(0, pos), i));
	}

	//for (it = btc.getValue().begin(); it != btc.getValue().end(); it++)
	//{
	//	std::cout << (*it).first << std::endl;
	//}
	//for (it = btc.getValue().begin(); it != btc.getValue().end(); it++)
	//{
	//	std::cout << (*it).second << std::endl;
	//}

	return 0;
}
