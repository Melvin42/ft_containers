#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "map.hpp"

namespace ft {
	template <class Iterator>
			class	reverse_iterator {
				public:
					typedef Iterator												iterator_type;
					typedef typename iterator_traits<Iterator>::value_type			value_type;
					typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
					typedef typename ft::iterator_traits<Iterator>::pointer			pointer;
					typedef typename ft::iterator_traits<Iterator>::reference		reference;

				protected:
					iterator_type	_pos;

				public:

					reverse_iterator() : _pos(NULL) {}

					explicit reverse_iterator(iterator_type it) : _pos(it) {}

					template <class U>
						reverse_iterator(const reverse_iterator<U> &it) : _pos(it.base()) {
						}

					~reverse_iterator() {}

					iterator_type	base() {
						return _pos;
					}

					const iterator_type	base() const {
						return _pos;
					}

					reference	operator*() const { return *_pos; }
					pointer		operator->() const { return _pos; }

					reverse_iterator	operator-=(int n) {
						for (int i = 0; i < n; i++, _pos--) ;
						return *this;
					}

					reverse_iterator	operator+=(int n) {
						for (int i = 0; i < n; i++, _pos++) ;
						return *this;
					}

					reverse_iterator	operator++(int) {
						reverse_iterator	tmp(*this);

						++(*this);
						return tmp;
					}

					reverse_iterator	&operator++() {
						_pos++;
						return *this;
					}

					reverse_iterator	operator--(int) {
						reverse_iterator	tmp = *this;

						--(*this);
						return tmp;
					}

					reverse_iterator	&operator--() {
						_pos--;
						return *this;
					}

					difference_type	operator+(const reverse_iterator &it) const {
						return base() + it.base();
					}

					reverse_iterator	operator+(difference_type v) const {
						return reverse_iterator(_pos + v);
					}

//					reverse_iterator	operator+(int n) {
//						return reverse_iterator(base() + n);
//					}

					difference_type	operator-(const reverse_iterator &it) const {
						return base() - it.base();
					}

					reverse_iterator	operator-(difference_type v) const {
						return reverse_iterator(_pos - v);
					}

//					reverse_iterator	operator-(int n) {
//						return reverse_iterator(_pos - n);
//					}

					reference	operator[](difference_type v) const {
//						return _pos[-v - 1];
						return *(_pos + v);
					}

//					template <class Iterator>
						friend bool	operator==(const Iterator &lhs, const Iterator &rhs);
//					template <class Iterator>
						friend bool	operator!=(const Iterator &lhs, const Iterator &rhs);
//					template <class Iterator>
						friend bool	operator<=(const Iterator &lhs, const Iterator &rhs);
//					template <class Iterator>
						friend bool	operator>=(const Iterator &lhs, const Iterator &rhs);
//					template <class Iterator>
						friend bool	operator<(const Iterator &lhs, const Iterator &rhs);
//					template <class Iterator>
						friend bool	operator>(const Iterator &lhs, const Iterator &rhs);
			};

	template <class Iterator>
		bool	operator==(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class Iterator>
		bool	operator!=(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class Iterator>
		bool	operator<=(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Iterator>
		bool	operator>=(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Iterator>
		bool	operator<(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos < rhs._pos;
		}

	template <class Iterator>
		bool	operator>(const Iterator &lhs, const Iterator &rhs) {
			return lhs._pos > rhs._pos;
		}
	/*
	template <class Category, class T>
		bool	operator==(const iterator &lhs, const iterator &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class Category, class T>
		bool	operator!=(const iterator &lhs, const iterator &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class Category, class T>
		bool	operator<=(const iterator &lhs, const iterator &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator>=(const iterator &lhs, const iterator &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator<(const iterator &lhs, const iterator &rhs) {
			return lhs._pos < rhs._pos;
		}


	template <class Category, class T>
		bool	operator>(const iterator &lhs, const iterator &rhs) {
			return lhs._pos > rhs._pos;
		}

		};
		*/

//	template <class Category, class T>
//		iterator<Category, T> operator-(iterator<Category, T> &lhs, iterator<Category, T> &rhs) {
//			std::cout << "coucou\n";	
//			return iterator<Category, T>(lhs.base() - rhs.base());
//		}
	
	template <class T>
		reverse_iterator<T> operator+(std::ptrdiff_t v, reverse_iterator<T> &it) {
			return reverse_iterator<T>(it.base() + v);
		}
	
	template <class T>
		reverse_iterator<T> operator-(std::ptrdiff_t v, reverse_iterator<T> &it) {
			return reverse_iterator<T>(it.base() + v);
		}
	
	template <class T>
		typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
			return lhs.base() - rhs.base();
		}
	
	template <class T, class U>
		typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) {
			return lhs.base() - rhs.base();
		}
	
	/*
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
