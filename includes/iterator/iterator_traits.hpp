#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


#include <memory>
#include <cstddef>
namespace ft {

template <class Iterator>
class iterator_traits
{
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category; 
};

template <class T>
class iterator_traits<T*>
{
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category; // ft::random_access_iterator_tag ft::bidirectional_iterator_tag ft::forward_iterator_tag ft::input_iterator_tag
};

template <class T>
class iterator_traits<const T*>
{
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef std::random_access_iterator_tag iterator_category; // ft::random_access_iterator_tag ft::bidirectional_iterator_tag ft::forward_iterator_tag ft::input_iterator_tag
};

struct input_iterator_tag {
    
};
struct output_iterator_tag {

};
struct forward_iterator_tag : public input_iterator_tag {
    
};
struct bidirectional_iterator_tag : public forward_iterator_tag {

};
struct random_access_iterator_tag : public bidirectional_iterator_tag {

};



}

#endif