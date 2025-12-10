NAME = FragTrap
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SOURCE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean ra
