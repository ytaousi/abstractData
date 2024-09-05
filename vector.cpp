#include "includes/sequence_containers/vector.hpp"
#include <vector>
int main()
{
    ft::vector<int> v(5, 10);
    ft::vector<int> v2(v);
    ft::vector<int> v3(5);
    ft::vector<int> v4 = v3;



    return (0);
}