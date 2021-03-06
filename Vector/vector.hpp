#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <limits>
#include <iterator>

#include "vector_iterator.hpp"

// https://internalpointers.com/post/writing-custom-iterators-modern-cpp
// https://www.it-swarm-fr.com/fr/c%2B%2B/ecrire-votre-propre-conteneur-stl/939838072/

namespace ft
{
	/*  --- PAIR --- */
	template< class T1, class T2 >
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;
		pair(void) : first(), second() {}
		template <class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
		pair(const first_type& a, const second_type& b) : first(a), second(b) {}
		pair& operator=(const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}
	};
	template < class T1, class T2 >
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) 
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template < class T1, class T2 >
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) 
	{
		return (!(lhs == rhs));
	}
	template < class T1, class T2 >
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) 
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template < class T1, class T2 >
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs < lhs));
	}
	template < class T1, class T2 >
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}
	template < class T1, class T2 >
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) 
	{
		return (!(lhs < rhs));
	}

	/* --- MAKE PAIR --- */
	template < class T1, class T2 >
	pair<T1, T2> make_pair(const T1& x, const T2& y) 
	{
		return (pair<T1, T2>(x, y));
	}

	/*  --- ENABLE_IF --- */
    template<bool Cond, class T = void>
    struct enable_if {};
    // specialized enable_if if first param is True 
	// if not, typedef doesn't work and constructor cannot be implemented
    template<class T>
    struct enable_if<true, T> // enable_if<bool, var>
    { 
		typedef T type;
	};

    /* --- IS_INTEGRAL --- */
    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;   // true or false vu qu'on passe un bool
        typedef T value_type;
        typedef integral_constant<T, v> type;
        operator T() { return v; }

    };
	template <class T>
    struct is_integral : public ft::integral_constant<bool, false> {};

    template<> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};
    // const
    template<> struct is_integral<const bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned long long int> : public ft::integral_constant<bool, true> {};
    // volatile
	// https://stackoverflow.com/questions/4437527/why-do-we-use-volatile-keyword
    template<> struct is_integral<volatile bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned long long int> : public ft::integral_constant<bool, true> {};

	template < class T, class Alloc = std::allocator<T> >
	class vector 
	{
		private:
            size_t	_size;
            size_t 	_capacity;
			Alloc 	_base;
			T* 		_ptr;

        public:
            /////////////////////////////////////////////////////// Typedef /////////////////////////////////////
			typedef T															value_type;
			typedef Alloc   													allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef	typename allocator_type::pointer 							pointer;
			typedef typename allocator_type::const_pointer 						const_pointer;	
			typedef It<value_type>												iterator;
			typedef It<const value_type>										const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef size_t														size_type;

			/////////////////////////////////////////////////////// Constructors /////////////////////////////////
			explicit vector(const allocator_type& alloc = allocator_type()) : _base(alloc), _size(0), _capacity(5) { this->_ptr = this->_base.allocate(5); }
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _base(alloc), _size(n), _capacity(n * 2)
			{
				this->_ptr = this->_base.allocate(n);
				size_t i = 0;

				while (i < n)
				{
					this->_base.construct(this->_ptr + i, val);
					i++;
				}
			}
			// if ft::enable_if<>::type is not defined (if InputIterator is an integral type), then
            // the template is not valid and the program will know to use the -FILL constructor-
            template < class InputIterator >
            vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
            {
                long    distance = std::distance(first, last);
                int     i;

                this->_ptr = this->_allocator.allocate(distance);
                this->_capacity = distance;
                this->_size = distance;
                i = 0;
                while (first != last)
                {
                    this->_allocator.construct(this->_ptr + i, *first);
                    first++;
                    i++;
                }
            }
			vector(const vector &x) : _base(allocator_type()), _size(x._size), _capacity(x._capacity) 
			{
				this->_ptr = this->_base.allocate(0);
				*this = x;
			}
			virtual ~vector()
			{
				this->clear();
				if (this->_ptr != NULL)
					this->_base.deallocate(this->_ptr, this->_capacity);
			}
			vector & operator=(const vector & x)
			{
				size_t i = 0;
				this->clear();
				this->_base.deallocate(this->_ptr, this->_capacity);
				this->_ptr = this->_base.allocate(x._capacity);
				while (i < x._size)
				{
					this->_base.construct(this->_ptr + i, *(x._ptr + i));
					i++;
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
				return *this;
			}
			///////////////////////////////////////////////////// Iterators /////////////////////////////////////////
			iterator begin(void) { return iterator(this->_ptr); }
			const_iterator begin(void) const { return const_iterator(this->_ptr); }
			iterator end(void)
			{
				if (this->_size == 0)
					return iterator(this->_ptr);
				return iterator(this->_ptr + this->_size);
			}
			const_iterator end(void) const
			{
				if (this->_size == 0)
					return const_iterator(this->_ptr);
				return const_iterator(this->_ptr + this->_size);
			}
			reverse_iterator rbegin()
			{
				if (!this->_size)
					return (reverse_iterator(this->_ptr));
				return (reverse_iterator(this->_ptr + this->_size - 1));
			}
			const_reverse_iterator rbegin() const 
			{
				if (!this->_size)
					return (const_reverse_iterator(this->_ptr));
				return (const_reverse_iterator(this->_ptr + this->_size - 1));
			}
			reverse_iterator rend()
			{ 
				return reverse_iterator(this->_ptr);
			}
			const_reverse_iterator rend() const
			{ 
				return const_reverse_iterator(this->_ptr - 1);
			}
			/////////////////////////////////////////////////////// Capacity /////////////////////////
			size_t size(void) const { return this->_size; }
			size_t max_size(void) const { return this->_base.max_size(); }
			void reserve(size_type n)
			{
				if (n > this->_capacity)
				{
					size_t i;
					vector cpy;

					i = 0;
				   	cpy = *this;
					this->clear();
					this->_base.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_base.allocate(n);
					while (i < cpy._size)
					{
						this->_base.construct(this->_ptr + i, *(cpy._ptr + i));
						i++;
					}
					this->_size = cpy._size;
					this->_capacity = n;
				}
			}
			size_type capacity() const { return _capacity; }
			bool empty() const
			{ 
				if (_size == 0)
					return true;
				return false;
			}
			void resize(size_type n, value_type val = value_type())
			{
				size_t i = 0;
				
				if (n > this->_size)
				{
					this->reserve(n);
					i = this->_size;
					while (i < n)
					{
						this->_base.construct(this->_ptr + i, val);
						i++;
					}
				}
				else
				{
					i = n;
					while(i < this->_size)
					{
						this->_base.destroy(this->_ptr + i);
						i++;
					}
					this->_size = n;
				}
				this->_size = n;
			}
			/////////////////////////////////////////////////////// Element access ////////////////////////
			reference operator[]( size_type n ) { return this->at(n); }
			reference at(size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				else
					return *(this->_ptr + n);
			}
			const_reference at(size_type n) const
			{
				if ( n >= this->_size )
					throw std::out_of_range("vector");
				else
					return *(this->_ptr + n);
			}
			reference front() { return *this->_ptr; }
			const_reference front() const { return *this->_ptr; }
			reference back() { return *(this->_ptr + this->_size - 1); }
			const_reference back() const { return *(this->_ptr + this->_size - 1); }
			//////////////////////////////////////////////////////// Modifiers /////////////////////////////////////
			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last)
			{

			}
			void assign(size_type n, const value_type& val)
			{
				size_t i = 0;
				
				this->clear();
				this->_base.deallocate(this->_ptr, this->_capacity);
				this->_ptr = this->_base.allocate(n);
				while (i < n)
				{
					this->_base.construct(this->_ptr + i, val);
					i++;
				}
				this->_size = n;
				this->_capacity = n;
			}
			void push_back(const value_type& val)
			{
				if (this->_capacity == this->_size)
					this->reserve(this->_size + 1);
				this->_base.construct(this->_ptr + this->_size, val);
				this->_size = this->_size + 1;
			}
			void pop_back() 
			{ 
				if (this->_size > 0)
				{
					std::cout << *(this->_ptr + (this->_size - 1)) << std::endl;
					std::cout << *(this->_ptr) << std::endl;
					_base.destroy(this->_ptr + (this->_size - 1));
					std::cout << "destructed" << *(this->_ptr + (this->_size - 1)) << std::endl;
					this->_size--;
					std::cout << *(this->_ptr + (this->_size - 2)) << std::endl;
				}
			}
			iterator insert(iterator position, const value_type& val)
			{

			}
			void insert(iterator position, size_type n, const value_type& val)
			{

			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			{

			}
			// iterator erase(iterator position);
			// iterator erase(iterator first, iterator last);
			void swap(vector& x)
			{
				vector tmp;

				tmp = *this;
				this->clear();
				*this = x;
				x.clear();
				x = tmp;
			}
			void clear(void)
			{				
				size_t i;
				
				i = 0;
				while (i < this->_size)
				{
					this->_base.destroy(this->_ptr + i);
					i++;
				}
				this->_size = 0;
			}
			////////////////////////////////////////////////// Allocator ////////////////////////////////////
			allocator_type getAllocator(void) const { return _base; }
	};
	template< class T, class Alloc >
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		typename ft::vector<const T>::iterator it1 = lhs.begin();
		typename ft::vector<const T>::iterator it2 = rhs.begin();

		if (lhs.size() != rhs.size())
			return false;
		while (it1 != lhs.end())
		{
			if (*it1 != *it2)
				return false;
			it1++;
			it2++;
		}
		return true;
	}
	template< class T, class Alloc >
	bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template< class T, class Alloc >
	bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		typename ft::vector<const T>::iterator it1 = lhs.begin();
		typename ft::vector<const T>::iterator it2 = rhs.begin();

		if (lhs.size() < rhs.size())
			return true;
		while (it1 != lhs.end())
		{
			if (*it1 < *it2)
				return true;
			it1++;
			it2++;
		}
		return false;
	}
	template< class T, class Alloc >
	bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		typename ft::vector<const T>::iterator it1 = lhs.begin();
		typename ft::vector<const T>::iterator it2 = rhs.begin();

		while (it1 != lhs.end())
		{
			if (*it1 > *it2)
				return false;
			it1++;
			it2++;
		}
		return true;
	}
	template< class T, class Alloc >
	bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
	template< class T, class Alloc >
	bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs <= rhs);
	}
}

#endif
