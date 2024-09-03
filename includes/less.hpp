#ifndef LESS_HPP
#define LESS_HPP

#include <functional>
#include "binary_function.hpp"
#include "unary_function.hpp"

namespace ft {

template< typename T >
struct less : ft::binary_function<T,T,bool> // ft::binary_function<T,T,bool>
{
    public:
        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;

        result_type operator() (const T& x, const T& y) const {
            return x<y;
        };
};

template< typename T >
struct less_than : ft::unary_function<T,bool>
{
    public:
        typedef T argument_type;
        typedef bool result_type;

        result_type operator() (const argument_type& x) const {
            return x < 0;
        };
};

}

#endif