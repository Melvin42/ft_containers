#include <iostream>
#include <climits>
#include <list>
#include <vector>

#if STD
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
	#include <map>
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

	ft::pair<int, int>	pair1;
	std::pair<int, int>	pair2;
	ft::map<int, int>	ftMap;
	std::map<int, int>	stdMap;

	std::cout << "std Size = " << stdMap.size() << '\n';
	std::cout << "ft Size = " << ftMap.size() << '\n';
	pair1 = ft::make_pair(10,20);
	pair2 = std::make_pair(10,20);

	ftMap.insert(pair1);
	ftMap.insert(ft::make_pair(11,21));
	ftMap.insert(ft::make_pair(12,22));

	stdMap.insert(pair2);
	stdMap.insert(std::make_pair(11,21));
	stdMap.insert(std::make_pair(12,25));

	ft::map<int, int>::iterator		ftIt;
	std::map<int, int>::iterator	stdIt;

	std::cout << "pair1: " << pair1.first << ", " << pair1.second << '\n';

	stdIt = stdMap.begin();
	std::cout << "std-print\n";
//	std::cout << "stdMap[" << 0 << "]  = " << stdMap[0] << '\n';
	std::cout << "stdMap[" << 10 << "]  = " << stdMap[10] << '\n';
	std::cout << "stdMap[" << 11 << "]  = " << stdMap[11] << '\n';
	std::cout << "stdMap[" << 12 << "]  = " << stdMap[12] << '\n';
	std::cout << "Size = " << stdMap.size() << '\n';
	std::cout << "find 10 = " << stdMap.find(10)->second << '\n';
	std::cout << "find 1000 = " << stdMap.find(1000)->second << '\n';
	for (size_t i = 0; i < stdMap.size(); i++, stdIt++) {
//		std::cout << "stdMap[" << i << "]  = " << stdMap[i] << '\n';
		std::cout << "first  = " << stdIt->first << '\n';
		std::cout << "second = " << stdIt->second << '\n';
	}

	std::cout << "ft-print\n";
	ftIt = ftMap.begin();
//	std::cout << "ftMap[" << 0 << "]  = " << ftMap[0] << '\n';
	std::cout << "ftMap[" << 10 << "]  = " << ftMap[10] << '\n';
	std::cout << "ftMap[" << 11 << "]  = " << ftMap[11] << '\n';
	std::cout << "ftMap[" << 12 << "]  = " << ftMap[12] << '\n';
	std::cout << "Size = " << ftMap.size() << '\n';
	std::cout << "find 10 = " << ftMap.find(10)->_pair.second << '\n';
//	std::cout << "find 10 = " << ftMap.find(1000)->_pair.second << '\n';
	for (size_t i = 0; i < ftMap.size(); i++, ftIt++) {
//		std::cout << "ftMap[" << i << "]  = " << ftMap[i] << '\n';
		std::cout << "first  = " << ftIt->_pair.first << '\n';
		std::cout << "second = " << ftIt->_pair.second << '\n';
//		std::cout << "first  = " << ftIt->first << '\n';
//		std::cout << "second = " << ftIt->second << '\n';
	}
	ftIt = ftMap.end();
	for (size_t i = 0; i < ftMap.size(); i++, ftIt--) {
		std::cout << "first  = " << ftIt->_pair.first << '\n';
		std::cout << "second = " << ftIt->_pair.second << '\n';
	}
//	ftIt = ftMap.begin();
//	for (size_t i = 0; i < ftMap.size(); i++, ftIt++) {
//		std::cout << "first  = " << ftIt->_pair.first << '\n';
//		std::cout << "second = " << ftIt->_pair.second << '\n';
//	}
//	for (ftIt = ftMap.begin(); ftIt != ftMap.end(); ftIt++) {
//		std::cout << "first  = " << ftIt->_pair.first << '\n';
//		std::cout << "second = " << ftIt->_pair.second << '\n';
//	}

//	map1.insert(pair1);
	std::cout << "stdCount: " << stdMap.count(4) << '\n';
	std::cout << "ftCount: " << ftMap.count(4) << '\n';
	std::cout << "stdCount: " << stdMap.count(10) << '\n';
	std::cout << "ftCount: " << ftMap.count(10) << '\n';

	std::cout << "std_lower_bound: " << stdMap.lower_bound(10)->first << '\n';
	std::cout << "ft_lower_bound: " << ftMap.lower_bound(10)->_pair.first << '\n';
	std::cout << "std_lower_bound: " << stdMap.lower_bound(11)->first << '\n';
	std::cout << "ft_lower_bound: " << ftMap.lower_bound(11)->_pair.first << '\n';
//	std::cout << "std_lower_bound: " << stdMap.lower_bound(8)->first << '\n';
//	std::cout << "ft_lower_bound: " << ftMap.lower_bound(8)->_pair.first << '\n';

	std::cout << "std_upper_bound: " << stdMap.upper_bound(10)->first << '\n';
	std::cout << "ft_upper_bound: " << ftMap.upper_bound(10)->_pair.first << '\n';
	std::cout << "std_upper_bound: " << stdMap.upper_bound(11)->first << '\n';
	std::cout << "ft_upper_bound: " << ftMap.upper_bound(11)->_pair.first << '\n';
	std::cout << "ft_upper_bound: " << ftMap.upper_bound(11)->_pair.first << '\n';
//	std::cout << "std_upper_bound: " << stdMap.upper_bound(8)->first << '\n';
//	std::cout << "ft_upper_bound: " << ftMap.upper_bound(8)->_pair.first << '\n';

	/*
	std::cout << "TESTING RESIZE\n" << std::endl;
	std::cout << "TESTING ERASE\n" << std::endl;
	std::cout << "TESTING OPERATOR[]\n" << std::endl;

	try {
	} catch (std::exception &e) {
		e.what();
	}
	std::cout << "TESTING MAX_SIZE\n";
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
