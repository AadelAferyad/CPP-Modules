NAME := banker
CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra
SOURCE := Account.cpp tests.cpp
OBJ := $(SOURCE:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
