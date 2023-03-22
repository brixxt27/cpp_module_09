#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define K	10

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();

	bool	isValidSequence(char** argv);
	void	printBeforeData();
	void	printAfterData();

	std::vector<int>	getVector() const;
	std::deque<int>	getDeque() const;

	void	sortVector(int left, int right);
	void	sortDeque(int left, int right);

	void	mergeVector(int left, int half, int right);
	void	mergeDeque(int left, int half, int right);

	void	insertionVector(int left, int right);
	void	insertionDeque(int left, int right);

	template <typename cont>
	void    printSortingTime(cont con, std::clock_t sortTime, std::string str) const;

private:
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator=(const PmergeMe& rhs);

	std::vector<int>	_vector;
	std::deque<int>		_deque;
};

template <typename cont>
void    PmergeMe::printSortingTime(cont con, std::clock_t sortTime, std::string str) const
{
	std::cout << "Time to process a range of " << con.size()
		<< " elements with std::" 
		<< str
		<< " : " << sortTime << std::endl;
}

#endif
