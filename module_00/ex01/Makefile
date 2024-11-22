NAME = graph_test
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -lpng
SRCS = main.cpp Vector2.cpp Graph.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

install_libpng:
	sudo apt-get install libpng-dev

uninstall_libpng:
	sudo apt-get remove libpng-dev

.PHONY: all clean fclean re install_libpng uninstall_libpng
