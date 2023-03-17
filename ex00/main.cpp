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
	
	std::size_t	pos = 0;
	int			i = 0;
	std::multimap<std::string, double>::iterator	it;

	while (std::getline(fin_input, str_getline))
	{
		if ((pos = str_getline.find(' ')) == std::string::npos)
		{
			std::cout << "There is not a space" << std::endl;
			return EXIT_FAILURE;
		}
		//if (i == 0)
		//{
			pos = str_getline.find(' ');
		//}
		btc.getValue().insert(std::pair<std::string, double>(str_getline.substr(0, pos), i));
		i++;
	}

	for (it = btc.getValue().begin(); it != btc.getValue().end(); it++)
	{
		std::cout << (*it).first << std::endl;
	}
	for (it = btc.getValue().begin(); it != btc.getValue().end(); it++)
	{
		std::cout << (*it).second << std::endl;
	}

	return 0;
}
