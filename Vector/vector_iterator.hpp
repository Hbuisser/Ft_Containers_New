# ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "vector.hpp"

namespace ft
{
    template<typename T>
    class iterator
    {
        protected:
            T   *_vector;
        
        public:
            iterator(void): _vector(nullptr) {}
            iterator(void *vector_): _vector(static_cast<T *>(vector_)) {}
            iterator(const iterator<T> &other) { *this = other; }
            virtual ~iterator() {}

            T *get_vector() const { return _vector; }
            iterator& operator=(const iterator<T>& other)
            {
                _vector = other._vector;
                return (*this);
            }
            bool		operator== (const iterator<T>& oth) const {return (_vector == oth._vector);}
			bool		operator!= (const iterator<T>& oth) const {return (_vector != oth._vector);}
			bool		operator< (const iterator<T>& oth) const {return (_vector < oth._vector);}
			bool		operator<= (const iterator<T>& oth) const {return (_vector <= oth._vector);}
			bool		operator> (const iterator<T>& oth) const {return (_vector > oth._vector);}
			bool		operator>= (const iterator<T>& oth) const {return (_vector >= oth._vector);}
            T &operator*() {return (*_vector);}
            iterator<T> operator++() // ++var
            {
                _vector++;
                return iterator<T>(_vector);
            }
            iterator<T> operator++(int) // var++
            {
                iterator<T> tmp(*this);

                _vector++;
                return iterator<T>(tmp);
            }
            iterator<T> operator--()
            {
                _vector--;
                return iterator<T>(_vector);
            }
            iterator<T> operator--(int)
            {
                iterator<T> tmp(*this);

                _vector--;
                return iterator<T>(tmp);
            }
    };

    ///////////////////////////////////// Reverse_iterator //////////////////////////////
    
    template<typename T>
	class reverse_iterator : public iterator<T>
	{
		public:
			reverse_iterator(void) : iterator<T>() {}
			reverse_iterator(void* p_vector) : iterator<T>(p_vector) {}
			reverse_iterator(const reverse_iterator<T>& oth) : iterator<T>() { this->_vector = oth._vector;}
			virtual ~reverse_iterator(void) {}
            
            reverse_iterator&	operator= (const reverse_iterator<T>& oth)
			{
				this->_vector = oth._vector;
				return (*this);
			}
			reverse_iterator&	operator++ () { this->_vector-- ; return (*this);}
			reverse_iterator	operator++ (int) { reverse_iterator<T> tmp(*this); operator++(); return tmp;}
			reverse_iterator&	operator-- () { this->_vector++ ; return (*this);}
			reverse_iterator	operator-- (int) { reverse_iterator<T> tmp(*this); operator--(); return tmp;}
	};
}

/////////////////////////////////////////////////////////////////////////////////////////////////


#endif