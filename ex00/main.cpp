#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"

int	main(int argc, char* argv[])
{
	std::ifstream	fin_input;
	std::ifstream	fin_data;
	const char*		data_path = "./data.csv";
	const char*		input_file = argv[1];
	std::string		str_getline;
	BitcoinExchange	btc;

	if (argc > 2)
	{
		std::cout << MSG_ERR_NOT_APPROPRIATE_ARGUMENTS << std::endl;
		return EXIT_FAILURE;
	}

	fin_input.open(input_file, std::ifstream::in);
	if (fin_input.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN << std::endl;
		return EXIT_FAILURE;
	}

	fin_data.open(data_path, std::ifstream::in);
	if (fin_data.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN_CSV_FILE << std::endl;
		return EXIT_FAILURE;
	}

	while (std::getline(fin_input, str_getline))
	{

	}

	return 0;
}
