#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {

	struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	struct output_iterator_tag {};

	template <class Iterator>
		class	iterator_traits {
			typedef std::ptrdiff_t					difference_type;
			typedef Iterator						value_type;
			typedef Iterator&						reference;
			typedef Iterator*						pointer;
			typedef std::random_access_iterator_tag	iterator_category;
		};

	template <class T>
		class iterator_traits<T*> {
			public:
				typedef std::ptrdiff_t					difference_type;
				typedef T								value_type;
				typedef T&								reference;
				typedef T*								pointer;
				typedef std::random_access_iterator_tag	iterator_category;
		};

	template <class T>
		class iterator_traits<const T*> {
			public:
				typedef std::ptrdiff_t					difference_type;
				typedef T								value_type;
				typedef const T&						reference;
				typedef const T*						pointer;
				typedef std::random_access_iterator_tag	iterator_category;
		};
};

#endif
