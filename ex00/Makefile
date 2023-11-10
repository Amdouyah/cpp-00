NAME = megaphone

CC = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)