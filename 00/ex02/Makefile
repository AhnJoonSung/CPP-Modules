CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = .

SRC = Account.cpp tests.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = account

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $^ -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
