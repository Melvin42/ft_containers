#ifndef map_HPP
#define map_HPP

#include <memory>
#include <limits>
#include <cstddef>
#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include <map>
#include "IteratorMap.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <class Key, class T, class Compare, class Alloc> class map;

	template <class Key, class T>
		class Node {
			public:
				typedef Node*	pointer;
				Node() {}
				Node(const Node &node) { *this = node; }

				~Node() {}

				Node	&operator=(const Node &node) {
					_pair = make_pair(node._pair.first, node._pair.second);
//					first = node.first;
//					second = node.second;
					left = node.left;
					right = node.right;
					height = node.height;

					return *this;
				}

//				pair<Key, T>	&operator*() const { return _pair; }
//				pair<Key, T>	&operator->() const { return &_pair; }

				pair<Key, T>	_pair;
//				Key				first;
//				T				second;
				Node			*left;
				Node			*right;
				int				height;
		};

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
				typedef Key																	key_type;
				typedef T																	mapped_type;
				typedef ft::pair<const key_type, mapped_type>								value_type;
				typedef Compare																key_compare;
				typedef std::less<key_type>													value_compare;
				typedef Alloc																allocator_type;
				typedef typename allocator_type::reference									reference;
				typedef typename allocator_type::const_reference							const_reference;
				typedef typename allocator_type::pointer									pointer;
				typedef typename allocator_type::const_pointer								const_pointer;
				typedef ft::IteratorMap<std::bidirectional_iterator_tag, Node<Key, T> >			iterator;
				typedef ft::IteratorMap<std::bidirectional_iterator_tag, const Node<Key, T> >	const_iterator;
				typedef std::reverse_iterator<iterator>										reverse_iterator;
//				typedef std::reverse_iterator<const_iterator>								const_reverse_iterator;
//				typedef std::ptrdiff_t														difference_type;
				typedef typename iterator_traits<iterator>::difference_type					difference_type;
				typedef std::size_t															size_type;

			public:
				/* CONSTRUCT/COPY/DESTROY */

				map	&operator=(const map<Key, T, Compare, Alloc> &map) {
					_alloc = map.get_allocator();
					_size = map.size();
					_tree.setRoot(_alloc_node.allocate(_size));

					return *this;
				}

				//empty (1)
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type())
					: _alloc(alloc), _size(0) {
						_tree.setRoot(_alloc_node.allocate(0));

						if (!comp(0, 0))
							std::cout << "coucou\n";
					}

				//fill (2)
				template <class InputIterator>
					map(InputIterator first, InputIterator last,
							const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type())
							: _alloc(alloc), _size(0) {
						size_t	n = 0;

						if (last - first > 0)
							n = last - first;

						_size = n;
						_tree.setRoot(_alloc_node.allocate(n));
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
				iterator				begin() { return iterator(_tree.getRoot()); }
//				const_iterator			begin() const { return const_iterator(_tree.getRoot()); }
				iterator				end() { return iterator(_tree.getRoot()); }
//				const_iterator			end() const { return const_iterator(_tree.getRoot()); }
//				reverse_iterator		rbegin() { return reverse_iterator(_tree.getRoot()); }
//				const_reverse_iterator	rbegin() const { return const_reverse_iterator(_tree.getRoot()); }
//				reverse_iterator		rend() { return reverse_iterator(_tree.getRoot()); }
//				const_reverse_iterator	rend() const { return const_reverse_iterator(_tree.getRoot()); }

				/* CAPACITY */
				size_type	size() const { return _size; }

				size_type	max_size() const {
//					return std::numeric_limits<size_type>::max() / sizeof(difference_type); }
					return _alloc.max_size(); }

				bool		empty() const { return (size() == 0); }

				/* ELEMENT ACCES */

				mapped_type	&operator[](const key_type &k) {
					mapped_type	ret;

					(void)k;
//					value_type	tmp = _tree.search(k);

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

//					pair<key_type, mapped_type>	tmp;

					_tree.insert(make_pair(val.first, val.second));
//					_tree.insert(ft::make_pair<key_type, mapped_type>(val.first, val.second));
//					return (ft::make_pair<iterator, bool>(iterator(_tree.insert(val)), true));
					pair<iterator, bool>	ret;

					++_size;
					_tree.printTree();
					return ft::make_pair<iterator, bool>(iterator(_tree.getRoot()), true);
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

					return 0;
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
				private:
					class Tree {
						public:
							Tree() : _root(NULL) {}

								Tree(const Tree &tree) { *this = tree; }

								Tree	&operator=(const Tree &tree) {
									_root = tree.getRoot();
									return *this;
								}

							~Tree() { destroyTree(); }

							int	height(Node<Key, T> *node) {
								if (!node)
									return 0;
								return node->height;
							}

							int	max(int a, int b) {
								return (a > b) ? a : b;
							}

							Node<Key, T>	*getRoot() const {
								return _root;
							}

							Node<Key, T>	*getRoot() {
								return _root;
							}

							void	setRoot(Node<Key, T> *node) {
								_root = node;
							}

							void	destroyTree() {
								destroyTree(_root);
							}

							void	insert(value_type pair) {
								_root = insert(_root, pair);
							}

							void	printTree() {
								std::cout << "PRINT TREE!!! \n";
								preOrder(_root);
							}

						private:
							Node<Key, T>	*newNode(value_type pair) {
								Node<Key, T>	*node = new Node<Key, T>();

								node->_pair = make_pair(pair.first, pair.second);
								node->left = NULL;
								node->right = NULL;
								node->height = 1;

								return (node);
							}

							Node<Key, T>	*rightRotate(Node<Key, T> *y) {
								Node<Key, T>	*x = y->left;
								Node<Key, T>	*T2 = x->right;

								x->right = y;
								y->left = T2;

								y->height = max(height(y->left), height(y->right)) + 1;
								x->height = max(height(x->left), height(x->right)) + 1;

								return x;
							}

							Node<Key, T>	*leftRotate(Node<Key, T> *x) {
								Node<Key, T>	*y = x->right;
								Node<Key, T>	*T2 = y->left;

								y->left = x;
								x->right = T2;

								x->height = max(height(x->left), height(x->right)) + 1;
								y->height = max(height(y->left), height(y->right)) + 1;

								return y;
							}

							int	getBalance(Node<Key, T> *node) {
								if (!node)
									return 0;
								return height(node->left) - height(node->right);
							}

							Node<Key, T>	*search(const key_type &k) {
								(void)k;

								Node<Key, T>	*tmp = NULL;

								return tmp;
							}

							Node<Key, T>	*insert(Node<Key, T> *node, value_type pair) {
								if (!node)
									return (newNode(pair));

								if (pair < node->_pair)
									node->left = insert(node->left, pair);
								else if (pair > node->_pair)
									node->right = insert(node->right, pair);
								return node;

								node->height = 1 + max(height(node->left), height(node->right));

								int balance = getBalance(node);

								if (balance > 1 && pair < node->left->_pair)
									return rightRotate(node);

								if (balance < -1 && pair > node->right->_pair)
									return leftRotate(node);

								if (balance > 1 && pair > node->left->_pair) {
									node->left = leftRotate(node->left);
									return rightRotate(node);
								}

								if (balance < -1 && pair < node->right->_pair) {
									node->right = rightRotate(node->right);
									return leftRotate(node);
								}

								return node;
							}

							void	preOrder(Node<Key, T> *root) {
								if (root) {
									std::cout << "First: " << root->_pair.first
										<< " " << root->_pair.second;
									preOrder(root->left);
									preOrder(root->right);
								}
								std::cout << std::endl;
							}

							void	destroyTree(Node<Key, T> *leaf) {
								if (leaf) {
									destroyTree(leaf->left);
									destroyTree(leaf->right);
									delete leaf;
								}
							}

							Node<Key, T>	*_root;
					};
			private:
				Alloc		_alloc;
				size_type	_size;
				typename allocator_type::template rebind<Node<Key, T> >::other	_alloc_node;

				Tree		_tree;


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
