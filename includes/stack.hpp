#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <vector>
#include <list>
#include <iostream>


namespace ft {

template< class T, class Container>
class stack
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef T& reference;
        typedef const T& const_reference;
    protected:
        Container 	    container;
    public:
        stack( const stack& other ) {
            std::cout << "Copy Constructor called" << std::endl;
            container = other.container; 
        }
        explicit stack( const Container& cont = Container() ) {
            std::cout << "Default Constructor called" << std::endl;
            container = cont;
        }
        ~stack() {
            container.clear();
        };
        stack& operator=( const stack& other ) {
            std::cout << "Assignement opperator called" << std::endl;
            container = other.container;
            return *this;
        }
        reference top() {
            return container.back();
        }
        const_reference top() const {
            return container.back();
        }
        bool empty() const {
            return container.empty();
        }
        size_type size() const {
            return container.size();
        }
        void push( const_reference value ) {
            container.push_back(value);
        }
		void pop() {
            container.pop_back();
        };

        friend bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs == rhs)
                return true;
            else
                return false;
        }
        friend bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs != rhs)
                return true;
            else
                return false;
        }
        friend bool operator< ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs < rhs)
                return true;
            else
                return false;
        }
        friend bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs <= rhs)
                return true;
            else
                return false;
        }
        friend bool operator> ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs > rhs)
                return true;
            else
                return false;
        }
        friend bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
            if (lhs >= rhs)
                return true;
            else
                return false;
        }
};

}


#endif