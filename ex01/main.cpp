#include "RPN.hpp"

static bool	isValidExpression(std::string exp)
{
	std::istringstream	iss(exp);
	std::string	str_getline;

	while (std::getline(iss, str_getline, ' '))
	{
		std::cout << str_getline << std::endl;
	}
	return true;
}

int	main(int argc, char* argv[])
{
	std::string	exp(argv[1]);

	if (argc != 2)
	{
		std::cout << "It's not valid arguments" << std::endl;
		return 1;
	}
	if (isValidExpression(exp) == false)
	{
		return 1;
	}
	return 0;
}
