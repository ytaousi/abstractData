#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include "lexicographical_compare.hpp"

// Unary , Binary , Compare Objects and iterator , InputIterator
namespace ft {

template< class T, class Allocator = std::allocator<T> >
class list
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef Allocator allocator_type;
        typedef ptrddiff_t difference_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef T* pointer; // check this
        typedef const T* const_pointer; // check this
        typedef value_type* iterator;
        typedef const value_type* const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;   // ft::reverse_iterator<value_type*>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const value_type*>
    public:
        explicit list( const Allocator& alloc );
        explicit list( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );
        list( const list& other );
        ~list();
        list& operator=( const list& other );
        void assign( size_type count, const T& value );
        void assign( InputIterator first, InputIterator last );
        allocator_type get_allocator() const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void clear();
        iterator insert( const_iterator pos, const T& value );
        iterator insert( const_iterator pos, size_type count, const T& value );
        iterator insert( const_iterator pos, InputIt first, InputIt last );
        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        void push_back( const T& value );
        void pop_back();
        void push_front( const T& value );
        void pop_front();
        void resize( size_type count );
        void resize( size_type count, const value_type& value );
        void swap( list& other );
        void merge( list& other );
        void merge( list& other, Compare comp );
        void splice( const_iterator pos, list& other );
        void splice( const_iterator pos, list& other, const_iterator it );
        void splice( const_iterator pos, list& other, const_iterator first, const_iterator last);
        void remove( const T& value ) {
            ;
        }
        void remove_if( UnaryPredicate p ) {
            for (iterator it = begin(); it != end(); it++)
            {
                if (p(*it) == true)
                    erase(it);
            }
        }
        void reverse();
        void unique();
        void unique( BinaryPredicate p ) {
            for (iterator it = begin() + 1; it != end(); it++)
            {
                if (p(*it, *(it + 1)) == true)
                    erase(it);
            }
        }
        void sort();
        void sort( Compare comp );

        friend bool operator==( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs )
        {
            if (lhs.size() != rhs.size())
                return false;
            else
            {
                ;
            }
        }
        friend bool operator!=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
            return !( lhs == rhs);
        }
        friend bool operator<( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
            return !(rhs < lhs);
        }
        friend bool operator>( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
            return 	(rhs < lhs);
        }
        friend bool operator>=( const ft::list<T, Alloc>& lhs, const ft::list<T, Alloc>& rhs ) {
            return 	!(lhs < rhs);
        }
        void swap( ft::list<T, Alloc>& lhs, ft::list<T, Alloc>& rhs ) {
            lhs.swap(rhs);
        }
};
}

#endif