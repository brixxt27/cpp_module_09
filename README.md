# cpp_module_09
### 이슈 관리: [전체 이슈 list](https://github.com/brixxt27/cpp_module_09/issues/1)

# Chapter III
## Module-specific rules
- It is mandatory to use the standard containers to perform each exercise in this module.
- 이번 모듈에서 각 예제를 해결하기 위해선 표준 컨테이너를 사용하는 것은 필수이다.

- Once a container is used you cannot use it for the rest of the module.
- 컨테이너가 사용되면 모듈의 나머지 부분에선 사용할 수 없다.

- It is advisable to read the subject in its entirety before doing the exercises.
- 예제를 풀기 전에 과제 전체를 읽는 것을 추천합니다.

- You must use at least one container for each exercise with the exception of exercise 02 which requires the use of two containers.
- 당신은 두 개의 컨테이너 사용을 요구하는 ex02 를 제외하고 각 예제에서 최소한의 컨테이너를 사용해야 한다.

- You must submit a Makefile for each program which will compile your source files
to the required output with the flags -Wall, -Wextra and -Werror.
- 당신은 -Wall, -Wextra, -Werror 플래그와 함께 요구되는 출력으로 소스 파일들을 컴파일할 각 프로그램을 위한 Makefile 을 제출해야 합니다.

- You must use c++, and your Makefile must not relink.
- c++ 을 사용해야 하고, Makefile 은 relink 하면 안 됩니다.

- Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
- Makefile 은 최소 $(NAME), all, clean, fclean, re 의 룰을 포함해야 합니다.

# Exercise 00: Bitcoin Exchange 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_09.git
cd cpp_module_09/ex00
make
./
```
## Summary
- Turn-in directory : ex00/
- Files to turn in : Makefile, main.cpp, BitcoinExchange.{cpp, hpp}
- Forbidden functions : None
## Detail
- You have to create a program which outputs the value of a certain amount of bitcoin on a certain date.
- 당신은 특정 날짜에 일정한 양의 비트코인의 값을 출력하는 프로그램을 만들어야 합니다.

- This program must use a database in csv(comma-separated values) format which will represent bitcoin price over time.
- 이번 과제는 시간 경과에 따라 비트코인 값을 나타내는 csv(comma-separated values) 형식의 database 를 사용해야 합니다.

- This database is provided with this subject.
- 데이터베이스는 과제에서 제공된다.

- The program will take as input a second database, storing the different prices/dates to evaluate.
- 프로그램은 평가할 다양한 값/날짜로 정렬된 두 번째 database를 입력으로 사용합니다.

- Your program must respect these rules:
- 당신의 프로그램은 이 규칙들을 따라야 합니다.
	- The program name is btc.
	- 프로그램 이름은 btc 이다.

	- Your program must take a file as argument.
	- 당신의 프로그램은 인자로 하나의 파일을 사용해야 한다.

	- Each line in this file must use the following format: "date | value".
	- 인자로 사용하는 이 파일에 있는 각 줄은 다음에 따라오는 형식을 사용해야 한다.: "date | value".

	- A valid date will always be in the following format: Year-Month-Day.
	- 유효한 날짜는 항상 다음 형식이다: Year-Month-Day.

	- A valid value must be either a float or a positive integer between 0 and 1000.
	- 유효한 값은 float 이거나 0 ~ 1000 사이인 양의 정수이어야 한다.

- You must use at least one container in your code to validate this exercise.
- 당신은 이 과제에서 유효성을 검사하려면 당신의 코드에 최소 하나의 컨테이너를 사용해야 한다.

- You should handle possible errors with an appropriate error message.
- 당신은 적절한 에러 메시지로 가능한 에러들을 다뤄야 한다.

- Here is an example of an input.txt file:
- 이것은 input.txt 파일의 예입니다.
```
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>

```
- Your program will use the value in your input file and the associated date.
- 당신의 프로그램은 당신의 input 파일과 연관된 날짜에서의 값을 사용할 것이다.

- Your program must display on the standard output the result of the value multiplied by the exchange rate according to the date indicated in your database.
- 당신의 프로그램은 데이터베이스에 표시된 날짜에 따라 환율을 곱한 값의 결과를 표준 출력으로 표시해야 합니다.

- The following is an example of the program’s use.
- 다음은 프로그램 사용의 예입니다.
```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```
- Warning: The container(s) you use to validate this exercise will no longer be usable for the rest of this module.
- 주의: 당신이 이 예제를 해결하기 위해 사용하는 container(s) 는 이 모듈의 나머지 부분에서 더 이상 사용할 수 없습니다.

# Exercise 01: Reverse Polish Notation 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_09.git
cd cpp_module_09/ex01
make
./
```
## Summary
- Turn-in directory : ex01/
- Files to turn in : Makefile, main.cpp, RPN.{cpp, hpp}
-Forbidden functions : None
## Detail
- You must create a program with these constraints:
- 이들을 포함한 프로그램을 만들어야 합니다:

	- The program name is RPN.
	- 프로그램의 이름은 RPN입니다.

	- Your program must take an inverted Polish mathematical expression as an argument.
	- 당신의 프로그램은 인자로 거꾸로된 Polish methematical expression 을 사용해야 합니다.

	- The numbers used in this operation will always be less than 10.
	- 연산 안에서 사용되는 숫자들은 항상 10 보다 작습니다.

	- Your program must process this expression and output the correct result on the standard output.
	- 당신의 프로그램은 이 수식을 풀어야 하고, 표준 출력에 올바른 결과를 출력해야 합니다.

	- If an error occurs during the execution of the program an error message should be displayed on the standard output.
	- 만약 프로그램 실행 중 에러가 발생한다면, 에러 메시지는 표준 출력에 표시되어야 합니다.

	- Your program must be able to handle operations with these tokens: "+ - / *".
	- 프로그램은 다음 나오는 token들이 들어 있는 수식들을 다룰 수 있어야 합니다: "+ - / *".

- You must use at least one container in your code to validate this exercise.
- 당신은 이번 예제를 통과하기 위해 코드 안에 최소 하나의 컨테이너를 포함해야 합니다.

- You don’t need to manage the brackets or decimal numbers.
- 당신은 괄호나 10진수를 관리할 필요가 없습니다.

- Here is an example of a standard use:
- 아래는 올바른 사용 예시입니다.
```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "(1 + 1)"
Error
$>
```
- Warning: The container(s) you used in the previous exercise are forbidden here. The container(s) you used to validate this exercise will not be usable for the rest of this module.
- 주의 사항: 이전 예제에서 사용한 컨테이너(들)은 여기에선 금지됩니다. 이번 과제를 풀기 위해 사용한 컨테이너(들)은 이 모듈의 나머지에서는 사용할 수 없습니다.

# Exercise 02: PmergeMe 
## Usage
```
git clone https://github.com/brixxt27/cpp_module_09.git
cd cpp_module_09/ex02
make
./
```
## Summary
- Turn-in directory : ex02/
- Files to turn in : Makefile, main.cpp, PmergeMe.{cpp, hpp}
- Forbidden functions : None

## Detail
You must create a program with these constraints:
	- The name of the program is PmergeMe.
	- Your program must be able to use a positive integer sequence as argument.
	- Your program must use a merge-insert sort algorithm to sort the positive integer
sequence.
	- If an error occurs during program execution, an error message should be displayed
on the standard output.
You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.
It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

Here are some additional guidelines on the information you should display line by line
on the standard output
	- On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
	- On the second line you must display an explicit text followed by the sorted positive
integer sequence.
	- On the third line you must display an explicit text indicating the time used by
your algorithm by specifying the first container used to sort the positive integer
sequence.
	- On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence.

The format for the display of the time used to carry out your sorting
is free but the precision chosen must allow to clearly see the
difference between the two containers used.

Here is an example of a standard use:

```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$>
```

Warning: The container(s) you used in the previous exercises are
forbidden here.
The management of errors related to duplicates is left to your
discretion.
