#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <	class Category, class T, class Distance = std::ptrdiff_t,
				class Pointer = T*, class Reference = T&>
			class	iterator {
				public:
					typedef T				value_type;
					typedef Pointer			pointer;
					typedef Reference		reference;
					typedef Distance		difference_type;
					typedef Category		iterator_category;

				protected:
					pointer	_pos;

				public:
					iterator() : _pos(NULL) {}
					iterator(pointer it) : _pos(it) {}
					iterator(const iterator &it) { *this = it; }
					~iterator() {}

					const pointer	&base() const {
						return _pos;
					}

					reference	operator*() const { return *_pos; }
					pointer		operator->() const { return _pos; }

					iterator	operator++(int) {
						iterator	tmp(*this);

						++(*this);
						return tmp;
					}

					iterator	&operator++() {
						++_pos;
						return *this;
					}

					iterator	operator--(int) {
						iterator	tmp = *this;

						--(*this);
						return tmp;
					}

					iterator	&operator--() {
						--_pos;
						return *this;
					}

					difference_type	operator+(const iterator &it) const {
						return base() + it.base();
					}

					iterator	operator+(difference_type v) const {
						return iterator(_pos + v);
					}

					iterator	operator+(int n) {
						return iterator(base() + n);
					}

					difference_type	operator-(const iterator &it) const {
						return base() - it.base();
					}

					iterator	operator-(difference_type v) const {
						return iterator(base() - v);
					}

					iterator	operator-(int n) {
						return iterator(base() - n);
					}

					reference	operator[](difference_type v) const {
						return *(_pos + v);
					}

					iterator	&operator=(value_type n) {
						*_pos = n;
						return *this;
					}

					iterator	&operator=(const iterator &it) {
						_pos = it.base();
						return *this;
					}

					bool	operator==(const iterator &it) const {
						return _pos == it._pos;
					}

					bool	operator!=(const iterator &it) const {
						return _pos != it._pos;
					}

					bool	operator<=(const iterator &it) const {
						return _pos <= it._pos;
					}

					bool	operator>=(const iterator &it) const {
						return _pos <= it._pos;
					}

					bool	operator<(const iterator &it) const {
						return _pos < it._pos;
					}

					bool	operator>(const iterator &it) const {
						return _pos > it._pos;
					}
			};

//	template <class Category, class T>
//		iterator<Category, T> operator-(iterator<Category, T> &lhs, iterator<Category, T> &rhs) {
//			std::cout << "coucou\n";	
//			return iterator<Category, T>(lhs.base() - rhs.base());
//		}
	
	/*
		template <class T>
			iterator<T> operator+(std::ptrdiff_t v, iterator<T> &lhs) {
				return iterator<T>(lhs.base() + v);
			}
	
		template <class T>
			typename iterator<T>::difference_type	operator-(const iterator<T> &lhs,
					const iterator<T> &rhs) {
				return lhs.base() - rhs.base();
			}
			*/

//	template <class Category, class T>
//		std::ostream	&operator<<(std::ostream &os, const iterator<Category, T> &it) {
//			std::cout << "coucou\n";	
//			std::cout << it.base();
//
//			return os;
//		}
};

#endif
