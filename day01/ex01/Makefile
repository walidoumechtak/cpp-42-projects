CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=zombie

all: $(NAME)

SRC= main.cpp zombieHorde.cpp Zombie.cpp  \

OBJ= $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all