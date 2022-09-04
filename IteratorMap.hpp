#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <	class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T& >
		class	IteratorMap {
			public:
				typedef T			value_type;
				typedef Pointer		pointer;
				typedef Reference	reference;
				typedef Distance	difference_type;
				typedef Category	IteratorMap_category;

			protected:
				pointer	_pos;

			public:
				IteratorMap() : _pos(NULL) {}

				IteratorMap(pointer it) : _pos(it) {}

				template <class U>
					IteratorMap(const IteratorMap<Category, U> &it) {
						*this = it;
					}

				template <class U>
					IteratorMap	&operator=(const IteratorMap<Category, U> &it) {
						_pos = it.base();
						return *this;
					}

				~IteratorMap() {}

				pointer	base() {
					return _pos;
				}

				const pointer	base() const {
					return _pos;
				}

				reference	operator*() const { return *_pos; }
				pointer		operator->() const { return _pos; }

				IteratorMap	operator-=(int n) {
					for (int i = 0; i < n; i++, _pos--) ;
					return *this;
				}

				IteratorMap	operator+=(int n) {
					for (int i = 0; i < n; i++, _pos++) ;
					return *this;
				}

				IteratorMap	operator++(int) {
					IteratorMap	tmp(*this);

					++(*this);
					return tmp;
				}

				IteratorMap	&operator++() {
					++_pos;
					return *this;
				}

				IteratorMap	operator--(int) {
					IteratorMap	tmp = *this;

					--(*this);
					return tmp;
				}

				IteratorMap	&operator--() {
					--_pos;
					return *this;
				}

				difference_type	operator+(const IteratorMap &it) const {
					return base() + it.base();
				}

				IteratorMap	operator+(difference_type v) const {
					return IteratorMap(_pos + v);
				}

				IteratorMap	operator+(int n) {
					return IteratorMap(base() + n);
				}

//				difference_type	operator-(const IteratorMap &it) const {
//					return base() - it.base();
//				}

//				IteratorMap	operator-(difference_type v) const {
//					return IteratorMap(_pos - v);
//				}

				IteratorMap	operator-(int n) {
					return IteratorMap(_pos - n);
				}

				reference	operator[](difference_type v) const {
					return *(_pos + v);
				}

				template <class IteratorMap>
					friend bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs);
		};

	template <class IteratorMap>
		bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class IteratorMap>
		bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class IteratorMap>
		bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class IteratorMap>
		bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos >= rhs._pos;
		}

	template <class IteratorMap>
		bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos < rhs._pos;
		}

	template <class IteratorMap>
		bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos > rhs._pos;
		}
	/*
	template <class Category, class T>
		bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class Category, class T>
		bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class Category, class T>
		bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos < rhs._pos;
		}

	template <class Category, class T>
		bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos > rhs._pos;
		}

		};
		*/

//	template <class Category, class T>
//		IteratorMap<Category, T> operator-(IteratorMap<Category, T> &lhs, IteratorMap<Category, T> &rhs) {
//			std::cout << "coucou\n";	
//			return IteratorMap<Category, T>(lhs.base() - rhs.base());
//		}

	template <class Category, class T>
		IteratorMap<Category, T> operator+(std::ptrdiff_t v, IteratorMap<Category, T> &it) {
			return IteratorMap<Category, T>(it.base() + v);
		}

//	template <class Category, class T>
//		IteratorMap<Category, T> operator-(std::ptrdiff_t v, IteratorMap<Category, T> &it) {
//			return IteratorMap<Category, T>(it.base() - v);
//		}

	template <class Category, class T>
		typename IteratorMap<Category, T>::difference_type operator+(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, T> &rhs) {
			return lhs.base() + rhs.base();
		}

	template <class Category, class T>
		typename IteratorMap<Category, T>::difference_type operator-(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, T> &rhs) {
			return lhs.base() - rhs.base();
		}

	template <class Category, class T, class U>
		typename IteratorMap<Category, T>::difference_type operator+(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, U> &rhs) {
			return lhs.base() + rhs.base();
		}

	template <class Category, class T, class U>
		typename IteratorMap<Category, T>::difference_type operator-(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, U> &rhs) {
			return lhs.base() - rhs.base();
		}

//	template <class Category, class T>
//		std::ostream	&operator<<(std::ostream &os, const IteratorMap<Category, T> &it) {
//			std::cout << "coucou\n";	
//			std::cout << it.base();
//
//			return os;
//		}
};

#endif
