#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include <cstddef>

namespace ft {


	template <class T, class Allocator = std::allocator<T> >
			class vector {
				public:
				/* TYPES */
				typedef typename Allocator::reference				reference;
				typedef typename Allocator::const_reference			const_reference;
				typedef T*											iterator;
				typedef const T*									const_iterator;
				typedef T											value_type;
				typedef std::size_t									size_type;
				typedef std::ptrdiff_t								difference_type;
				typedef Allocator									allocator_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer			const_pointer;
				typedef std::reverse_iterator<iterator>				reverse_iterator;
				typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

				/* CONSTRUCT/COPY/DESTROY */
								vector();
								vector(const vector<T, Allocator> &vector);
//				explicit		vector(const Allocator & = Allocator());
//				explicit		vector(size_type n, const T &value = T(),
//									const Allocator & = Allocator());
//				template <class InputIterator>
//								vector(InputIterator first, InputIterator last,
//									const Allocator& = Allocator());

								~vector();

				vector			&operator=(const vector<T, Allocator> &vector);
				template <class InputIterator>
					void		assign(InputIterator first, InputIterator last);
				void			assign(size_type n, const T& u);
				allocator_type	get_allocator() const;


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
				size_type	size() const;
				size_type	max_size() const;
				void		resize(size_type sz);
				size_type	capacity() const;
				bool		empty() const;
				void		reserve(size_type n);

				/* ELEMENT ACCES */
				reference		operator[](size_type n);
				const_reference	operator[](size_type n) const;
				const_reference	at(size_type n) const;
				reference		at(size_type n);
				reference		front();
				const_reference	front() const;
				reference		back();
				const_reference	back() const;

				/* MODIFIERS */
				void		push_back(const value_type& val);
				void		pop_back();
				iterator	insert(iterator position, const T& x);
				void		insert(iterator position, size_type n, const T& x);
				template <class InputIterator>
					void	insert(iterator position,
								InputIterator first, InputIterator last);
				iterator	erase(iterator position);
				iterator	erase(iterator first, iterator last);
				void		swap(vector<T, Allocator> &);
				void		clear();

				bool	operator==(const vector<T, Allocator>& rhs) { return (*this == rhs);}
				bool	operator!=(const vector<T, Allocator>& rhs) { return (*this != rhs);}
				bool	operator<(const vector<T, Allocator>& rhs) { return (*this < rhs);}
				bool	operator<=(const vector<T, Allocator>& rhs) { return (*this <= rhs);}
				bool	operator>(const vector<T, Allocator>& rhs) { return (*this > rhs);}
				bool	operator>=(const vector<T, Allocator>& rhs) { return (*this >= rhs);}
//}

				private:
					Allocator	_alloc;
					size_type	_size;
					size_type	_capacity;
	};

	/* CONSTRUCT/COPY/DESTROY */
	template <class T, class Allocator>
	vector<T, Allocator>::vector() : _size(0), _capacity(0) {
	}

	template <class T, class Allocator>
	vector<T, Allocator>::~vector() {
	}

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator> &vector) {
		*this = vector;
	}

	/* CAPACITY */
	template <class T, class Allocator>
	size_type	vector<T, Allocator>::size() const {
		//faux!!!
		return _size;
	}

	template <class T, class Allocator>
	size_type	vector<T, Allocator>::max_size() const {
		return std::numeric_limits<T>::max();
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::resize(size_type sz) {
	}

	template <class T, class Allocator>
	size_type	vector<T, Allocator>::capacity() const {
		return _size;

	}

	template <class T, class Allocator>
	bool	vector<T, Allocator>::empty() const {
		return true;
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::reserve(size_type n) {
	}

	template <class T, class Allocator>
	vector<T, Allocator>	&vector<T, Allocator>::operator=(const vector<T, Allocator> &vector) {
		*this._size = vector._size;
	}
}

template <class T, class Allocator>
void	push_back(const value_type& val) {
//	value_type*	ret = new value_type(val);
}

template <class T, class Allocator>
void	pop_back() {
}

template <class T, class Allocator>
iterator	insert(iterator position, const T& x) {
}

template <class T, class Allocator>
void	insert(iterator position, size_type n, const T& x) {
}

template <class InputIterator>
void	insert(iterator position,
	InputIterator first, InputIterator last) {
}

template <class T, class Allocator>
iterator	erase(iterator position) {
}

template <class T, class Allocator>
iterator	erase(iterator first, iterator last) {
}

template <class T, class Allocator>
void	swap(vector<T, Allocator> &) {
	T*	tmp;

	for (size_type	i = 0; i < _size; i++) {
		tmp = &;
		this.[i];

	}
}

template <class T, class Allocator>
void	clear() {

}

#endif
