NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -O2
SOURCE = main.cpp PmergeMe.cpp
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
