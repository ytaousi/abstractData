#ifndef BINARY_FUNCTION_HPP
#define BINARY_FUNCTION_HPP

namespace ft {

// Derived classes can be used as binary function objects. And they are responsible of Defining the operator() function.
// the binary_function class is a base class for binary function objects and defines the types first_argument_type, second_argument_type and result_type Only.
template<class Arg1, class Arg2, class Result>
struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;

    result_type operator() (const Arg1& x, const Arg2& y) const {};
};
}
#endif