STACK = stack
VECTOR = vector
LIST = list
DEQUE = deque
PRIORITY_QUEUE = priority_queue
QUEUE = queue

SRCS_STACK = ./stack.cpp
SRCS_VECTOR = ./vector.cpp
SRCS_LIST = ./list.cpp
SRCS_DEQUE = ./deque.cpp
SRCS_PRIORITY_QUEUE = ./priority_queue.cpp
SRCS_QUEUE = ./queue.cpp


FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS_QUEUE:.cpp=.o)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

all: $(QUEUE)

$(QUEUE): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(QUEUE)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(QUEUE)

re: fclean all