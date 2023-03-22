#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Need to input more arguments." << std::endl;
		return 1;
	}
	PmergeMe	pmm;

	if (pmm.isValidSequence(argv) == false)
		return 1;
	return 0;
}
