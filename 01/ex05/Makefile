CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = .

SRC = main.cpp Harl.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = harl

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $^ -o $@

%.o : %.cpp
	$(CPP) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
