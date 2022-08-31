#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class T1, class T2>
		class	pair {
			public:
				typedef T1		first_type;
				typedef T2		second_type;
				first_type		first;
				second_type		second;

				//default (1)
				pair() {}

				//copy (2)
				template <class U, class V>
					pair(const pair<U, V> &pr)
					: first(pr.first), second(pr.second) {}

				//initialization (3)
				pair(const first_type &a, const second_type &b)
					: first(a), second(b) {}

				~pair() {}

				pair<T1, T2>	&operator=(const pair<const T1, T2> &pair) {
					first = pair.first;
					second = pair.second;
					return *this;
				}

				/*
				void	swap(pair &pair) noexcept ( noexcept(swap(first, pair.first))
							&& noexcept(swap(second, pair.second)) ) {
					first_type	tmp_first = first;
					first = pair.first;
					pair.first = tmp.first;

					second_type	tmp_second = second;
					second = pair.second;
					pair.second = tmp_second;
				}
				*/
		};

	template <class T1, class T2>
		pair<T1, T2> make_pair(T1 first, T2 second) {
			return (pair<T1, T2>(first, second));
		}
};

#endif
