#ifndef map_HPP
#define map_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include <map>
//#include "IteratorMap.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <class Key, class T, class Compare, class Alloc> class map;

	template <class T> struct less : std::binary_function <T,T,bool> {
		bool operator() (const T& x, const T& y) const { return x < y; }
	};

	template <	class Key,
				class T,
				class Compare = std::less<Key>,
				class Alloc = std::allocator<pair<const Key, T> > >
		class map {

			private:
				struct Node;

			public:
				/* TYPES */
				typedef Key																key_type;
				typedef T																mapped_type;
				typedef ft::pair<const key_type, mapped_type>							value_type;
				typedef Compare															key_compare;
				typedef std::less<key_type>												value_compare;
				typedef Alloc															allocator_type;
				typedef typename allocator_type::reference								reference;
				typedef typename allocator_type::const_reference						const_reference;
				typedef typename allocator_type::pointer								pointer;
				typedef typename allocator_type::const_pointer							const_pointer;
//				typedef ft::IteratorMap<std::bidirectional_iterator_tag, Node>			iterator;
//				typedef ft::IteratorMap<std::bidirectional_iterator_tag, Node>			const_iterator;
//				typedef ft::IteratorMap<std::bidirectional_iterator_tag, const Node>	const_iterator;
//				typedef std::reverse_iterator<iterator>									reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>							const_reverse_iterator;
//				typedef std::ptrdiff_t													difference_type;
				typedef std::size_t														size_type;

			private:
				struct Node {
					value_type		_pair;
					Node			*parent;
					Node			*left;
					Node			*right;
					int				height;
				};

//****************************************************************************//
//*                            MAP ITERATOR                                  *//
//****************************************************************************//

	template <	class Category,
				class U,
				class Distance = std::ptrdiff_t,
				class Pointer = U*,
				class Reference = U& >
		class	IteratorMap {
			public:
				typedef U			value_type;
				typedef Pointer		pointer;
				typedef Reference	reference;
				typedef Distance	difference_type;
				typedef Category	IteratorMap_category;

			protected:
				Node	*_pos;

			public:
				explicit IteratorMap() : _pos(NULL) {}

				explicit IteratorMap(pointer it) : _pos(it) {

//					if (it)
//						std::cout << it->_pair.first << '\n';
				}

				template <class V>
					explicit IteratorMap(const IteratorMap<Category, V> &it) {
						*this = it;
					}

				template <class V>
					IteratorMap	&operator=(const IteratorMap<Category, V> &it) {
						_pos = it.base();
						return *this;
					}

				~IteratorMap() {}

				pointer	base() {
					return _pos;
				}

				const pointer	base() const {
					return _pos;
				}

				reference	operator*() const { return _pos->_pair; }
				pointer		operator->() const { return &(_pos->_pair); }

				IteratorMap	operator-=(int n) {
					for (int i = 0; i < n; i++, _pos--)
						*this = _pos->left;
					return *this;
				}

				IteratorMap	operator+=(int n) {
					for (int i = 0; i < n; i++)
						*this = _pos->right;
					return *this;
				}

				IteratorMap	operator++(int) {
					IteratorMap	tmp(*this);

					if (_pos->right) {
						*this = _pos->right;
						if (_pos->left) {
							*this = _pos->left;
							if (_pos->left && _pos->left->_pair.first > tmp->_pair.first)
								*this = _pos->left;
						}
					} else if (_pos->parent && _pos->parent->_pair.first > _pos->_pair.first) {
						if (_pos->parent->_pair.first > _pos->_pair.first)
							*this = _pos->parent;
					} else if (_pos->right) {
						*this = _pos->right;
						while (_pos->left)
							*this = _pos->left;
					} else {
						if (_pos->parent) {
							if (_pos->parent->_pair.first < _pos->_pair.first) {
								while (_pos->parent && _pos->_pair.first > _pos->parent->_pair.first)
									*this = _pos->parent;
								*this = _pos->parent;
							}
							else if (_pos->right)
								*this = _pos->right;
						} else {
							if (_pos->right)
								*this = _pos->right;
						}
					}
					return tmp;
				}

				IteratorMap	&operator++() {
					IteratorMap	tmp(*this);

					if (_pos->right) {
						*this = _pos->right;
						if (_pos->left) {
							*this = _pos->left;
							if (_pos->left && _pos->left->_pair.first > tmp->_pair.first)
								*this = _pos->left;
						}
					} else if (_pos->parent && _pos->parent->_pair.first > _pos->_pair.first) {
						if (_pos->parent->_pair.first > _pos->_pair.first)
							*this = _pos->parent;
					} else if (_pos->right) {
						*this = _pos->right;
						while (_pos->left)
							*this = _pos->left;
					} else {
						if (_pos->parent) {
							if (_pos->parent->_pair.first < _pos->_pair.first) {
								while (_pos->parent && _pos->_pair.first > _pos->parent->_pair.first)
									*this = _pos->parent;
								*this = _pos->parent;
							}
							else if (_pos->right)
								*this = _pos->right;
						} else {
							if (_pos->right)
								*this = _pos->right;
						}
					}
					return *this;
				}

				IteratorMap	operator--(int) {
					IteratorMap	tmp(*this);

					if (_pos->left) {
						*this = _pos->left;
						if (_pos->right) {
							*this = _pos->right;
							if (_pos->right && _pos->right->_pair.first > tmp->_pair.first)
								*this = _pos->right;
						}
					} else if (_pos->parent && _pos->parent->_pair.first < _pos->_pair.first) {
						if (_pos->parent->_pair.first < _pos->_pair.first)
							*this = _pos->parent;
					} else if (_pos->left) {
						*this = _pos->left;
						while (_pos->right)
							*this = _pos->right;
					} else {
						if (_pos->parent) {
							if (_pos->parent->_pair.first > _pos->_pair.first) {
								while (_pos->parent && _pos->_pair.first < _pos->parent->_pair.first)
									*this = _pos->parent;
								*this = _pos->parent;
							}
							else if (_pos->left)
								*this = _pos->left;
						} else {
							if (_pos->left)
								*this = _pos->left;
						}
					}
					return tmp;
				}

				IteratorMap	&operator--() {
					IteratorMap	tmp(*this);

					if (_pos->left) {
						*this = _pos->left;
						if (_pos->right) {
							*this = _pos->right;
							if (_pos->right && _pos->right->_pair.first > tmp->_pair.first)
								*this = _pos->right;
						}
					} else if (_pos->parent && _pos->parent->_pair.first < _pos->_pair.first) {
						if (_pos->parent->_pair.first < _pos->_pair.first)
							*this = _pos->parent;
					} else if (_pos->left) {
						*this = _pos->left;
						while (_pos->right)
							*this = _pos->right;
					} else {
						if (_pos->parent) {
							if (_pos->parent->_pair.first > _pos->_pair.first) {
								while (_pos->parent && _pos->_pair.first < _pos->parent->_pair.first)
									*this = _pos->parent;
								*this = _pos->parent;
							}
							else if (_pos->left)
								*this = _pos->left;
						} else {
							if (_pos->left)
								*this = _pos->left;
						}
					}
					return *this;
				}

				difference_type	operator+(const IteratorMap &it) const {
					return base() + it.base();
				}

				IteratorMap	operator+(difference_type v) const {
					return IteratorMap(_pos + v);
				}

				IteratorMap	operator+(int n) {
					return IteratorMap(base() + n);
				}

//				difference_type	operator-(const IteratorMap &it) const {
//					return base() - it.base();
//				}

//				IteratorMap	operator-(difference_type v) const {
//					return IteratorMap(_pos - v);
//				}

				IteratorMap	operator-(int n) {
					return IteratorMap(_pos - n);
				}

				reference	operator[](difference_type v) const {
					return *(_pos + v);
				}

				template <class IteratorMap>
					friend bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs);
				template <class IteratorMap>
					friend bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs);
		};

	/*
	template <class IteratorMap>
		bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class IteratorMap>
		bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class IteratorMap>
		bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class IteratorMap>
		bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos >= rhs._pos;
		}

	template <class IteratorMap>
		bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos < rhs._pos;
		}

	template <class IteratorMap>
		bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos > rhs._pos;
		}

	template <class Category, class T>
		IteratorMap<Category, T> operator+(std::ptrdiff_t v, IteratorMap<Category, T> &it) {
			return IteratorMap<Category, T>(it.base() + v);
		}

	template <class Category, class T>
		typename IteratorMap<Category, T>::difference_type operator+(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, T> &rhs) {
			return lhs.base() + rhs.base();
		}

	template <class Category, class T>
		typename IteratorMap<Category, T>::difference_type operator-(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, T> &rhs) {
			return lhs.base() - rhs.base();
		}

	template <class Category, class T, class U>
		typename IteratorMap<Category, T>::difference_type operator+(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, U> &rhs) {
			return lhs.base() + rhs.base();
		}

	template <class Category, class T, class U>
		typename IteratorMap<Category, T>::difference_type operator-(const IteratorMap<Category, T> &lhs, const IteratorMap<Category, U> &rhs) {
			return lhs.base() - rhs.base();
		}
	*/

			public:
				typedef IteratorMap<std::bidirectional_iterator_tag, value_type>		iterator;
				typedef IteratorMap<std::bidirectional_iterator_tag, value_type>		const_iterator;
				typedef typename iterator_traits<iterator>::difference_type				difference_type;


//****************************************************************************//
//*                            MAP IMPLEMENTATION                            *//
//****************************************************************************//

			public:
				/* CONSTRUCT/COPY/DESTROY */

				map	&operator=(const map<Key, T, Compare, Alloc> &map) {
					if (this != &map) {
						_alloc = map.get_allocator();
//						_comp;
						_size = map.size();
						for (iterator it = map.begin(); it != map.end(); it++)
							this->insert(it);
					}
					return *this;
				}

				//empty (1)
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _comp(comp), _size(0), _root(NULL) {}

				//fill (2)
				template <class InputIterator>
					map(InputIterator first, InputIterator last,
							const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _comp(comp), _size(0), _root(NULL) {

						std::cout << "Iterator Constructor\n";
						while (first != last) {
							insert(first->_pair);
							++first;
						}
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

				void	printTree() {
					std::cout << "PRINT TREE!!! \n";
					preOrder(_root);
				}

				/* ITERATORS */
				iterator				begin() { return iterator(min(_root)); }
				const_iterator			begin() const { return const_iterator(min(_root)); }
				iterator				end() { return iterator(max(_root)); }
				const_iterator			end() const { return const_iterator(max(_root)); }
//				reverse_iterator		rbegin() { return reverse_iterator(max(_root)); }
//				const_reverse_iterator	rbegin() const { return const_reverse_iterator(max(_root)); }
//				reverse_iterator		rend() { return reverse_iterator(min(_root)); }
//				const_reverse_iterator	rend() const { return const_reverse_iterator(min(_root)); }

				/* CAPACITY */
				size_type	size() const { return _size; }

				size_type	max_size() const { return _alloc.max_size(); }

				bool		empty() const { return (size() == 0); }

				/* ELEMENT ACCES */

				mapped_type	&operator[](const key_type &k) {
					Node	*tmp = search(k);

					return tmp->_pair.second;
				}

				/* UTILS */

				key_compare		key_comp() const {
					return key_compare();
				}

				value_compare	value_comp() const {
					return value_compare();
				}

				size_type		count(const key_type &k) const {
//					return (search(k) != NULL);
					if (search(k))
						return 1;
					return 0;
				}

				iterator		find(const key_type &k) {
					return iterator(search(k));
				}

				const_iterator	find(const key_type &k) const {
					return const_iterator(search(k));
				}

				iterator		lower_bound(const key_type &k) {
					return (iterator(find(k)));
				}

				const_iterator	lower_bound(const key_type &k) const {
					return (const_iterator(find(k)));
				}

				iterator		upper_bound(const key_type &k) {
					iterator	it(find(k));

					if (it != end())
						++it;
					return it;
				}

				const_iterator	upper_bound(const key_type &k) const {
					const_iterator	it(find(k));

					if (it != end())
						++it;
					return it;

				}

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

//					std::cout << "INSERTING = " << val.first << '\n';
					_root = insert(_root, make_pair(val.first, val.second));

					++_size;
//					printTree();
					return ft::make_pair<iterator, bool>(find(val.first), true);
				}

				//with hint (2)
				iterator	insert(iterator pos, const value_type& val) {
					insert(val);
					return pos;
				}

				//range (3)
				template <class InputIterator>
					void	insert(InputIterator first, InputIterator last) {
						while (first != last) {
							insert(first->_pair);
							++first;
						}
					}

				void	erase(iterator pos) {
					deleteNode(pos.base(), pos->_pair);
				}

				size_type	erase(const key_type &k) {
					Node	*node = search(k);

//					std::cout << "ERASE " << k << '\n';
					if (deleteNode(node, node->_pair))
						return 1;
					return 0;
				}

				void	erase(iterator first, iterator last) {
					while (first != last) {
						deleteNode(first, first->_pair->first);
						++first;
					}
				}

				void		swap(map<Key, T, Compare, Alloc> &x) {
					(void)x;
				}

				void		clear() {
					destroyTree();
				}

//****************************************************************************//
//*                              AVL TREE                                    *//
//****************************************************************************//

			private:
				int	height(Node *node) {
					if (!node)
						return 0;
					return node->height;
				}

				int	max(int a, int b) {
					return (a > b) ? a : b;
				}

				void	destroyTree() {
					destroyTree(_root);
				}

				Node	*newNode(value_type pair) {
					Node	*node = _alloc_node.allocate(1);

					_alloc.construct(&node->_pair, pair);
					node->parent = NULL;
					node->left = NULL;
					node->right = NULL;
					node->height = 1;

					return (node);
				}

/*
** T1, T2 and T3 are subtrees of the tree,
** rooted with y (on the left side) or x (on the right side)
**
**     y                               x
**    / \     Right Rotation          /  \
**   x   T3   - - - - - - - >        T1   y
**  / \       < - - - - - - -            / \
** T1  T2     Left Rotation            T2  T3
**
*/

				Node	*rightRotate(Node *y) {
					Node	*x = y->left;
					Node	*T2 = x->right;

					x->right = y;
					x->parent = y->parent;
					y->parent = x;
					y->left = T2;

					y->height = max(height(y->left), height(y->right)) + 1;
					x->height = max(height(x->left), height(x->right)) + 1;
					return x;
				}

				Node	*leftRotate(Node *x) {
					Node	*y = x->right;
					Node	*T2 = y->left;

					y->left = x;
					y->parent = x->parent;
					x->parent = y;
					x->right = T2;

					x->height = max(height(x->left), height(x->right)) + 1;
					y->height = max(height(y->left), height(y->right)) + 1;
					return y;
				}

				int	getBalance(Node *node) {
					if (!node)
						return 0;
					return height(node->left) - height(node->right);
				}

				Node	*search(const key_type &k) const {
					return searchRecurs(_root, k);
				}

				Node	*searchRecurs(Node *node, const key_type &k) const {
					if (!node || k == node->_pair.first) {
						return node;
					}
					if (_comp(k, node->_pair.first))
						return searchRecurs(node->left, k);
					return searchRecurs(node->right, k);
				}

				Node	*insert(Node *node, value_type pair) {
					if (!node)
						return (newNode(pair));

					if (pair.first < node->_pair.first) {
						node->left = insert(node->left, pair);
						node->left->parent = node;
					} else if (pair.first > node->_pair.first) {
						node->right = insert(node->right, pair);
						node->right->parent = node;
					} else
						return node;

					node->height = 1 + max(height(node->left), height(node->right));

					int balance = getBalance(node);

					if (balance > 0 && pair.first < node->left->_pair.first)
						return rightRotate(node);

					if (balance < -1 && pair.first > node->right->_pair.first)
						return leftRotate(node);

					if (balance > 1 && pair.first > node->left->_pair.first) {
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}

					if (balance < -1 && pair.first < node->right->_pair.first) {
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}

					return node;
				}

				void	preOrder(Node *root) {
					if (root) {
						std::cout << "First: " << root->_pair.first
							<< " " << root->_pair.second << ", height = " << root->height
							<< " " << "root addr = " << &root << ", parent addr = " << root->parent << '\n';
						preOrder(root->left);
						preOrder(root->right);
					}
				}

				Node	*min(Node *root) {
					if (!root->left)
						return root;
					if (root->left->_pair.first < root->_pair.first)
						return min(root->left);
					return root;
				}

				Node	*max(Node *root) {
					if (!root->right)
						return root;
					if (root->right->_pair.first > root->_pair.first)
						return max(root->right);
					return root;
				}

				Node	*deleteNode(Node *node, const value_type &val) {
					if (!node)
						return node;
					if (val.first < node->_pair.first)
						node->left = deleteNode(node->left, val);
					else if (val.first > node->_pair.first)
						node->right = deleteNode(node->right, val);
					else {
						if (!node->left || !node->right) {
							Node	*tmp;

							tmp = node->left ? node->left : node->right;
							if (!tmp) {
								tmp = node;
								node = NULL;
							} else {

								_alloc_node.destroy(node);
//								node->_pair = make_pair(tmp->_pair.first, tmp->_pair.first);
								_alloc.construct(&node->_pair, tmp->_pair);
								node->parent = tmp->parent;
								node->left = tmp->left;
								node->right = tmp->right;
								node->height = tmp->height;

								_alloc_node.destroy(tmp);
//								_alloc.deallocate(&tmp);
//								free(tmp);
							}
						} else {
							Node	*tmp = min(node->right);

//							_alloc_node.destroy(node);
//							node->_pair = make_pair(tmp->_pair.first, tmp->_pair.first);
							_alloc.construct(&node->_pair, tmp->_pair);
							node->right = deleteNode(node->right, tmp->_pair);
						}
					}
					if (!node)
						return node;

					node->height = 1 + max(height(node->left),
											height(node->right));

					int	balance = getBalance(node);

					if (balance > 1 && getBalance(node->left) >= 0)
						return rightRotate(node);

					if (balance > 1 && getBalance(node->left) < 0) {
						node->left = leftRotate(node->left);
						return rightRotate(node);
					}

					if (balance < -1 && getBalance(node->right) <= 0) {
						return leftRotate(node);
					}

					if (balance < -1 && getBalance(node->right) > 0) {
						node->right = rightRotate(node->right);
						return leftRotate(node);
					}
					return node;
				}

				void	destroyTree(Node *leaf) {
					if (leaf) {
						destroyTree(leaf->left);
						destroyTree(leaf->right);
						_alloc.deallocate(leaf);
					}
				}

				Alloc		_alloc;
				key_compare	_comp;
				size_type	_size;
				Node		*_root;
				typename allocator_type::template rebind<Node>::other	_alloc_node;
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
