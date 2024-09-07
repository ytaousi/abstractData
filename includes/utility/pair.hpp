#ifndef PAIR_HPP
#define PAIR_HPP

#include <utility>

namespace ft {

template< class T1, class T2 >
class pair
{
    public:
        typedef T1 first_type;
        typedef T2 second_type;

    public:
        // Defautl // Copy // Initilization
        pair() {
            first_type = T1();
            second_type = T2();
        };
        pair( const pair& p ) = default {
            this->first_type = p.first_type;
            this->second_type = p.second_type;  
        };
        pair (const first_type& a, const second_type& b) {
            this->first_type = a;
            this->second_type = b;
        }
        pair& operator=( const pair& other ) {
            this->first_type = other.first_type;
            this->second_type = other.second_type;
            return *this;
        };
        pair& operator=( const pair<U1, U2>& other ) {
            this->first_type = other.first_type;
            this->second_type = other.second_type;
            return *this;
        };

        // Non-Member Functions
        friend bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            if (lhs.first_type == rhs.first_type && lhs.second_type == rhs.second_type)
                return true;
            else
                return false;
        }
        friend bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            return !(lhs == rhs);
        }
        friend bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            if (lhs.first < rhs.first)
                return true;
            else
            {
                if (rhs.first < lhs.first)
                    return false;
                else
                {
                    if (lhs.second < rhs.second)
                        return true;
                    else
                        return false;
                }
            }

        }
        friend bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            return !(rhs < lhs);
        }
        friend bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            return (rhs < lhs);
        }
        friend bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ) {
            return !(lhs < rhs);
        }
        friend ft::pair<T1, T2> make_pair( T1 t, T2 u ) {
            return ft::pair<T1, T2>(t, u);
        }
};
}
#endif