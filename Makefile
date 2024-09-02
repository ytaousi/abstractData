STACK = stack
VECTOR = vector
LIST = list
DEQUE = deque
PRIORITY_QUEUE = priority_queue

SRCS_STACK = ./stack.cpp
SRCS_VECTOR = ./vector.cpp
SRCS_LIST = ./list.cpp
SRCS_DEQUE = ./deque.cpp
SRCS_PRIORITY_QUEUE = ./priority_queue.cpp



FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS_STACK:.cpp=.o)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

all: $(STACK)

$(STACK): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(STACK)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(STACK)

re: fclean all