#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {
	class enable_if {
	};
	
//	template <class T>
//		struct is_integral : public integral_constant<bool, __is_integral(T)> {};
	
//	template <typename T> struct is_integral : public std::__false_type {};
//	template <> struct is_integral<bool> : public std::__true_type {};
//	template <> struct is_integral<char> : public std::__true_type {};
////	template <> struct is_integral<char16_t> : public std::__true_type {};
////	template <> struct is_integral<char32_t> : public std::__true_type {};
//	template <> struct is_integral<wchar_t> : public std::__true_type {};
//	template <> struct is_integral<signed char> : public std::__true_type {};
//	template <> struct is_integral<short int> : public std::__true_type {};
//	template <> struct is_integral<int> : public std::__true_type {};
//	template <> struct is_integral<long int> : public std::__true_type {};
//	template <> struct is_integral<long long int > : public std::__true_type {};
//	template <> struct is_integral<unsigned char> : public std::__true_type {};
//	template <> struct is_integral<unsigned short int> : public std::__true_type {};
//	template <> struct is_integral<unsigned int> : public std::__true_type {};
//	template <> struct is_integral<unsigned long int> : public std::__true_type {};
//	template <> struct is_integral<unsigned long long int> : public std::__true_type {};
	
	template <class InputIterator1, class InputIterator2>
		bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
			while (first1 != last1) {
				if (!(*first1 == *first2))
					return false;
				++first1;
				++first2;
			}
			return true;
		};
	
	class lexicographical_compare {
	};
};

#endif
