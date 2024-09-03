#ifndef SET_HPP
#define SET_HPP


#include "less.hpp"
#include "iterator.hpp"
#include "lexicographical_compare.hpp"
#include <iterator>
#include <cstddef>

namespace ft {

template< class Key, class Compare = ft::less<Key>, class Allocator = std::allocator<Key> >
class set
{
    public:
        typedef Key key_type;
        typedef Key value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef std::iterator<std::bidirectional_iterator_tag, value_type> iterator; // ft::iterator<std::bidirectional_iterator_tag, value_type>
        typedef std::iterator<std::bidirectional_iterator_tag, const value_type> const_iterator; // ft::iterator<std::bidirectional_iterator_tag, const value_type>
        typedef std::reverse_iterator<iterator> reverse_iterator; // ft::reverse_iterator<iterator>
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; // ft::reverse_iterator<const_iterator>
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
    protected:
    public:
        // Empty // Range // Copy
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        set (const set& x);
        ~set();
        set& operator=( const set& other );
        allocator_type get_allocator() const;
        // Capacity:
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        // Modifiers:
        void clear();
        std::pair<iterator, bool> insert( const value_type& value );
        iterator insert( iterator pos, const value_type& value );
        void insert( InputIterator first, InputIterator last );
        size_type erase( const Key& key );
        iterator erase( iterator first, iterator last );
        iterator erase( iterator pos );
        void swap( set& other );
        // Observers:
        key_compare key_comp() const;
        value_compare value_comp() const;
        // Operations:
        iterator find (const value_type& val) const;
        size_type count (const value_type& val) const;
        iterator lower_bound (const value_type& val) const;
        iterator upper_bound (const value_type& val) const;
        std::pair<iterator,iterator> equal_range (const value_type& val) const;

        friend bool operator==( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs )
        {
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
        friend bool operator!=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ) {
            return !(lhs == rhs);
        }
        friend bool operator<( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ) {
            return !(rhs < lhs);
        }
        friend bool operator>( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ) {
            return 	(lhs < rhs);
        }
        friend bool operator>=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ) {
            return !(lhs < rhs);
        }

        friend void swap( ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs ) {
            lhs.swap(rhs);
        }
};

}
#endif