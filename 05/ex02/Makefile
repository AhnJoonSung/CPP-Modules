CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
INCLUDE = .

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

-include $(DEPS)

clean :
	rm -f $(OBJS) $(DEPS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
