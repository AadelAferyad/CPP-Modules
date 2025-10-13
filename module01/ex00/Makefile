NAME := zombie
CXX:= c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror
SOURCE := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
