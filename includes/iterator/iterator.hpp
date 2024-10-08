#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"
#include <memory>
#include <iostream>
#include <cstddef>

namespace ft {
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator
{
    public:
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category; 
};

template <class Iterator>
class reverse_iterator
{
    public:
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;

    protected:
        iterator_type _it;
    public:
        // Default // Initialization // Copy
        reverse_iterator() {
            std::cout << "Default Constructor Called" << std::endl;
            _it = Iterator();
        }
        explicit reverse_iterator (iterator_type it) {
            std::cout << "Initialization Constructor Called" << std::endl;
            _it = it;
        }
        reverse_iterator (const reverse_iterator<Iterator>& rev_it) {
            std::cout << "Copy Constructor Called" << std::endl;
            _it = rev_it.base();
        }
  
        reverse_iterator& operator++() {
            --_it;
            return *this;
        }
        reverse_iterator operator++( int ) {
            reverse_iterator temp = *this;
            ++(*this);
            return temp;
        }
        reverse_iterator& operator--() {
            ++_it;
            return *this;
        }
        reverse_iterator operator--( int ) {
            reverse_iterator temp = *this;
            --(*this);
            return temp;
        }
        reverse_iterator operator+( difference_type n ) const {
            return reverse_iterator(base()- n);
        }
        reverse_iterator operator-( difference_type n ) const {
            return reverse_iterator(base() + n);
        }
        reverse_iterator& operator+=( difference_type n ) {
            this->operator-=(n);
            return *this;
        }
        reverse_iterator& operator-=( difference_type n ) {
            this->operator+=(n);
            return *this;
        }
        iterator_type base() const {
            return (reverse_iterator(_it).base() == _it);
        }
        reference operator*() const {
            Iterator temp = _it;
            return *(--temp);
        }
        pointer operator->() const  {
            return &(operator*());
        }
        reference operator[] (difference_type n) const {
            return base()[-n - 1];
        }

        // Noo-Member functions
        friend bool operator== (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() == rhs.base();
        }  
        friend bool operator!= (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() != rhs.base();
        }  
        friend bool operator<  (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() > rhs.base();
        }  
        friend bool operator<= (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() >= rhs.base();
        }  
        friend bool operator>  (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() < rhs.base();
        }  
        friend bool operator>= (const reverse_iterator<Iterator>& lhs,                   const reverse_iterator<Iterator>& rhs) {
            return lhs.base() <= rhs.base();
        }
        friend difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
            return rhs.base() - lhs.base();
        }
        friend reverse_iterator<Iterator> operator+ (difference_type n, const reverse_iterator<Iterator>& rev_it) {
            return rev_it.operator+(n);
        }
};

template <class Iterator>
class random_access_iterator
{
    public:
    public:
};

template <class Iterator>
class bideractional_iterator
{
    public:
    public:
};

template <class Iterator>
class InputIterator
{
    public:
    public:
};

}

#endif