NAME = RPN
FILES.c = main.cpp RPN.cpp\

FILES.o = ${FILES.c:.cpp=.o}

CXX=c++
SFLAGS  = -std=c++98 -g3
DEBUGFLAGS  = -g3
SANFLAG = -fsanitize=address
ERRFLAG = -Wall -Wextra -Werror

CPPFLAGS= $(ERRFLAG) $(SFLAGS) $(SANFLAG)

$(NAME): $(FILES.o)
	$(CXX) $(CPPFLAGS) $(FILES.o) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(FILES.o)

fclean: clean
	rm -f $(NAME)

re: fclean all