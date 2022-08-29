#include <iostream>
#include <climits>
#include <list>

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

	int							n = 7;
	ft::vector<int>				vect(n);
	ft::vector<int>::iterator	it = vect.begin();
	ft::vector<int>::iterator	ite = vect.end();

	std::cout << "len = " << ite - it << '\n';
	for (; it != ite; it++) {
		*it = (ite - it);
	}
	vect.push_back(42);
	vect.pop_back();

	ft::vector<std::string>	vect_str(8);
	ft::vector<std::string>	vect_str2;

	vect_str.push_back("coucou\n");
	it = vect.begin();
	ite = vect.end();
	for (size_t i = 0; it != ite; it++, i++) {
//		std::cout << "at[" << i << "] = " << vect.at(i) << '\n';
		std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
	}

	vect.clear();
	it = vect.begin();
	for (;it != ite; it++) {
		std::cout << *it << '\n';
	}
//	it = vect.begin();
	try {
		ft::vector<int>	vect_range(it, --(--ite));
//		ft::vector<int>	vect_range(it, ite);

//		it = vect_range.begin();
//		ite = vect_range.end();

		std::cout << vect.max_size();
		for (size_t i = 0; it != ite; it++, i++) {
			std::cout << "vect_range[" << i << "] = " << vect_range[i] << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "SIZE = " << vect.size() << std::endl;
	std::cout << "BACK = " << vect.back() << std::endl;

	ft::vector<int>				vectZero(vect);

	int	i = 0;
	for (it = vectZero.begin(); it != vectZero.end(); it++) {
		std::cout << "vect[" << i << "] = " << vectZero[i] << std::endl;
		i++;
	}

	i = 0;

	for (it = vect.begin(); it != vect.end(); it++) {
		vect[i] = i;
		std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
		i++;
	}
	std::cout << "FRONT = " << vect.front() << std::endl;
	std::cout << "BACK = " << vect.back() << std::endl;
//	vect[i] = i;

//	ft::MyIterator<int> it(vect.begin());

	std::cout << "TESTING REVERSE_ITERATOR\n" << std::endl;

	std::list<int>				lst;

	for (size_t i = 0; i < 5; i++) {
		lst.push_back(i);
	}

//	ft::vector<int>				rvect(lst.begin(), lst.end());

//	rvect.insert(rvect.end(), lst.rbegin(), lst.rend());
//	std::cout << "TESTING ITERATOR_TRAITS\n" << std::endl;
//
}

void	test_vector() {
	std::cout << "/******** TESTING VECTOR ********/\n" << std::endl;

	int							n = 7;
	ft::vector<int>				vect(n);
	ft::vector<int>				vect2(n);
//	ft::vector<int>::iterator	it = vect.begin();

	/*
	std::cout << "TESTING RESIZE\n" << std::endl;

	std::cout << "Size = " << vect.size() << '\n';
	std::cout << "Resize 20, 42\n";
	vect.resize(20, 42);
	std::cout << "Size = " << vect.size() << '\n';

	std::cout << "Size = " << vect.size() << '\n';
	std::cout << "Resize 6\n";
	vect.resize(6);
	std::cout << "Size = " << vect.size() << '\n';
	std::cout << "Resize 10\n";
	vect.resize(10);
	std::cout << "Size = " << vect.size() << '\n';
	std::cout << "vect = ";
	for (it = vect.begin(); it != vect.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';
	std::cout << "Resize 11, 42\n";
	vect.resize(11, 42);
	std::cout << "Resize 18, 45\n";
	vect.resize(18, 45);
	std::cout << "vect = ";
	for (it = vect.begin(); it != vect.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';
	std::cout << "Size = " << vect.size() << '\n';

	*/
	std::cout << "TESTING ERASE\n" << std::endl;

	ft::vector<int>				vectDel;

	for (size_t i = 0; i < 5; i++) {
		vectDel.push_back(i + i * 5);
	}

	std::cout << "VectDel = ";
	for (ft::vector<int>::iterator it = vectDel.begin(); it != vectDel.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	std::cout << "SIZE = " << vectDel.size() << '\n';
	vectDel.erase(vectDel.begin());
	std::cout << "SIZE = " << vectDel.size() << '\n';
//	vectDel.erase(vectDel.end() - 3, vectDel.end() - 1);
	vectDel.erase(vectDel.end());
	std::cout << "SIZE = " << vectDel.size() << '\n';
	vectDel.erase(vectDel.begin(), vectDel.begin() + 2);
	std::cout << "SIZE = " << vectDel.size() << '\n';
//	vectDel.erase(vectDel.begin(), vectDel.begin() + 3);
//	vectDel.erase(vectDel.end());;
//	vectDel.erase(vectDel.begin());;
//	std::cout << "SIZE = " << vectDel.size() << '\n';
//	vectDel.erase(vectDel.begin(), vectDel.begin() + 1);
//	vectDel.erase(vectDel.begin(), vectDel.begin() - 1);
//	vectDel.erase(vectDel.end() - 3, vectDel.end() - 1);

//	vectDel.push_back(42);
//	vectDel.push_back(532);
//	vectDel.erase(vectDel.end() - 3, vectDel.end());
	std::cout << "VectDel = ";
	for (ft::vector<int>::iterator it = vectDel.begin(); it != vectDel.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

//	std::cout << "TESTING OPERATOR[]\n" << std::endl;

/*
	try {
		for (int i = 0; i < n; i++) {
			vect[i] = i;
			std::cout << "vector[" << i << "] = " << vect[i] << std::endl;
		}
		std::cout << "size = " << vect.size() << '\n';
		vect.resize(4);

		std::cout << "after resize 4 size = " << vect.size() << '\n';

		int big = n + 1;

		vect[big] = 42;
	} catch (std::exception &e) {
		e.what();
	}

	for (int i = 0; i < n; i++) {
		vect[i] = i + 5;
		vect[i] += 5;
	}

	try {
		std::cout << "vector size = " << vect.size() << '\n';
		for (int i = 0; i < n; i++) {
			std::cout << "vector.at(" << i << ") = " << vect.at(i) << std::endl;
		}
	} catch (std::exception &e) {
		e.what();
	}

		std::cout << "overflow: vect.at(1) = " << INT_MAX << " + 1" << std::endl;
		vect[1] = INT_MAX;
		vect[1] += 1;
		std::cout << "vect.at(1) = " << vect.at(1) << std::endl;
	std::cout << "TESTING MAX_SIZE\n"
		<< "max_size = " << vect.max_size() << std::endl;

	ft::vector<int>	vect_cpy(vect);

	*/
	/*
	std::cout << "\nvect.insert() TESTS:\n" << std::endl;

	std::cout << "TESTING INSERT\n";

	ft::vector<int>	Vctor(2,400);
	ft::vector<int>	vect3;

//	std::cout << "Vctor ";
//	for (size_t i = 0; i < Vctor.size(); i++) {
//		std::cout << Vctor[i] << ", ";
//	}
//	std::cout << '\n';
	Vctor.insert(Vctor.begin(), 1, 42);
	Vctor.insert(Vctor.begin()+2, 1, 42);
	Vctor.insert(Vctor.end(), 1, 42);

//	Vctor.insert(Vctor.end(), 1, 42);
	for (size_t i = 0; i < Vctor.size(); i++) {
		std::cout << Vctor[i] << ", ";
	}
	std::cout << '\n';

	vect3.insert(vect3.end(), 99);
	std::cout << "vect3 = ";

	vect3.insert(vect3.begin() + 1, Vctor.begin(), Vctor.end());

	for (it = vect3.begin(); it != vect3.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	ft::vector<int> vectorOne;

	vectorOne.insert(vectorOne.begin(), 2, 42);
	vectorOne.insert(vectorOne.end(), 12);
	vectorOne.insert(vectorOne.begin(), 2, 41);

//	vectorOne.insert(vectorOne.begin() + 2, vectorOne.begin(), vectorOne.end());

	size_t	i = 0;

	for (ft::vector<int>::iterator it = vectorOne.begin(); it != vectorOne.end(); it++) {
		std::cout << "vect[" << i << "] = " << *it << std::endl;
//		std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
		++i;
	}

	std::cout << std::endl;
	ft::vector<int> anotherVector(2,400);

	i = 0;
	for (ft::vector<int>::iterator it = anotherVector.begin(); it != anotherVector.end(); it++) {
		std::cout << "vect[" << i << "] = " << *it << std::endl;
		i++;
	}
//	vect.insert(it+2, anotherVector.begin(), anotherVector.end());
	*/

	/*
	std::cout << "TESTING SWAP\n";

	ft::vector<int>	vectA(4, 42);
	ft::vector<int>	vectB(6, 21);

	std::cout << "VectA Before = ";
	for (ft::vector<int>::iterator it = vectA.begin(); it != vectA.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	std::cout << "VectB Before = ";
	for (ft::vector<int>::iterator it = vectB.begin(); it != vectB.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	vectA.swap(vectB);

	std::cout << "VectA After = ";
	for (ft::vector<int>::iterator it = vectA.begin(); it != vectA.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	std::cout << "VectB After = ";
	for (ft::vector<int>::iterator it = vectB.begin(); it != vectB.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << '\n';
	*/

	/*
	std::cout << "TESTING ASSIGN\n";
	ft::vector<int>	first;
	ft::vector<int>	second;
	ft::vector<int>	third;

	first.assign(7, 100);
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++) {
		std::cout << "AssignVect = " << *it << '\n';
	}

	ft::vector<int>::iterator it;
	it = first.begin()+1;

	second.assign(it,first.end()-1); // the 5 central values of first

	int	myints[] = {1776,7,4};
	third.assign(myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "TESTING PUSH_BACK\n";
	ft::vector<int> myVector;

	// set some values (from 1 to 10)
	std::cout << "SIZE = " << myVector.size() << '\n';
	for (int j = 1; j <= 10; j++) myVector.push_back(j);
	std::cout << "SIZE = " << myVector.size() << '\n';

	for (int j = 0; j < 10; j++) std::cout << "push back : " << myVector.at(j) << '\n';

	std::cout << "CLEAR myVector\n";
	myVector.clear();

	ft::vector<std::string>	strVect;

	strVect.push_back("Hello World!\n");
	std::cout << strVect.at(0);
	std::cout << "size = " << strVect.size() << '\n';
	strVect.pop_back();
	std::cout << "size = " << strVect.size() << '\n';

	// erase the 6th element
//	myVector.erase(myVector.begin() + 5);

//	for (int j = 0; j < 9; j++) std::cout << "push back : " << myVector.at(j) << '\n';

	// erase the first 3 elements:
//	myVector.erase(myVector.begin(), myVector.begin() + 3);

	std::cout << "myVector contains:";
	for (size_t j = 0; j < myVector.size(); ++j)
		std::cout << ' ' << myVector[j];
	std::cout << '\n';
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
	ft::vector<int>	myvector(myints, myints + 5);   // myvector: 20 40 60 80 100

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
	test_vector();
//	test_is_integral();
//	test_equal();
//	test_lexicographical_compare();
//	test_enable_if();
//	test_map();
	return 0;
}
