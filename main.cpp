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

//	std::cout << "TESTING IS_INTEGRAL\n" << std::endl;
//	std::cout << "bool: " << ft::is_integral<bool>::value << std::endl;
//	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//	std::cout << "char16_t: " << ft::is_integral<char16_t>::value << std::endl;
//	std::cout << "char32_t: " << ft::is_integral<char32_t>::value << std::endl;
//	std::cout << "wchar_t: " << ft::is_integral<wchar_t>::value << std::endl;
//	std::cout << "signed_char: " << ft::is_integral<signed_char>::value << std::endl;
//	std::cout << "short int: " << ft::is_integral<short int>::value << std::endl;
//	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//	std::cout << "long int: " << ft::is_integral<long int>::value << std::endl;
//	std::cout << "long long int: " << ft::is_integral<long long int>::value << std::endl;
//	std::cout << "unsigned char: " << ft::is_integral<unsigned char>::value << std::endl;
//	std::cout << "unsigned short int: " << ft::is_integral<unsigned short int>::value << std::endl;
//	std::cout << "unsigned long int: " << ft::is_integral<unsigned long int>::value << std::endl;
//	std::cout << "unsigned long long int: " << ft::is_integral<unsigned long long int>::value << std::endl;
//
//	std::cout << "TESTING EQUAL\n" << std::endl;
//	std::cout << "TESTING ENABLE_IF\n" << std::endl;

	return 0;
}
