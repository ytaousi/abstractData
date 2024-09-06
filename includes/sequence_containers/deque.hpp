#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "../utility/lexicographical_compare.hpp"
#include "../iterator/iterator.hpp"
#include <memory>
#include <iterator>
#include <cstddef>

namespace ft {

template< class T, class Allocator>
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
        typedef std::iterator<std::random_access_iterator_tag, value_type> iterator; // value_type*
        typedef std::iterator<std::random_access_iterator_tag, const value_type> const_iterator; // const value_type*
        typedef std::reverse_iterator<iterator> reverse_iterator;   //std::reverse_iterator<value_type*>
        typedef std::reverse_iterator<const_iterator> const_reverse_itestdtor; // ft::reverse_iterator<const value_type*>
    protected:
        pointer     _content; //T*
        size_t      _contentSize;
        size_t      _begin;
        size_t      _end;
    public:
        // Desfault // Fill // Range // Copy
        explicit deque (const allocator_type& alloc = allocator_type()) {
            std::cout << "Default constructor" << std::endl;
            (void)alloc;
        }
        explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
            std::cout << "Fill constructor" << std::endl;
            (void)n;
            (void)val;
            (void)alloc;
        }
        deque (std::iterator<std::input_iterator_tag, value_type> first, std::iterator<std::input_iterator_tag, value_type> last, const allocator_type& alloc = allocator_type()) {
            std::cout << "Range Constructor Called" << std::endl;
            (void)first;
            (void)last;
            (void)alloc;
        }
        deque (const deque& x) {
            std::cout << "Copy constructor" << std::endl;
            (void)x;
        }
        ~deque(){};
        // 
        deque& operator=( const deque& other );
        void assign( size_type count, const T& value );
        //     template< class InputIt >
        // void assign( InputIt first, InputIt last );
        allocator_type get_allocator() const;
        reference at( size_type pos );
        const_reference at( size_type pos ) const;
        reference operator[]( size_type pos ) {
            (void)pos;
        };
        const_reference operator[]( size_type pos ) const {
            return *(_content + pos);
        };
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        bool empty() const {
            if (this->size() == 0)
                return true;
            else
                return false;
        }
        size_type size() const {
            return this->_contentSize;
        };
        size_type max_size() const;
        void shrink_to_fit();
        void clear();
        iterator insert( const_iterator pos, const T& value );
        iterator insert( const_iterator pos, size_type count, const T& value );
        iterator insert( const_iterator pos, std::iterator<std::input_iterator_tag, value_type> first, std::iterator<std::input_iterator_tag, value_type> last );
        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        void push_back( const T& value );
        void pop_back();
        void push_front( const T& value );
        void pop_front();
        void resize( size_type count );
        void resize( size_type count, const value_type& value );
        void swap( deque& other ) {
            (void)other;
        }


        // Non-member function overloads
        friend bool operator== (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            if (lhs.size() != rhs.size())
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
        friend bool operator!= (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            return !(lhs == rhs);
        }
        friend bool operator<  (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<= (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            return !(rhs < lhs);
        }
        friend bool operator>  (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            return rhs < lhs;
        }
        friend bool operator>= (const ft::deque<T,Allocator>& lhs, const ft::deque<T,Allocator>& rhs) {
            return	!(lhs < rhs);
        }
        friend void swap( ft::deque<T, Allocator>& lhs, ft::deque<T, Allocator>& rhs ) {
        lhs.swap(rhs);
    }

};
}

#endif