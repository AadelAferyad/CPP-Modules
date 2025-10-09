NAME := megaphone
CP := c++  
FLAGS := -std=c++98 -Wall -Wextra -Werror 
SOURCE := megaphone.cpp
OBJ := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)



