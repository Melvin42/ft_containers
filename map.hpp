#ifndef map_HPP
#define map_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template <	class Key,
				class T,
				class Compare = less<Key>,
				class Alloc = std::allocator<pair<const Key, T> > >
		class map {
			public:
				/* TYPES */
				typedef Key										key_type;
				typedef T										mapped_type;
				typedef pair<const key_type, mapped_type>		value_type;
				typedef Compare									key_compare;
				typedef Alloc									allocator_type;
				typedef std::less<key_type>						value_compare;
				typedef std::size_t								size_type;
				typedef std::ptrdiff_t							difference_type;
				typedef value_type*								pointer;
				typedef const value_type*						const_pointer;
				typedef value_type*								iterator;
				typedef const value_type*						const_iterator;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef std::reverse_iterator<iterator>			reverse_iterator;
				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			private:
				Alloc		_alloc;
				pointer		_p;
				pointer		_p_end;

			public:
				/* CONSTRUCT/COPY/DESTROY */

				map	&operator=(const map<Key, T, Compare, Alloc> &map) {
					(void)map;
					return *this;
				}

				//empty (1)
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type& = allocator_type())
					: _p(NULL), _p_end(NULL) {
						_p = _alloc.allocate(0);
						_p_end = _p;
						if (!comp(0, 0))
							std::cout << "coucou\n";
					}

				//fill (2)
				template <class InputIterator>
					map(InputIterator first, InputIterator last,
							const key_compare &comp = key_compare(),
							const allocator_type& = allocator_type())
							: _p(NULL), _p_end(NULL) {
						size_t	n = 0;

						if (last - first > 0)
							n = last - first;

						_p = _alloc.allocate(n);
						_p_end = _p;
						if (!comp(0, 0) || comp(0, 0))
						std::cout << "Iterator Constructor\n";
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
					mapped_type	ret;

					(void)k;
					return ret;
				}

				/* UTILS */

				key_compare		key_comp() const {
					return key_compare();
				}

				value_compare	value_comp() const {
					return value_compare();
				}

				size_type		count(const key_type &k) const {
					for (const_iterator it = begin(); it != end(); it++) {
						(void)k;
//						if (it.first == k)
//							return 1;
					}
					return 0;
				}

				iterator		find(const key_type &k) {
					iterator	it = begin();

					(void)k;
					while (it != end()) {
//						if (it.first == k)
//							return it;
//						++it;
					}
					return it;
				}

				const_iterator	find(const key_type &k) const {
					const_iterator	it = begin();

					(void)k;
					while (it != end()) {
//						if (it.first == k)
//							return it;
//						++it;
					}
					return it;
				}

				iterator		lower_bound(const key_type &k) {(void)k;}
				const_iterator	lower_bound(const key_type &k) const {(void)k;}
				iterator		upper_bound(const key_type &k) {(void)k;}
				const_iterator	upper_bound(const key_type &k) const {(void)k;}

				pair<const_iterator,
					const_iterator>	equal_range(const key_type &k) const {
						pair<const_iterator, const_iterator>	ret;

						(void)k;
//						for (const_iterator it = begin(); it != end(); it++) {
//						}
						return ret;
					}

				pair<iterator, iterator>	equal_range(const key_type &k) {
					pair<iterator, iterator>	ret;

					(void)k;

					return ret;
				}

				/* MODIFIERS */

				//INSERT

				//single element (1)
				pair<iterator, bool>	insert(const value_type& val) {
					pair<iterator, bool>	ret;

					(void)val;

					return ret;
				}

				//with hint (2)
				iterator	insert(iterator pos, size_type n,
								const value_type& val) {
					(void)n;
					(void)val;

					return pos;
				}

				//range (3)
				template <class InputIterator>
					void	insert(InputIterator first, InputIterator last) {
						(void)first;
						(void)last;
					}

				void	erase(iterator pos) {
					(void)pos;
				}

				size_type	erase(const key_type &k) {
					(void)k;
				}

				void	erase(iterator first, iterator last) {
					(void)first;
					(void)last;
				}

				void		swap(map<Key, T, Compare, Alloc> &x) {
					(void)x;
				}

				void		clear() {
				}

//				friend typename iterator::difference_type operator-(const_iterator &lhs, const_iterator &rhs) {;;;
//					return lhs - rhs;
//				}
		};

	/*
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
	*/

}

#endif
