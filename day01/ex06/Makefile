CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=harlFilter

SRC=main.cpp Harl.cpp\

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all