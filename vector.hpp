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
	template <typename T> class	MyIterator;

	template <typename T>
	class	MyIterator {
		public:
				typedef MyIterator<T>							iterator;
				typedef T										value_type;
				typedef T*										pointer;
				typedef T&										reference;
				typedef const T*								const_iterator;
				typedef ptrdiff_t								difference_type;
//				typedef std::reverse_iterator<iterator>			reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			MyIterator() : _pos(NULL) {} ;
			MyIterator(const T* vector) { *this = vector; };
			~MyIterator() {};

			iterator				begin() { return _pos; };
			const_iterator			begin() const { return _pos; };
			iterator				end() { return _pos; };
			const_iterator			end() const { return _pos; };
//			reverse_iterator		rbegin() { return _pos; };
//			const_reverse_iterator	rbegin() const { return _pos; };
//			reverse_iterator		rend() { return _pos; };
//			const_reverse_iterator	rend() const { return _pos; };

			iterator	operator++(int) { return _pos++; };
			iterator	operator++() { ++_pos; return *this; };
			iterator	operator* () const { return *_pos; };
			iterator	operator->() const { return _pos; };
			iterator	operator+ (difference_type v) const { return _pos + v; };
			iterator	operator==(const iterator& rhs) const { return _pos == rhs._pos; };
			iterator	operator!=(const iterator& rhs) const { return _pos != rhs._pos; };
		private:
			pointer	_pos;
	};

//	template<typename T>
//	class	iterator {
//		iterator(const iterator&);
//		~iterator();
//		iterator& operator=(const iterator&);
//		iterator& operator++();
//		reference operator*() const;
//		friend void swap(iterator& lhs, iterator rhs);
//	};
//
//input_iterator : public virtual iterator {
//	iterator operator++(int);
//	value_type operator*() const;
//	pointer operator->() const;
//	friend bool operator==(const iterator&, const iterator&);
//	friend bool operator!=(const iterator&, const iterator&);
//};
//
//
//output_iterator : public virtual iterator {
//	reference operator*() const;
//	iterator operator++(int);
//};
//
//forward_iterator : input_iterator, output_iterator{
//	forward_iterator();
//};
//
//bidirectional_iterator : forward_iterator {
//	iterator& operator--();
//	iterator operator--(int);
// };
//
//random_access_iterator : bidirectionel_iterator {
//	friend bool operator<(const iterator&, const iterator&);
//	friend bool operator>(const iterator&, const iterator&);
//	friend bool operator<=(const iterator&, const iterator&);
//	friend bool operator>=(const iterator&, const iterator&);
//
//	iterator& operator+=(size_type);
//	friend iterator operator+(const iterator&, size_type);
//	friend iterator operator+(size_type, const iterator&);
//	iterator& operator-=(size_type);
//	friend iterator operator- const iterator&, size_type);
//	friend difference_type operator-(iterator, iterator);
//
//	reference operator[](size_type) const;
//};
//
	template <class T, class Allocator = std::allocator<T> >
		class vector {
			public:
				/* TYPES */
				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef T										value_type;
				typedef T*										iterator;
				typedef const T*								const_iterator;
				typedef size_t									size_type;
				typedef ptrdiff_t								difference_type;
				typedef Allocator								allocator_type;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef std::reverse_iterator<iterator>			reverse_iterator;
				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

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
				vector(size_type n) //, const value_type &val = value_type())
					: _size(n), _capacity(n) {
						_p = _alloc.allocate(n);
				};

				vector	&operator=(const vector<T, Allocator> &vector) {
					_alloc = vector._alloc;
					_size = vector._size;
					_capacity = vector._capacity;
					return *this;
				};

				//range (3)
//				template <class InputIterator>
//					vector(InputIterator first, InputIterator last,
//							const Allocator& = Allocator()) {
//					};

				//copy (4)
				vector(const vector<T, Allocator> &vector) { *this = vector; };

				~vector() {
					_alloc.deallocate(_p, _capacity);
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
				iterator				begin();
				const_iterator			begin() const;
				iterator				end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator	rbegin() const;
				reverse_iterator		rend();
				const_reverse_iterator	rend() const;

				/* CAPACITY */
				size_type	size() const { return _size; };
				size_type	capacity() const { return _capacity; };

				size_type	max_size() const {
					return std::numeric_limits<size_type>::max(); };

				bool		empty() const { return false; };

				void		resize(size_type sz) {
					(void)sz;
				};

				void		reserve(size_type n) {
					(void)n;
				};

				/* ELEMENT ACCES */
				reference		operator[](size_type n) {
					if (n >= _capacity)
						throw std::out_of_range("");
					return *(_p + n);
				};
				const_reference	operator[](size_type n) const { return *(_p + n); };
				const_reference	at(size_type n) const { return *(_p + n); };
				reference		at(size_type n) { return *(_p + n); };
				reference		front() { return _p; };
				const_reference	front() const { return _p; };
				reference		back() { return _p + _capacity; };
				const_reference	back() const { return _p + _capacity; };

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
					(void)pos;
					(void)n;
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
