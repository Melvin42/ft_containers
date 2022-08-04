#include <iostream>
#include <climits>

#if STD
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "iterator_traits.hpp"
	#include "pair.hpp"
	#include "utils.hpp"
#endif

void	test_pair() {
	std::cout << "/******** TESTING PAIR ********/\n" << std::endl;
		std::pair <int,int> pair1;
		std::pair <int,int> pair2;

		pair1 = std::make_pair (10,20);
		pair2 = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

		std::cout << "pair1: " << pair1.first << ", " << pair1.second << '\n';
		std::cout << "pair2: " << pair2.first << ", " << pair2.second << '\n';
}

void	test_iterator() {
	std::cout << "TESTING ITERATOR\n" << std::endl;

	int	n = 7;
	ft::vector<int>					vect(n);

	for (int i = 0; i < n; i++) {
		vect[i] = i;
	}
//	ft::MyIterator<int> it(vect.begin());

//	std::cout << "TESTING REVERSE_ITERATOR\n" << std::endl;
//	std::cout << "TESTING ITERATOR_TRAITS\n" << std::endl;
//
}

#include <unistd.h>
void	test_vector() {
	std::cout << "/******** TESTING VECTOR ********/\n" << std::endl;

	int	n = 7;
//	ft::vector<int>	vect;
	ft::vector<int>					vect(n);
//	ft::vector<int>::iterator		it;
//	ft::vector<int>::const_iterator	const_it;

	std::cout << "TESTING OPERATOR[]\n" << std::endl;

	try {
	write(1, "1", 1);
		for (int i = 0; i < n; i++) {
			vect[i] = i;
			std::cout << "vector[" << i << "] = " << vect[i] << std::endl;
		}
		int big = n + 1;

		vect[big] = 42;
	} catch (std::exception &e) {
		e.what();
	}

	for (int i = 0; i < n; i++) {
		vect[i] = i + 5;
		vect[i] += 5;
	}

	for (int i = 0; i < n; i++) {
		std::cout << "vector.at(" << i << ") = " << vect.at(i) << std::endl;
	}

	std::cout << "overflow: vect.at(1) = " << INT_MAX << " + 1" << std::endl;
	vect[1] = INT_MAX;
	vect[1] += 1;
	std::cout << "vect.at(1) = " << vect.at(1) << std::endl;

	std::cout << "TESTING MAX_SIZE\n"
		<< "max_size = " << vect.max_size() << std::endl;

	ft::vector<int>	vect_cpy(vect);

	std::cout << "\nvect.insert() TESTS:\n" << std::endl;


	vect.insert(vect.end(), n + 1);
}

void	test_is_integral() {
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
}

void	test_equal() {
	std::cout << "TESTING EQUAL\n" << std::endl;
	int	myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100

	ft::vector<int>myvector (myints,myints+5);      // myvector: 20 40 60 80 100

	// using default comparison:
	if (ft::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3] = 81;                           // myvector: 20 40 60 81 100
}

void	test_enable_if() {
//	std::cout << "TESTING ENABLE_IF\n" << std::endl;
}

void	test_lexicographical_compare() {
	std::cout << "TESTING LEXICOGRAPHICAL_COMPARE\n" << std::endl;

	char	foo[]="Apple";
	char	bar[]="apartment";

//	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';
}

//void	test_map() {
//	std::cout << "/******** TESTING MAP ********/\n" << std::endl;
//}

int	main() {
	test_pair();
	test_iterator();
	test_vector();
//	test_is_integral();
	test_equal();
//	test_lexicographical_compare();
//	test_enable_if();
//	test_map();
	return 0;
}
