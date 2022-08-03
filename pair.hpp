#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct	pair {
		public:
			pair();
			~pair();
			pair(const pair<T1, T2> &pair);

			pair<T1, T2> make_pair(T1 first, T2 second);

		private:
			pair	_pair;
			T1		_first;
			T2		_second;
	};

template <class T1, class T2>
	pair::pair<T1, T2> makepair(T1 first, T2 second) {
		return (pair<T1, T2>(first, second);
	}
}

#endif
