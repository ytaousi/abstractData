#include "includes/iterator/iterator.hpp"
#include "includes/iterator/iterator_traits.hpp"
#include "includes/sequence_containers/vector.hpp"
#include <vector>


int main()
{
    ft::vector<int> v(9, 150);
    std::reverse_iterator<ft::vector<int>::iterator> it = v.rbegin();
    std::cout << "v.rbegin() = " << *it << std::endl;
    return (0);
}