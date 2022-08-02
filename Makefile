all: main.cpp
	clang++ -Wall -Wextra -Werror -std=c++98 main.cpp -o ft_exec
std: main.cpp
	clang++ -Wall -Wextra -Werror -D TEST -std=c++98 main.cpp -o std_exec
debug: main.cpp
	clang++ -Wall -Wextra -Werror -g3 -std=c++98 main.cpp -o debug_exec
