#include <iostream>
#include <climits>
#include <list>
#include <vector>

#if STD
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "iterator_traits.hpp"
	#include "pair.hpp"
	#include "utils.hpp"
#endif

void	test_pair() {
	std::cout << "/******** TESTING PAIR ********/\n" << std::endl;
		ft::pair <int,int> pair1;
//		ft::pair <int,int> pair2;

		pair1 = ft::make_pair(10,20);
//		pair2 = ft::make_pair(10.5,'A'); // ok: implicit conversion from pair<double,char>

		std::cout << "pair1: " << pair1.first << ", " << pair1.second << '\n';
//		std::cout << "pair2: " << pair2.first << ", " << pair2.second << '\n';
}

void	test_iterator() {
	std::cout << "TESTING ITERATOR\n" << std::endl;

//	std::cout << "TESTING REVERSE_ITERATOR\n" << std::endl;
//	std::cout << "TESTING BIDIR_ITERATOR\n" << std::endl;
//	std::cout << "TESTING ITERATOR_TRAITS\n" << std::endl;
}

void	test_map() {
	std::cout << "/******** TESTING MAP ********/\n" << std::endl;

	ft::pair<int,int>	pair1;
	ft::map<int, int>	map1;

	pair1 = ft::make_pair(10,20);

	std::cout << "pair1: " << pair1.first << ", " << pair1.second << '\n';
	/*
	std::cout << "TESTING RESIZE\n" << std::endl;
	std::cout << "TESTING ERASE\n" << std::endl;
	std::cout << "TESTING OPERATOR[]\n" << std::endl;

	try {
	} catch (std::exception &e) {
		e.what();
	}
	std::cout << "TESTING MAX_SIZE\n";
	std::cout << "TESTING INSERT\n";
	std::cout << "TESTING SWAP\n";
	std::cout << "CLEAR\n";
	*/
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

	int				myints[] = {20, 40, 60, 80, 100};//  myints: 20 40 60 80 100
	std::vector<int>	myvector(myints, myints + 5);   // myvector: 20 40 60 80 100

	// using default comparison:
	if (ft::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

//	myvector[3] = 81;                               // myvector: 20 40 60 81 100
}

void	test_enable_if() {
	std::cout << "TESTING ENABLE_IF\n" << std::endl;
}

void	test_relational_operator() {
	std::cout << "TESTING RELATIONAL_OPERATOR\n" << std::endl;

//	std::cout << "== " << (vect1 == vect2) << '\n';
//	std::cout << "!= " << (vect1 != vect2) << '\n';
//	std::cout << "< " << (vect1 < vect2) << '\n';
//	std::cout << "<= " << (vect1 <= vect2) << '\n';
//	std::cout << "> " << (vect1 > vect2) << '\n';
//	std::cout << ">= " << (vect1 >= vect2) << '\n';
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
//	test_pair();
//	test_iterator();
	test_map();
//	test_is_integral();
//	test_equal();
//	test_relational_operator();
//	test_lexicographical_compare();
//	test_enable_if();
	return 0;
}
