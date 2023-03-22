#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	PmergeMe	pmm;

    std::clock_t vector_start;
    std::clock_t vector_end;
    std::clock_t deque_start;
    std::clock_t deque_end;

	if (argc < 2)
	{
		std::cout << "Need to input more arguments." << std::endl;
		return 1;
	}

	if (pmm.isValidSequence(argv) == false)
		return 1;

	pmm.printBeforeData();

    vector_start = std::clock();
	pmm.sortVector(0, pmm.getVector().size() - 1);
    vector_end = std::clock();
	deque_start = std::clock();
	pmm.sortDeque(0, pmm.getDeque().size() - 1);
    deque_end  = std::clock();

	pmm.printAfterData();

	pmm.printSortingTime(pmm.getVector(), vector_end - vector_start, "vector");
	pmm.printSortingTime(pmm.getDeque(), deque_end - deque_start, "deque");

	return 0;
}
