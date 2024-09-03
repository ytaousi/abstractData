#ifndef UNARY_FUNCTION_HPP
#define UNARY_FUNCTION_HPP


namespace ft {

template< typename ArgumentType, typename ResultType >
struct unary_function
{
    typedef ArgumentType argument_type;
    typedef ResultType result_type;
    result_type operator() (const argument_type& x) const {};
};
}

#endif