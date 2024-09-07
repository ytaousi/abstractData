#ifndef MULTIMAP_HPP
#define MULTIMAP_HPP

#include "../utility/pair.hpp"
#include "../utility/binary_function.hpp"

namespace {

template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
class multimap
{
    public:
        typedef T mapped_type;
        typedef Key key_type;
        typedef ft::pair<const Key, T> value_type;
        typedef syze_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef allocator_type::pointer pointer;
        typedef allocator_type::const_pointer const_pointer;
        typedef std::iterator<std::bidirectional_iterator_tag, value_type> iterator; // ft::iterator<std::bidirectional_iterator_tag, value_type>
        typedef std::iterator<std::bidirectional_iterator_tag, const value_type> const_iterator; // ft::iterator<std::bidirectional_iterator_tag, const value_type>
        typedef std::reverse_iterator<iterator> reverse_iterator; // ft::reverse_iterator<iterator>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const_iterator>

    class value_compare : ft::binary_function<value_type, value_type, bool>
    {
        protected:
            Compare comp;
        public:
            value_compare( const Compare& c ) : comp(c) {}
            bool operator()( const value_type& x, const value_type& y ) const
            {
                return comp(x.first, y.first);
            }
    };
    public:
        explicit multimap (const key_compare& comp = key_compare(),                   const allocator_type& alloc = allocator_type());
        multimap (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        multimap (const multimap& x);
        ~multimap();
        multimap& operator= (const multimap& x);

        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();

        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void clear();


        iterator insert( const value_type& value );
        iterator insert( iterator pos, const value_type& value );
        void insert( InputIt first, InputIt last );

        void insert( InputIt first, InputIt last );
        iterator erase( iterator first, iterator last );
        size_type erase( const Key& key );
        void swap( multimap& other );
        size_type count( const Key& key ) const;
        iterator find( const Key& key );
        const_iterator find( const Key& key ) const;
        ft::pair<iterator, iterator> equal_range( const Key& key );
        ft::pair<const_iterator, const_iterator> equal_range( const Key& key ) const;
        iterator lower_bound( const Key& key );
        const_iterator lower_bound( const Key& key ) const;

        iterator upper_bound( const Key& key );
        const_iterator upper_bound( const Key& key ) const;

        key_compare key_comp() const;
        ft::multimap::value_compare value_comp() const;

        friend bool operator==( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );	
        friend bool operator!=( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );
        friend bool operator<( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );
        friend bool operator<=( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );
        friend bool operator>( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );
        friend bool operator>=( const ft::multimap<Key, T, Compare, Allocator>& lhs, const ft::multimap<Key, T, Compare, Allocator>& rhs );
        friend void swap( ft::multimap<Key, T, Compare, Allocator>& lhs, ft::multimap<Key, T, Compare, Allocator>& rhs );

};
}
#endif