#include "BitcoinExchange.hpp"
#include "fstream"
#include "iostream"

int	main(int argc, char* argv[])
{
	std::ifstream	fin;
	const char*	input_file = argv[1];

	if (argc > 2)
	{
		std::cout << MSG_ERR_NOT_APPROPRIATE_ARGUMENTS << std::endl;
		return EXIT_FAILURE;
	}

	fin.open(input_file, std::ifstream::in);
	if (fin.is_open() == false)
	{
		std::cout << MSG_ERR_NOT_OPEN << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}
