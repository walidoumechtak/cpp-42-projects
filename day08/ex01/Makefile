NAME = ex01
FILES.c = Span.cpp main.cpp \

FILES.o = ${FILES.c:.cpp=.o}

CXX=c++
SFLAGS  = -std=c++98
DEBUGFLAGS  = -g3
SANFLAG = -fsanitize=address
ERRFLAG = -Wall -Wextra -Werror

CPPFLAGS= $(ERRFLAG) $(SFLAGS)

$(NAME): $(FILES.o)
	$(CXX) $(CPPFLAGS) $(FILES.o) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(FILES.o)

fclean: clean
	rm -f $(NAME)

re: fclean all