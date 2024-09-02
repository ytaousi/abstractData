#include "includes/stack.hpp"


int main()
{
    ft::stack<int, std::vector<int> > stack_vector;
    ft::stack<int, std::deque<int> > stack_deque;
    ft::stack<int, std::list<int> > stack_list;

    std::cout << "------push() function called" << std::endl;
    
    stack_vector.push(42);
    stack_vector.push(13);
    stack_vector.push(99);
    stack_vector.push(1);
    stack_vector.push(-3);

    stack_deque.push(42);
    stack_deque.push(13);
    stack_deque.push(99);
    stack_deque.push(1);
    stack_deque.push(-3);

    stack_list.push(42);
    stack_list.push(13);
    stack_list.push(99);
    stack_list.push(1);
    stack_list.push(-3);
    
    std::cout << "------End of push() function" << std::endl;






    std::cout << "------size() function Called ------" << std::endl;
    
    std::cout << "size of stack_vector: " << stack_vector.size() << std::endl;
    std::cout << "size of stack_deque: " << stack_deque.size() << std::endl;
    std::cout << "size of stack_list: " << stack_list.size() << std::endl;

    std::cout << "------End of size() function ------" << std::endl;

    std::cout << "------empty() function Called ------" << std::endl;
    
    std::cout << "empty of stack_vector: " << stack_vector.empty() << std::endl;
    std::cout << "empty of stack_deque: " << stack_deque.empty() << std::endl;
    std::cout << "empty of stack_list: " << stack_list.empty() << std::endl;
    
    std::cout << "------End of empty() function" << std::endl;





    // std::cout << "------assignement opperator called------" << std::endl;

    // ft::stack<int> default_stack_deque = stack_deque;
    // ft::stack<int, std::vector<int> > default_stack_vector = stack_vector;
    // ft::stack<int, std::list<int> > default_stack_list = stack_list;
    
    // std::cout << "------End of assignement opperator ------" << std::endl;
    

    // std::cout << "------pop() function Called------" << std::endl;

    // stack_vector.pop();
    // stack_vector.pop();
    // stack_vector.pop();
    // stack_vector.pop();
    // stack_vector.pop();

    // stack_deque.pop();
    // stack_deque.pop();
    // stack_deque.pop();
    // stack_deque.pop();
    // stack_deque.pop();

    // stack_list.pop();
    // stack_list.pop();
    // stack_list.pop();
    // stack_list.pop();
    // stack_list.pop();


    // std::cout << "------End of pop() function------" << std::endl;
    
    
    
    
    
    return (0);
}