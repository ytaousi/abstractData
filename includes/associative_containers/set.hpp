#ifndef SET_HPP
#define SET_HPP


#include "../utility/less.hpp"
#include "../iterator/iterator.hpp"
#include "../utility/lexicographical_compare.hpp"
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
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        {
            (void)comp;
            (void)alloc;
        };
        set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        {
            (void)first;
            (void)last;
            (void)comp;
            (void)alloc;
        };
        set (const set& x)
        {
            (void)x;
        };
        ~set() {};
        set& operator=( const set& other )
        {
            (void)other;
            return *this;
        };
        allocator_type get_allocator() const {};
        // Capacity:
        bool empty() const {
            return true;
        };
        size_type size() const {
            return 0;
        };
        size_type max_size() const
        {
            return 0
        };
        // Modifiers:
        void clear() {};
        std::pair<iterator, bool> insert( const value_type& value )
        {
            (void)value;
            return std::pair<iterator, bool>(iterator(), false);
        };
        iterator insert( iterator pos, const value_type& value ) {
            (void)pos;
            (void)value;
            return NULL;
        };
        void insert( InputIterator first, InputIterator last ) {
            (void)first;
            (void)last;
        };
        size_type erase( const Key& key );
        iterator erase( iterator first, iterator last ) {
            (void)first;
            (void)last;
            return NULL;
        };
        iterator erase( iterator pos ) {
            (void)pos;
            return NULL;
        };
        void swap( set& other );
        // Observers:
        key_compare key_comp() const {};
        value_compare value_comp() const {};
        // Operations:
        iterator find (const value_type& val) const {
            (void)val;
            return NULL;
        };
        size_type count (const value_type& val) const {
            (void)val;
            return 0;
        };
        iterator lower_bound (const value_type& val) const {
            (void)val;
            return NULL;
        };
        iterator upper_bound (const value_type& val) const {
            (void)val;
            return NULL;
        }
        std::pair<iterator,iterator> equal_range (const value_type& val) const {
            (void)val;
            return std::pair<iterator,iterator>(iterator(), iterator());
        };

        friend bool operator==( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
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
        friend bool operator!=( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
            return !(lhs == rhs);
        }
        friend bool operator<( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        friend bool operator<=( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
            return !(rhs < lhs);
        }
        friend bool operator>( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
            return 	(lhs < rhs);
        }
        friend bool operator>=( const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs ) {
            return !(lhs < rhs);
        }

        friend void swap( ft::set<Key, Compare, Allocator>& lhs, ft::set<Key, Compare, Allocator>& rhs ) {
            lhs.swap(rhs);
        }
};

}
#endif