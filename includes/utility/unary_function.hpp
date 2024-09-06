#ifndef UNARY_FUNCTION_HPP
#define UNARY_FUNCTION_HPP


namespace ft {

// Derived classes can be used as unary function objects. And they are responsible of Defining the operator() function.
// the unary_function class is a base class for unary function objects and defines the types argument_type and result_type Only.
template< typename ArgumentType, typename ResultType >
struct unary_function
{
    typedef ArgumentType argument_type;
    typedef ResultType result_type;
    result_type operator() (const argument_type& x) const {};
};
}

#endif