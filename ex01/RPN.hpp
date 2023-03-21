#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
public:
	RPN();
	~RPN();

	bool	executeRPN(std::string exp);
	void	printResult() const;

private:
	RPN(const RPN& other);
	RPN&	operator=(const RPN& rhs);
	
	std::stack<int>	_my_stack;
	int				_result;
};

#endif
