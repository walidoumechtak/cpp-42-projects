CXX=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
NAME=Poly

SRC=main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp\

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all