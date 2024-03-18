NAME		= program
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -g -std=c++98
SOURCE		= Base.cpp C.cpp B.cpp A.cpp main.cpp 
OBJS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re