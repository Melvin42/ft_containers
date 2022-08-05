all: main.cpp
	rm -f ft_exec std_exec
	clang++ -Wall -Wextra -Werror -std=c++98 main.cpp -o ft_exec
std: main.cpp
	clang++ -Wall -Wextra -Werror -D STD -std=c++11 main.cpp -o std_exec
debug: main.cpp
	rm -f debug_exec
	clang++ -Wall -Wextra -Werror -g3 -std=c++98 main.cpp -o debug_exec
