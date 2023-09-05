CXX=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=ex02

SRC= AForm.cpp Bureaucrat.cpp  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp\

OBJ= $(SRC:.cpp=.o)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:fclean all