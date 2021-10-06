# ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
    /*Category*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

    /*Base class*/
    template< class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
    class iterator
    {
        public:
            ///////////////////// Typedef //////////////////////////////////////////
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
    };

    /*Define properties of iterators*/
	template <class Iterator> 
	class iterator_traits
	{
		public:
			/*Member types*/
			typedef typename Iterator::value_type value_type;
    		typedef typename Iterator::difference_type difference_type;
    		typedef typename Iterator::pointer pointer;
    		typedef typename Iterator::reference reference;
    		typedef typename Iterator::iterator_category  iterator_category;
	};

	/*T* specialization*/ 
	template <class T> 
	class iterator_traits<T*>
	{
		public:
			/*Member types*/
			typedef T value_type;
    		typedef ptrdiff_t difference_type;
    		typedef T* pointer;
    		typedef T& reference;
    		typedef ft::random_access_iterator_tag iterator_category;
	};

	/*const T* specialization*/
	template <class T> 
	class iterator_traits<const T*>
	{
		public:
			/*Member types*/
			typedef T value_type;
    		typedef ptrdiff_t difference_type;
    		typedef const T* pointer;
    		typedef const T& reference;
    		typedef ft::random_access_iterator_tag iterator_category;
	};

    /*legacy*/
    // template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
    template<class Category = ft::random_access_iterator_tag, class T = int, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
    class It
    {
        private:
            Pointer _ptr;
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;

            It(pointer ptr = nullptr) : _ptr(ptr) {}
            ~It() { _ptr = nullptr; }
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            It& operator++() { _ptr++; return *this; }  
            It operator++(int) { It tmp = *this; ++(*this); return tmp; }
            It& operator--() { _ptr--; return *this; }  
            It operator--(int) { It tmp = *this; --(*this); return tmp; }
            // friend of non member overload
            friend bool operator==(const It& a, const It& b) { return a._ptr == b._ptr; }
            friend bool operator!=(const It& a, const It& b) { return a._ptr != b._ptr; }
            It& operator=(const It & x) { this->_ptr = x._ptr; return *this; }
            It& operator+=(difference_type n) const 
            {
                difference_type m;

                m = this->_ptr - n._ptr;
                if (m >= 0) 
                {
                    while (m--) 
                        ++this->_ptr;
                }
                else
                {
                    while (m++) 
                        --this->_ptr;
                }
                return this->_ptr;
            }
            It& operator+(const It & x) const
            {
                It temp = *this;
                return temp += x;
            }
            It& operator-=(const It & x) const
            {
                difference_type m;

                m = this->_ptr - x._ptr;
                if (m >= 0) 
                {
                    while (m--) 
                        --this->_ptr;
                }
                else
                {
                    while (m++) 
                        ++this->_ptr;
                }
                return this->_ptr;
            }
            It& operator-(const It & x) const
            {
                It temp = *this;
                return temp -= x;
            }
            bool operator<(const It & x) const { return this->_ptr < x._ptr; }
            bool operator<=(const It & x) const { return this->_ptr <= x._ptr; }
            bool operator>(const It & x) const { return this->_ptr > x._ptr; }
            bool operator>=(const It & x) const { return this->_ptr >= x._ptr; }
            It& operator[](difference_type n) { return *this->_ptr + n; }
    };

    /*Reverse iterator*/
	template <class Iterator> 
	class reverse_iterator
	{
		public:
			/*Member types*/
			typedef Iterator iterator_type;
    		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    		typedef typename iterator_traits<Iterator>::value_type value_type;
    		typedef typename iterator_traits<Iterator>::difference_type difference_type;
    		typedef typename iterator_traits<Iterator>::pointer pointer;
    		typedef typename iterator_traits<Iterator>::reference reference;

			/*Constructor and destructor*/
			reverse_iterator() {}
			explicit reverse_iterator (iterator_type it) : current( it ) {}
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) : current( rev_it.current ) {}

			/*Member functions*/
			iterator_type base() const
			{
				return this->current;
			}
			reference operator*() const
			{
				return *this->current;
			}
			reverse_iterator operator+(difference_type n) const { }
			reverse_iterator& operator++() {}
			reverse_iterator operator++(int) {}
			reverse_iterator& operator+= (difference_type n) {}
			reverse_iterator operator-(difference_type n) const {}
			reverse_iterator& operator--() {}
			reverse_iterator  operator--(int) {}
			reverse_iterator& operator-=(difference_type n) {}
			pointer operator->() const {}
			reference operator[](difference_type n) const {}
        protected:
			iterator_type current;
    };
    // template< class Iterator1, class Iterator2 >
    // bool operator==( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator==( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

        
    // template< class Iterator1, class Iterator2 >
    // bool operator!=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator!=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

        
    // template< class Iterator1, class Iterator2 >
    // bool operator<( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator<( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

        
    // template< class Iterator1, class Iterator2 >
    // bool operator<=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator<=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // bool operator>( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator>( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

        
    // template< class Iterator1, class Iterator2 >
    // bool operator>=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, class Iterator2 >
    // constexpr bool operator>=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

    // template< class Iterator1, std::three_way_comparable_with<Iterator1> Iterator2 >
    // constexpr std::compare_three_way_result_t<Iterator1, Iterator2>
    //     operator<=>( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );
}

#endif