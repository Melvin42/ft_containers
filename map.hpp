#ifndef map_HPP
#define map_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <	class Key,
				class T,
				class Compare = less<Key>,
				class Alloc = allocator<pair<const Key, T> >
		class map {
			public:
				/* TYPES */
				typedef T										key_type;
				typedef T										mapped_type;
				typedef T										value_type;
				typedef T										key_compare;
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
				Alloc	_alloc;
//				iterator	_p;
				pointer		_p;
				pointer		_p_end;
				size_type	_capacity;

			public:
				/* CONSTRUCT/COPY/DESTROY */

				map	&operator=(const map<Key, T, Compare, Alloc> &map) {
					return *this;
				}

				//empty (1)
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
					: _p(NULL), _p_end(NULL), _capacity(0) {};

				//fill (2)
				template <class InputIterator>
					map(InputIterator first, InputIterator last,
						const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
						: _p(NULL), _p_end(NULL), _capacity(n) {
					}

				//copy (3)
				map(const map<Key, T, Compare, Alloc> &map) {
					*this = map;
				}

				~map() {
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

				size_type	max_size() const {
					return std::numeric_limits<size_type>::max() / sizeof(difference_type); }

				bool		empty() const { return (size() == 0); }

				/* ELEMENT ACCES */

				mapped_type	&operator[](const key_type &k) {
					return ;
				}

				/* UTILS */

				key_compare		key_comp() const {}
				value_compare	value_comp() const {}
				size_type		count(const key_type &k) const {}
				iterator		find(const key_type &k) {}
				const_iterator	find(const key_type &k) const {}
				iterator		lower_bound(const key_type &k) {}
				const_iterator	lower_bound(const key_type &k) const {}
				iterator		upper_bound(const key_type &k) {}
				const_iterator	upper_bound(const key_type &k) const {}

				pair<const_iterator,
					const_iterator>	equal_range(const key_type &k) const {}

				pair<iterator, iterator>	equal_range(const key_type &k) {}

				/* MODIFIERS */

				//INSERT

				//single element (1)
				pair<iterator, bool>	insert(const value_type& val) {
//					insert(pos, 1, val);
//					return pos;
				}

				//with hint (2)
				iterator	insert(iterator pos, size_type n,
								const value_type& val) {
				}

				//range (3)
				template <class InputIterator>
					void	insert(InputIterator first, InputIterator last) {
					}

				void	erase(iterator pos) {
				}

				size_type	erase(const key_type &k) {
				}

				void	erase(iterator first, iterator last) {
				}

				void		swap(map<Key, T, Compare, Alloc> &x) {
				}

				void		clear() {
				}

//				friend typename iterator::difference_type operator-(const_iterator &lhs, const_iterator &rhs) {;;;
//					return lhs - rhs;
//				}
		};

	template<class Key, class T, class Compare, class Alloc>
		bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs)
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

	template<class Key, class T, class Compare, class Alloc>
		bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (!(lhs == rhs));
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator<(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
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

	template<class Key, class T, class Compare, class Alloc>
		bool	operator<=(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (!(rhs < lhs));
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator>(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (rhs < lhs);
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (!(lhs < rhs));
		}

	template<class Key, class T, class Compare, class Alloc>
		void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
			x.swap(y);
		}

}

#endif
