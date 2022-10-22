CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

CC = c++

NAME = container

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(OBJ:%.o=%.d)

all: $(NAME)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

-include $(DEP)

clean:
	rm -f $(OBJ)
	rm -f $(DEP)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

annihilation:
	make run -C ./annihilation

.PHONY: clean fclean all re .cpp.o annihilation
