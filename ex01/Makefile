NAME = RPN

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS =  RPN.hpp

OBJ = main.o RPN.o

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADERS)
	c++ $(CPPFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all