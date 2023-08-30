CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=Interface

SRC= AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp \

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all