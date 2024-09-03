#include "includes/deque.hpp"

int main()
{
    ft::deque<int, std::allocator<int> > defaultConstruct_deque;
    ft::deque<int, std::allocator<char> > fillConstruct_deque(3, 'c');
    ft::deque<int, std::allocator<char> > another_deque(5, 'a');
    ft::deque<int, std::allocator<char> > copyConstruct_deque(another_deque);
    ft::deque<int, std::allocator<int> > assignConstruct_deque = defaultConstruct_deque;


    // if (fillConstruct_deque == another_deque)
    //     std::cout << "Both deques are equal" << std::endl;
    // else
    //     std::cout << "Both deques are not equal" << std::endl;
    // if (fillConstruct_deque != another_deque)
    //     std::cout << "Both deques are not equal" << std::endl;
    // else
    //     std::cout << "Both deques are equal" << std::endl;
    // if (fillConstruct_deque < another_deque)
    //     std::cout << "fillConstruct_deque is less than copyConstruct_deque" << std::endl;
    // else
    //     std::cout << "fillConstruct_deque is not less than copyConstruct_deque" << std::endl;
    // if (fillConstruct_deque > another_deque)
    //     std::cout << "fillConstruct_deque is greater than copyConstruct_deque" << std::endl;
    // else
    //     std::cout << "fillConstruct_deque is not greater than copyConstruct_deque" << std::endl;
    // if (fillConstruct_deque <= another_deque)
    //     std::cout << "fillConstruct_deque is less than or equal to copyConstruct_deque" << std::endl;
    // else
    //     std::cout << "fillConstruct_deque is not less than or equal to copyConstruct_deque" << std::endl;
    // if (fillConstruct_deque >= another_deque)
    //     std::cout << "fillConstruct_deque is greater than or equal to copyConstruct_deque" << std::endl;
    // else
    //     std::cout << "fillConstruct_deque is not greater than or equal to copyConstruct_deque" << std::endl;

    
    std::cout << "fillConstruct_deque Size() : " << std::endl;
    std::cout << "copyConstruct_deque Size() : " << std::endl;

    if (fillConstruct_deque.empty())
        std::cout << "fillConstruct_deque is empty" << std::endl;
    else
        std::cout << "fillConstruct_deque is not empty" << std::endl;
    return (0);


}