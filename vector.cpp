#include "includes/sequence_containers/vector.hpp"
#include <vector>
int main()
{
    ft::vector<int> v(5, 10);
    std::vector<int> vv2(5, 10);
    std::vector<int> vv3(vv2);




    ft::vector<int>::iterator it = v.begin();
    std::cout << "v.begin() = " << *it << std::endl;
    std::cout << std::endl;
    
    


    return (0);
}