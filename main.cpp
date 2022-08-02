#include <iostream>
#include <climits>

#if TEST
	#include <vector>
	namespace ft = std;
#else
	#include "Vector.hpp"
#endif

int	main() {
	int	n = 7;
//	ft::vector<int>	vect;
	ft::vector<int>					vect(n);
//	ft::vector<int>::iterator		it;
//	ft::vector<int>::const_iterator	const_it;

	std::cout << "\nOPERATOR[] TESTS:\n" << std::endl;

	try {
		for (int i = 0; i < n; i++) {
			vect[i] = i;
			std::cout << "vector[" << i << "] = " << vect[i] << std::endl;
		}
		int big = n + 1;
		vect[big] = 42;

		std::cout << "\nvect.at() TESTS:\n add + 10" << std::endl;
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

	std::cout << "\nMAX_SIZE TESTS:\n"
		<< "max_size = " << vect.max_size() << std::endl;

	std::cout << "TESTING ITERATOR\n" << std::endl;

	std::cout << "\nvect.insert() TESTS:\n" << std::endl;

	vect.insert(vect.end(), n + 1);

	ft::vector<int>	vect_cpy(vect);

	return 0;
}
