#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
: _vector(other._vector)
, _deque(other._deque)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	_vector = rhs._vector;
	_deque = rhs._deque;
	return *this;
}

bool	PmergeMe::isValidSequence(char** argv)
{
	int i = 1;
	long	value;

	while (argv[i])
	{
		value = std::strtol(argv[i], NULL, 10);

		if (value < 1 || value > INT_MAX)
		{
			std::cout << "error: Out of range" << std::endl;
			return false;
		}
		else
		{
			_vector.push_back(static_cast<int>(value));
			_deque.push_back(static_cast<int>(value));
		}
		i++;
	}
	return true;
}

void	PmergeMe::printBeforeData()
{
	std::cout << "Before: ";

	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printAfterData()
{
	std::cout << "After: ";
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int>    PmergeMe::getVector() const
{
	return _vector;
}

std::deque<int>    PmergeMe::getDeque() const
{
	return _deque;
}

void    PmergeMe::sortVector(int left, int right)
{
	if (right - left > K)
	{
		int half = (left + right) / 2;

		sortVector(left, half);
		sortVector(half + 1, right);
		mergeVector(left, half, right);
	}
	else
	{
		insertionVector(left, right);
	}
}

void    PmergeMe::sortDeque(int left, int right)
{
	if (right - left > K)
	{
		int half = (left + right) / 2;
		
		sortDeque(left, half);
		sortDeque(half + 1, right);
		mergeDeque(left, half, right);
	}
	else
	{
		insertionDeque(left, right);
	}
}

void PmergeMe::mergeVector(int left, int half, int right)
{
	std::vector<int> LA;
	std::vector<int> RA;

	int LA_index = 0;
	int RA_index = 0;

	LA.assign(_vector.begin() + left, _vector.begin() + half + 1);
	RA.assign(_vector.begin() + half + 1, _vector.begin() + right + 1);
	
	for (int i = left; i < right + 1; i++)
	{
		if (RA_index == right - half)
		{
			_vector[i] = LA[LA_index];
			LA_index++;
		}
		else if (LA_index == half - left + 1)
		{
			_vector[i] = RA[RA_index];
			RA_index++;
		}
		else if (RA[RA_index] > LA[LA_index])
		{
			_vector[i] = LA[LA_index];
			LA_index++;
		}
		else
		{
			_vector[i] = RA[RA_index];
			RA_index++;
		}
	}
}

void PmergeMe::mergeDeque(int left, int half, int right)
{
	std::deque<int> LA;
	std::deque<int> RA;

	int LA_index = 0;
	int RA_index = 0;

	LA.assign(_deque.begin() + left, _deque.begin() + half + 1);
	RA.assign(_deque.begin() + half + 1, _deque.begin() + right + 1);
	
	for (int i = left; i < right + 1; i++)
	{
		if (RA_index == right - half)
		{
			_deque[i] = LA[LA_index];
			LA_index++;
		}
		else if (LA_index == half - left + 1)
		{
			_deque[i] = RA[RA_index];
			RA_index++;
		}
		else if (RA[RA_index] > LA[LA_index])
		{
			_deque[i] = LA[LA_index];
			LA_index++;
		}
		else
		{
			_deque[i] = RA[RA_index];
			RA_index++;
		}
	}
}

void	PmergeMe::insertionVector(int left, int right)
{
    for (int i = left; i < right; i++)
	{
        int temp = _vector[i + 1];
        int j = i + 1;
        while (j > left && _vector[j - 1] > temp)
		{
            _vector[j] = _vector[j - 1];
            j--;
        }
        _vector[j] = temp;
    }
}

void	PmergeMe::insertionDeque(int left, int right)
{
    for (int i = left; i < right; i++)
	{
        int temp = _deque[i + 1];
        int j = i + 1;
        while (j > left && _deque[j - 1] > temp)
		{
            _deque[j] = _deque[j - 1];
            j--;
        }
        _deque[j] = temp;
    }
}
