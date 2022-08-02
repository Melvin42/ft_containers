#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>

namespace ft {

	class	iterator {
	};

	template <class T, class Allocator>	class vector;

	template <class T, class Allocator = std::allocator<T> >
		class vector {
			public:
				/* TYPES */
				typedef typename Allocator::reference				reference;
				typedef typename Allocator::const_reference			const_reference;
				typedef T											value_type;
				typedef T*											iterator;
				typedef const T*									const_iterator;
				typedef size_t										size_type;
				typedef ptrdiff_t									difference_type;
				typedef Allocator									allocator_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer			const_pointer;
				typedef std::reverse_iterator<iterator>				reverse_iterator;
				typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

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
						for (size_type	i = 0; i < n; i++) {
							*(_p + i) = i + 1;
						}
						for (size_type	i = 0; i < n; i++) {
//							std::cout << *(_p + i) << std::endl;
						}
				};

				//range (3)
				template <class InputIterator>
					vector(InputIterator first, InputIterator last,
							const Allocator& = Allocator()) {};

				//copy (4)
				vector(const vector<T, Allocator> &vector) { *this = vector; };

				~vector() {
					_alloc.deallocate(_p, _capacity);
				};

				vector	&operator=(const vector<T, Allocator> &vector) {
					*this._alloc = vector._alloc;
					*this._size = vector._size;
					*this._capacity = vector._capacity;
				};

				template <class InputIterator>
					void		assign(InputIterator first, InputIterator last) {
					};

				void			assign(size_type n, const T& u) {
				};

				allocator_type	get_allocator() const {
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
				};

				void		reserve(size_type n) {
				};

				/* ELEMENT ACCES */
				reference		operator[](size_type n) { return *(_p + n); };
				const_reference	operator[](size_type n) const { return *(_p + n); };
				const_reference	at(size_type n) const { return *(_p + n); };
				reference		at(size_type n) { return *(_p + n); };
				reference		front() { return _p; };
				const_reference	front() const { return _p; };
				reference		back() { return _p + _capacity; };
				const_reference	back() const { return _p + _capacity; };

				/* MODIFIERS */
				void		push_back(const value_type& val) {};
				void		pop_back() {};
				iterator	insert(iterator position, const T& x) {};
				void		insert(iterator position, size_type n, const T& x) {};
				template <class InputIterator>
					void	insert(iterator position,
							InputIterator first, InputIterator last) {};
				iterator	erase(iterator position) {};
				iterator	erase(iterator first, iterator last) {};
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
