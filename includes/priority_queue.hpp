#ifndef PRIORIT_QUEUE_HPP
#define PRIORIT_QUEUE_HPP

#include <iostream>
#include <algorithm>
#include "less.hpp"

namespace ft {

template <class T, class Container , class Compare > // ft::less<typename Container::value_type>
class priority_queue
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef Container container_type;
        typedef Compare value_compare;
    protected:
        container_type container;
        value_compare comp;
    public:
        priority_queue( InputIterator first, InputIterator last, const Compare& compare = Compare(), const Container& cont = Container() );
        priority_queue( const priority_queue& other );
        explicit priority_queue (const Compare& comp = Compare(), const Container& ctnr = Container()) {
            std::cout << " Default Constructor Called " << std::endl;
            container = ctnr;
            comp = comp;
            std::make_heap(c.begin(), c.end(), comp); // ft::make_heap(c.begin(), c.end(), comp <- ft::less);
        }
        ~priority_queue() {
            container.clear();
        }
        priority_queue& operator=( const priority_queue& other ) {
            container = other.container;
            comp = other.comp;
            return *this;
        }
        const_reference top() const {
            return container.front();
        }
        bool empty() const {
            return container.empty();
        }
        size_type size() const {
            return container.size();
        }
        void push( const value_type& value )
        {
            container.push_back(value);
            std::push_heap(container.begin(), container.end(), comp); // ft::push_heap(Container::begin(), Container::end(), comp <- ft::less);
        }
        void pop() {
            std::pop_heap(container.begin(), container.end(), comp); // ft::pop_heap(container.begin(), container.end(), comp <- ft::less);
            container.pop_back();
        }
};
}

#endif