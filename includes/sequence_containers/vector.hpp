#ifndef VECTOR_HPP
#define VECTOR_HPP

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
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef T* pointer; // check this
        typedef const T* const_pointer; // check this
        typedef value_type* iterator;  // should implement iterator traits and get to random_access_iterator .
        typedef const value_type* const_iterator; // should implement iterator traits and get to random_access_iterator .
        typedef std::reverse_iterator<iterator> reverse_iterator;   // ft::reverse_iterator<value_type*>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const value_type*>
        typedef typename std::iterator<std::random_access_iterator_tag, value_type> InputIterator;
        typedef iterator  begin();
        typedef iterator  end();
    protected:
        allocator_type _alloc;
        size_type   _capacity;
        size_type   _size;
        pointer     _array; // T*
    public:
        // Default // Fill // Range // Copy
        vector(){std::cout <<" Default Constructor Called No param " << std::endl;
            this->_capacity = 24;
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
            (void)other;
        };
        ~vector() { // Done
            std::cout << " Destructor Called " << std::endl;
            this->clear();
            this->_alloc.deallocate(this->_array, this->_capacity);
            this->_size = 0;
            this->_capacity = 0;
        };
        vector& operator=( const vector& other ){
            std::cout << " Assign operator Called" << std::endl;
            (void)other;
            return NULL;
        };
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
        reference at( size_type pos ){
            std::cout << " At Called " << std::endl;
            (void)pos;
            return NULL;
        };
        const_reference at( size_type pos ) const{
            std::cout << "const At Called " << std::endl;
            (void)pos;
            return NULL;
        };
        reference operator[]( size_type pos ) { // Done
            return this->_array[pos];
        }
        const_reference operator[]( size_type pos ) const { // Done
            return this->_array[pos];
        }
        reference front() { // Done
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
        value_type* data(){
            return NULL;
        };
        const value_type* data() const {
            return NULL;
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