#ifndef LESS_HPP
#define LESS_HPP

#include <functional>

namespace ft {

template< class T >
struct less : std::binary_function<T,T,bool> // ft::binary_function<T,T,bool>
{
    public:
        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;

        result_type operator() (const T& x, const T& y) const {
            return x<y;
        };
};
}

#endif