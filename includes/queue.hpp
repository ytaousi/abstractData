#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>

namespace ft {

template< class T, class Container = std::deque<T> >
class queue
{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        Container container;

    public:
        queue( const queue& other ) {
            container = other.container;
        }
        explicit queue (const container_type& ctnr = container_type()) {
            std::cout << " Default Constructor Called " << std::endl;
            container = ctnr;
        }
        ~queue() {
            container.clear();
        }
        queue& operator=( const queue& other ) {
            container = other.container;
            return *this;
        }
        value_type& front() {
            return container.front();
        }
        const value_type& front() const {
            return container.front();
        }
        value_type& back() {
            return container.back();
        }
        const value_type& back() const {
            return container.back();
        }
        bool empty() const {
            return container.empty();
        }
        size_type size() const {
            return container.size();
        }
        void push( const value_type& value ) {
            container.push_back(value);
        }	
        void pop() {
            container.pop_front();
        }
	
        friend bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
            if (lhs == rhs)
                return true;
            else
                return false;
        }
        friend bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            if (lhs != rhs)
                return true;
            else
                return false;
        }
        friend bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            if (lhs < rhs)
                    return true;
                else
                    return false;
        }
        friend bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            if (lhs <= rhs)
                    return true;
                else
                    return false;
        }
        friend bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            if (lhs > rhs)
                    return true;
                else
                    return false;
        }
        friend bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            if (lhs >= rhs)
                    return true;
                else
                    return false;
        }
};		
}

#endif