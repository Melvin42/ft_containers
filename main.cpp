#include <iostream>
#include <climits>

#if STD
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "iterator_traits.hpp"
	#include "utils.hpp"
#endif

int	main() {
	std::cout << "/******** TESTING VECTOR ********/\n" << std::endl;

	int	n = 7;
//	ft::vector<int>	vect;
	ft::vector<int>					vect(n);
//	ft::vector<int>::iterator		it;
//	ft::vector<int>::const_iterator	const_it;

	std::cout << "TESTING OPERATOR[]\n" << std::endl;

	try {
		for (int i = 0; i < n; i++) {
			vect[i] = i;
			std::cout << "vector[" << i << "] = " << vect[i] << std::endl;
		}
		int big = n + 1;

		vect[big] = 42;
		std::cout << "TESTING \nvect.at()\n add + 10" << std::endl;
	} catch (std::exception &e) {
		e.what();
	}

	for (int i = 0; i < n; i++) {
		vect.at(i) = i + 5;
		vect.at(i) += 5;
	}

	for (int i = 0; i < n; i++) {
		std::cout << "vector.at(" << i << ") = " << vect.at(i) << std::endl;
	}

	std::cout << "overflow: vect.at(1) = " << INT_MAX << " + 1" << std::endl;
	vect.at(1) = INT_MAX;
	vect.at(1) += 1;
	std::cout << "vect.at(1) = " << vect.at(1) << std::endl;

	std::cout << "TESTING MAX_SIZE\n"
		<< "max_size = " << vect.max_size() << std::endl;

	std::cout << "TESTING ITERATOR\n" << std::endl;
	std::cout << "\nvect.insert() TESTS:\n" << std::endl;

//	vect.insert(vect.end(), n + 1);

	ft::vector<int>	vect_cpy(vect);

	std::cout << "TESTING IS_INTEGRAL\n"
		<< "\nbool: " << ft::is_integral<bool>::value
		<< "\nchar: " << ft::is_integral<char>::value
		<< "\nwchar_t: " << ft::is_integral<wchar_t>::value
		<< "\nsigned char: " << ft::is_integral<signed char>::value
		<< "\nshort int: " << ft::is_integral<short int>::value
		<< "\nint: " << ft::is_integral<int>::value
		<< "\nlong int: " << ft::is_integral<long int>::value
		<< "\nlong long int: " << ft::is_integral<long long int>::value
		<< "\nunsigned char: " << ft::is_integral<unsigned char>::value
		<< "\nunsigned short int: "
		<< ft::is_integral<unsigned short int>::value
		<< "\nunsigned long int: " << ft::is_integral<unsigned long int>::value
		<< "\nunsigned long long int: "
		<< ft::is_integral<unsigned long long int>::value << std::endl;
//
//	std::cout << "TESTING EQUAL\n" << std::endl;

	std::cout << "TESTING LEXICOGRAPHICAL_COMPARE\n" << std::endl;

	char	foo[]="Apple";
	char	bar[]="apartment";

//	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

//	std::cout << "TESTING ENABLE_IF\n" << std::endl;

	std::cout << "/******** TESTING MAP ********/\n" << std::endl;
	return 0;
}
