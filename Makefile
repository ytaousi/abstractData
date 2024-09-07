STACK = stack
VECTOR = vector
LIST = list
DEQUE = deque
PRIORITY_QUEUE = priority_queue
QUEUE = queue
ITERATORS = iterator
SET = set

SRCS_STACK = ./stack.cpp
SRCS_VECTOR = ./vector.cpp
SRCS_LIST = ./list.cpp
SRCS_DEQUE = ./deque.cpp
SRCS_PRIORITY_QUEUE = ./priority_queue.cpp
SRCS_QUEUE = ./queue.cpp
SRCS_ITERATOR = ./iterator.cpp
SRCS_SET = ./set.cpp


FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS_SET:.cpp=.o)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

all: $(SET)

$(SET): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(SET)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(SET)

re: fclean all