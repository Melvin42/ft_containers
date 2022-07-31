#include "Vector.hpp"
using namespace ft;


/* CONSTRUCT/COPY/DESTROY */
template <class T, class Allocator>
Vector<T, Allocator>::Vector() : _size(0) {
}

template <class T, class Allocator>
Vector<T, Allocator>::~Vector() {
}

template <class T, class Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator> &vector) {
	*this = vector;
}

/* CAPACITY */
template <class T, class Allocator>
size_type	Vector<T, Allocator>::size() const {
	//faux!!!
	return _size;
}

template <class T, class Allocator>
size_type	Vector<T, Allocator>::max_size() const {
	return std::numeric_limits<T>::max();
}

template <class T, class Allocator>
void	Vector<T, Allocator>::resize(size_type sz) {
}

template <class T, class Allocator>
size_type	Vector<T, Allocator>::capacity() const {
	return _size;

}

template <class T, class Allocator>
bool	Vector<T, Allocator>::empty() const {
	return true;
}

template <class T, class Allocator>
void	Vector<T, Allocator>::reserve(size_type n) {
}

template <class T, class Allocator>
Vector<T, Allocator>	&Vector<T, Allocator>::operator=(const Vector<T, Allocator> &vector) {
	*this._size = vector._size;
}

/* relational Operators */
template <class T, class Allocator>
bool Vector<T, Allocator>::operator== (const Vector<T, Allocator>& rhs) {
	return (*this == rhs);
}

template <class T, class Allocator>
bool Vector<T, Allocator>::operator!= (const Vector<T, Allocator>& rhs) {
	return (*this != rhs);
}

template <class T, class Allocator>
bool Vector<T, Allocator>::operator< (const Vector<T, Allocator>& rhs) {
	return (*this < rhs);
}

template <class T, class Allocator>
bool Vector<T, Allocator>::operator<= (const Vector<T, Allocator>& rhs) {
	return (*this <= rhs);
}

template <class T, class Allocator>
bool Vector<T, Allocator>::operator> (const Vector<T, Allocator>& rhs) {
	return (*this > rhs);
}

template <class T, class Allocator>
bool Vector<T, Allocator>::operator>= (const Vector<T, Allocator>& rhs) {
	return (*this >= rhs);
}
