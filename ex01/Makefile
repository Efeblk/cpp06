NAME		= program
CPP			= c++
CPPFLAGS	= -Wall -Wextra -Werror -g -std=c++98
SOURCE		= Serializer.cpp main.cpp 
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