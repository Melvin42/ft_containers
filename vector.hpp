#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "iterator_traits.hpp"

//namespace ft {
	template <typename T, class Allocator>	class vector;
//	template <class T> class				MyIterator<T>;

	/*
	template <class T>
	class	MyIterator {
		public:
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::ptrdiff_t							difference_type;
			typedef	std::random_access_iterator_tag			iterator_categorie;

		private:
			typedef MyIterator<T>		iterator;
		protected:
			pointer	_pos;

		public:
			typedef std::reverse_iterator<iterator>			reverse_iterator;
//			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

//			operator	MyIterator<const T>() const { return MyIterator<const T>(_pos); }
			MyIterator() : _pos(NULL) {}
			MyIterator(pointer it) : _pos(it) {}
			MyIterator(const iterator &it) : _pos(it.base()) {}
			~MyIterator() {}

			const pointer	&base() const {
				return _pos;
			}

			iterator				begin() { return _pos; }
			iterator				end(difference_type v) { return _pos + v; }
			reverse_iterator		rbegin() { return _pos; }
//			const_reverse_iterator	rbegin() const { return _pos; }
			reverse_iterator		rend() { return _pos; }
//			const_reverse_iterator	rend() const { return _pos; }

			reference	operator*() const { return *_pos; }
			pointer		operator->() const { return _pos; }
			MyIterator	operator++(int) { MyIterator tmp = *this; ++(*this); return tmp; }
			MyIterator	&operator++() { ++_pos; return *this; }
			MyIterator	operator--(int) { MyIterator tmp = *this; --(*this); return tmp; }
			MyIterator	&operator--() { --_pos; return *this; }
			MyIterator	operator+(difference_type v) const { return MyIterator(_pos + v); }
			MyIterator	operator-(difference_type v) const { return iterator(_pos - v); }
			reference	operator[](difference_type v) const { return *(_pos + v); }
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
			bool	operator==(const MyIterator &rhs) const { return _pos == rhs._pos; }
			bool	operator!=(const MyIterator &rhs) const { return _pos != rhs._pos; }
			bool	operator<=(const MyIterator &rhs) const { return _pos <= rhs._pos; };
			bool	operator>=(const MyIterator &rhs) const { return _pos <= rhs._pos; };
			bool	operator<(const MyIterator &rhs) const { return _pos < rhs._pos; };
			bool	operator>(const MyIterator &rhs) const { return _pos < rhs._pos; };
	};

	template <class T>
		MyIterator<T> operator+ (std::ptrdiff_t v, MyIterator<T> &lhs) { return MyIterator<T>(lhs.base() + v); }

	template <class T>
		MyIterator<T> operator- (std::ptrdiff_t v, MyIterator<T> &lhs) { return MyIterator<T>(lhs.base() - v); }

	template <class T>
	typename MyIterator<T>::difference_type	operator-(const MyIterator<T> &lhs, const MyIterator<T> &rhs) { return lhs.base() - rhs.base(); }
}
*/

namespace ft {
	template <typename T, class Allocator = std::allocator<T> >
		class vector {
			public:
				/* TYPES */

				typedef T										value_type;
				typedef std::size_t								size_type;
				typedef std::ptrdiff_t							difference_type;
				typedef T*										pointer;
//				typedef MyIterator<T>							iterator;
//				typedef const MyIterator<T>						const_iterator;
				typedef T*										iterator;
				typedef const T*								const_iterator;
				typedef T&										reference;
				typedef const T&								const_reference;
				typedef Allocator								allocator_type;
				typedef std::reverse_iterator<iterator>			reverse_iterator;
				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			private:
				Allocator	_alloc;
//				iterator	_p;
				pointer		_p;
				pointer		_p_end;
				size_type	_capacity;

			public:
				/* CONSTRUCT/COPY/DESTROY */

				vector	&operator=(const vector<T, Allocator> &vector) {
					if (this != &vector) {
						if (_p)
							_alloc.deallocate(_p, size());
						_alloc = vector.get_allocator();//_alloc;
						_capacity = vector._capacity;
						_p = _alloc.allocate(_capacity);
						size_t	i = 0;

						_p_end = _p;
						for (const_iterator it = vector.begin(); it != vector.end(); it++, i++) {
							_alloc.construct(_p + i, *it);
							++_p_end;
						}
					}
					return *this;
				}

				//default (1)
				vector() : _p(NULL), _p_end(NULL), _capacity(0) {};

				//fill (2)
				vector(size_type n, const value_type &val = value_type())
					: _p(NULL), _p_end(NULL), _capacity(n) {
						_p = _alloc.allocate(_capacity);
						_p_end = _p;
						for (size_t i = 0; i < n; i++) {
							_alloc.construct(_p + i, val);
							++_p_end;
						}
				}

				//range (3)
				template <class InputIterator>
					vector(InputIterator first, InputIterator last,
							const Allocator& = Allocator(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
							: _p(NULL), _p_end(NULL), _capacity(0) {
						if (last - first > 0) {
							_capacity = last - first;
							_p = _alloc.allocate(_capacity);
							_p_end = _p;
							for (size_t i = 0; first != last; i++) {
								_alloc.construct(_p + i, *first);
								++first;
								++_p_end;
							}
						}
						else
							throw std::length_error("cannot create std::vector larger than max_size()");
					}

				//copy (4)
				vector(const vector<T, Allocator> &vector) {
					*this = vector;
				}

				~vector() {
					if (_capacity > 0)
						_alloc.deallocate(_p, _capacity);
				}

				template <class InputIterator>
					void	assign(InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {

						if (last - first > 0) {
							_capacity = last - first;
							_p = _alloc.allocate(_capacity);
							_p_end = _p;
							for (size_t i = 0; first != last; i++) {
								_alloc.construct(_p + i, *first);
								++first;
								++_p_end;
							}
						}
					}

				void			assign(size_type n, const T& u) {
					reserve(n);
					for (size_t i = 0; i < n; i++) {
						_alloc.construct(_p + i, u);
						if (size() <= i)
							++_p_end;
					}
					for (size_t i = size(); i > n; i--) {
						--_p_end;
					}
				}

				allocator_type	get_allocator() const {
					return _alloc;
				}

				/* ITERATORS */
				iterator				begin() { return _p; }
				const_iterator			begin() const { return _p; }
				iterator				end() { return _p_end; }
				const_iterator			end() const { return _p_end; }
				reverse_iterator		rbegin() { return reverse_iterator(_p_end); }
				const_reverse_iterator	rbegin() const { return const_reverse_iterator(_p_end); }
				reverse_iterator		rend() { return reverse_iterator(_p); }
				const_reverse_iterator	rend() const { return const_reverse_iterator(_p); }
//				iterator_type			base() const { return ; }

				/* CAPACITY */
				size_type	size() const { return _p_end - _p; }

				size_type	capacity() const { return _capacity; }

				size_type	max_size() const {
					return std::numeric_limits<size_type>::max() / sizeof(difference_type); }

				bool		empty() const { return (size() == 0); }

				void		resize(size_type sz, value_type val = value_type()) {
					size_t	i = 0;

					if (sz < size()) {
						_p_end = _p;
						for (i = 0; i < sz; i++) { ++_p_end; }
					} else {
						size_t	tmp = size();

						for (i = 0; i < sz; i++) {
							if (i >= tmp)
								push_back(val);
						}
					}
				}

				void		reserve(size_type n) {
					size_t		size_tmp = size();
					value_type	tmp[size_tmp];

					for (size_t i = 0; i < size(); i++) {
						tmp[i] = *(_p + i);
					}
					if (_capacity > 0)
						_alloc.deallocate(_p, _capacity);
					if (_capacity <= n)
						_capacity = n;
					else
						_capacity += n;
					_p = _alloc.allocate(_capacity);
					_p_end = _p;
					for (size_t i = 0; i < size_tmp; i++) {
						_alloc.construct(_p + i, tmp[i]);
						++_p_end;
					}
				}

				/* ELEMENT ACCES */

				reference		operator[](size_type n) {
					if (n >= size())
						throw std::out_of_range("");
					return _p[n];
				}

				const_reference	operator[](size_type n) const {
					if (n >= size())
						throw std::out_of_range("");
					return _p[n];
				}

				reference		at(size_type n) {
					if (n >= size())
						throw std::out_of_range("");
					return *(_p + n);
				}

					const_reference	at(size_type n) const {
					if (n >= size())
						throw std::out_of_range("");
					return *(_p + n);
				}

				reference		front() { return *_p; }
				const_reference	front() const { return *_p; }
				reference		back() { return *(_p_end - 1); }
				const_reference	back() const { return *(_p_end - 1); }

				/* MODIFIERS */

				void		push_back(const value_type& val) {
//					std::cout << "CAPACITY = " << _capacity << '\n';
					if (size() + 1 > _capacity)
						reserve(_capacity + 1);
					_alloc.construct(_p + size(), val);
					++_p_end;
				}

				void		pop_back() {
					if (_p + size()) {
						_alloc.destroy(_p + size());
						_p_end--;
					}
				}

				//INSERT

				//single element (1)
				iterator	insert(iterator pos, const value_type& val) {
					insert(pos, 1, val);
					return pos;
				}

				//fill (2)
				void		insert(iterator pos, size_type n,
								const value_type& val) {
					size_t		count = 0;
					size_t		i = 0;
					size_t		j = 0;
					value_type	tmp[size()];
					iterator	it = begin();
					size_t		size_tmp = size();

					for (i = 0; it != end(); it++, i++) {
						tmp[i] = *it;
					}
					it = begin();
					if (pos < it)
						return ;
					for (iterator it = begin(); it != pos; it++, count++) ;

					if (n + size() > _capacity)
						reserve(n + size());

					i = 0;
					while (i < size()) {
						_alloc.destroy(_p + i);
						i++;
					}
					i = 0;
					if (!count) {
						while (i < n) {
							_alloc.construct(_p + i, val);
							++i;
							++_p_end;
						}
					}
					while (j < count) {
						_alloc.construct(_p + j, tmp[j]);
						++j;
					}
					while (i < n) {
						_alloc.construct(_p + count + i, val);
						++_p_end;
						++i;
					}
					while (j < size_tmp) {
						_alloc.construct(_p + j + i, tmp[j]);
						++j;
					}
				}

				//range (3)
				template <class InputIterator>
					void	insert(iterator pos,
							InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
						size_t		i = 0;
						size_t		j = 0;
						size_t		count = 0;
						size_t		n = 0;
						value_type	tmp[size()];
						iterator	it = begin();
						size_t		size_tmp = size();

						for (i = 0; it != end(); it++, i++) {
							tmp[i] = *it;
						}
						it = begin();
						if (pos < it)
							return ;
						for (iterator it = begin(); it != pos; it++, count++) ;

						i = 0;
						if (last - first > 0)
							n = last - first;
						if (n + size() > _capacity)
							reserve(n + size());

						if (!count) {
							while (i < n) {
								_alloc.construct(_p + i, *first);
								++i;
								++_p_end;
								++first;
							}
						}
						while (j < count) {
							_alloc.construct(_p + j, tmp[j]);
							++j;
						}
						while (i < n) {
							_alloc.construct(_p + count + i, *first);
							++_p_end;
							++i;
							++first;
						}
						while (j < size_tmp) {
							_alloc.construct(_p + j + i, tmp[j]);
							++j;
						}
					}

				iterator	erase(iterator pos) {
					value_type	tmp[size() - 1];
					iterator	it = begin();
					size_t		i = 0;
					size_t		len = size();
					size_t		ret;

					while (it != pos) {
						tmp[i] = *it;
						++it;
						++i;
					}
					ret = i;
					while (++it != end()) {
						tmp[i] = *it;
						++i;
					}
					i = 0;
					for (i = 0; i < size(); i++) {
						_alloc.destroy(_p + i);
					}
					_p_end = _p;
					for (i = 0; i + 1 < len; i++) {
						_alloc.construct(_p + i, tmp[i]);
						++_p_end;
					}
					return _p + ret;
				}

				iterator	erase(iterator first, iterator last) {
					size_t	i = 0;
					size_t	n = 0;
					size_t	len = size();
					size_t	ret = 0;

					if (last - first > 0)
						n = last - first;
					if (n > len)
						n = len;
					if (len - n <= 0)
						len = 0;
					else
						len -= n;

					value_type	tmp[len + 1];

					if (len > 0) {
						iterator	it = begin();

						while (it != first && i < len) {
							tmp[i] = *it;
							++it;
							++i;
						}
						ret = i;
						while (it != last) {
							++it;
						}
						while (it != end() && i < len) {
							tmp[i] = *it;
							++it;
							++i;
						}
					}
					for (i = 0; i < size(); i++) {
						_alloc.destroy(_p + i);
					}
					_p_end = _p;
					for (i = 0; i < len; i++) {
						_alloc.construct(_p + i, tmp[i]);
						++_p_end;
					}
					return _p + ret;
				}

				void		swap(vector<T, Allocator> &x) {
					pointer		p_tmp;
					value_type	cap_tmp;

					p_tmp = _p;
					_p = x._p;
					x._p = p_tmp;

					p_tmp = _p_end;
					_p_end = x._p_end;
					x._p_end = p_tmp;

					cap_tmp = _capacity;
					_capacity = x._capacity;
					x._capacity = cap_tmp;
				}

				void		clear() {
					for (iterator it = begin(); it != end(); it++) {
						_alloc.destroy(it);
					}
					_p_end = _p;
				}

//				friend typename iterator::difference_type operator-(const_iterator &lhs, const_iterator &rhs) {;;;
//					return lhs - rhs;
//				}
		};

	template<class T, class Alloc>
		bool	operator==(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs)
		{
			if (lhs.size() == rhs.size()) {
				for (size_t i = 0; i < lhs.size(); i++) {
					if (lhs[i] != rhs[i])
						return false;
				}
				return true;
			}
			return false;
		}

	template<class T, class Alloc>
		bool	operator!=(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs) {
			return (!(lhs == rhs));
		}

	template<class T, class Alloc>
		bool	operator<(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs) {
			size_t i;

			for (i = 0; i < lhs.size() && i < rhs.size(); i++) {
				if (lhs[i] < rhs[i])
					return true;
				else if (lhs[i] > rhs[i])
					return false;
			}
			if (i == lhs.size() && i < rhs.size())
				return true;
			else
				return false;
		}

	template<class T, class Alloc>
		bool	operator<=(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs) {
			return (!(rhs < lhs));
		}

	template<class T, class Alloc>
		bool	operator>(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs) {
			return (rhs < lhs);
		}

	template<class T, class Alloc>
		bool	operator>=(const vector<T, Alloc> &lhs,
							const vector<T, Alloc> &rhs) {
			return (!(lhs < rhs));
		}

	template<class T, class Alloc>
		void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
			x.swap(y);
		}

}

#endif
