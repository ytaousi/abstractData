#ifndef MULTISET_HPP
#define MULTISET_HPP

//#include "../pair.hpp"
#include "../less.hpp"
#include "../lexicographical_compare.hpp"
#include <memory>
#include <cstddef>

namespace ft {

template< class Key, class Compare = ft::less<Key>, class Allocator = std::allocator<Key> >
class multiset
{
    public:
        typedef Key value_type;
        typedef Key key_type;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef std::iterator<std::bidirectional_iterator_tag, value_type> iterator; // ft::iterator<std::bidirectional_iterator_tag, value_type>
        typedef std::iterator<std::bidirectional_iterator_tag, const value_type> const_iterator; // ft::iterator<std::bidirectional_iterator_tag, const value_type>
        typedef std::reverse_iterator<iterator> reverse_iterator; // ft::reverse_iterator<iterator>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const_iterator>
    protected:
    public:
        // Member Functions
        // Defautl // Range // Copy
        explicit multiset( const Compare& comp, const Allocator& alloc = Allocator() );
        multiset( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
        multiset( const multiset& other );
        ~multiset();
        multiset& operator=( const multiset& other );
        allocator_type get_allocator() const;
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        void clear();
        iterator insert( const value_type& value );
        iterator insert( iterator pos, const value_type& value );
        void insert( InputIt first, InputIt last );
        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        size_type erase( const Key& key );
        void swap( multiset& other );
        size_type count( const Key& key ) const;
        iterator find( const Key& key );
        const_iterator find( const Key& key ) const;
        std::pair<iterator, iterator> equal_range( const Key& key );
        std::pair<const_iterator, const_iterator> equal_range( const Key& key ) const;
        iterator lower_bound( const Key& key );
        const_iterator lower_bound( const Key& key ) const;
        iterator upper_bound( const Key& key );
        const_iterator upper_bound( const Key& key ) const;
        key_compare key_comp() const;
        ft::multiset::value_compare value_comp() const;


        // Non-Member Functions
        friend bool operator==( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {   
            if (lhs.size != rhs.size)
                return false;
            else
            {
                for (size_t i = 0; i < lhs.size(); i++)
                {
                    if (lhs[i] == rhs[i])
                        continue;
                    else
                        return false;
                }
                return true;
            }
        }
        friend bool operator!=( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {
            return !(lhs == rhs);
        }
        friend bool operator<( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<=( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator>( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {
            return !(lhs <= rhs);
        }
        friend bool operator>=( const ft::multiset<Key, Compare, Allocator>& lhs, const ft::multiset<Key, Compare, Allocator>& rhs ) {
            return !(lhs < rhs);
        }
        friend void swap(ft::multiset<Key, Compare, Allocator>& lhs, ft::multiset<Key, Compare, Allocator>& rhs ) { 
            lhs.swap(rhs);
        }
}; 
}
#endif