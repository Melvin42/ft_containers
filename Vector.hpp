#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

template <class T, class Alloc = allocator<T>>
class Vector {
	public:
		/* TYPES */
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef implementation defined					iterator;
		typedef implementation defined					const_iterator;
		typedef implementation defined					size_type;
		typedef implementation defined					difference_type;
		typedef T;										value_type;
		typedef Allocator								allocator_type;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		/* CONSTRUCT/COPY/DESTROY */
						Vector();
						Vector(const Vector<T, Allocator> &vector);
		explicit		vector(const Allocator & = Allocator());
		explicit		vector(size_type n, const T &value = T(),
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
		void		swap(vector<T, Allocator> &);
		void		clear();




		/*
		 * ITERATORS
		 * begin();
		 * end();
		 * rbegin()
		 * rend();
		 *
		 * CAPACITY
		 * size();
		 * max_size();
		 * resize();
		 * capacity()
		 * empty();
		 * reserve();
		 *
		 * MODIFIERS
		 * assign();
		 * push_back();
		 * pop_back();
		 * insert();
		 * erase();
		 * swap();
		 * clear();
		 *
		 * ALLOCATOR
		 * get_allocator();
		 *
		 * NON-MEMBER FUNCTION OVERLOADS
		 *
		 * relational operators
		 * ==
		 * !=
		 * <
		 * <=
		 * >
		 * >=
		 *
		 * swap;
		 *
		 * TEMPLATE SPECIALIZATIONS
		 *
		 * vector<bool>
		 */
		bool operator== (const Vector<T, Alloc>& rhs);
		bool operator!= (const Vector<T, Alloc>& rhs);
		bool operator< (const Vector<T, Alloc>& rhs);
		bool operator<= (const Vector<T, Alloc>& rhs);
		bool operator> (const Vector<T, Alloc>& rhs);
		bool operator>= (const Vector<T, Alloc>& rhs);
	private:
};

#endif
