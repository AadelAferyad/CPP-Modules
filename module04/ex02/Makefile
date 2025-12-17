NAME = animals 
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SOURCE = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp AAnimal.cpp
OBJ = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
