#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"

namespace ft {
	template <class T>
		class	iterator {
			public:
				typedef typename iterator_traits<T*>::value_type		value_type;
				typedef typename iterator_traits<T*>::difference_type	difference_type;
				typedef typename iterator_traits<T*>::pointer			pointer;
				typedef typename iterator_traits<T*>::reference			reference;
				typedef std::random_access_iterator_tag					iterator_category;

			protected:
				pointer	_pos;

			public:

				iterator() : _pos(NULL) {}

				explicit iterator(pointer it) : _pos(it) {}

				iterator(const iterator<typename ft::remove_const<T>::type> &it)
					: _pos(it.base()) {
				}

				iterator	&operator=(const iterator &it) {
					_pos = it.base();
					return *this;
				}

				~iterator() {}

				pointer	base() {
					return _pos;
				}

				pointer	base() const {
					return _pos;
				}

//				reference	operator*() { return *_pos; }
				reference	operator*() const { return *_pos; }
//				pointer		operator->() { return _pos; }
				pointer		operator->() const { return _pos; }

				iterator	&operator-=(difference_type n) {
					for (int i = 0; i < n; i++)
						--_pos;
					return *this;
				}

				iterator	&operator+=(difference_type n) {
					for (int i = 0; i < n; i++)
						++_pos;
					return *this;
				}

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

				iterator	operator+(difference_type v) const {
					iterator	tmp(*this);

					tmp += v;
					return tmp;
				}

				iterator	operator-(difference_type v) const {
					iterator	tmp(*this);

					tmp -= v;
					return tmp;
				}

				template <class Iterator>
					difference_type	operator-(const iterator<Iterator> &it) const {
						return base() - it.base();
					}

				reference	operator[](difference_type v) {
					return *(_pos + v);
				}

				reference	operator[](difference_type v) const {
					return *(_pos + v);
				}

				template <class Iterator>
					bool	operator==(const iterator<Iterator> &it) const {
						return base() == it.base();
					}

				template <class Iterator>
					bool	operator!=(const iterator<Iterator> &it) const {
						return base() != it.base();
					}

				template <class Iterator>
					bool	operator<=(const iterator<Iterator> &it) const {
						return base() <= it.base();
					}

				template <class Iterator>
					bool	operator>=(const iterator<Iterator> &it) const {
						return base() >= it.base();
					}

				template <class Iterator>
					bool	operator<(const iterator<Iterator> &it) const {
						return base() < it.base();
					}

				template <class Iterator>
					bool	operator>(const iterator<Iterator> &it) const {
						return base() > it.base();
					}
		};

	template <class Iterator>
		Iterator operator+(
				typename Iterator::difference_type v,
				const Iterator &it) {
				Iterator	tmp(it);

				tmp += v;
				return tmp;
		}

	template <class Iterator>
		Iterator operator-(
				typename Iterator::difference_type v,
				const Iterator &it) {
				Iterator	tmp(it);

				tmp -= v;
				return tmp;
		}

};

#endif
