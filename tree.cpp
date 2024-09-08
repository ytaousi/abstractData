#include "includes/iterator/tree.hpp"
#include <map>

int main()
{
    ft::tree<int, int> rbt = ft::tree<int, int>();


    std::cout << rbt.root->key << " : " << rbt.root->value << std::endl;
    ft::tree<int, int>::Node *node = new ft::tree<int, int>::Node(1, 1);
    // ft::tree<int, int>::Node *node1 = new ft::tree<int, int>::Node(2, 5);
    // ft::tree<int, int>::Node *node2 = new ft::tree<int, int>::Node(10, 5);
    // ft::tree<int, int>::Node *node3 = new ft::tree<int, int>::Node(19, 5);



    //rbt.PreorderTraversal(rbt.getRoot());



    return (0);
}