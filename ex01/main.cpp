#include "RPN.hpp"
static bool	isNumOneGreaterThanOperator(int cnt_num, int cnt_operator)
{
	if (cnt_num - 1 != cnt_operator)
		return false;
	return true;
}

static bool	isValidExpression(char*	exp)
{
	int	cnt_num = 0;
	int	cnt_operator = 0;
	int	i = 0;

	while (exp[i] != '\0')
	{
		if (exp[i] == ' ')
		{
			i++;
			continue;
		}

		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			cnt_operator++;
		}
		else if (exp[i] >= '0' && exp[i] <= '9')
		{
			if (exp[i + 1] >= '0' && exp[i + 1] <= '9')
			{
				std::cout << "The numbers used in this operation will always be less than 10." << std::endl;
				return false;
			}
			cnt_num++;
		}
		else
		{
			std::cout << "Your program must be able to handle operations with these tokens: +, -, /, *, numbers between 0 to 9." << std::endl;
			return false;
		}
		i++;
	}
	if (isNumOneGreaterThanOperator(cnt_num, cnt_operator) == false)
	{
		std::cout << "The number of numbers muse be 1 greater than the number of operators." << std::endl;
		return false;
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
	if (isValidExpression(argv[1]) == false)
	{
		return 1;
	}
	return 0;
}
