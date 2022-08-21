#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <typename T, class Allocator>	class vector;
/*
	template <class T> class	MyIterator;

	template <class T>
	class	MyIterator {
		public:
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef ptrdiff_t								difference_type;
			
//			typedef std::reverse_iterator<iterator>			reverse_iterator;
//			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

//			pointer					begin() { return _pos; };
//			pointer					end(difference_type v) { return _pos + v; };
//			reverse_iterator		rbegin() { return _pos; };
//			const_reverse_iterator	rbegin() const { return _pos; };
//			reverse_iterator		rend() { return _pos; };
//			const_reverse_iterator	rend() const { return _pos; };

		private:
//			typedef MyIterator<T>	iterator;
			pointer	_pos;

		public:
			MyIterator() : _pos(NULL) {} ;
			MyIterator(const iterator &it) { *this = it; };
			~MyIterator() {};

			iterator	operator++(int) { return _pos++; };
			iterator	&operator++() { ++_pos; return *this; };
			reference	operator*() const { return *_pos; };
			pointer		operator->() const { return _pos; };
			reference	operator+(difference_type v) const { return _pos + v; };
			reference	operator[](difference_type v) const { return *(_pos + v); };
			iterator	&operator=(const iterator &it) {
//				clear();
//				insert(begin(), it.begin(), it.end());
				_pos = it._pos;
				return *this;
			};
			bool		operator==(const iterator &rhs) const { return _pos == rhs._pos; };
			bool		operator!=(const iterator &rhs) const { return _pos != rhs._pos; };
	};
	*/

	template <typename T, class Allocator = std::allocator<T> >
		class vector {
			public:
				/* TYPES */

				typedef T										value_type;
				typedef size_t									size_type;
				typedef ptrdiff_t								difference_type;
				typedef T*										iterator;
				typedef const T*								const_iterator;
				typedef T&										reference;
				typedef const T&								const_reference;
				typedef Allocator								allocator_type;
//				typedef std::reverse_iterator<iterator>			reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			private:
				Allocator	_alloc;
				iterator	_p;
				size_type	_size;
				size_type	_capacity;
			public:
				/* CONSTRUCT/COPY/DESTROY */

				//default (1)
				vector() : _p(NULL), _size(0), _capacity(0) {};

				//fill (2)
				vector(size_type n, const value_type &val = value_type())
					: _p(NULL), _size(n), _capacity(n) {
						_p = _alloc.allocate(_capacity);
						for (size_t i = 0; i < n; i++) {
							_alloc.construct(_p + i, val);
						}
				}

				vector	&operator=(const vector<T, Allocator> &vector) {
					_alloc = vector._alloc;
					_p = vector._p;
					_size = vector._size;
					_capacity = vector._capacity;
					return *this;
				};

				//range (3)
				vector(iterator first, iterator last,
						const Allocator& = Allocator())
						: _p(NULL), _size(0), _capacity(0) {

					if (last >= first)
						_capacity = last - first;
					_size = _capacity;
					_p = _alloc.allocate(_capacity);
					for (size_t i = 0; first != last; i++) {
						_alloc.construct(_p + i, *first);
						++first;
					}
				};

				//copy (4)
				vector(const vector<T, Allocator> &vector) { *this = vector; };

				~vector() {
//					if (_capacity > 0)
//						_alloc.deallocate(_p, _capacity);
//					_alloc.destroy(_p);
				};

//				template <class InputIterator>
//					void	assign(InputIterator first, InputIterator last) {
//					};

				void			assign(size_type n, const T& u) {
					(void)n;
					(void)u;
				};

				allocator_type	get_allocator() const {
					return _alloc;
				};


				/* ITERATORS */
				iterator				begin() { return _p; };
				const_iterator			begin() const { return _p; };
				iterator				end() { return _p + _size; };
				const_iterator			end() const { return _p + _size; };
//				reverse_iterator		rbegin() { return _pos; };
//				const_reverse_iterator	rbegin() const { return _pos; };
//				reverse_iterator		rend() { return _pos; };
//				const_reverse_iterator	rend() const { return _pos; };

				/* CAPACITY */
				size_type	size() const { return _size; };
				size_type	capacity() const { return _capacity; };

				size_type	max_size() const {
					return std::numeric_limits<size_type>::max() / sizeof(difference_type); };

				bool		empty() const { return false; };

				void		resize(size_type sz) {
					if (sz < _capacity)
						_p[sz] = 0;
					else {
//						insert();
						_p[sz] = 0;
						//destroy
					}
				}; 

				void		reserve(size_type n) {
					value_type	tmp[_size];

					for (size_t i = 0; i < _size; i++) {
						tmp[i] = *(_p + i);
					}
					if (_capacity > 0)
						_alloc.deallocate(_p, _capacity);
					_capacity += n;
					_p = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++) {
						_alloc.construct(_p + i, tmp[i]);
					}
				}

				/* ELEMENT ACCES */

				reference		operator[](size_type n) {
					if (n >= _capacity)
						throw std::out_of_range("");
					return _p[n];
				};
				const_reference	operator[](size_type n) const { return _p[n]; };
				reference		at(size_type n) { return *(_p + n); };
				const_reference	at(size_type n) const { return *(_p + n); };
				reference		front() { return _p; };
				const_reference	front() const { return _p; };
				reference		back() { return _p + _size; };
				const_reference	back() const { return _p + _size; };

				/* MODIFIERS */

				void		push_back(const value_type& val) {
					if (_capacity == 0)
						reserve(1);
					else if (_size == _capacity)
						reserve(_capacity + 1);
					_alloc.construct(_p + _size, val);
					++_size;
				};

				void		pop_back() {
					--_size;
				};

				//INSERT

				//single element (1)
				iterator	insert(iterator pos, const value_type& val) {
					insert(pos, 1, val);
					return pos;
				};

				//fill (2)
				void		insert(iterator pos, size_type n,
								const value_type& val) {
					reserve(n);
					iterator	it = begin() + _size;
					(void)pos;
					_size += n;
					while (it != end()) {
						*it = val;
						++it;
					}
				};

				//range (3)
//				template <class InputIterator>
//					void	insert(iterator position,
//							InputIterator first, InputIterator last) {
//					};

//				void	insert(iterator position,
//						iterator first, iterator last) {
//				//move (4)
//				//initializer list (5)
//
//				};

				iterator	erase(iterator position) {
					value_type	tmp[_size - 1];
					iterator	it = begin();
					size_t		i = 0;

					while (it != position) {
						tmp[i] = *it;
						++it;
						++i;
					}
					while (++it != end()) {
						tmp[i] = *it;
						++i;
					}
					--_size;
					i = 0;
					for (i = 0; i < _size; i++) {
						_alloc.construct(_p + i, tmp[i]);
					}
					_alloc.construct(_p + i, 0);
					return _p;
				};

				iterator	erase(iterator first, iterator last) {
					int			diff = 0;

					if (last - first > 0)
						diff = last - first;
					value_type	tmp[_size - diff];
					iterator	it = begin();
					size_t		i = 0;

					while (it != first) {
						tmp[i] = *it;
						++it;
						++i;
					}
					while (it != last) {
						++it;
					}
					while (it != end()) {
						tmp[i] = *it;
						++it;
						++i;
					}
					for (i = 0; i < _size; i++) {
						_alloc.construct(_p + i, tmp[i]);
					}
					_size -= diff;
					return _p;
				};

				void		swap(vector<T, Allocator> &) {};
				void		clear() {};

				bool	operator==(const vector<T, Allocator>& rhs) { return (*this == rhs);}
				bool	operator!=(const vector<T, Allocator>& rhs) { return (*this != rhs);}
				bool	operator<(const vector<T, Allocator>& rhs) { return (*this < rhs);}
				bool	operator<=(const vector<T, Allocator>& rhs) { return (*this <= rhs);}
				bool	operator>(const vector<T, Allocator>& rhs) { return (*this > rhs);}
				bool	operator>=(const vector<T, Allocator>& rhs) { return (*this >= rhs);}

		};
}

#endif
