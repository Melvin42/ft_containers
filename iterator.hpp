#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {
	template <	class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef T										value_type;
			typedef Distance								difference_type;
			typedef Pointer									pointer;
			typedef Reference								reference;
			typedef Category								iterator_category;
		};
}

template < class Category, class T>
		class	iterator {
			public:
				typedef T				value_type;
				typedef T*				pointer;
				typedef T&				reference;
				typedef std::ptrdiff_t	difference_type;
				typedef Category		iterator_category;

			private:
//				typedef iterator<T>		iterator;
			protected:
				pointer	_pos;

			public:
//				typedef std::reverse_iterator<iterator>			reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

				//			operator	iterator<const T>() const { return iterator<const T>(_pos); }
				iterator() : _pos(NULL) {}
				iterator(pointer it) : _pos(it) {}
				iterator(const iterator &it) : _pos(it.base()) {}
				~iterator() {}

				const pointer	&base() const {
					return _pos;
				}

				iterator				begin() { return _pos; }
				iterator				end(difference_type v) { return _pos + v; }
//				reverse_iterator		rbegin() { return _pos; }
//				const_reverse_iterator	rbegin() const { return _pos; }
//				reverse_iterator		rend() { return _pos; }
//				const_reverse_iterator	rend() const { return _pos; }

				reference	operator*() const { return *_pos; }
				pointer		operator->() const { return _pos; }

				iterator	operator++(int) {
					iterator tmp = *this;
					++(*this);
					return tmp;
				}

				iterator	&operator++() {
					++_pos; return *this;
				}

				iterator	operator--(int) {
					iterator tmp = *this;
					--(*this); return tmp;
				}

				iterator	&operator--() {
					--_pos;
					return *this;
				}

				iterator	operator+(difference_type v) const {
					return iterator(_pos + v);
				}

				iterator	operator-(difference_type v) const {
					return iterator(_pos - v);
				}

				reference	operator[](difference_type v) const {
					return *(_pos + v);
				}

				iterator	&operator=(value_type n) {
					*_pos = n;
					return *this;
				}

				iterator	&operator=(const iterator &it) {
					//				clear();
					//				insert(begin(), it.begin(), it.end());
					_pos = it.base();
					return *this;
				}

				/*
				bool	operator==(const iterator &rhs) const {
					return _pos == rhs._pos;
				}

				bool	operator!=(const iterator &rhs) const {
					return _pos != rhs._pos;
				}

				bool	operator<=(const iterator &rhs) const {
					return _pos <= rhs._pos;
				}

				bool	operator>=(const iterator &rhs) const {
					return _pos <= rhs._pos;
				}

				bool	operator<(const iterator &rhs) const {
					return _pos < rhs._pos;
				}

				bool	operator>(const iterator &rhs) const {
					return _pos > rhs._pos;
				}
		};

	template <class T>
		iterator<T> operator+(std::ptrdiff_t v, iterator<T> &lhs) {
			return iterator<T>(lhs.base() + v);
		}

	template <class T>
		iterator<T> operator-(std::ptrdiff_t v, iterator<T> &lhs) {
			return iterator<T>(lhs.base() - v);
		}

	template <class T>
		typename iterator<T>::difference_type	operator-(const iterator<T> &lhs,
				const iterator<T> &rhs) {
			return lhs.base() - rhs.base();
		}
*/
};
#endif
