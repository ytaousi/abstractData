#ifndef PRIORIT_QUEUE_HPP
#define PRIORIT_QUEUE_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//#include "less.hpp"

namespace ft {

template <class T, class Container = std::vector<T> , class Compare = std::less<typename Container::value_type> > // ft::less<typename Container::value_type>
class priority_queue
{
    public:
        typedef T value_type;
        typedef size_t size_type;
        typedef Container container_type;
        typedef Compare value_compare;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::iterator iterator;
        typedef typename std::iterator_traits<iterator>::difference_type InputIterator;

    protected:
        container_type container;
        value_compare comp;
    public:
        priority_queue(InputIterator first, InputIterator last, const Compare& compare = Compare(), const Container& cont = Container()) {
            std::cout << " Constructor with InputIterator Called " << std::endl;
            this->container = cont;
            this->comp = compare;
            container.insert(this->container.end(), first, last);
            std::make_heap(this->container.begin(), container.end(), this->comp); // ft::make_heap(container.begin(), container.end(), comp <- ft::less);
        }
        priority_queue( const priority_queue& other ){
            std::cout << " Copy Constructor Called " << std::endl;
            this->container = other.container;
            this->comp = other.comp;
        }
        explicit priority_queue (const Compare& comp = Compare(), const Container& ctnr = Container()) {
            std::cout << " Default Constructor Called " << std::endl;
            this->container = ctnr;
            this->comp = comp;
            std::make_heap(this->container.begin(), this->container.end(), this->comp); // ft::make_heap(c.begin(), c.end(), comp <- ft::less);
        }
        ~priority_queue() {
            this->container.clear();
        }
        priority_queue& operator=( const priority_queue& other ) {
            this->container = other.container;
            this->comp = other.comp;
            return *this;
        }
        const_reference top() const {
            return this->container.front();
        }
        bool empty() const {
            return this->container.empty();
        }
        size_type size() const {
            return this->container.size();
        }
        void push( const value_type& value ) {
            this->container.push_back(value);
            std::push_heap(this->container.begin(), this->container.end(), this->comp); // ft::push_heap(Container::begin(), Container::end(), comp <- ft::less);
        }
        void pop() {
            std::pop_heap(this->container.begin(), this->container.end(), this->comp); // ft::pop_heap(container.begin(), container.end(), comp <- ft::less);
            this->container.pop_back();
        }
};
}

#endif