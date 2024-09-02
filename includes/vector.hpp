#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {

template< class T, class Allocator = std::allocator<T> >
class vector
{
    public:

    ~vector();
    vector& operator=( const vector& other );
    // Range // Fill
    //     template <class InputIterator>
    // void assign (InputIterator first, InputIterator last);
    void assign (size_type n, const value_type& val);
    allocator_type get_allocator() const;
    reference at( size_type pos );
    const_reference at( size_type pos ) const;
    reference operator[]( size_type pos );
    const_reference operator[]( size_type pos ) const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    value_type* data();
    const value_type* data() const;
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    void reserve( size_type new_cap );
    size_type capacity() const;
    void shrink_to_fit();
    void clear();
    // Single Element // Fill // Range
    iterator insert (iterator position, const_reference val);
    void insert (iterator position, size_type n, const_reference val);
    //     template <class InputIterator>
    // void insert (iterator position, InputIterator first, InputIterator last);
    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );
    void push_back (const_reference val);
    void pop_back();    
    void resize (size_type n, value_type val = value_type());
    void swap( vector& other );

    friend bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
    friend bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
        if (lhs.size() != rhs.size())
            return true;
        else
        {
            for (size_t i = 0; i < lhs.size(); i++)
            {
                if ( lhs[i] == rhs[i] )
                    continue;
                else
                    return true;
            }
            return false;
        }
    }
    friend bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    friend bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    friend bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
    friend bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);
};

}

#endif