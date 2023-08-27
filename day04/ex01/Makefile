CXX=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=brain

SRC=main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp\

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all