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
				class Compare = ft::less<Key>,
				class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {

			private:
				struct Node;

			public:
				/* TYPES */
				typedef Key											key_type;
				typedef T											mapped_type;
				typedef ft::pair<const key_type, mapped_type>		value_type;
				typedef Compare										key_compare;
				typedef Alloc										allocator_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;
				typedef std::size_t									size_type;

			private:
				struct Node {
					value_type		_pair;
					Node			*parent;
					Node			*left;
					Node			*right;
					int				height;
				};

				class value_compare
				{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
					friend class map;

					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					public:
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;

						bool	operator() (const value_type& x, const value_type& y) const {
								return comp(x.first, y.first);
						}
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

			friend class map<Key, T, Compare, Alloc>;

			public:
				typedef U							value_type;
				typedef Pointer						pointer;
				typedef Reference					reference;
				typedef Distance					difference_type;
				typedef Category					IteratorMap_category;
				typedef typename map::key_compare	key_compare;

			protected:
				Node		*_pos;
				Node		*_p_end;
				key_compare	_comp;

			public:
				explicit IteratorMap() : _pos(NULL) {}

			private:
				IteratorMap(Node *pos, Node *end, key_compare comp)
					: _pos(pos), _p_end(end), _comp(comp) {}


			public:
				template <class V>
					explicit IteratorMap(const IteratorMap<Category, V> &it) {
						*this = it;
					}

				/*
				template <class V>
					IteratorMap	&operator=(const IteratorMap<Category, V> &it) {
						std::cout << "operator = iterator\n";
						_pos = it._pos;
//						_pos->parent = it._pos->parent;
//						_pos->left = it._pos->left;
//						_pos->right = it._pos->right;
//						_pos->height = it._pos->height;
//						this = it.base();
						return *this;
					}
					*/

				~IteratorMap() {}

//				pointer	base() {
//					return _pos;
//				}

//				const pointer	base() const {
//					return _pos;
//				}

				reference	operator*() const { return _pos->_pair; }
				pointer		operator->() const { return &(_pos->_pair); }

				IteratorMap	operator++(int) {
					IteratorMap	tmp(*this);

					if (_pos->right) {
						if (!_pos->right->left || _pos->right == _p_end)
							_pos = _pos->right;
						else
							_pos = ft::map<Key, T, Compare, Alloc>::minValueNode(_pos->right);
					} else if (!_pos->parent) {
						Node	*tmpNode = _pos;
						_pos = _pos->parent;
						while (_comp(tmpNode->_pair.first, _pos->_pair.first) == false)
							_pos = _pos->parent;
					}
					return tmp;
				}

				IteratorMap	&operator++() {
					if (_pos->right) {
						if (!_pos->right->left || _pos->right == _p_end)
							_pos = _pos->right;
						else
							_pos = ft::map<Key, T, Compare, Alloc>::minValueNode(_pos->right);
					} else if (!_pos->parent) {
						Node	*tmpNode = _pos;
						_pos = _pos->parent;
						while (_comp(tmpNode->_pair.first, _pos->_pair.first) == false)
							_pos = _pos->parent;
					}
					return *this;
				}

				IteratorMap	operator--(int) {
					IteratorMap	tmp(*this);

					if (_pos == _p_end) {
						if (_p_end->left != NULL)
							_pos = _p_end->left;
						return tmp;
					} else if (_pos == _p_end->right) {
						_pos = _p_end;
						return tmp;
					}
					if (_pos->left) {
						if (!_pos->left->right)
							_pos = _pos->left;
						else
							_pos = ft::map<Key, T, Compare, Alloc>::maxValueNode(_pos->left);
					} else if (_pos->parent != NULL) {
						Node *tmpNode = _pos;

						_pos = _pos->parent;
						while (_comp(_pos->_pair.first, tmpNode->_pair.first) == false)
							_pos = _pos->parent;
					}
					return tmp;
				}

				IteratorMap	&operator--() {
					if (_pos == _p_end) {
						if (_p_end->left != NULL)
							_pos = _p_end->left;
						return *this;
					} else if (_pos == _p_end->right) {
						_pos = _p_end;
						return *this;
					}
					if (_pos->left) {
						if (!_pos->left->right)
							_pos = _pos->left;
						else
							_pos = ft::map<Key, T, Compare, Alloc>::maxValueNode(_pos->left);
					} else if (_pos->parent != NULL) {
						Node *tmpNode = _pos;

						_pos = _pos->parent;
						while (_comp(_pos->_pair.first, tmpNode->_pair.first) == false)
							_pos = _pos->parent;
					}
					return *this;
				}

				bool	operator==(const IteratorMap &it) const {
					return _pos == it._pos;
				}

				bool	operator!=(const IteratorMap &it) const {
					return _pos != it._pos;
				}
		};

			public:
				typedef IteratorMap<std::bidirectional_iterator_tag, value_type>		iterator;
				typedef IteratorMap<std::bidirectional_iterator_tag, value_type>		const_iterator; // rajouter const
				typedef std::reverse_iterator<iterator>									reverse_iterator;
				typedef std::reverse_iterator<const_iterator>							const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type				difference_type;


//****************************************************************************//
//*                            MAP IMPLEMENTATION                            *//
//****************************************************************************//

			public:
				/* CONSTRUCT/COPY/DESTROY */

				map	&operator=(const map<Key, T, Compare, Alloc> &map) {
					if (this != &map) {
						_alloc = map.get_allocator();
						_comp = map._comp;
						_size = 0;
						_p_end = _alloc_node.allocate(1);
//						_p_end->parent = NULL;
						_p_end->left = NULL;
						_p_end->right = NULL;
						_p_end->height = 0;
						insert(map.begin(), map.end());
					}
					return *this;
				}

				//empty (1)
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _comp(comp), _size(0), _root(NULL) {
						_p_end = _alloc_node.allocate(1);
						_p_end->parent = _root;
						_p_end->left = NULL;
						_p_end->right = NULL;
						_p_end->height = 0;
					}

				//fill (2)
				template <class InputIterator>
					map(InputIterator first, InputIterator last,
							const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _comp(comp), _size(0), _root(NULL) {
						_p_end = _alloc_node.allocate(1);
						_p_end->parent = _root;
						_p_end->left = NULL;
						_p_end->right = NULL;
						_p_end->height = 0;

						insert(first, last);
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
				iterator				begin() {
					return iterator(minValueNode(_root), _p_end, _comp);
				}

				const_iterator			begin() const {
					return const_iterator(minValueNode(_root), _p_end, _comp);
				}

				iterator				end() {
					if (_size == 0)
						return begin();
					return iterator(_p_end, _p_end, _comp);
				}

				const_iterator			end() const {
					if (_size == 0)
						return begin();
					return const_iterator(_p_end, _p_end, _comp);
				}

				reverse_iterator		rbegin() {
					if (_size == 0)
						return begin();
					return reverse_iterator(_p_end, _p_end, _comp);
				}

				const_reverse_iterator	rbegin() const {
					if (_size == 0)
						return begin();
					return const_reverse_iterator(_p_end, _p_end, _comp);
				}

				reverse_iterator		rend() {
					return reverse_iterator(minValueNode(_root, _p_end, _comp));
				}

				const_reverse_iterator	rend() const {
					return const_reverse_iterator(minValueNode(_root, _p_end, _comp));
				}

				/* CAPACITY */
				size_type	size() const { return _size; }

				size_type	max_size() const { return _alloc.max_size(); }

				bool		empty() const { return (_size == 0); }

				/* ELEMENT ACCES */

				mapped_type	&operator[](const key_type &k) {
					Node	*tmp = search(k);

					if (!tmp)
						insert(ft::make_pair(k, mapped_type()));
					tmp = search(k);
					return tmp->_pair.second;
				}

				/* UTILS */

				key_compare		key_comp() const {
					return key_compare();
				}

				value_compare	value_comp() const {
					return value_compare(key_comp());
				}

				size_type		count(const key_type &k) const {
//					return (search(k) != NULL);
					if (search(k))
						return 1;
					return 0;
				}

				iterator		find(const key_type &k) {
					return iterator(search(k), _p_end, _comp);
				}

				const_iterator	find(const key_type &k) const {
					return const_iterator(search(k), _p_end, _comp);
				}

				iterator		lower_bound(const key_type &k) {
					return (iterator(find(k), _p_end, _comp));
				}

				const_iterator	lower_bound(const key_type &k) const {
					return (const_iterator(find(k), _p_end, _comp));
				}

				iterator		upper_bound(const key_type &k) {
					iterator	it(find(k), _p_end, _comp);

					if (it != end())
						++it;
					return it;
				}

				const_iterator	upper_bound(const key_type &k) const {
					const_iterator	it(find(k), _p_end, _comp);

					if (it != end())
						++it;
					return it;

				}

				pair<const_iterator, const_iterator>	equal_range(
						const key_type &k) const {
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}

				pair<iterator, iterator>	equal_range(const key_type &k) {
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}

				/* MODIFIERS */

				//INSERT

				//single element (1)
				pair<iterator, bool>	insert(const value_type& val) {

					++_size;
//					Node	*tmp = max(_root);

//					_p_end->parent = tmp;
					if (!_p_end->parent) {
//						std::cout << _root << '\n';// = _root->right;
						_p_end->parent = _alloc_node.allocate(1);
						_p_end->parent->parent = NULL;
						_p_end->parent->left = NULL;
						_p_end->parent->right = _p_end;
						_p_end->left = _p_end->parent;
						_p_end->right = _p_end->parent;

						_root = insert(_root, ft::make_pair(val.first, val.second));
						return ft::make_pair<iterator, bool>(find(val.first), false);
					}
					Node	*tmp;

					tmp = search(val.first);
					if (!tmp)
						return ft::make_pair<iterator, bool>(find(val.first), false);
					_root = insert(_root, ft::make_pair(val.first, val.second));
//					tmp->right = _p_end;

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
							insert(*first);
							++first;
						}
					}

				void	erase(iterator pos) {
					deleteNode(pos.base(), *pos);
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
						deleteNode(first, *(first->first));
						++first;
					}
				}

				void		swap(map<Key, T, Compare, Alloc> &x) {
					Node	*tmp;

					tmp = _root;
					_root = x._root;
					x._root = tmp;

					size_type	tmp_size;

					tmp_size = _size;
					_size = x._size;
					x._size = tmp_size;

					key_compare	tmp_comp;

					tmp_comp = _comp;
					_comp = x._comp;
					x._comp = tmp_comp;
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
					if (!node || k == node->_pair.first)
						return node;
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

				static Node	*minValueNode(Node *root) {
					if (!root->left)
						return root;
					if (root->left->_pair.first < root->_pair.first)
						return minValueNode(root->left);
					return root;
				}

				static Node	*maxValueNode(Node *root) {
					if (!root->right)
						return root;
					if (root->right->_pair.first > root->_pair.first)
						return maxValueNode(root->right);
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

					if (balance < -1 && getBalance(node->right) <= 0)
						return leftRotate(node);

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
						_alloc_node.deallocate(leaf, 1);
						--_size;
					}
				}

				Alloc		_alloc;
				key_compare	_comp;
				size_type	_size;
				Node		*_root;
				Node		*_p_end;
				typename allocator_type::template rebind<Node>::other	_alloc_node;
		};

	template<class Key, class T, class Compare, class Alloc>
		bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (!(lhs == rhs));
		}

	template<class Key, class T, class Compare, class Alloc>
		bool	operator<(const map<Key, T, Compare, Alloc> &lhs,
							const map<Key, T, Compare, Alloc> &rhs) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.begin()));
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
