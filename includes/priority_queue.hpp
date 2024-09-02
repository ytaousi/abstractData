#ifndef PRIORIT_QUEUE_HPP
#define PRIORIT_QUEUE_HPP

#include <iostream>

namespace ft {

template <class T, class Container, class Compare>
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
        explicit priority_queue (const Compare& comp = Compare(), const Container& ctnr = Container());
        ~priority_queue() {
            container.clear();
        }
        priority_queue& operator=( const priority_queue& other );
        const_reference top() const;
        bool empty() const {
            return container.empty();
        }
        size_type size() const {
            return container.size();
        }
        void push( const value_type& value )
        {
            container.push_back(value);
            std::push_heap(container.begin(), container.end(), comp); // ft::push_heap(Container::begin(), Container::end(), comp);
        }
        void pop();
};
}

#endif