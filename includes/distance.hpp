#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template<class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type do_distance(InputIterator first, InputIterator last, std::input_iterator_tag)
    {
        typename std::iterator_traits<It>::difference_type result = 0;
        while (first != last)
        {
            ++first;
            ++result;
        }
        return result;
    }
 
    template<class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type do_distance(InputIterator first, InputIterator last, ft::random_access_iterator_tag)
    {
        return last - first;
    }
}

#endif