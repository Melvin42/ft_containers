#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {

	template <class Iterator>
		class iterator_traits {
		};

	template <class T>
		class iterator_traits<T*> {
			public:
				typedef ptrdiff_t						difference_type;
				typedef T								value_type;
				typedef T&								reference;
				typedef T*								pointer;
				typedef std::random_access_iterator_tag	iterator_category;
		};

	template <class T>
		class iterator_traits<const T*> {
			public:
				typedef ptrdiff_t						difference_type;
				typedef T								value_type;
				typedef const T&						reference;
				typedef const T*						pointer;
				typedef std::random_access_iterator_tag	iterator_category;
		};


	/*
	template <class T>
		struct	iterator_traits {
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::random_access_iterator_tag	iterator_category;
		};
	*/
};

namespace ft {
	template <	class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&>
		struct iterator {
			typedef T										value_type;
			typedef Distance								difference_type;
			typedef Pointer									pointer;
			typedef Reference								reference;
			typedef Category								iterator_category;
		};
}

#endif
