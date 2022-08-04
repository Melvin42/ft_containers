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
			typedef MyIterator<T>	iterator;
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
//				typedef T*										pointer;
				typedef T*										iterator;
//				typedef const T*								const_pointeur;
				typedef const T*								const_iterator;
				typedef T&										reference;
				typedef const T&								const_reference;
//				typedef MyIterator<T>							iterator;
//				typedef const iterator							const_iterator;
//				typedef MyReverseIterator<iterator>				reverse_iterator;
//				typedef MyReverseIterator<const_iterator>		const_reverse_iterator;
				typedef Allocator								allocator_type;
//				typedef typename Allocator::reference			reference;
//				typedef typename Allocator::const_reference		const_reference;
//				typedef typename Allocator::pointer				pointer;
//				typedef typename Allocator::const_pointer		const_pointer;
//				typedef std::reverse_iterator<iterator>			reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			private:
				Allocator	_alloc;
				iterator	_p;
//				pointer		_p;
//				iterator	_it;
				size_type	_size;
				size_type	_capacity;
			public:
				/* CONSTRUCT/COPY/DESTROY */
				//default (1)
				vector() : _p(NULL), _size(0), _capacity(0) {};

				//fill (2)
				vector(size_type n, const value_type &val = value_type())
					: _size(n), _capacity(n) {
						_p = _alloc.allocate(_capacity);
//						for (
//						_it = _p.begin();
						(void)val;
				}

				vector	&operator=(const vector<T, Allocator> &vector) {
					_alloc = vector._alloc;
					_size = vector._size;
					_capacity = vector._capacity;
					return *this;
				};

				//range (3)
				template <class iterator>
					vector(iterator first, iterator last,
							const Allocator& = Allocator())
							: _p(NULL), _size(0), _capacity(0) {

						if (last >= first)
							_capacity = last - first;
						_size = _capacity;
						std::cout << "Constructor _capacity = " << _capacity << std::endl;
						_p = _alloc.allocate(_capacity);
						while (first != last) {
							_alloc.construct(_p, *first);
							std::cout << *first << std::endl;
							++first;
							++_p;
						}
//						_p -= _capacity;
						iterator it = begin();
						std:: cout << "_p = " << *it << std::endl;
//						for (iterator	it = begin(); it != end(); ++it) {
//							std:: cout << "_p = " << *it << std::endl;
//						}
					};

				//copy (4)
				vector(const vector<T, Allocator> &vector) { *this = vector; };

				~vector() {
//					_alloc.deallocate(_p.begin(), _capacity);
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
					_alloc.deallocate(_p, _capacity);
//					_alloc.destroy(_p);
					_p = _alloc.allocate(n);
//					for (size_t i = 0; i < _size; i++) {
					size_t	i = 0;
					std::cout << _size << std::endl;
					while (i < _size) {
						_alloc.construct(_p + i, tmp[i]);
						++i;
					}
					_capacity = n;
					std::cout << "AFTER RESERVE" << std::endl;
					for (iterator it = begin(); it != end(); it++) {
						std::cout << "_p =" << *it << std::endl;
					}
//					std::cout << "Reserve add :" << (int)(_capacity - _size) << std::endl;
					std::cout << "Reserve _capacity:" << _capacity << std::endl;
					std::cout << "Reserve _size:" << _size << std::endl;
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
					(void)val;
				};

				void		pop_back() {};

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

					(void)pos;
					(void)val;
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
					(void)position;
				};

				iterator	erase(iterator first, iterator last) {
					(void)first;
					(void)last;
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
