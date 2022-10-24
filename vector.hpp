#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
		class vector {
			public:
				/* TYPES */

				typedef T													value_type;
				typedef Alloc												allocator_type;
				typedef typename allocator_type::reference					reference;
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::pointer					pointer;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef ft::iterator<value_type>							iterator;
				typedef ft::iterator<const value_type>						const_iterator;
				typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type	difference_type;
				typedef std::size_t											size_type;

			protected:
				Alloc		_alloc;

			private:
				iterator	_p;
				iterator	_p_end;
				size_type	_capacity;

			public:
				/* CONSTRUCT/COPY/DESTROY */

				vector	&operator=(const vector<T, Alloc> &vector) {
					if (&vector != this) {
						clear();
//						_capacity = vector
						if (_capacity) {
							_alloc.deallocate(_p.base(), _capacity);
							_p_end = NULL;
							_p = _p_end;
							_capacity = 0;
						}
//						_p_end = NULL;
//						_p = _p_end;
//						_capacity = 0;
						_alloc = vector.get_allocator();//_alloc;
						assign(vector.begin(), vector.end());
					}
					return *this;
				}

				//default (1)
				explicit vector(const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _p_end(NULL), _capacity(0) {
						_p = _p_end;
					};

				//fill (2)
				explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _p_end(NULL), _capacity(0) {
					_p_end = _p;
					assign(n, val);
				}

				//range (3)
				template <class InputIterator>
					vector(InputIterator first, InputIterator last,
							const allocator_type &alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
							: _alloc(alloc), _p_end(NULL), _capacity(0) {
//						_p_end = _p;
						assign(first, last);
//						else
//							throw std::length_error("cannot create std::vector larger than max_size()");
					}

				//copy (4)
//				IteratorMap(const IteratorMap<typename std::remove_const<U>::type> &it)
//				vector(const vector<typename std::remove_const<T>::type, Alloc> &vector) {
				vector(const vector<T, Alloc> &vector) {
					if (!_p.base())
						_capacity = 0;
					*this = vector;
	//				assign(vector.begin(), vector.end());
				}

				~vector() {
					clear();
//					std::cout << _capacity<< std::endl;
//					if (_p.base())
						_alloc.deallocate(_p.base(), _capacity);
//					_alloc.deallocate(_p, _capacity);
				}

				template <class InputIterator>
					void	assign(InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
						size_type	n = 0;

						for (InputIterator it = first; it != last; ++it) {
							++n;
						}
						clear();
						reserve(n);
						_p_end = _p;
						for (InputIterator it = first; it != last; ++it) {
							_alloc.construct(_p_end.base(), *it);
							++_p_end;
						}
					}

				void			assign(size_type n, const T& u) {
					clear();
//					reserve(n);

					insert(begin(), n, u);
				}

				allocator_type	get_allocator() const {
					return _alloc;
				}

				/* ITERATORS */
				iterator				begin() {
					return (_p);
				}

				const_iterator			begin() const {
					return (_p);
				}

				iterator				end() {
					return (_p_end);
				}

				const_iterator			end() const {
					return (_p_end);
				}

				reverse_iterator		rbegin() {
					return reverse_iterator(end());
				}

				const_reverse_iterator	rbegin() const {
					return const_reverse_iterator(end());
				}

				reverse_iterator		rend() {
					return reverse_iterator(begin());
				}

				const_reverse_iterator	rend() const {
					return const_reverse_iterator(begin());
				}

				/* CAPACITY */
				size_type	size() const { return _p_end - _p; }

				size_type	capacity() const { return _capacity; }

				size_type	max_size() const {
					return _alloc.max_size(); }

				bool		empty() const { return (size() == 0); }

				void		resize(size_type sz, value_type val = value_type()) {
					if (sz < size()) {
						for (size_type i = size(); i > sz; --i) {
							--_p_end;
							_alloc.destroy(_p_end.base());
						}
					} else {
						if (sz > _capacity) {
							reserve(sz);
						}
						for (iterator last = _p + sz; _p_end != last; ++_p_end) {
							_alloc.construct(_p_end.base(), val);
						}
					}
				}

				void		reserve(size_type n) {
					if (n > max_size())
						throw std::length_error("vector::reserve");
					if (n > _capacity) {
						vector<T, Alloc>	tmp(*this);
						size_type	new_capacity = (_capacity + 1) * 2 + n;

						clear();
						if (_capacity)
							_alloc.deallocate(_p.base(), _capacity);
						_p = _alloc.allocate(new_capacity);
						_capacity = new_capacity;
						_p_end = _p;
						for (iterator it = tmp.begin(); it != tmp.end(); ++it) {
							_alloc.construct(_p_end.base(), *it);
							++_p_end;
						}
					}
				}

				/* ELEMENT ACCES */

				reference		operator[](size_type n) {
					return *(_p + n);
				}

				const_reference	operator[](size_type n) const {
					return *(_p + n);
				}

				reference		at(size_type n) {
					if (n >= size() || size() == 0)
						throw std::out_of_range("");
					return *(_p + n);
				}

				const_reference	at(size_type n) const {
					if (n >= size() || size() == 0)
						throw std::out_of_range("");
					return *(_p + n);
				}

				reference		front() { return *_p; }
				const_reference	front() const { return *_p; }

				reference		back() { return *(_p_end - 1); }

				const_reference	back() const {
					return *(_p_end - 1); }

				/* MODIFIERS */

				void	push_back(const value_type& val) {
//					if (size() + 1 > _capacity)
					reserve(size() + 1);
					_alloc.construct(_p_end.base(), val);
					++_p_end;
				}

				void	pop_back() {
//					if (_p.base() + size()) {
					--_p_end;
					_alloc.destroy(_p_end.base());
				}

				//INSERT

				//single element (1)
				iterator	insert(iterator pos, const value_type& val) {
					insert(pos, 1, val);
					return pos;
				}

				//fill (2)
				void	insert(iterator position, size_type n,
								const value_type& val) {
						vector<T, Alloc>	tmp(*this);
						size_type	pos = position - _p;

						reserve(size() + n);
						iterator	it_tmp = _p + pos;

						for (size_type i = 0; i < n; ++i) {
							if (it_tmp < _p_end)
								_alloc.destroy(it_tmp.base());
							_alloc.construct(it_tmp.base(), val);
							++it_tmp;
						}
						iterator	tpmp = tmp._p + pos;

						while (it_tmp != _p + _capacity && tpmp != tmp.end()) {
							if (it_tmp < _p_end)
								_alloc.destroy(it_tmp.base());
							_alloc.construct(it_tmp.base(), *tpmp);
							++it_tmp;
							++tpmp;
						}
						_p_end += n;
				}

				//range (3)
				template <class InputIterator>
					void	insert(iterator position,
							InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
						size_type	n = 0;

						for (InputIterator it = first; it != last; ++it) {++n;}

						vector<T, Alloc>	tmp(*this);
						size_type	pos = position - _p;

						reserve(size() + n);
						iterator	it_tmp = _p + pos;
						while (first != last) {
							if (it_tmp < _p_end)
								_alloc.destroy(it_tmp.base());
							_alloc.construct(it_tmp.base(), *first);
							++it_tmp;
							++first;
						}
						iterator	tpmp = tmp._p + pos;

						while (it_tmp != _p + _capacity && tpmp != tmp._p_end) {
							if (it_tmp < end())
								_alloc.destroy(it_tmp.base());
							_alloc.construct(it_tmp.base(), *tpmp);
							++it_tmp;
							++tpmp;
						}
						_p_end += n;
					}

				iterator	erase(iterator position) {
//					if (position == end())
//						return(position);
					--_p_end;
					for (iterator it = position; it != _p_end; ++it) {
						_alloc.destroy(it.base());
						_alloc.construct(it.base(), *(it + 1));
					}
					_alloc.destroy(_p_end.base());
					return position;
				}

				iterator	erase(iterator first, iterator last) {
					if (first == last)
						return last;
					size_type	dist = std::distance(first, last);
					iterator	ret(first);
					while (dist) {
						ret = erase(ret);
						--dist;
					}
					return ret;
				}

				void	swap(vector<T, Alloc> &x) {
//					Alloc		alloc_tmp;
					iterator	p_tmp;
					size_type	cap_tmp;

//					alloc_tmp = _alloc;
//					_alloc = x._alloc;
//					x._alloc = alloc_tmp;

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

				void	clear() {
					while (_p != _p_end) {
						--_p_end;
						_alloc.destroy(_p_end.base());
					}
				}
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

};

#endif
