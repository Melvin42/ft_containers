#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP

#include "iterator_traits.hpp"
#include "map.hpp"


namespace ft {
//	template <class Key, class V, class Compare, class Alloc> class map;

	template <	class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T& >
		class	IteratorMap {
			public:
				typedef T			value_type;
				typedef Pointer		pointer;
				typedef Reference	reference;
				typedef Distance	difference_type;
				typedef Category	IteratorMap_category;

			protected:
//				Node	*node;
				pointer	_pos;

			public:
				IteratorMap() : _pos(NULL) {}

				IteratorMap(pointer it) : _pos(it) {

//					if (it)
//						std::cout << it->_pair.first << '\n';
				}

				template <class U>
					IteratorMap(const IteratorMap<Category, U> &it) {
						*this = it;
					}

				template <class U>
					IteratorMap	&operator=(const IteratorMap<Category, U> &it) {
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

				reference	operator*() const { return *_pos; }
				pointer		operator->() const { return _pos; }

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

					std::cout << "Call operator++\n";

					if (_pos->right) {
						*this = _pos->right;
//						if (_pos->left) {
//							std::cout << "inleft = " << _pos->left->_pair.first << '\n';
//						}
//						if (_pos->right) {
//							std::cout << "inright = " << _pos->right->_pair.first << "\n";
//							if (_pos->right->left)
//								std::cout << "inright = " << _pos->right->left->_pair.first << "\n";
//						}
						if (_pos->left) {
							*this = _pos->left;
//							if (_pos->left)
//								std::cout << "inleft = " << _pos->left->_pair.first << '\n';
							if (_pos->left && _pos->left->_pair.first > tmp->_pair.first) {
								*this = _pos->left;
							}
						}
					} else if (_pos->parent && _pos->parent->_pair.first > _pos->_pair.first) {
					std::cout << "Call operator++\n";
						if (_pos->parent->_pair.first > _pos->_pair.first) {
							*this = _pos->parent;
//							if (_pos->left)
//								std::cout << "left = " << _pos->left->_pair.first << '\n';
//							if (_pos->right)
//								std::cout << "right = " << _pos->right->_pair.first << "\n";
//							if (_pos->parent) {
//								std::cout << "parent = " << _pos->parent->_pair.first << '\n';
//								std::cout << "parent left = " << _pos->parent->left->_pair.first << '\n';
//								std::cout << "parent right = " << _pos->parent->right->_pair.first << '\n';
//								std::cout << "parent right = " << _pos->parent->right->left->_pair.first << '\n';
//								std::cout << "parent right = " << _pos->parent->right->right->_pair.first << '\n';
						}
					} else if (_pos->right) {
						std::cout << "TEST\n";
//						if (this->_pos->right->_pair.first
						*this = this->_pos->right;
						while (_pos->left) {
//							std::cout << "TEST2\n";
							std::cout << _pos->left->_pair.first << "\n";
							*this = _pos->left;
						}
					} else {
						std::cout << "le bon else first = " << _pos->_pair.first << '\n';
						if (_pos->parent) {
//							std::cout <<  "Go too parent bordel " << _pos->parent->_pair.first << '\n';
//							std::cout << _pos->_pair.first << '\n';
							if (_pos->parent->_pair.first < _pos->_pair.first) {
								while (_pos->parent && _pos->_pair.first > _pos->parent->_pair.first) {
//									std::cout << "par ici les parents\n";
									*this = _pos->parent;
								}
								*this = _pos->parent;
							}
							else if (_pos->right) {
								std::cout << "right = " << _pos->right->_pair.first << "\n";
								*this = _pos->right;
							}
						} else {
//							std::cout << "No parent go right\n";
							if (_pos->right)
								*this = _pos->right;


//							if (this->_pos->right)
//							{
//								std::cout << "++ tourne a droite\n";
//								*this = _pos->right;
//								if (_pos->left)
//									*this = _pos->left;
//							}
						}
					}
					return tmp;
				}

				IteratorMap	&operator++() {
					std::cout << "Call ++operator\n";
					if (_pos->right)
						*this = _pos->right;
					else
						*this = *(_pos->parent);
					return *this;
				}

				IteratorMap	operator--(int) {
					std::cout << "Call operator--\n";
					IteratorMap	tmp = *this;

					if (_pos->left)
						*this = _pos->left;
					else
						*this = _pos->parent;
					return tmp;
				}

				IteratorMap	&operator--() {
					std::cout << "Call --operator\n";
					if (_pos->left)
						*this = _pos->left;
					else
						*this = _pos->parent;
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
	/*
	template <class Category, class T>
		bool	operator==(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos == rhs._pos;
		}

	template <class Category, class T>
		bool	operator!=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos != rhs._pos;
		}

	template <class Category, class T>
		bool	operator<=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator>=(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos <= rhs._pos;
		}

	template <class Category, class T>
		bool	operator<(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos < rhs._pos;
		}

	template <class Category, class T>
		bool	operator>(const IteratorMap &lhs, const IteratorMap &rhs) {
			return lhs._pos > rhs._pos;
		}

		};
		*/

//	template <class Category, class T>
//		IteratorMap<Category, T> operator-(IteratorMap<Category, T> &lhs, IteratorMap<Category, T> &rhs) {
//			std::cout << "coucou\n";	
//			return IteratorMap<Category, T>(lhs.base() - rhs.base());
//		}

	template <class Category, class T>
		IteratorMap<Category, T> operator+(std::ptrdiff_t v, IteratorMap<Category, T> &it) {
			return IteratorMap<Category, T>(it.base() + v);
		}

//	template <class Category, class T>
//		IteratorMap<Category, T> operator-(std::ptrdiff_t v, IteratorMap<Category, T> &it) {
//			return IteratorMap<Category, T>(it.base() - v);
//		}

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

//	template <class Category, class T>
//		std::ostream	&operator<<(std::ostream &os, const IteratorMap<Category, T> &it) {
//			std::cout << "coucou\n";	
//			std::cout << it.base();
//
//			return os;
//		}
};

#endif
