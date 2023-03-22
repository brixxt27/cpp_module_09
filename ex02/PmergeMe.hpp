#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();
	PmergeMe&	operator=(const PmergeMe& rhs);

	bool	isValidSequence(char** argv);

private:
	std::vector<int>	vector;
	std::deque<int>		deque;
};

#endif
