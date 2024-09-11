#ifndef VECTOR_HPP
#define VECTOR_HPP

// Done :  , Not Done : 13
#include <memory>
#include "../utility/lexicographical_compare.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>

namespace ft {

template< class T, class Allocator = std::allocator<T> >
class vector
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef Allocator allocator_type;
        typedef ptrdiff_t difference_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef value_type* iterator;  // should implement iterator traits and get to random_access_iterator .
        typedef const value_type* const_iterator; // should implement iterator traits and get to random_access_iterator .
        typedef std::reverse_iterator<iterator> reverse_iterator;   // ft::reverse_iterator<value_type*>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const value_type*>
        typedef typename std::iterator<std::random_access_iterator_tag, value_type> InputIterator;
    protected:
        allocator_type _alloc;
        size_type   _capacity;
        size_type   _size;
        pointer     _array; // T*
    public:
        // Default // Fill // Range // Copy
        vector(){std::cout <<" Default Constructor Called No param " << std::endl;
            this->_capacity = 0;
            this->_size = 0;
            this->_array = this->get_allocator().allocate(this->_capacity);
        };
        explicit vector( const Allocator& alloc ) {
            std::cout << " Default Constructor Called " << std::endl;
            this->_alloc = alloc;
            this->_capacity = 24;
            this->_size = 0;
            this->_array = this->_alloc.allocate(this->_capacity);
        };
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ) {
            std::cout << " Fill Constructor Called " << std::endl;
            this->_alloc = alloc;
            this->_capacity = count;
            this->_size = count;
            this->_array = this->_alloc.allocate(this->_capacity);
            for (size_t i = 0; i < count; i++)
                this->_alloc.construct(this->_array + i, value);
        };
        vector( InputIterator first, InputIterator last, const Allocator& alloc = Allocator() ) {
            std::cout << " Range Constructor Called " << std::endl;
            (void)first;
            (void)last;
            (void)alloc;
        };
        vector( const vector& other ) {
            std::cout << " Copy constructor Called " << std::endl;
            this->_capacity = other._capacity;
            this->_size = other._size;
            this->_array = this->_alloc.allocate(this->_capacity);
            for (size_t i = 0; i < this->_size; i++)
                this->_alloc.construct(this->_array + i, other._array[i]);
        };
        ~vector() { // Done
            std::cout << " Destructor Called " << std::endl;
            for (; this->_size > 0; this->_size--)
                _alloc.destroy(this->_array + (this->_size - 1));
            this->_alloc.deallocate(this->_array, this->_capacity);
            this->_size = 0;
            this->_capacity = 0;
        };
        vector& operator=( const vector& other ){ // should be tested
            std::cout << " Assign operator Called" << std::endl;
            if (this == &other)
                return *this;
            this->clear();
            this->insert(this->begin(), other.begin(), other.end());
            return *this;
        };
        iterator begin() { // Done
            // return an iterator pointing to the first element
            return this->_array;
        };

        const_iterator begin() const { // Done
            return this->_array;
        }
        iterator end() { // Done
            return this->_array + this->_size;
        }
        const_iterator end() const { // Done
            return this->_array + this->_size;
        }
        reverse_iterator rbegin() { // Done
            // return a reverse iterator pointing to the last element in the array
            return reverse_iterator(this->_array + this->_size);
        }
        const_reverse_iterator rbegin() const { // Done
            return const_reverse_iterator(this->_array + this->_size);
        }
        reverse_iterator rend() { // Done
            return reverse_iterator(this->_array - 1);
        }
        const_reverse_iterator rend() const { // Done
            return const_reverse_iterator(this->_array - 1);
        }
        // Range // Fill
        void assign (InputIterator first, InputIterator last){
            std::cout << " Assign Range Called " << std::endl;
            (void)first;
            (void)last;
        };
        void assign (size_type n, const value_type& val){
            std::cout << " Assign Fill Called " << std::endl;
            (void)n;
            (void)val;
        };
        allocator_type get_allocator() const { // Done
            return this->_alloc;
        };
        reference at( size_type pos ){ // Done
            if (pos < 0 || pos >= this->_size)
                throw std::out_of_range("Out of range");
            return this->_array[pos];
        };
        const_reference at( size_type pos ) const { // Done
           if (pos < 0 || pos >= this->_size)
                throw std::out_of_range("Out of range");
            return this->_array[pos];
        };
        reference operator[]( size_type pos ) { // Done
            return this->_array[pos];
        }
        const_reference operator[]( size_type pos ) const { // Done
            return this->_array[pos];
        }
        reference front() { // Done
            // return reference of the first element
            return this->_array[0];
        }
        const_reference front() const { // Done
            return this->_array[0];
        }
        reference back() { // Done
            return this->_array[this->_size - 1];
        }
        const_reference back() const { // Done
            return this->_array[this->_size - 1];
        }
        value_type* data() { // Done
            return this->_array;
        };
        const value_type* data() const { // Done
            return this->_array;
        };
        bool empty() const { // Done
            if (this->_size == 0)
                return true;
            else
                return false;
        }
        size_type size() const { // Done
            return this->_size;
        }
        size_type max_size() const { // Done
            return this->_alloc.max_size();
        }
        void reserve( size_type new_cap ){
            std::cout << " Reserve Called " << std::endl;
            (void)new_cap;
        };
        size_type capacity() const { // Done
            return this->_capacity;
        }
        void shrink_to_fit(){};
        void clear() { // Done
            for (; this->_size > 0; this->_size--)
                _alloc.destroy(this->_array + (this->_size - 1));
        }
        // Single Element // Fill // Range
        iterator insert (iterator position, const_reference val){
            std::cout << " Insert Single Element Called " << std::endl;
            (void)position;
            (void)val;
        };
        void insert (iterator position, size_type n, const_reference val){
            std::cout << " Insert Fill Called " << std::endl;
            (void)position;
            (void)n;
            (void)val;
        };
        void insert (iterator position, InputIterator first, InputIterator last){
            std::cout << " Insert Range Called " << std::endl;
            (void)position;
            (void)first;
            (void)last;
        };
        iterator erase( iterator pos ){
            std::cout << " Erase Called " << std::endl;
            (void)pos;
        };
        iterator erase( iterator first, iterator last ){
            std::cout << " Erase Range Called " << std::endl;
            (void)first;
            (void)last;
        };
        void push_back (const_reference val){
            std::cout << " Push Back Called " << std::endl;

            (void)val;
        };
        void pop_back() { // Done
            this->_alloc.destroy(this->_array + (this->_size - 1));
            this->_size -= 1;
        }
        void resize (size_type n, value_type val = value_type()){
            std::cout << " Resize Called " << std::endl;
            (void)n;
            (void)val;
        };
        void swap( vector& other ){
            std::cout << " Swap Called " << std::endl;
            (void)other;
        };

        friend bool operator== (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
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
        friend bool operator!= (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
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
        friend bool operator<  (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
            return ft::lexicographical_compare<T>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<= (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
            return !(rhs < lhs);
        }
        friend bool operator>  (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
            return (rhs < lhs);
        }
        friend bool operator>= (const ft::vector<T,Allocator>& lhs, const ft::vector<T,Allocator>& rhs) { // Done
            return !(lhs < rhs);
        }
        void swap( ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs ) { // Done
            lhs.swap(rhs);
        }
};

}

#endif