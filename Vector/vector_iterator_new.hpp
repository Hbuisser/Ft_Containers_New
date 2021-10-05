# ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector.hpp"

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
    class iterator
    {
        private:

        public:
            ///////////////////// Typedef //////////////////////////////////////////
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;

            ////////////////////// Constructors /////////////////////////////////////
            iterator(void) {}
            
    };

    // class iterators_traits {}
    // class reverse_iterator {}
    // class enable_if {}
    // class is_integral {}
    // equal/lexicographical compare
    // std::pair
    // std::make_pair
}

#endif