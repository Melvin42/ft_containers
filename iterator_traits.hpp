#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {
	template <class T>
		struct	iterator_traits {
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::random_access_iterator_tag	iterator_category;
		};
};

#endif
