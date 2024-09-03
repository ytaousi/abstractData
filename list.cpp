#include "includes/list.hpp"

int main()
{
    ft::list<int, std::allocator<int> > list1(int);
    ft::list<int> list2(5, 6, std::allocator<int>());
    ft::list<int> list3(list2);
    return (0);
}