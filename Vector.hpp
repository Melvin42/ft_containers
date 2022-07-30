#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
namespace ft {
template <class T, class Allocator = std::allocator<T> >
class Vector {
	public:
	/* TYPES */
	typedef typename Allocator::reference			reference;
	typedef typename Allocator::const_reference		const_reference;
	typedef T*										iterator;
	typedef const T*								const_iterator;
	typedef std::size_t								size_type;
	typedef ptrdiff_t								difference_type;
	typedef T										value_type;
	typedef Allocator								allocator_type;
	typedef typename Allocator::pointer				pointer;
	typedef typename Allocator::const_pointer		const_pointer;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		/* CONSTRUCT/COPY/DESTROY */
						Vector();
						Vector(const Vector<T, Allocator> &vector);
		explicit		Vector(const Allocator & = Allocator());
		explicit		Vector(size_type n, const T &value = T(),
							const Allocator & = Allocator());
		template <class InputIterator>
						Vector(InputIterator first, InputIterator last,
							const Allocator& = Allocator());

						~Vector();

		Vector			&operator=(const Vector<T, Allocator> &vector);
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
		void		resize(size_type sz, T c = T());
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
		void		push_back(const T& x);
		void		pop_back();
		iterator	insert(iterator position, const T& x);
		void		insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
			void	insert(iterator position,
						InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void		swap(Vector<T, Allocator> &);
		void		clear();

		bool operator== (const Vector<T, Allocator>& rhs);
		bool operator!= (const Vector<T, Allocator>& rhs);
		bool operator< (const Vector<T, Allocator>& rhs);
		bool operator<= (const Vector<T, Allocator>& rhs);
		bool operator> (const Vector<T, Allocator>& rhs);
		bool operator>= (const Vector<T, Allocator>& rhs);
	private:
};

}
#endif
