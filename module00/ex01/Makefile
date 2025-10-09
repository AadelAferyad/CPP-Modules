NAME := phonebook
CC := c++
FLAGS := -std=c++98 -Wall -Werror -Wextra
SOURCE := main.cpp Contact.cpp
OBJ := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
