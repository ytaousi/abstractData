#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "lexicographical_compare.hpp"
#include <memory>

namespace ft {

template< class T, class Allocator = std::allocator<T> >
class deque
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef T* pointer; // check this
        typedef const T* const_pointer; // check this
        typedef value_type* iterator;
        typedef const value_type* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;   // ft::reverse_iterator<value_type*>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const value_type*>
    public:
        // Desfault // Fill // Range // Copy
        explicit deque (const allocator_type& alloc = allocator_type());
        explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
        deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        deque (const deque& x);
        ~deque();
        deque& operator=( const deque& other );
        void assign( size_type count, const T& value );
        //     template< class InputIt >
        // void assign( InputIt first, InputIt last );
        allocator_type get_allocator() const;
        reference at( size_type pos );
        const_reference at( size_type pos ) const;
        reference operator[]( size_type pos );
        const_reference operator[]( size_type pos ) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void shrink_to_fit();
        void clear();
        iterator insert( const_iterator pos, const T& value );
        iterator insert( const_iterator pos, size_type count, const T& value );
        iterator insert( const_iterator pos, InputIterator first, InputIterator last );
        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        void push_back( const T& value );
        void pop_back();
        void push_front( const T& value );
        void pop_front();
        void resize( size_type count );
        void resize( size_type count, const value_type& value );
        void swap( deque& other );


        // Non-member function overloads
        friend bool operator== (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            if (lhs.size != rhs.size)
                return false;
            else
            {
                for (size_t i = 0; i < lhs.size(); i++)
                {
                    if ( lhs[i] == rhs[i] )
                        continue;
                    else
                        return false;
                }
                return true;
            }
        }
        friend bool operator!= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            return !(lhs == rhs);
        }
        friend bool operator<  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            return lexicographical_compare<T>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            return !(rhs < lhs);
        }
        friend bool operator>  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            return rhs < lhs;
        }
        friend bool operator>= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
            return	!(lhs < rhs);
        }
        friend void swap( ft::deque<T, Alloc>& lhs, ft::deque<T, Alloc>& rhs ) {
        lhs.swap(rhs);
    }

};
}

#endif