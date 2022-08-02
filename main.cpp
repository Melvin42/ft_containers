#if TEST
	#include <vector>
	#include <iostream>
	namespace ft = std;
#else
	#include "Vector.hpp"
#endif

int	main() {
	ft::vector<int>	vect;
	ft::vector<int>	vect1(7);
	
	std::cout << "INT TEST"
		<< "vector = {1, 2, 3, 4, 5, 6, 7}\n"

		<< "\nOPERATOR[] TESTS:\n"
		<< "vector[0] = " << vect1[0] << "\n"
		<< "vector[1] = " << vect1[1] << "\n"
		<< "vector[2] = " << vect1[2] << "\n"
		<< "vector[3] = " << vect1[3] << "\n"
		<< "vector[4] = " << vect1[4] << "\n"
		<< "vector[5] = " << vect1[5] << "\n"
		<< "vector[6] = " << vect1[6] << "\n"
		<< "vector[7] = " << vect1[7] << "\n"
		<< "vector[8] = " << vect1[8] << "\n"
		<< "vector[8] = " << vect1[9] << "\n"

		<< "\nOPERATOR[] TESTS:\n"
		<< "vector.at(0) = " << vect1.at(0) << '\n'
		<< "vector.at(1) = " << vect1.at(1) << '\n'
		<< "vector.at(2) = " << vect1.at(2) << '\n'
		<< "vector.at(3) = " << vect1.at(3) << '\n'
		<< "vector.at(4) = " << vect1.at(4) << '\n'
		<< "vector.at(5) = " << vect1.at(5) << '\n'
		<< "vector.at(6) = " << vect1.at(6) << "\n\n"
//		<< "vector.at(8) = " << vect1.at(7) << "\n\n"
		<< "modif: vect1.at(1) = 2" << std::endl;
//		vect1.at(1) = 2147687748;
		std::cout << "vect1.at(1) = " << vect1.at(1) << std::endl;

		std::cout << "\nMAX_SIZE TESTS:\n"
			<< "max_size = " << vect1.max_size() << std::endl;
//	ft::vector<int>	vect_cpy(vect);

	return 0;
}
