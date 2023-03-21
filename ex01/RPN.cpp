#include "RPN.hpp"

RPN::RPN()
{
}


RPN::RPN(const RPN& other)
	: _my_stack(other._my_stack)
	, _result(other._result)
{
}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this == &rhs)
		return *this;
	
	_my_stack = rhs._my_stack;
	_result = rhs._result;
	return *this;
}

RPN::~RPN()
{
}

bool	RPN::executeRPN(std::string exp)
{
	for (std::string::iterator it = exp.begin(); it != exp.end(); it++)
	{
		if (*it == ' ')
		{
			continue;
		}		
		else if (*it >= '0' && *it <= '9')
		{
			char	str[2];

			str[1] = '\0';
			str[0] = *it;
			_my_stack.push(std::atoi(str));
		}
		else
		{
			int	num1;
			int	num2;

			if (_my_stack.size() < 2)
			{
				std::cout << "Invalid expression!" << std::endl;
				return false;
			}
			num2 = _my_stack.top();
			_my_stack.pop();
			num1 = _my_stack.top();
			_my_stack.pop();

			if (*it == '+')
			{
				_my_stack.push(num1 + num2);
			}
			else if (*it == '-')
			{
				_my_stack.push(num1 - num2);
			}
			else if (*it == '*')
			{
				_my_stack.push(num1 * num2);
			}
			else
			{
				if (num2 == 0)
				{
					std::cout << "error: floating point exception" << std::endl;
					return false;
				}
				_my_stack.push(num1 / num2);
			}
		}
	}
	_result = _my_stack.top();
	_my_stack.pop();
	
	if (_my_stack.size() != 0)
	{
		std::cout << "Invalid expression!" << std::endl;
		return false;
	}
	return true;
}

void	RPN::printResult() const
{
	std::cout << _result << std::endl;
}
