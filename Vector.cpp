#include "Vector.hpp"

using namespace ft;

/* CONSTRUCT/COPY/DESTROY */
template <class T, class Allocator>
ft::Vector<T, Allocator>::Vector() {
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
//	return ;
}

template <class T, class Allocator>
size_type	Vector<T, Allocator>::max_size() const {
}

template <class T, class Allocator>
void	Vector<T, Allocator>::resize(size_type sz, T c = T()) {
}
template <class T, class Allocator>
size_type	Vector<T, Allocator>::capacity() const {
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
	*this.a = vector.a;
	*this.b = vector.b;
	*this.c = vector.c;
	*this.d = vector.d;
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
