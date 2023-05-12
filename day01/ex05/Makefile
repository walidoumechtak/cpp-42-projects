CPP=c++
CPPFLAGS=-wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=HARL

SRC=main.cpp Harl.cpp\

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:flcean all