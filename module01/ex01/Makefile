NAME := zombie
CC := c++
FLAGS := -std=c++98 -Wall -Werror -Wextra
SOURCE := main.cpp Zombie.cpp zombieHorde.cpp
OBJ := $(SOURCE:.cpp=.o)

all:$(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $^

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
.PHONY: all clean fclean
